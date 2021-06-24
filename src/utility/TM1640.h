/*
TM1640.h - Library for TM1640.

Copyright (C) 2011 Ricardo Batista <rjbatista at gmail dot com>
Adjusted for TM1640 by Maxint R&D, based on orignal code. See https://github.com/maxint-rd/

This program is free software: you can redistribute it and/or modify
it under the terms of the version 3 GNU General Public License as
published by the Free Software Foundation.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef TM1640_h
#define TM1640_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include "TM16xx.h"

#define TM1640_MAX_POS 16

class TM1640 : public TM16xx
{
  public:
		// Instantiate a TM1640 module specifying data and clock pins, number of digits, the display state, the starting intensity (0-7).
  	TM1640(byte dataPin, byte clockPin, byte numDigits=16, boolean activateDisplay = true, byte intensity = 7);
    TM1640(int port);


  protected:
    //virtual void bitDelay();
    virtual void start();
    virtual void stop();
    virtual void send(byte data);

  private:
    //int _Port_Digital[6][2] = {{18, 19}, {4, 5}, {13, 14}, {16, 17}, {32, 33}, {25, 26}};
};

#endif
