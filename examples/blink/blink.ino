#include <xcontroller.h>

XController xcon;
// the setup function runs once when you press reset or power the board
void setup() {
}

// the loop function runs over and over again forever
void loop() {
  xcon.showLed(1, 255, 0, 0); // change color led 1
  xcon.showLed(2, 0, 255, 0); // change color led 2
  delay(1000);                       // wait for a second
  xcon.showLed(0, 0, 0, 0);
  delay(1000);                       // wait for a second
}