#include <LiquidCrystal.h>
int buttonpin = 2;
int state = 0;
int buttonState = 0;
int BeforeBtnState = 0;
LiquidCrystal lcd(3, 4, 10, 11, 12, 13); //LCD 선언

void setup() {
  pinMode(buttonpin, INPUT);
  lcd.begin(16, 2);
  lcd.clear();
}

void loop() {
  buttonState = digitalRead(buttonpin);
  if(BeforeBtnState != buttonState) {
    BeforeBtnState = buttonState;
    if(buttonState) {
      LCDSet();
    }
  }
  delay(100);
}

void LCDSet() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("TWICE's Song:");
  lcd.setCursor(0,1);
  if(state == 0) {
    lcd.print("Like OOH-AHH");
    state++;
  }
  else if(state == 1) {
    lcd.print("CHEER UP");
    state++;
  }
  else if(state == 2) {
    lcd.print("TT");
    state++;
  }
  else if(state == 3) {
    lcd.print("KNOCK KNOCK");
    state++;
  }
  else if(state == 4) {
    lcd.print("SIGNAL");
    state++;
  }
  else if(state == 5) {
    lcd.print("ONE MORE TIME");
    state++;
  }
  else if(state == 6) {
    lcd.print("What's NEXT?");
    state = 0;
  }
}

