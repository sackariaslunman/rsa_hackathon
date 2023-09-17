#include "gamepad.h"
#include "motor.h"
#include <Servo.h>

Gamepad gamepad = Gamepad(); 
Motor motor = Motor();
Servo left_fork;
Servo right_fork;
int left_fork_pos = 45;
int right_fork_pos = 180-45;
bool left_fork_disabled = false;
bool right_fork_disabled = false;

//===============================================================================
//  Initialization
//===============================================================================
void setup() {
  Serial.begin(115200); // DO NOT REMOVE
  motor.init(); // DO NOT REMOVE
  left_fork.attach(6);
  right_fork.attach(11);
  left_fork.write(left_fork_pos);
  right_fork.write(right_fork_pos);
}
//===============================================================================
//  Main
//=============================================================================== 

void change_fork(int change, bool use_right_fork = false) {
  if (use_right_fork) {
    right_fork_pos = constrain(right_fork_pos + change, 0, 180);
  } else {
    left_fork_pos = constrain(left_fork_pos + change, 0, 180);
  }
}

void change_left_fork(int change) {
  change_fork(change, false);
}

void change_right_fork(int change) {
  change_fork(change, true);
}

void loop() {
  gamepad.update(); // DO NOT REMOVE

  if (gamepad.isPressed(left_trigger) && !gamepad.isPressed(right_trigger)) {
    change_left_fork(-1);
    change_right_fork(1);
  }
  else if (!gamepad.isPressed(left_trigger) && gamepad.isPressed(right_trigger)) {
    change_left_fork(1);
    change_right_fork(-1);
  }

  if (gamepad.isPressed(dpad_up)) {
    left_fork_pos = 180-45;
    right_fork_pos = 45;
  } else if (gamepad.isPressed(dpad_down)) {
    left_fork_pos = 45;
    right_fork_pos = 180-45;
  } else if (gamepad.isPressed(dpad_left)) {
    left_fork_disabled = !left_fork_disabled;
  } else if (gamepad.isPressed(dpad_right)) {
    right_fork_disabled = !right_fork_disabled;
  }

  int left_speed = map(gamepad.getLeftY(), -100, 100, -255, 255);
  int right_speed = map(gamepad.getRightY(), -100, 100, -255, 255);

  // left_speed = 50;
  // right_speed = 50;

  Serial.print("Left speed: ");
  Serial.print(left_speed);
  Serial.print("\tRight speed: ");
  Serial.println(right_speed);

  motor.setLeft(left_speed);
  motor.setRight(right_speed);

  if (left_fork_disabled) {
    left_fork.write(180);
  } else {
    left_fork.write(left_fork_pos);
  }
  if (right_fork_disabled) {
    right_fork.write(0);
  } else {
    right_fork.write(right_fork_pos);
  }
  delay(1);
}