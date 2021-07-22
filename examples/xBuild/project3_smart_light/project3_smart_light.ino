#define LIGHT_PIN A4_1
#define PIR_PIN D5_1
#define LED_PIN D6_1
 
int lightSensorValue = 0;
int pirState = 0;
int ledState = 0;

unsigned long ledOnTime = 0; // lưu thời gian lúc bật đèn

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(PIR_PIN, INPUT);
}

void loop() {
  // đọc giá trị cảm biến ánh sáng
  lightSensorValue = analogRead(LIGHT_PIN);
  pirState = digitalRead(PIR_PIN);
  if (pirState == HIGH && lightSensorValue < 200) {
    // trời tối và phát hiện có người => bật đèn
    digitalWrite(LED_PIN, HIGH);
    ledOnTime = millis();
    ledState = 1;
  }

  // lấy thời gian hiện tại
  unsigned long currentMillis = millis();
  if (ledState == 1 && currentMillis - ledOnTime >= 10000) {
    // đã bật đèn được quá 15s => tắt đèn
    digitalWrite(LED_PIN, LOW);
    ledOnTime = 0;
    ledState = 0;
  }
}
