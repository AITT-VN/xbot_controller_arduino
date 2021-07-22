//Blink LED
// Bật tắt đèn LED sau mỗi 1 giây
int ledPin = D1_1; 

void setup() { 
  pinMode(ledPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
  delay(1000);
}
