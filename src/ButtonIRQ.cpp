#include "HardwareSerial.h"
#include "ButtonIRQ.h"
#include <Arduino.h>

volatile bool flag = false;
     
void buttonPressed(){
  flag = true;   
}

ButtonIRQ::ButtonIRQ(int Button) {
  _button = Button;
  pinMode(_button, INPUT_PULLUP); 
   //Using Interupt to check when there is a chage from obstruction to hole in the encoder
  attachInterrupt(digitalPinToInterrupt(_button), buttonPressed, FALLING); //on falling edge

}

void ButtonIRQ::begin(double bdrate) {
  delay(30);
  Serial.begin(bdrate);      
  Serial.println("Started");
  Serial.print("Button pin = ");  
  Serial.println(_button);
  Serial.println("Setup finished");
}

bool ButtonIRQ::isTrue() {
   if (flag) {
    flag = !flag; 
    return true;
  }
  else{return false;}
}
