//Bibliotecas para controlar el servo
#include <Servo.h>
//Constantes:
//  + Pin de lectura del LDR
//  + Pin de control del servo
#define LDRPIN A0
#define SERVOPIN 13
//  + Valores de grados para abir y cerrar el servo
#define CLOSE 0
#define OPEN 90
//  + Valores minimos y maximos del LDR
#define MINVALUE 50
#define MAXVALUE 100
//  + Delay entre mediciones
#define DELAY 1000

Servo servo;
 
void setup() {
  Serial.begin(9600);
  servo.attach(SERVOPIN);
  pinMode(LDRPIN,INPUT);
}
 
void loop() {
  //leer datos del LDR
  int test = analogRead(LDRPIN);
  //Imprimirlos por pantalla
  Serial.println(test);
  //Mover el servo si hay poca luz y en caso contrario
  //   dejarlo en la posicion inicial
  if( test < MINVALUE )
    servo.write(OPEN);
  else
    servo.write(CLOSE);
  //Esperar delay segundos
  delay(DELAY);
}




