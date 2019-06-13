//Bibliotecas para el teclado de membrana y el LCD respectivamente
#include <Keypad.h>
#include <LiquidCrystal.h>
//Constantes:
//  + Pines para conectar el LCD
//  + numero de filas y columnas del LCD
  #define RSPIN 8
  #define ENPIN 9
  #define DATA4 10
  #define DATA5 11
  #define DATA6 12
  #define DATA7 13
  #define NROW 2
  #define NCOL 16
//  + numero de filas y columnas del teclado
//  + pines en los que esta conectado el teclado
//  + valores de cada fila y columna del teclado
  const byte NROWS=4, NCOLS=4;
  byte colPins[NCOLS] = {26,27,28,29}, rowPins[NROWS] = {22,23,24,25 };
  char inputs[NROWS][NCOLS] = { {'1','2','3','A'}, {'4','5','6','B'}, {'7','8','9','C'}, {'*','0','#','D'} };
//  + delay de refresco de los LED
  #define DELAY 100
//Objeto manejador del teclado
  Keypad keypad = Keypad( makeKeymap(inputs),rowPins,colPins,NROWS,NCOLS);
//Objeto manejador del LCD
  LiquidCrystal lcd(RSPIN, ENPIN, DATA4, DATA5, DATA6, DATA7);

void setup() {
  // Inicializar el monitor serie
   Serial.begin(9600);
  // Inicializar el LCD con el número de  columnas y filas del LCD
  lcd.begin(NCOL, NROW);
}
void loop() {
  //Leemos un caracter
  char input = keypad.getKey();
  //en el caso de que haya un caracter
  if (input != 0){
    //Escribimos el caracer en la pantalla del PC
    Serial.println(input);
    //Escribimos en el LCD
    lcd.print(input);
  }
  delay(DELAY);
}
