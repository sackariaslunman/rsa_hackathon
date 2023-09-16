class Motor {
  private:
    const uint8_t enable_pin_left = 3;
    const uint8_t in1_pin_left = 4;
    const uint8_t in2_pin_left = 5;

    const uint8_t enable_pin_right = 9;
    const uint8_t in3_pin_right = 8;
    const uint8_t in4_pin_right = 12;

    const int lower_bound_speed = 5;

  public:
    void init();
    void setLeft(int speed);
    void setRight(int speed);
    void setMotor(uint8_t enable_pin, uint8_t in1_pin, uint8_t in2_pin, int speed);
};