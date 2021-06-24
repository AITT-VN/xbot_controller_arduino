#include "xBot.h"

#define MATRIX_NUMCOLUMNS 16
#define MATRIX_NUMROWS 8

TM1640 module(2);
TM16xxMatrix matrix(&module, MATRIX_NUMCOLUMNS, MATRIX_NUMROWS);

void setup(){

  Serial.begin(115200);

  module.setDisplayToString("HALO");
  delay(500);                        // wait
  module.clearDisplay();

  // all at once
  matrix.setAll(true);
  delay(200);

  // Columns binary
  for(int i=0; i<MATRIX_NUMCOLUMNS; i++)
  {
    for(int j=0; j<=0xFF; j++)
    {
      matrix.setColumn(i,j);
      delay(5);
    }
    delay(200);
  }
  matrix.setAll(false);

  // One pixel, column by column
  for(int i=0; i<MATRIX_NUMCOLUMNS; i++)
  {
    for(int j=0; j<MATRIX_NUMROWS; j++)
    {
        matrix.setPixel(i,j, true);
        delay(50);
        matrix.setPixel(i,j, false);
    }
  }

  // One pixel, row by row
  for(int i=0; i<MATRIX_NUMROWS; i++)
  {
    for(int j=0; j<MATRIX_NUMCOLUMNS; j++)
    {
        matrix.setPixel(j,i, true);
        delay(50);
        matrix.setPixel(j,i, false);
    }
  }
}

void loop(){
  static bool fLoop=true;

  // Fill/unfill columns
  for(int i=0; i<MATRIX_NUMROWS; i++)
  {
    for(int j=0; j<MATRIX_NUMCOLUMNS; j++)
    {
        matrix.setPixel(j, i, fLoop);
        delay(50);
    }
  }
  fLoop=!fLoop;
}
