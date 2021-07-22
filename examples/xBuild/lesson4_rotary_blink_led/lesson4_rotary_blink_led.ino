int ledPin = D1_1; // Module LED nối vào cổng 1
int rotaryPin = A4_1; // Module rotary nối vào cổng 4
int rotaryValue = 0; 

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // đọc giá trị cảm biến
  rotaryValue = analogRead(rotaryPin);
  // bật đèn LED
  digitalWrite(ledPin, HIGH);
  // dừng chương trình trong khoảng thời gian 
  // bằng đúng giá trị cảm biến đọc được (milliseconds)
  delay(rotaryValue);
  // tắt đèn LED
  digitalWrite(ledPin, LOW);
  // dừng chương trình trong khoảng thời gian 
  // bằng đúng giá trị cảm biến đọc được (milliseconds)
  delay(rotaryValue);
}
