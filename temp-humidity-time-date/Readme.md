# Arduino Temperature, Humidity \& Time Monitor

A real-time monitoring system that displays temperature, humidity, date, and time on a 16x2 LCD display using Arduino Uno.

## Components List

| Component | Quantity | Description |
| :-- | :-- | :-- |
| Arduino Uno | 1 | Main microcontroller board |
| DHT22 Temperature \& Humidity Sensor Module | 1 | 3-pin module with built-in pull-up resistor |
| DS3231 RTC Module | 1 | Real-Time Clock module with battery backup |
| 16x2 I2C LCD Display | 1 | LCD with I2C interface (address 0x27) |
| Jumper Wires | Several | Male-to-female or male-to-male |
| USB Cable | 1 | For programming and power |

## Required Libraries

Install these libraries via Arduino IDE (Sketch → Include Library → Manage Libraries):

1. **LiquidCrystal I2C** - for I2C LCD display
2. **DHT sensor library** by Adafruit - for DHT22 sensor[^1]
3. **RTClib** by Adafruit - for DS3231 RTC module[^11]

## Pin Connections

### DHT22 Sensor Module (3-pin version)

```
DHT22 Module → Arduino Uno
─────────────────────────────
VCC (or +)   → 5V
DATA (or S)  → Pin 2
GND (or -)   → GND
```

**Note:** No external resistor needed - the module has a built-in pull-up resistor.[^12][^1]

### DS3231 RTC Module

```
DS3231 → Arduino Uno
─────────────────────
VCC    → 5V
GND    → GND
SDA    → A4
SCL    → A5
```


### 16x2 I2C LCD Display

```
I2C LCD → Arduino Uno
──────────────────────
VCC     → 5V
GND     → GND
SDA     → A4 (shared with DS3231)
SCL     → A5 (shared with DS3231)
```


## Complete Wiring Diagram

```
Arduino Uno Pins:
├── 5V    → DHT22 VCC, DS3231 VCC, LCD VCC
├── GND   → DHT22 GND, DS3231 GND, LCD GND
├── Pin 2 → DHT22 DATA
├── A4    → DS3231 SDA, LCD SDA (I2C Bus)
└── A5    → DS3231 SCL, LCD SCL (I2C Bus)
```

**Important:** All devices share the same power (5V) and ground connections. The DS3231 and LCD share the I2C bus (A4/A5).[^13][^14]
