#ifndef MINIFAN_H
#define MINIFAN_H

#include <Arduino.h>

class MiniFan {
  private:
    uint8_t _pin;

  public:
    MiniFan(uint8_t pin);
    void on();
    void off();
};

#endif