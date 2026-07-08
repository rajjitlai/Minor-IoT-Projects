# ⏰ Arduino RTC 12-Hour Clock

A 12-hour Arduino Uno clock using a DS3231 RTC module, I2C 16x2 LCD, and push buttons for manual time adjustment.

## Features

- 12-hour time display with AM/PM
- Full day name on second LCD row
- DS3231 RTC keeps time even when Arduino power is off
- Manual time/day adjustment using buttons
- Uses I2C LCD at address `0x27`
- Uses `INPUT_PULLUP` for buttons, so no external resistors are required

## Display Format

```text
10:42:08 PM
Sunday
```

## Hardware Used

| Component | Quantity |
|---|---:|
| Arduino Uno | 1 |
| DS3231 RTC module | 1 |
| 16x2 I2C LCD | 1 |
| Push buttons | 4 |
| Breadboard | 1 |
| Jumper wires | As needed |
| 5V USB adapter | 1 |

## Libraries Required

Install these from Arduino IDE Library Manager:

| Library | Author |
|---|---|
| LiquidCrystal I2C | Frank de Brabander |
| RTClib | Adafruit |

## Wiring & Connections

### Breadboard Rails

```text
Arduino 5V  -> breadboard + rail
Arduino GND -> breadboard - rail
```

### I2C Devices

Both LCD and RTC share SDA/SCL.

```text
LCD SDA -> Arduino A4
RTC SDA -> Arduino A4

LCD SCL -> Arduino A5
RTC SCL -> Arduino A5
```

### LCD Pin Map

| LCD Pin | Arduino Uno |
|---|---|
| GND | GND rail |
| VCC | 5V rail |
| SDA | A4 |
| SCL | A5 |

### DS3231 RTC Pin Map

| RTC Pin | Arduino Uno |
|---|---|
| GND | GND rail |
| VCC | 5V rail |
| SDA | A4 |
| SCL | A5 |

*Note: Do not connect `SQW` or `32K` pins on the RTC module.*

### Buttons Wiring

Using `INPUT_PULLUP`:

| Button | Arduino Pin | Other Side |
|---|---|---|
| SELECT | D2 | GND |
| PLUS / HOUR | D3 | GND |
| MINUS / MIN | D4 | GND |
| SAVE / SEC | D5 | GND |

#### Button Placement Rule

Each button must be placed across the breadboard center gap. A 4-pin tactile button has two internally connected legs on each side.

**Correct:**
```text
Arduino pin side | center gap | GND side
```

**Wrong:**
```text
Arduino pin and GND on same side of button
```

*If the button registers as pressed continuously, it is probably wired on the same internal side.*

## Button Controls

Normal mode:
```text
SELECT -> enter edit mode
```

Edit mode:
```text
SELECT -> move to next field
PLUS   -> increase selected field
MINUS  -> decrease selected field
SAVE   -> save immediately
```

Edit fields sequence:
```text
Hour -> Minute -> Second -> Day -> Save
```

## Code Files

The clock files are in this folder:

| File | Purpose |
|---|---|
| [arduino-rtc-clock.ino](./arduino-rtc-clock.ino) | Main clock code with manual adjustment |
| [set-rtc-time-once.ino](./set-rtc-time-once.ino) | Upload once to set RTC time from computer compile time |
| [i2c-scanner.ino](./i2c-scanner.ino) | Checks detected I2C addresses |

## Expected I2C Addresses

```text
0x27 -> I2C LCD
0x57 -> RTC EEPROM
0x68 -> DS3231 RTC
```

## Power Recommendation

Use:
```text
Branded 5V USB adapter -> USB cable -> Arduino Uno USB port
```

*Avoid 12V barrel jack for continuous 24/7 use because Arduino's onboard regulator may heat up.*

## Safety Notes

- **Do not leave jumper-wire prototypes squeezed inside cardboard boxes.** Use a plastic enclosure and avoid exposed wires.
- Keep jumper wires loose, not compressed.
- Keep the power adapter outside the enclosure.
- Breadboard is acceptable for prototype, but solder/screw terminals are better for permanent use.

## Status

Prototype tested and working.
