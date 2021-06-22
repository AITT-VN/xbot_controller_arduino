#ifndef _TONE32_h
#define _TONE32_h

#include "Arduino.h"
#include "utility/pitches.h"

class Tone32{
	public:
		void tone(unsigned int frequency, unsigned long duration = 0);
        void noTone();
};

#endif



