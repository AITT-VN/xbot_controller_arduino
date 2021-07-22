#include <xcontroller.h>

#define BUZZER_CHANNEL 0 // giá trị bất kỳ từ 0 đến 15

XController xcon;

void setup() {
}

void loop() {
  // phát bài nhạc Twinkle twinkle little stars
  // đoạn 1: Đồ, Đồ, Son, Son, La, La, Son
  xcon.tone(NOTE_C4, 500, BUZZER_CHANNEL);
  xcon.noTone(BUZZER_CHANNEL);
  xcon.tone(NOTE_C4, 500, BUZZER_CHANNEL);
  xcon.noTone(BUZZER_CHANNEL);
  xcon.tone(NOTE_G4, 500, BUZZER_CHANNEL);
  xcon.noTone(BUZZER_CHANNEL);
  xcon.tone(NOTE_G4, 500, BUZZER_CHANNEL);
  xcon.noTone(BUZZER_CHANNEL);
  xcon.tone(NOTE_A4, 500, BUZZER_CHANNEL);
  xcon.noTone(BUZZER_CHANNEL);
  xcon.tone(NOTE_A4, 500, BUZZER_CHANNEL);
  xcon.noTone(BUZZER_CHANNEL);
  xcon.tone(NOTE_G4, 500, BUZZER_CHANNEL);
  xcon.noTone(BUZZER_CHANNEL);

  delay(500);

  // đoạn 2: Fa, Fa, Mi, Mi, Rê, Rê, Đồ
  xcon.tone(NOTE_F4, 500, BUZZER_CHANNEL);
  xcon.noTone(BUZZER_CHANNEL);
  xcon.tone(NOTE_F4, 500, BUZZER_CHANNEL);
  xcon.noTone(BUZZER_CHANNEL);
  xcon.tone(NOTE_E4, 500, BUZZER_CHANNEL);
  xcon.noTone(BUZZER_CHANNEL);
  xcon.tone(NOTE_E4, 500, BUZZER_CHANNEL);
  xcon.noTone(BUZZER_CHANNEL);
  xcon.tone(NOTE_D4, 500, BUZZER_CHANNEL);
  xcon.noTone(BUZZER_CHANNEL);
  xcon.tone(NOTE_D4, 500, BUZZER_CHANNEL);
  xcon.noTone(BUZZER_CHANNEL);
  xcon.tone(NOTE_C4, 500, BUZZER_CHANNEL);
  xcon.noTone(BUZZER_CHANNEL);

  delay(1000);
}
