#ifndef PCA9685_H
#define PCA9685_H

#include "utility/AITT_PWMServoDriver.h"

class Pca9685{
	private:
		// called this way, it uses the default address 0x40
		AITT_PWMServoDriver pca9685 = AITT_PWMServoDriver();
	public:
		void init();
};

class Motors{
	private:
		AITT_PWMServoDriver pca9685 = AITT_PWMServoDriver();
		int max_pwm_value = 3000;
		int DCMotors[2][3] = {{10, 11, 12}, {15, 14, 13}};
	public:
		void _pin(int pin, int value);
		void _speed(int index, int value);
		void move(int dir, int speed);
		void stop();
};

class Servos{
	private:
		AITT_PWMServoDriver pca9685 = AITT_PWMServoDriver();
    	int pos[8] = {0 ,0, 0, 0, 0, 0, 0, 0};
	public:
		int _angleToPulse(int ang);
		void position(int index, int degrees);
		void rotate(int index, int change, int sleep);
		void release(int index);
		void spin(int index, int direction, int speed);
};

#endif