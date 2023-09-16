

void Motor::init() {
  pinMode(enable_pin_left, OUTPUT); // Enable A pin
  pinMode(in1_pin_left, OUTPUT); // In1 A pin
  pinMode(in2_pin_left, OUTPUT); // In2 A pin

  pinMode(enable_pin_right, OUTPUT);  // Enable B pin
  pinMode(in3_pin_right, OUTPUT);  // In3 B pin
  pinMode(in4_pin_right, OUTPUT); // In4 B pin
}

void Motor::setLeft(int speed) {
  setMotor(enable_pin_left, in1_pin_left, in2_pin_left, -speed);
}

void Motor::setRight(int speed) {
  setMotor(enable_pin_right, in3_pin_right, in4_pin_right, -speed);
}

// Speed is -255 to 255
// Direction: false == forward, true == backward
void Motor::setMotor(uint8_t enable_pin, uint8_t in1_pin, uint8_t in2_pin, int speed) {

  bool direction = false;
  speed = constrain(speed, -100, 100);

  if (speed <= -lower_bound_speed) {
    direction = true;
    speed = -speed;
  } else if (speed >= lower_bound_speed) {
    direction = false;
  } else {
    analogWrite(enable_pin_left, 0);
  }

  if (direction) {
    digitalWrite(in1_pin, HIGH);
    digitalWrite(in2_pin, LOW);
  } else {
    digitalWrite(in1_pin, LOW);
    digitalWrite(in2_pin, HIGH);
  }

  analogWrite(enable_pin, speed);
};