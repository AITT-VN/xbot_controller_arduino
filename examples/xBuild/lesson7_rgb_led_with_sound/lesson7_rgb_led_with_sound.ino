#include <xcontroller.h>

XController xcon;

int soundSensorPin = A4_1;
int sensorValue = 0;
int ledState = 0;

void setup() {
  Serial.begin(9600);
}

void loop(){
  // đọc giá trị cảm biến
  sensorValue = analogRead(soundSensorPin); 
  // in ra giá trị cửa sổ Serial đọc được
  Serial.println(sensorValue);
  // nếu giá trị cảm biến lớn hơn 1000 
  // thì đảo trạng thái bật tắt của đèn led
  if (sensorValue > 1000){
    ledState = 1 - ledState;
    delay(300);
  }

  // bật tắt đèn led RGB dựa vào trạng thái đã được xử lý
  if (ledState == 0){
    xcon.showLed(0, 0, 0, 0);
  } else {
    xcon.showLed(0, 255, 0, 0);
  }
 
  delay(1);
}
