#include "Servos.h"

Servos::Servos() {
  //pca9685.begin();
  //pca9685.setPWMFreq(50); 
  //delay(10);
}

void Servos::init(){
    pca9685.begin();
    pca9685.setPWMFreq(50); 
    delay(10);
}


int Servos::_angleToPulse(int ang){
  int pulse = map(ang, 0, 200, 150, 600);
  return pulse;
}

void Servos::position(int index, int degrees){
  //Serial.println("position");
  if ((index > 7) || (index < 0) || (degrees > 180) || (degrees < 0)){
    delay(100);
  }
  else{
    pca9685.setPWM(index, 0, _angleToPulse(degrees));
    pos[index] = degrees;
  } 
}

void Servos::release(int index){
  //Serial.println("release");
  if ((index > 7) || (index < 0)){
    Serial.println("Release Error");
    delay(100);
  } 
  else{
    pca9685.setPWM(index, 0, 0);
    pos[index] = 0;
  }
}

void Servos::rotate(int index, int change, int sleep){
  //Serial.println("rotate");
  int limit, new_pos;
  if (change <= 0){
    limit = 0;
  }
  else {
    limit = 180;
  }
  if ((index > 7) || (index < 0)){
    Serial.println("Rotate Error");
    delay(100);
  }
  else{
    while (true)
    {
      new_pos = pos[index] + change;
      if (((change <= 0) && (new_pos < limit)) || ((change > 0) && (new_pos > limit))) {
        Serial.println("limit");
        break;
      }
      else{
        pca9685.setPWM(index, 0, _angleToPulse(new_pos));
        pos[index] = new_pos;
        delay(sleep);
      } 
    }
    
  }
}

void Servos::spin(int index, int direction, int speed){
  //Serial.println("spin");
  int degree = 0;
  if ((index > 7) || (index < 0) || (speed > 100) || (speed < 0) || (direction > 1) || (direction < 0)){
    Serial.println("Spin Error");
    delay(100);
  }
  else if (speed == 0){
    pca9685.setPWM(index, 0, 0);
  }
  else {
    if (direction == 0){
      //forward
      degree = 90 - (speed * 80) / 100;
    }
    else {
      //reverse
      degree = 90 + (speed * 80) / 100;
    }
    pca9685.setPWM(index, 0, _angleToPulse(degree));
  } 
}
