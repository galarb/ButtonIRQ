#include "ButtonIRQ.h"

ButtonIRQ rightbutton(3);//must be either 2 or 3 (UNO R3)
bool togsw = false;
bool result;

void setup() {
  rightbutton.begin(115200);
}

void loop() {
  result = rightbutton.isTrue();
  if(result){
    togsw = !togsw;
  }
  
  Serial.println(togsw);
  delay(1000);

}

