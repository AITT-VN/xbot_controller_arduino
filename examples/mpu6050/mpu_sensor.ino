#include "xBot.h"

Mpu6050 mpu;
float tmp;

void setup(){
  mpu.begin();
  Serial.begin(115200);
}

void loop(){
  tmp = map(mpu.get_accx(), -16384, 16384, -90, 90);
  Serial.println(tmp);
  delay(100);
}