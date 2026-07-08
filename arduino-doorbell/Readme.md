# 🔔 Arduino Doorbell

A simple Arduino Uno based doorbell using a push button and buzzer/chime.

## Features

- Push-button controlled doorbell
- Uses Arduino `INPUT_PULLUP`, so no external resistor is required for the button
- Tested with a long low-voltage wire for the button
- Uses a passive/clock buzzer driven with `tone()`
- Safe low-voltage design when powered through a certified 5V USB adapter

## Hardware Used

| Component | Quantity |
|---|---:|
| Arduino Uno | 1 |
| Push button | 1 |
| Buzzer / clock buzzer / piezo buzzer | 1 |
| Jumper wires | As needed |
| 2-core low-voltage wire | As needed |
| Breadboard / temporary connector | 1 |
| 5V USB adapter | 1 |

## Wiring & Connections

### Prototype Wiring

```text
Arduino GND -> Breadboard negative rail
Button one side -> Arduino D2
Button other side -> GND
Buzzer + -> Arduino D8
Buzzer - -> GND
```

### Pin Map

| Arduino Pin | Connected To |
|---|---|
| D2 | Push button signal |
| D8 | Buzzer signal |
| GND | Button ground and buzzer ground |
| USB | 5V power input |

### Long Wire Button Test

Use 2-core low-voltage wire:

```text
Arduino D2  -> long wire core 1 -> button terminal 1
Arduino GND -> long wire core 2 -> button terminal 2
```

### Final Deployment Concept

```text
[Door Button]
     |
     | 2-core low-voltage wire
     |
[Arduino Uno + Buzzer indoors]
     |
     | USB cable
     |
[5V USB Adapter]
```

## Power

Recommended:

```text
230V AC socket -> certified 5V USB adapter -> Arduino USB port
```

Do not connect Arduino directly to 230V AC.

## Code

Main code is available in:
- [arduino-doorbell.ino](./arduino-doorbell.ino)

## Safety & Installation Notes

- Keep 230V AC only up to the certified adapter.
- Everything after the adapter must be low-voltage DC.
- Do not use exposed wires.
- Do not run low-voltage Arduino wires in the same conduit as 230V AC wires.
- Breadboard is okay for prototype/testing, but not ideal for permanent use.
- For long-term use, use soldered joints or screw terminals inside a plastic enclosure.
- **Do not leave jumper-wire prototypes squeezed inside cardboard boxes.** Use a plastic enclosure and avoid exposed wires.

## Status

Prototype tested and working.
