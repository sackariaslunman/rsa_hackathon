#include "gamepad.h"
#include "motor.h"
Gamepad gamepad = Gamepad(); 
Motor motor = Motor();

//===============================================================================
//  Initialization
//===============================================================================
void setup() {
    Serial.begin(115200); // DO NOT REMOVE
    motor.init(); // DO NOT REMOVE


}
//===============================================================================
//  Main
//=============================================================================== 

void loop() {
  gamepad.update(); // DO NOT REMOVE
  

}