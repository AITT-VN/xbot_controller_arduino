#include <xcontroller.h>

#define BUZZER_CHANNEL 0 // any from 0-15
#define PIR_PIN D5_1

XController xcon;
bool alarmMode = false;
int pirState = 0;

void setup() {
  Serial.begin(9600);
  pinMode(PIR_PIN, INPUT);
  pinMode(BUTTON, INPUT);
}

void loop() {
  if (digitalRead(BUTTON) == LOW) {
    // bật tắt chế độ bảo vệ
    alarmMode = !alarmMode;
    if (alarmMode) {
      Serial.println("Chế độ bảo vệ được bật");
    } else {
      Serial.println("Chế độ bảo vệ được tắt");
    }
    delay(200);
  }

  pirState = digitalRead(PIR_PIN);

  if (alarmMode && pirState == HIGH) {
    Serial.println("Phát hiện có người xâm nhập");
    for (int i=0; i<5; i++) {
      xcon.showLed(0, 255, 0, 0);
      xcon.tone(NOTE_C4, 1000, BUZZER_CHANNEL);
      xcon.noTone(BUZZER_CHANNEL);
      xcon.showLed(0, 0, 0, 0);
      delay(1000);      
    }
  }
}
