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

  int left_speed = map(gamepad.getLeftY(), -100, 100, -255, 255);
  int right_speed = map(gamepad.getRightY(), -100, 100, -255, 255);

  // left_speed = 50;
  // right_speed = 50;

  // Serial.print("Left speed: ");
  // Serial.print(left_speed);
  // Serial.print("\tRight speed: ");
  // Serial.println(right_speed);

  motor.setLeft(left_speed);
  motor.setRight(right_speed);
  delay(5);
}