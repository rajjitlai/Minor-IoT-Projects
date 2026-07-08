/*
  Arduino RTC 12-Hour Clock
  Board: Arduino Uno

  Display:
    16x2 I2C LCD, address 0x27

  RTC:
    DS3231

  Buttons:
    SELECT -> D2
    PLUS   -> D3
    MINUS  -> D4
    SAVE   -> D5

  Button wiring:
    One side -> Arduino pin
    Other side -> GND

  Uses INPUT_PULLUP:
    Not pressed = HIGH
    Pressed     = LOW
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <RTClib.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
RTC_DS3231 rtc;

const int selectBtn = 2;
const int plusBtn   = 3;
const int minusBtn  = 4;
const int saveBtn   = 5;

const char* daysOfWeek[7] = {
  "Sunday", "Monday", "Tuesday", "Wednesday",
  "Thursday", "Friday", "Saturday"
};

// 0 = normal, 1 = edit hour, 2 = edit minute, 3 = edit second, 4 = edit day
int mode = 0;
DateTime editTime;

bool lastSelect = HIGH;
bool lastPlus   = HIGH;
bool lastMinus  = HIGH;
bool lastSave   = HIGH;

bool buttonPressed(int pin, bool &lastState) {
  bool current = digitalRead(pin);

  if (lastState == HIGH && current == LOW) {
    delay(40);
    lastState = current;
    return true;
  }

  lastState = current;
  return false;
}

void printTwoDigits(int value) {
  if (value < 10) lcd.print("0");
  lcd.print(value);
}

void displayClock(DateTime now) {
  int hour24 = now.hour();
  int hour12 = hour24 % 12;
  if (hour12 == 0) hour12 = 12;

  const char* ampm = (hour24 >= 12) ? "PM" : "AM";

  lcd.setCursor(0, 0);
  printTwoDigits(hour12);
  lcd.print(":");
  printTwoDigits(now.minute());
  lcd.print(":");
  printTwoDigits(now.second());
  lcd.print(" ");
  lcd.print(ampm);
  lcd.print("   ");

  lcd.setCursor(0, 1);
  lcd.print(daysOfWeek[now.dayOfTheWeek()]);
  lcd.print("                ");
}

void displayEdit(DateTime t) {
  lcd.setCursor(0, 0);

  if (mode == 1) lcd.print("Set Hour:       ");
  else if (mode == 2) lcd.print("Set Minute:     ");
  else if (mode == 3) lcd.print("Set Second:     ");
  else if (mode == 4) lcd.print("Set Day:        ");

  lcd.setCursor(0, 1);

  if (mode == 4) {
    lcd.print(daysOfWeek[t.dayOfTheWeek()]);
    lcd.print("                ");
  } else {
    int hour24 = t.hour();
    int hour12 = hour24 % 12;
    if (hour12 == 0) hour12 = 12;

    const char* ampm = (hour24 >= 12) ? "PM" : "AM";

    printTwoDigits(hour12);
    lcd.print(":");
    printTwoDigits(t.minute());
    lcd.print(":");
    printTwoDigits(t.second());
    lcd.print(" ");
    lcd.print(ampm);
    lcd.print("   ");
  }
}

void saveTime() {
  rtc.adjust(editTime);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Time Updated");
  delay(1000);

  mode = 0;
  lcd.clear();
}

void increaseSelected() {
  if (mode == 1) editTime = editTime + TimeSpan(0, 1, 0, 0);
  else if (mode == 2) editTime = editTime + TimeSpan(0, 0, 1, 0);
  else if (mode == 3) editTime = editTime + TimeSpan(0, 0, 0, 1);
  else if (mode == 4) editTime = editTime + TimeSpan(1, 0, 0, 0);
}

void decreaseSelected() {
  if (mode == 1) editTime = editTime - TimeSpan(0, 1, 0, 0);
  else if (mode == 2) editTime = editTime - TimeSpan(0, 0, 1, 0);
  else if (mode == 3) editTime = editTime - TimeSpan(0, 0, 0, 1);
  else if (mode == 4) editTime = editTime - TimeSpan(1, 0, 0, 0);
}

void setup() {
  Wire.begin();

  pinMode(selectBtn, INPUT_PULLUP);
  pinMode(plusBtn, INPUT_PULLUP);
  pinMode(minusBtn, INPUT_PULLUP);
  pinMode(saveBtn, INPUT_PULLUP);

  lcd.init();
  lcd.backlight();

  if (!rtc.begin()) {
    lcd.setCursor(0, 0);
    lcd.print("RTC not found");
    while (1);
  }

  lcd.clear();
}

void loop() {
  if (mode == 0) {
    DateTime now = rtc.now();
    displayClock(now);

    if (buttonPressed(selectBtn, lastSelect)) {
      editTime = now;
      mode = 1;
      lcd.clear();
    }
  } else {
    displayEdit(editTime);

    if (buttonPressed(selectBtn, lastSelect)) {
      mode++;
      if (mode > 4) saveTime();
      lcd.clear();
    }

    if (buttonPressed(plusBtn, lastPlus)) {
      increaseSelected();
      lcd.clear();
    }

    if (buttonPressed(minusBtn, lastMinus)) {
      decreaseSelected();
      lcd.clear();
    }

    if (buttonPressed(saveBtn, lastSave)) {
      saveTime();
    }
  }

  delay(150);
}
