/*
  Upload this sketch once to set DS3231 RTC time
  from the computer's compile time.

  After uploading this, upload rtc-clock-main.ino again.
*/

#include <Wire.h>
#include <RTClib.h>

RTC_DS3231 rtc;

void setup() {
  Serial.begin(9600);
  Wire.begin();

  if (!rtc.begin()) {
    Serial.println("RTC not found");
    while (1);
  }

  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));

  Serial.println("RTC time set from computer compile time.");
}

void loop() {
}
