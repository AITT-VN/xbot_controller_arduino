#include <Arduino.h>
#include "xBot.h" 
#include <Wire.h>
#include <AITT_PWMServoDriver.h>


extern AITT_PWMServoDriver pca9685;

int max_pwm_value = 3000;
int DCMotors[2][3] = {{10, 11, 12}, {15, 14, 13}};


/* Class Motors */
void _pin(int pin, int value){
	Serial.println("Pin");
  if (value == 0){
    pca9685.setPin(pin, 0, false);
  }
  else {
    pca9685.setPin(pin, 4095, false);
  }
}

void _speed(int index, int value){
  Serial.println(value);
  Serial.println("Speed");

  int pin_pwm = DCMotors[index][0]; 
  int in2 = DCMotors[index][1];  
  int in1 = DCMotors[index][2]; 
  Serial.print(pin_pwm); Serial.print(in2); Serial.println(in1); 
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
  pca9685.setPWM(pin_pwm, 0, map(abs(value), 0, 100, 0, max_pwm_value));
}

void Motors::move(int dir, int speed){
	Serial.println("Move");
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
  _speed(0, int(m1));
  _speed(1, int(m2));
}

void Motors::stop(){
	Serial.println("Stop");
  _speed(0, 0);
  _speed(1, 0);
}

/* Class Servos */
Servos::Servos(){
  pca9685.begin();
  pca9685.setOscillatorFrequency(27000000);
  pca9685.setPWMFreq(50);  // This is the maximum PWM frequency
  //Wire.setClock(400000);
}

int _angleToPulse(int ang){
  int pulse = map(ang, 0, 200, 150, 600);
  return pulse;
}

void Servos::position(int index, int degrees){
  //Serial.println("position");
  pca9685.setPWM(index, 0, _angleToPulse(degrees));
}

void Servos::release(int index){
  Serial.println("release");
  pca9685.setPWM(index, 0, 0);
}

void Servos::rotate(){
  Serial.println("rotate");
}

void Servos::spin(int index, int direction, int speed){
  Serial.println("spin");
}
