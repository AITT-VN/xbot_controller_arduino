#ifndef _MPU6050_H
#define _MPU6050_H

#include "Arduino.h"
#include <Wire.h>

#define   ACCEL_XOUT_H    0x3B
#define   ACCEL_XOUT_L    0x3C
#define   ACCEL_YOUT_H    0x3D
#define   ACCEL_YOUT_L    0x3E
#define   ACCEL_ZOUT_H    0x3F
#define   ACCEL_ZOUT_L    0x40
#define   TEMP_OUT_H      0x41
#define   TEMP_OUT_L      0x42
#define   GYRO_XOUT_H     0x43
#define   GYRO_XOUT_L     0x44
#define   GYRO_YOUT_H     0x45
#define   GYRO_YOUT_L     0x46
#define   GYRO_ZOUT_H     0x47
#define   GYRO_ZOUT_L     0x48
#define   ADDR_MPU6050    0x68

class MPU6050
{
    public:
        void begin();
        int16_t getData(int8_t address);
        int16_t getAccX(void);
        int16_t getAccY(void);
        int16_t getAccZ(void);
        int16_t getGyroX(void);
        int16_t getGyroY(void);
        int16_t getGyroZ(void);
} ;

#endif