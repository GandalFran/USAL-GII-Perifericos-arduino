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
  //imprimir distancia por puerto serie: para hacer plotting o leerlo
  Serial.println(medicion);
  //esperar DELAY ms
  delay(DELAY);
}
