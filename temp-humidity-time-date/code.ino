#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include <RTClib.h>

// Define pins and sensor type
#define DHTPIN 2      
#define DHTTYPE DHT22 

// Initialize sensor, LCD, and RTC
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);
RTC_DS3231 rtc;

int errorCount = 0;

void setup()
{
    Serial.begin(9600);
    
    lcd.init();      
    lcd.backlight(); 
    dht.begin();     
    
    // Initialize RTC
    if (!rtc.begin()) {
        lcd.setCursor(0, 0);
        lcd.print("RTC not found!");
        while (1);
    }
    
    // Auto-set time ONLY if RTC lost power or time is invalid
    if (rtc.lostPower()) {
        lcd.setCursor(0, 0);
        lcd.print("RTC Lost Power!");
        lcd.setCursor(0, 1);
        lcd.print("Setting time...");
        
        // Set to compile time automatically
        rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
        
        delay(2000);
    }
    
    lcd.setCursor(0, 0);
    lcd.print("Temp & Time");
    lcd.setCursor(0, 1);
    lcd.print("Monitor Ready");
    delay(2000);
    lcd.clear();
}

void loop()
{
    // Read DHT22 sensor
    float h = dht.readHumidity();
    float t = dht.readTemperature();
    
    // Read RTC time
    DateTime now = rtc.now();
    
    // Handle sensor errors
    if (isnan(h) || isnan(t))
    {
        errorCount++;
        lcd.setCursor(0, 0);
        lcd.print("Sensor error   ");
        lcd.setCursor(0, 1);
        lcd.print("Check DHT22    ");
        delay(2000);
        
        if (errorCount >= 5)
        {
            errorCount = 0; // Reset counter
        }
        return;
    }
    
    errorCount = 0; // Reset on success
    
    // Display temperature and humidity on first line
    lcd.setCursor(0, 0);
    lcd.print("T:");
    lcd.print(t, 1);
    lcd.print((char)223);
    lcd.print("C H:");
    lcd.print(h, 0);
    lcd.print("%  ");
    
    // Display time on second line
    lcd.setCursor(0, 1);
    
    // Format: HH:MM:SS  DD/MM/YY
    if (now.hour() < 10) lcd.print("0");
    lcd.print(now.hour());
    lcd.print(":");
    if (now.minute() < 10) lcd.print("0");
    lcd.print(now.minute());
    lcd.print(":");
    if (now.second() < 10) lcd.print("0");
    lcd.print(now.second());
    
    lcd.print(" ");
    
    if (now.day() < 10) lcd.print("0");
    lcd.print(now.day());
    lcd.print("/");
    if (now.month() < 10) lcd.print("0");
    lcd.print(now.month());
    
    delay(1000); // Update every second
}
