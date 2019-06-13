#include <Keypad.h>

const byte NROWS=4, NCOLS=4;
const char inputs[NROWS][NCOLS] = { {'1','2','3','A'}, {'4','5','6','B'}, {'7','8','9','C'}, {'*','0','#','D'} };
const byte colPins[NCOLS] = {9, 8, 7, 6}, rowPins[NROWS] = {13,12,11,10};
Keypad keypad = Keypad( makeKeymap(inputs),rowPins,colPins,NROWS,NCOLS);

void setup(){
   Serial.begin(9600);
}
  
void loop(){
  char input = keypad.getKey();
  if (input != 0)
    Serial.println(input);
}
