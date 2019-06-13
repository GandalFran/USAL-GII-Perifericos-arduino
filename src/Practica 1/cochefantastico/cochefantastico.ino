//Constantes:
//  + numero de pins que hay
//  + pin donde hemos conectado el led de la izda
//  + pin donde hemos conectado el led de la dcha
//  + maximo valor que acepta analogWrite
//  + minimo valor para darle a un LED conectado a 
//       un pin analogico
//  + delay de refresco de los LED
#define NPINS 8
#define DIGITAL1 12
#define DIGITAL2 13
#define MAXV 255
#define BASEV 45
#define DELAYTIME 100

//Vector que contiene los pins en los que estan conectados los LED
int pins[] = { DIGITAL1, A0, A1, A2, A3, A4, A5, DIGITAL2};

//Function para escribir sobre un pin, indiferentemente si es analogico o digital
void writeAnalogicOrDigital(int pin, int analogicValue, int digitalValue);

void setup() {
  //declarar todos los pins contenidos en pins como salida
  int i;
  for(i+0; i<NPINS; i++)
    pinMode(pins[i],OUTPUT);
  //iniciar el terminal a 9600 baudios
  Serial.begin(9600);
}

void loop() { 
  int i, current, currentV;

 //Encender de forma gradual de izquierda a derecha 
 for(current=0; current<NPINS; current++){

      //apagar desde el led actual hacia la derecha
      for(i=0; i<current ;i++){
          currentV = BASEV + (MAXV/(1+current-i));
          writeAnalogicOrDigital(pins[i],currentV,LOW);
      }

      //encender de formga gradual desde el led actual
      //   hacia la izquierda
      for(i=current+1; i<NPINS; i++){
          writeAnalogicOrDigital(pins[i],0,LOW);
      }

      //encender a el maximo el led actual
      writeAnalogicOrDigital(pins[current],MAXV,HIGH);

      //para una mayor suavidad en las transiciones
      if(current < 3)
        digitalWrite(DIGITAL1,HIGH);

      //esperar a la siguiente actualizacion de los LED
      delay(DELAYTIME);
  }

  //para una mayor suavidad en las transiciones
  analogWrite(A4,0);
  digitalWrite(DIGITAL2,HIGH);
  delay(DELAYTIME);
  analogWrite(A5,0);
  digitalWrite(DIGITAL2,HIGH);
  delay(DELAYTIME);
  analogWrite(A5,MAXV);
  digitalWrite(DIGITAL2,HIGH);
  delay(DELAYTIME);

  //Encender de forma gradual de dercha a izquierda 
  for(current=NPINS-1; current>=0; current--){

      //apagar desde el led actual hacia la izquierda
      for(i=current-1;i>=0;i--){
         currentV = BASEV + (MAXV/(1+current-i));
         writeAnalogicOrDigital(pins[i],currentV,LOW);
      }
      
      //encender de formga gradual desde el led actual
      //   hacia la derecha
      for(i=NPINS-1; i>current; i--){
          writeAnalogicOrDigital(pins[i],0,LOW);
      }
      
      //encender a el maximo el led actual
      writeAnalogicOrDigital(pins[current],MAXV,HIGH);

      //para una mayor suavidad en las transiciones
      if(current < 3)
        digitalWrite(DIGITAL1,HIGH);
      
      //esperar a la siguiente actualizacion de los LED
      delay(DELAYTIME);
  }
  
}

//Escribe el pin sobre el que se va a escribir, y en el caso de ser 
//   digital escribe en el con digitalWrite. En caso contrario, escribe 
//   con analogWrite.
void writeAnalogicOrDigital(int pin, int analogicValue, int digitalValue){

  Serial.println(pin);
    if(pin==DIGITAL1 || pin == DIGITAL2)
        digitalWrite(pin,digitalValue);
    else
        analogWrite(pin,analogicValue);
}
