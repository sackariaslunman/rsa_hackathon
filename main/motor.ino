

void Motor::init() {
  pinMode(enable_pin_left, OUTPUT); // Enable A pin
  pinMode(in1_pin_left, OUTPUT); // In1 A pin
  pinMode(in2_pin_left, OUTPUT); // In2 A pin

  pinMode(enable_pin_right, OUTPUT);  // Enable B pin
  pinMode(in3_pin_right, OUTPUT);  // In3 B pin
  pinMode(in4_pin_right, OUTPUT); // In4 B pin
}

// Speed is 0-100
void Motor::setLeft(int speed) {
  digitalWrite(in1_pin_left, LOW);
  digitalWrite(in2_pin_left, HIGH);

  int pwm_speed = map(speed, 0, 100, 0, 255);
  analogWrite(enable_pin_left, pwm_speed);
};

// void Motor::setLeft(int speed) {
//   if(speed > 5){
//     digitalWrite(5, LOW);
//     // digitalWrite(3, HIGH);
//     analogWrite(3, speed);
//   }else if(speed < -5){ 
//     digitalWrite(3, LOW);
//     // digitalWrite(5, HIGH);

//     analogWrite(5, -speed);
//   }else{
//     digitalWrite(3, LOW);
//     digitalWrite(5, LOW);
//   }
// }

// void Motor::setRight(int speed) {
//   if(speed > 5){
//     digitalWrite(9, LOW);
//     analogWrite(6, speed);
//     // digitalWrite(6, HIGH);
//   }else if(speed < -5){
//     digitalWrite(6, LOW);
//     // digitalWrite(9, HIGH);
//     analogWrite(9, -speed);
//   }else{
//     digitalWrite(6, LOW);
//     digitalWrite(9, LOW);
//   }
// }