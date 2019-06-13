//Bibliotecas para controlar el sensor de temperatura y humedad
#include <DHT.h>
#include <DHT_U.h>
//Constantes:
//  + Pin para controlar el buzzer
//  + Frecuencia del buzzer
#define BUZZERPIN 6
#define BUZZERTONE 440
//  + Pin del boton de menu
//  + Pin del boton de up
//  + Pin del boton de down
#define MENUBUTTON 7
#define UPBUTTON 8
#define DOWNBUTTON 9
//  + Pin del LDR
//  + Valor minimo del LDR
#define LDRPIN A1
#define MINIMUNLDR 300
//  + Pin del sensor de temperatura
//  + Pin del sensor de temperatura y humedad DHT
#define TEMPERATURE A2
#define DHTPIN A0
//  + Delay entre mediciones
#define DELAY 1000

//Objeto manejador del sensor de temperatura y humedad
DHT dht(DHTPIN,DHT11);

void setup() {
  // Inicializar el monitor serie
  Serial.begin(9600);
  // Inicializar el pin del buffer
  pinMode(BUZZERPIN,OUTPUT);
  // Inicializar los pines de los botones
  pinMode(MENUBUTTON,INPUT);
  pinMode(UPBUTTON,INPUT);
  pinMode(DOWNBUTTON,INPUT);
  // Inicializar el pin del LDR
  pinMode(LDRPIN,INPUT);
  // Inicializar el pin del sensor de temperatura
  pinMode(TEMPERATURE,INPUT);
  // Inicializar el sensor DHT
  dht.begin();
}

void loop() {
    int data;

    //bucle infinito esperando a que se pulse en un boton
    do{
      //si se pulsa el boton de menu se entra en modo LDR y buzzer hasta que se vuelva a pulsar
      if(digitalRead(MENUBUTTON)){
        //imprimir el nuevo modo
        Serial.println("Menu Button pushed: entered in LDR and buzzer mode");
        //esperar para que no se confunda la medicion de condicion del while con el pulso del boton
        //   para entrar a este modo
        delay(DELAY);
        do{
            //si se le quita la luz a el LDR, hacemos sonar a el BUZZER por DELAY segundos
            if(analogRead(LDRPIN) < MINIMUNLDR){
                tone(BUZZERPIN,BUZZERTONE);
                delay(DELAY);
                noTone(BUZZERPIN);
            }
        //cuando se vuelva a pulsar el boton de menu, se sale del bucle y se vuelve a comenzar
        //   el loop
        }while(!digitalRead(MENUBUTTON));
        delay(DELAY);
        return;  
      }else if(digitalRead(UPBUTTON)){
        //imprimir el nuevo modo
        Serial.println("Up Button pushed: entered in temperature measurement with TMP36");
        //esperar para que no se confunda la medicion de condicion del while con el pulso del boton
        //   para entrar a este modo
        delay(DELAY);
        do{
              //medir voltaje, convertirlo a celsius e imprimirlo por pantalla
              int medicion = analogRead(TEMPERATURE);
              float celsius = (medicion*5.0/1024 - 0.5)*100;
              Serial.print("Current temperature TMP36: "); Serial.println(celsius);
        //cuando se vuelva a pulsar el boton de up, se sale del bucle y se vuelve a comenzar
        //   el loop
        }while(!digitalRead(UPBUTTON));
        delay(DELAY);
        return;  
      }else if(digitalRead(DOWNBUTTON)){
        Serial.println("Down Button pushed: entered in temperature and humdity measurement with DHT");
        //esperar para que no se confunda la medicion de condicion del while con el pulso del boton
        //   para entrar a este modo
        delay(DELAY);
        do{
              //Medir temperatura e imprimirla por pantalla
              Serial.print("Current temperature DHT: "); Serial.print(dht.readTemperature());
              //Medir humedad e imprimirla por pantalla
              Serial.print("   Current humidity DHT:"); Serial.println(dht.readHumidity());
        //cuando se vuelva a pulsar el boton de down, se sale del bucle y se vuelve a comenzar
        //   el loop
        }while(!digitalRead(DOWNBUTTON));
        delay(DELAY);
        return;  
      }
    }while(1);
}
