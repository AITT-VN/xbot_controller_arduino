/*
  LineArray.cpp
*/

#include "LineArray.h"

LineArray::LineArray(int sda, int scl)
{
  _sda = sda;
  _scl = scl;
  Line_array.begin(sda, scl);
}

uint8_t LineArray::read_pin(int pin)
{
  Line_array.read(pin);
  /*
    .read(pin) = 0 white line
    .read(pin) = 1 black line
  */
}

uint8_t LineArray::read_all()
{
  int line_1 = Line_array.read(0); 
  int line_2 = Line_array.read(1); 
  int line_3 = Line_array.read(2); 
  int line_4 = Line_array.read(3);
  return ((line_1, line_2, line_3, line_4));
}