#ifndef XBOT_H
#define XBOT_H

class Motors{
	public:
		void move(int dir, int speed);
		void stop();
};

class Servos{
	public:
		Servos();
		void position(int index, int degrees);
		void rotate();
		void release(int index);
		void spin(int index, int direction, int speed);
};

#endif