#include "Motors.h"

Motors::Motors() {
  //pca9685.begin();
  //pca9685.setPWMFreq(50); 
  //delay(10);
}

void Motors::init(){
    pca9685.begin();
    pca9685.setPWMFreq(50); 
    delay(10);
}

void Motors::_pin(int pin, int value){
  if (value == 0){
    pca9685.setPin(pin, 0, false);
  }
  else {
    pca9685.setPin(pin, 4095, false);
  }
}

void Motors::_speed(int index, int value){
  // set M1 speed
  int pwm = DCMotors[index][0];
  int in2 = DCMotors[index][1];  
  int in1 = DCMotors[index][2]; 
  if (value > 0){
    //Forward
    _pin(in2, 0);
    _pin(in1, 1);
  }
  else if (value < 0){
    //Backward
    _pin(in2, 1);
    _pin(in1, 0);
  }
  else{
    //Release
    _pin(in2, 0);
    _pin(in1, 0);
  }
  pca9685.setPWM(pwm, 0, map(abs(value), 0, 100, 0, MAX_PWM));
}

void Motors::speed(int m1, int m2){
  _speed(0, m1);
  _speed(1, m2);
}

void Motors::move(int dir, int speed){
	//Serial.println("Move");
  int m1 = 0; //speed of motor 1 to steer
  int m2 = 0; //speed of motor 2 to steer
  if (dir == 1){
    m1 = speed/2;
    m2 = -speed/2;
  }
  else if (dir == 2){
    m1 = speed;
    m2 = speed/2;
  }
  else if (dir == 3){
    m1 = speed;
    m2 = speed;
  }
  else if (dir == 4){
    m1 = speed/2;
    m2 = speed;
  }
  else if (dir == 5){
    m1 = -speed/2;
    m2 = speed/2;
  }
  else if (dir == 6){
    m1 = -speed/2;
    m2 = -speed;
  }
  else if (dir == 7){
    m1 = -speed;
    m2 = -speed;
  }
  else if (dir == 8){
    m1 = -speed;
    m2 = -speed/2;
  }
  else{
    m1 = 0;
    m2 = 0;
  }
  this->speed(m1, m2);
}

void Motors::stop() {
  speed(0, 0);
}