#ifndef Sega6Joi
#define Sega6Joi

#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif 

//#include "HardwareSerial.h"

class Sega6j
{
  public:
    Sega6j(byte, byte, byte, byte, byte, byte, byte);
    word update(void);
  private:
    byte D0;
    byte D1;
    byte D2;
    byte D3;
    byte D4;
    byte select;
    byte D5;
};

#endif
