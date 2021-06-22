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

class Mpu6050
{
    public:
        void begin();
        int16_t getData_mpu6050(int8_t diachi);
        int16_t get_accx(void);
        int16_t get_accy(void);
        int16_t get_accz(void);
        int16_t get_gyrox(void);
        int16_t get_gyroy(void);
        int16_t get_gyroz(void);
} ;

#endif