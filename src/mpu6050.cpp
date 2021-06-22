#include "mpu6050.h"

void Mpu6050::begin(){
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

int16_t Mpu6050::getData_mpu6050(int8_t diachi){
    Wire.beginTransmission(ADDR_MPU6050);
    Wire.write(diachi);
    Wire.endTransmission();
    Wire.requestFrom(ADDR_MPU6050, 2);
    return (Wire.read() << 8) | Wire.read();
}

int16_t Mpu6050::get_accx(){
    return getData_mpu6050(ACCEL_XOUT_H);
}

int16_t Mpu6050::get_accy(){
    return getData_mpu6050(ACCEL_YOUT_H);
}

int16_t Mpu6050::get_accz(){
    return getData_mpu6050(ACCEL_ZOUT_H);
}
int16_t Mpu6050::get_gyrox()
{
  return getData_mpu6050(GYRO_XOUT_H );
}
int16_t Mpu6050::get_gyroy()
{
  return getData_mpu6050(GYRO_YOUT_H );
}

int16_t Mpu6050::get_gyroz()
{
  return getData_mpu6050(GYRO_ZOUT_H );
}