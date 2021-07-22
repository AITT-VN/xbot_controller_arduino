int ledPin = D1_1;   
int buttonPin = D2_1;
int buttonState = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  // đọc trạng thái của nút nhấn
  buttonState = digitalRead(buttonPin);

  // kiểm tra xem nút có được nhấn không
  // nếu nút được nhấn thì giá trị là LOW
  if (buttonState == LOW) {
    // bật đèn LED
    digitalWrite(ledPin, HIGH);
  } else {
    // tắt đèn LED
    digitalWrite(ledPin, LOW);
  }
}
