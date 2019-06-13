//Constantes:
//  + pin de input del sensor de flexion
//  + delay entre mediciones
#define INPUTPIN A0
#define DELAY 100

void setup() {
  //inicializacion de la terminal serie
  Serial.begin(9600);
}

void loop() {
  //obtener voltaje
  int medicion = analogRead(INPUTPIN);
  //convertir medicion de voltaje a grados celsius
  float celsius = (medicion*5.0/1024 - 0.5)*100;
  //imprimir distancia por puerto serie: para hacer plotting o leerlo
  Serial.println(celsius);
  //esperar DELAY ms
  delay(DELAY);
}
