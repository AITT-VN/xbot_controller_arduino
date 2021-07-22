#include <xcontroller.h>

#define BUZZER_CHANNEL 0 // any from 0-15

XController xcon;
// the setup function runs once when you press reset or power the board
void setup() {
}

// the loop function runs over and over again forever
void loop() {
  xcon.tone(NOTE_C4, 500, BUZZER_CHANNEL);
  xcon.noTone(BUZZER_CHANNEL);
  xcon.tone(NOTE_D4, 500, BUZZER_CHANNEL);
  xcon.noTone(BUZZER_CHANNEL);
  xcon.tone(NOTE_E4, 500, BUZZER_CHANNEL);
  xcon.noTone(BUZZER_CHANNEL);
  xcon.tone(NOTE_F4, 500, BUZZER_CHANNEL);
  xcon.noTone(BUZZER_CHANNEL);
  xcon.tone(NOTE_G4, 500, BUZZER_CHANNEL);
  xcon.noTone(BUZZER_CHANNEL);
  xcon.tone(NOTE_A4, 500, BUZZER_CHANNEL);
  xcon.noTone(BUZZER_CHANNEL);
  xcon.tone(NOTE_B4, 500, BUZZER_CHANNEL);
  xcon.noTone(BUZZER_CHANNEL);
}