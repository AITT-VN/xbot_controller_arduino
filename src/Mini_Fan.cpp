#include "Mini_Fan.h"

MiniFan::MiniFan(uint8_t pin) {
  _pin = pin;
  pinMode(_pin, OUTPUT);
}

void MiniFan::on() {
  digitalWrite(_pin, HIGH);
}

void MiniFan::off() {
  digitalWrite(_pin, LOW);
}
