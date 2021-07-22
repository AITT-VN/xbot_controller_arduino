#include <xcontroller.h>
#include <IRremote.h>

XController xcon;
IRrecv irrecv(IR_RX);
int irCommand;
int lightLevel = 0;

void setup()
{
  irrecv.begin();
  Serial.begin(9600);   
}

void loop() {
  if (irrecv.decode()) {
    irCommand = irrecv.decodedIRData.command;
    Serial.println(irCommand);
    if (irCommand == IR_REMOTE_UP){
      lightLevel += 50; // tăng độ sáng 25%
      if (lightLevel > 255) {
        lightLevel = 255;
      }
    } else if (irCommand == IR_REMOTE_DOWN){
      lightLevel -= 50; // giảm độ sáng 25%
      if (lightLevel < 0) {
        lightLevel = 0;
      }
    } else if (irCommand == IR_REMOTE_SETUP){
      if (lightLevel > 0) { // đèn đang bật thì tắt
        lightLevel = 0;
      } else { // đèn đang tắt thì bật
        lightLevel = 255;
      }
    }
    xcon.showLed(0, lightLevel, 0, 0);
    irrecv.resume();
    delay(200);
  }
}
