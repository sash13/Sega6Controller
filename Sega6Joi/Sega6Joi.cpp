#include "Sega6Joi.h"

Sega6j::Sega6j(byte d0, byte d1, byte d2, byte d3, byte d4, byte sel, byte d5)
{
  pinMode(d0, INPUT);     
  pinMode(d1, INPUT);     
  pinMode(d2, INPUT);     
  pinMode(d3, INPUT);     
  pinMode(d4, INPUT);     
  pinMode(d5, INPUT);     
  
  pinMode(sel, OUTPUT);
  digitalWrite(sel, HIGH);

  select = sel;
  D0 = d0;
  D1 = d1;
  D2 = d2;
  D3 = d3;
  D4 = d4;
  D5 = d5;
}


word Sega6j::update(void)
{
  byte button_D4, button_D5, button_D0, button_D1, button_D2, button_D3;
  word out = 0;

  //hight select
  digitalWrite(select, HIGH);
  
  button_D4 = digitalRead(D4);
  if (button_D4 == 0) out +=16; //B button
  button_D5 = digitalRead(D5);
  if (button_D5 == 0) out +=32; //C button 
  button_D0 = digitalRead(D0);
  if (button_D0 == 0) out +=1; //up button 
  button_D1 = digitalRead(D1);
  if (button_D1 == 0) out +=2; //down button
  button_D2 = digitalRead(D2);
  if (button_D2 == 0) out +=4; //left button
  button_D3 = digitalRead(D3);
  if (button_D3 == 0) out +=8; //right button
  
 //low select  
  digitalWrite(select, LOW);
  delayMicroseconds(10);
  
  button_D4 = digitalRead(D4);
  if (button_D4 == 0) out +=64; //A button
  button_D5 = digitalRead(D5);
  if (button_D5 == 0) out +=128; // Start button 
  
  digitalWrite(select, HIGH);
  delayMicroseconds(10);
    

  // pulse mode
  digitalWrite(select, LOW);
  delayMicroseconds(10);
  digitalWrite(select, HIGH);
  delayMicroseconds(10);


  digitalWrite(select, LOW);
  delayMicroseconds(10);
  digitalWrite(select, HIGH);
  delayMicroseconds(10);
  
  button_D0 = digitalRead(D0); 
  if (button_D0 == 0) out += 256; // Z button 
  button_D1 = digitalRead(D1); 
  if (button_D1 == 0) out += 512; //Y button
  button_D2 = digitalRead(D2);
  if (button_D2 == 0) out += 1024; // X button 
  button_D3 = digitalRead(D3);
  if (button_D3 == 0) out +=2048; //M button

  digitalWrite(select, LOW);
  delayMicroseconds(10);
  digitalWrite(select, HIGH);
  delayMicroseconds(10);

  return out;  
	  
}

