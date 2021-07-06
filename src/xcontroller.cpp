#include "xcontroller.h"
#include "Tone32.h"

XController::XController() {

}

/*
void xcontroller::init(){
  pca.init();
  led.init();
}
*/
void XController::showLed(uint8_t index, uint8_t r, uint8_t g, uint8_t b) {
  if (index == 0) {
    ledOnboard.setPixelColor(0, r, g, b);
    ledOnboard.setPixelColor(1, r, g, b);
  } else {
    ledOnboard.setPixelColor(index-1, r, g, b);
  }

  ledOnboard.show();
}

void XController::tone(unsigned int frequency, unsigned long duration, uint8_t channel) {
  tone32(BUZZER, frequency, duration, channel);
}

void XController::noTone(uint8_t channel) {
  noTone32(BUZZER, channel);
}