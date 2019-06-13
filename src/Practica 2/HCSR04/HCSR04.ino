//Biblioteca que encapsula el uso del sensor: https://github.com/Martinsos/arduino-lib-hc-sr04
#include <HCSR04.h>

//Constantes:
//  + pin de trigger del HCSR04
//  + pin de echo del HCSR04
//  + delay entre mediciones
#define TRIGGERPIN  13
#define ECHOPIN 12
#define DELAY 100

//Objeto que encpapsula el uso del sensor
UltraSonicDistanceSensor distanceSensor(TRIGGERPIN, ECHOPIN);

void setup () {
    //inicializacion de la terminal serie
    Serial.begin(9600);
}

void loop () {
    //obtener distancia
    double distance = distanceSensor.measureDistanceCm();
    Serial.println(distance);
    //esperar DELAY ms
    delay(DELAY);
}

