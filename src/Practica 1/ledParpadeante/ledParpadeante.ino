//Constantes:
//  + pin en el que hemos conectado la alimentacion positiva del led
//  + duracion del intervalo entre 2 parpadeos
#define MYPIN 13
#define DELAY 500

void setup() {
  //declarar el pin como salida
  pinMode(MYPIN,OUTPUT);
}

void loop() {
  //activar la salida MYPIN (encender el LED)
  digitalWrite(MYPIN,HIGH);
  //esperar
  delay(DELAY);
  //desactivar la salida MYPIN (apagar el LED)
  digitalWrite(MYPIN,LOW);
  //esperar
  delay(DELAY);
}

