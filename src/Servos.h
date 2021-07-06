#ifndef SERVOS_H
#define SERVOS_H

#include "Adafruit_PWMServoDriver.h"

class Servos{
  private:
    Adafruit_PWMServoDriver pca9685 = Adafruit_PWMServoDriver();
    int pos[8] = {0 ,0, 0, 0, 0, 0, 0, 0};
    int _angleToPulse(int ang);

  public:
    Servos();
    void init();
    void position(int index, int degrees);
    void rotate(int index, int change, int sleep);
    void release(int index);
    void spin(int index, int direction, int speed);
};

#endif