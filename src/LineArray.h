/*
  LineArray.h 
*/

#ifndef LineArray_h
#define LineArray_h

#include "Arduino.h"
#include "PCF8574.h"
#include "Wire.h"

class LineArray
{
  public:
  LineArray(int sda, int scl);
    uint8_t read_pin(int pin);
    uint8_t read_all();
  private:
    PCF8574 Line_array = PCF8574(const uint8_t deviceAddress = 0x23, TwoWire = &Wire1);
    int _scl;
    int _sda;
};

#endif