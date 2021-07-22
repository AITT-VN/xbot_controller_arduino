/* Chương trình điều khiển servo bằng phần mềm 
 *  Servo được gắn vào cổng S1 trên board điều khiển
 *  Bluefruit Connect thông qua giao thức BLE
 *  Trên app, quét và kết nối đến thiết bị
 *  Vào mục Controller > Control Pad
 *  Nhấn nút sang trái và sang phải để điều khiển
 */
#include <xcontroller.h>
#include <esp32BLEUtilities.h>
#include <Servos.h>

#define LEFT_PRESSED "!B714" // sự kiện nút left được nhấn
#define RIGHT_PRESSED "!B813" // sự kiện nút right được nhấn

Servos s;

String cmd = "";
int angle = 90;

void setup() {
  Serial.begin(9600);
  s.init();
  s.position(0, angle);
  BLE.begin("OhStem-xController");
  delay(10);
  Serial.println("Setup Done!");
}

// the loop function runs over and over again forever
void loop() {
  if(BLE.isConnected()) {
    if (BLE.available()) {
      cmd = "";
      while(BLE.available()) {
        char data = BLE.read();
        cmd += data;
      }
      Serial.println(cmd);
    }
    
    if (cmd == LEFT_PRESSED) {
      if (angle > 0) {
        angle -= 5;
        s.position(0, angle);
      }      
    } else if (cmd == RIGHT_PRESSED) {
      if (angle < 180) {
        angle += 5;
        s.position(0, angle);
      }      
    }
  }
  delay(10); 
}
