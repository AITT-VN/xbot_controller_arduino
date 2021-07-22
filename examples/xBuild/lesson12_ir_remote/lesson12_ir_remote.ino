#include <xcontroller.h>
#include <IRremote.h>

XController xcon;
IRrecv irrecv(IR_RX);
int irCommand;

void setup()
{
  irrecv.begin();
  Serial.begin(9600);   
}

void loop() {
  if (irrecv.decode()) {
    irCommand = irrecv.decodedIRData.command;
    Serial.println(irCommand);
    irrecv.resume();
    if (irCommand == IR_REMOTE_A){
      xcon.showLed(0, 255, 0, 0);
    } else if (irCommand == IR_REMOTE_B){
      xcon.showLed(0, 0, 255, 0);
    } else if (irCommand == IR_REMOTE_C){
      xcon.showLed(0, 0, 0, 255);
    } else if (irCommand == IR_REMOTE_D){
      xcon.showLed(0, 255, 255, 255);
    } else {
      xcon.showLed(0, 0, 0, 0);
    }
  }
}
