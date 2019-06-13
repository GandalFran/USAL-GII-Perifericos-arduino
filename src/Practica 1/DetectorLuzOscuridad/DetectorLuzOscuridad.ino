//Constantes:
//  + pin en el que hemos conectado el LDR
//  + pin en el que hemos conectado el LED
//  + limite a partir del cual el LDR detecta que
//          no hay luz (sacado a ensallo y error)
//  + delay entre mediciones del LDR y actuacion
//          sobre el LED
#define LDRINPUT A0
#define LEDPIN 9
#define LDRLIMIT 990
#define DELAY 500

void setup() {
  //declarar el pin del LDR como entrada (buscamos medir de este)
  //   y el del LED como salida (para ilumniarlo)
  pinMode(LDRINPUT,INPUT);
  pinMode(LEDPIN,OUTPUT);
  //Iniciar la terminal a 9600 baudios
  Serial.begin(9600);
}

void loop() {
  //Leer la entrada del pin del LDR
  int output = analogRead(LDRINPUT);
  //mostrar el dato leido
  Serial.println(output);

  //si hay luz (aumenta el valor de la entrada del LDR) apagamos el LED
  //    en caso contrario lo encendemos
  if( output > LDRLIMIT )
    digitalWrite(LEDPIN,LOW);
  else
    digitalWrite(LEDPIN,HIGH);
    
  //esperar DELAY ms
   delay(DELAY);
}
