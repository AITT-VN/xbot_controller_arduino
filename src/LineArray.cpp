/*
  LineArray.cpp
*/

#include "LineArray.h"

LineArray::LineArray(int sda, int scl) {
  _pcf8574.begin(sda, scl);
}
int* LineArray::read() {
    int result[4];
    result[0] = _pcf8574.read(0);
    result[1] = _pcf8574.read(1);
    result[2] = _pcf8574.read(2);
    result[3] = _pcf8574.read(3);
    return result;
}

int LineArray::read(uint8_t index) {
  if ((index > 3) || (index < 0)) {
    Serial.println("Support pin 0 to 3 only");
  } else {
    int result;
    result = _pcf8574.read(index);
    return result;
  }
}