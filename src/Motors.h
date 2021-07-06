#ifndef MOTORS_H
#define MOTORS_H

#include "Adafruit_PWMServoDriver.h"

#define MAX_PWM 3000
#define M1_PWM 10
#define M1_IN2 11
#define M1_IN1 12

#define M2_IN1 13
#define M2_IN2 14
#define M2_PWM 15

class Motors{
  private:
    Adafruit_PWMServoDriver pca9685 = Adafruit_PWMServoDriver();
    int DCMotors[2][3] = {{M1_PWM, M1_IN2, M1_IN1}, {M2_PWM, M2_IN2, M2_IN1}};
    void _pin(int pin, int value);
    void _speed(int index, int value);

  public:
    Motors();
    void speed(int m1, int m2);
    void move(int dir, int speed);
    void stop();
};

#endif