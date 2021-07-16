/*
  LineArray.h 
*/

#ifndef LINEARRAY_h
#define LINEARRAY_h

#include "Arduino.h"
#include "PCF8574.h"
#include "Wire.h"


class LineArray
{
  public:
    LineArray(int sda, int scl);
    int* read(uint8_t index = -1);
  private:
    PCF8574 _pcf8574 = PCF8574(0x23, &Wire1);
};

#endif