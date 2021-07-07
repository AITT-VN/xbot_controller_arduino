#include "mpu6050.h"

void MPU6050::begin(){
    Wire.begin();
    delay(10);
    Wire.beginTransmission(ADDR_MPU6050);
    Wire.write(0x1b);
    Wire.write(0b11000);
    Wire.endTransmission();

    Wire.beginTransmission(ADDR_MPU6050);
    Wire.write(0x6b);
    Wire.write(0x01);
    Wire.endTransmission();
}

int16_t MPU6050::getData(int8_t address){
    Wire.beginTransmission(ADDR_MPU6050);
    Wire.write(address);
    Wire.endTransmission();
    Wire.requestFrom(ADDR_MPU6050, 2);
    return (Wire.read() << 8) | Wire.read();
}

int16_t MPU6050::getAccX(){
    return getData(ACCEL_XOUT_H);
}

int16_t MPU6050::getAccY(){
    return getData(ACCEL_YOUT_H);
}

int16_t MPU6050::getAccZ(){
    return getData(ACCEL_ZOUT_H);
}
int16_t MPU6050::getGyroX()
{
  return getData(GYRO_XOUT_H );
}
int16_t MPU6050::getGyroY()
{
  return getData(GYRO_YOUT_H );
}

int16_t MPU6050::getGyroZ()
{
  return getData(GYRO_ZOUT_H );
}