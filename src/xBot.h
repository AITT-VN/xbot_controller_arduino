#ifndef XBOT_H
#define XBOT_H
#include "setting.h"
#include "esp32BLEUtilities.h"
#include "Tone32.h"
class Motors{
	public:
		void move(int dir, int speed);
		void stop();
};

class Servos{
	private:
    	int pos[8] = {0 ,0, 0, 0, 0, 0, 0, 0};
	public:
		Servos();
		void position(int index, int degrees);
		void rotate(int index, int change, int sleep);
		void release(int index);
		void spin(int index, int direction, int speed);
};

#endif