#include "mpu6050.h"

MPU6050 mpu;
float tmp;

void setup(){
  Serial.begin(115200);
  mpu.begin();
}

void loop(){
  tmp = map(mpu.getAccX(), -16384, 16384, -90, 90);
  Serial.print("    AccelX:  "); Serial.print(mpu.getAccX());
  tmp = map(mpu.getAccY(), -16384, 16384, -90, 90);
  Serial.print("    AccelY:  "); Serial.print(mpu.getAccY());
  tmp = map(mpu.getAccZ(), -16384, 16384, -90, 90);
  Serial.print("    AccelZ:  "); Serial.print(mpu.getAccZ());
  Serial.print("    GyroX:  "); Serial.print(mpu.getGyroX());
  Serial.print("    GyroY:  "); Serial.print(mpu.getGyroY());
  Serial.print("    GyroZ:  "); Serial.print(mpu.getGyroZ()); 
  Serial.println("   ");
  delay(500);
}
