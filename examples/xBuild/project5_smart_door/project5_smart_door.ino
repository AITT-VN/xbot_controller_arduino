#include <xcontroller.h>
#include <IRremote.h>
#include <Servos.h>
#include <LCD_1602.h>

#define PASSCODE "1234"

XController xcon;
IRrecv irrecv(IR_RX);
LCD_1602 lcd(0x21);
Servos s;

int irCommand;

void setup()
{
  Serial.begin(9600);
  irrecv.begin();
  s.init();
  s.position(0, 0);
  lcd.begin(D1_1, D1_2);
  lcd.backlight();
}

void loop() {
  if (irrecv.decode()) {
    irCommand = irrecv.decodedIRData.command;
    Serial.println(irCommand);
    irrecv.resume();
    if (irCommand == IR_REMOTE_A){
      // khóa cửa lại
      s.position(0, 0);
    } else if (irCommand == IR_REMOTE_B){
      // bắt đầu nhập mật mã
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Hay nhap mat ma:");
      String passcode = "";
      while (irCommand != IR_REMOTE_C) {
        // liên tục đọc tín hiệu remote để nhập
        // mật mã cho đến khi phím C được nhấn
        if (irrecv.decode()) {
          irCommand = irrecv.decodedIRData.command;
          Serial.println(irCommand);
          char input;
          switch (irCommand) {
            case IR_REMOTE_0:
              passcode += "0";
              break;
            case IR_REMOTE_1:
              passcode += "1";
              break;
            case IR_REMOTE_2:
              passcode += "2";
              break;
            case IR_REMOTE_3:
              passcode += "3";
              break;
            case IR_REMOTE_4:
              passcode += "4";
              break;
            case IR_REMOTE_5:
              passcode += "5";
              break;
            case IR_REMOTE_6:
              passcode += "6";
              break;
            case IR_REMOTE_7:
              passcode += "7";
              break;
            case IR_REMOTE_8:
              passcode += "8";
              break;
            case IR_REMOTE_9:
              passcode += "9";
              break;
          }
          lcd.setCursor(0, 1);
          lcd.print(passcode);
          delay(500);
          irrecv.resume();
        }
      }

      // nhập mật mã đã xong, cần kiểm tra
      if (passcode == PASSCODE) {
        lcd.setCursor(0, 1);
        lcd.print("Mat ma dung");
        s.position(0, 90);
      } else {
        lcd.setCursor(0, 1);
        lcd.print("Mat ma sai");
      }
    }
  }
}
