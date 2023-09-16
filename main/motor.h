class Motor {
  private:
    const int enable_pin_left = 3;
    const int in1_pin_left = 4;
    const int in2_pin_left = 5;

    const int enable_pin_right = 9;
    const int in3_pin_right = 8;
    const int in4_pin_right = 12;

  public:
    void init();
    void setLeft(int speed);
    void setRight(int speed);
};