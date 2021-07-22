#include <xcontroller.h>

XController xcon;
int lightSensorPin = A4_1; // cảm biến ánh sáng nối với cổng 4
int sensorValue= 0; // giá trị đọc được từ cảm biến
int outputValue= 0; // giá trị xuất ra cho led RGB

void setup() {
  Serial.begin(9600);
}

void loop() {
  //  đọc giá trị cảm biến ánh sáng (0-4095)
  sensorValue = analogRead(lightSensorPin);
  // in ra cửa sổ Serial kết quả đọc được
  Serial.println(sensorValue);
  //  chuyển kết quả đọc được sang dải giá trị 0-255
  outputValue = map(sensorValue, 0, 4095, 0, 255);
  // in ra kết quả chuyển đổi
  Serial.println(outputValue);
  // thay đổi màu sắc của led RGB, chỉ thay đổi giá trị màu đỏ
  xcon.showLed(0, outputValue, 0, 0);
  delay(100);                    
}
