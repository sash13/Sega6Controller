#include <Sega6Joi.h>

//Pin Assign (D-SUB9P)
#define pin1  8
#define pin2  7
#define pin3  6
#define pin4  5
#define pin6  4
#define pin7  3
#define pin9  2


Sega6j control = Sega6j(pin1,pin2,pin3,pin4,pin6,pin7,pin9);

word aux;

void setup() 
{
  Serial.begin(9600);
}

void loop()
{
  aux=control.update();
  Serial.println(aux, DEC);
  delay(10);
}
