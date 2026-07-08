/*
  Arduino Doorbell
  Board: Arduino Uno

  Button:
    D2 -> one side of push button
    GND -> other side of push button

  Buzzer:
    D8 -> buzzer positive / red wire
    GND -> buzzer negative / yellow wire

  Uses INPUT_PULLUP, so button reads:
    Not pressed = HIGH
    Pressed     = LOW
*/

const int buttonPin = 2;
const int buzzerPin = 8;

const int buzzerFrequency = 4000; // Tested loud frequency

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  if (digitalRead(buttonPin) == LOW) {
    tone(buzzerPin, buzzerFrequency);
  } else {
    noTone(buzzerPin);
  }
}
