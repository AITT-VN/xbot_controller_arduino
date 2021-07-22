/*
  LineArray.h 
*/

#ifndef LINEARRAY_h
#define LINEARRAY_h

#include "Arduino.h"
#include "PCF8574.h"
#include "Wire.h"

#define LINE_1 0
#define LINE_2 1
#define LINE_3 2
#define LINE_4 3

class LineArray
{
  public:
    LineArray(int sda, int scl);
    int* read();
    int read(uint8_t index);
  private:
    PCF8574 _pcf8574 = PCF8574(0x23, &Wire1);
};

#endif