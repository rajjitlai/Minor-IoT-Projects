# 🔧 My Personal IoT Systems

<p align="left">
  <a href="License"><img src="https://img.shields.io/badge/License-MIT-yellow.svg?style=flat-square" alt="License: MIT"></a>
  <a href="https://www.arduino.cc/"><img src="https://img.shields.io/badge/Platform-Arduino-00979D?style=flat-square&logo=arduino&logoColor=white" alt="Platform: Arduino"></a>
  <a href="https://www.espressif.com/"><img src="https://img.shields.io/badge/Platform-ESP32-E7352C?style=flat-square&logo=espressif&logoColor=white" alt="Platform: ESP32"></a>
  <a href="https://isocpp.org/"><img src="https://img.shields.io/badge/Language-C%2B%2B-00599C?style=flat-square&logo=c%2B%2B&logoColor=white" alt="Language: C++"></a>
  <img src="https://img.shields.io/badge/Field-IoT%20%26%20Robotics-blueviolet?style=flat-square" alt="Field: IoT & Robotics">
  <img src="https://img.shields.io/github/repo-size/rajjitlai/home-iot-systems?style=flat-square&color=blue" alt="GitHub repo size">
</p>

This repository contains various IoT projects built for learning, experimentation, and practical applications. Each subfolder includes project-specific code, documentation, and hardware integration.

---

## 📋 Project Status Overview

| Project                               | Status           | Description                                               |
|---------------------------------------|------------------|-----------------------------------------------------------|
| Smart Plant Watering System           | ✅ Done           | Automatically waters plants based on soil moisture level. |
| Temperature Display System            | ✅ Done           | Shows real-time room temperature using DHT sensor.        |
| Arduino Doorbell                      | ✅ Done           | A simple Arduino Uno doorbell using a button and buzzer.  |
| Arduino RTC Clock                     | ✅ Done           | A 12-hour DS3231 RTC clock with I2C LCD and buttons.      |
| PID Line Follower                     | 🚧 In Progress    | Follows black lines using PID algorithm and IR sensors.   |
| Bluetooth Control Car                 | 🚧 In Progress    | Controlled wirelessly via phone over Bluetooth.           |
| Life-Logging Camera                   | ⚙️ Prototype      | Takes photos at intervals using ESP32-CAM.                |
| Object Avoidance Car                 | ❌ Not Started    | Avoids obstacles using ultrasonic sensors.                |

---

## 📂 Project Directory Guide

Each project folder is self-contained with its own code, schematics, and setup guide. Explore them here:

- 💧 **[Smart Plant Watering System](./smart-plant-watering-system/Readme.md)** — Monitors soil moisture levels and triggers a 5V pump to water plants automatically. Includes [code.ino](./smart-plant-watering-system/code.ino) and schematic diagrams.
- 🌡️ **[Temperature Display System](./home_temp_system/Readme.md)** — Real-time temperature measurement system utilizing a DHT22 sensor and an LCD screen. Check out [home_temp_system.ino](./home_temp_system/home_temp_system.ino).
- 🔔 **[Arduino Doorbell](./arduino-doorbell/Readme.md)** — A simple low-voltage doorbell designed with a piezo buzzer and an `INPUT_PULLUP` push button. See [arduino-doorbell.ino](./arduino-doorbell/arduino-doorbell.ino).
- ⏰ **[Arduino RTC Clock](./arduino-rtc-clock/Readme.md)** — A 12-hour clock using a DS3231 real-time clock module, an I2C 16x2 LCD, and tactile buttons for manual time setting. Contains the main sketch [arduino-rtc-clock.ino](./arduino-rtc-clock/arduino-rtc-clock.ino), a [set-rtc-time-once.ino](./arduino-rtc-clock/set-rtc-time-once.ino) tool, and an [i2c-scanner.ino](./arduino-rtc-clock/i2c-scanner.ino) utility.
- 🚗 **[PID Line Follower (Advanced)](./pid-line-follower/Readme.md)** — Line following robot utilizing a PID control loop, Arduino Nano, TB6612FNG driver, and a 7-channel IR sensor array. Code: [pid-line-follower.ino](./pid-line-follower/pid-line-follower.ino).
- 🏎️ **[PID Line Follower (Minimal)](./line-follower-minimal/Readme.md)** — Compact PID line-tracking robot featuring an Arduino Uno and a 5-channel IR array. Code: [line-follower-minimal.ino](./line-follower-minimal/line-follower-minimal.ino).
- 📱 **[Bluetooth Control Car](./bluetooth-car/Readme.md)** — Wirelessly driven robot car controlled via a mobile application interfacing with an HC-05 module. View [bluetooth-car.ino](./bluetooth-car/bluetooth-car.ino).
- 📸 **[Life-Logging Camera](./life-long-camera/)** — Time-lapse photo capturing device powered by an ESP32-CAM module.
- 🤖 **[Object Avoidance Car](./object-avoidance-car/)** — Self-steering robot that detects and avoids obstacles using an ultrasonic sensor on a micro servo.
- 📊 **[Temp, Humidity & Time Monitor](./temp-humidity-time-date/Readme.md)** — Station displaying real-time clock data alongside ambient temperature/humidity metrics. View [code.ino](./temp-humidity-time-date/code.ino).
- 🏆 **[Competition & Exhibition Code](./competition/)** — Repository subdirectory preserving codebases, caliber routines, and experimental test structures built for electronics competitions.

---

## 📦 Common Components Used

- Arduino UNO / Nano / ESP32 / ESP32-CAM
- DHT22 Temperature & Humidity Sensor
- Ultrasonic Sensor (HC-SR04)
- Soil Moisture Sensor
- DS3231 RTC (Real-Time Clock)
- L298N Motor Driver
- IR Sensor (TCRT5000)
- Servo Motor (SG90)
- DC BO Motors
- LCD Display (I2C-based 16x2)
- Buzzer / Piezo Buzzer
- Bluetooth Module (HC-05)
- Jumper Wires, Breadboard
- 9V / 7.4V Batteries or 5V Adapter
- SD Card (ESP32-CAM)
- Resistors (10kΩ, etc.)

---

## 📂 Project Setup

Each project folder contains:

- `Readme.md`: Specific setup and circuit details
- `<project_name>.ino` or `code.ino`: Arduino/ESP32 sketch
- `circuit_diagram.png`: Wiring and schematics (if available)
- `License`: Project license (MIT)

To get started:

1. Open the folder of the desired project.
2. Read the project-specific `Readme.md`.
3. Upload the code to your Arduino/ESP32.
4. Build the circuit using the schematic.
5. Power the device and monitor via Serial Monitor or display.

---

## ⚠️ Safety & Best Practices

When building and deploying these projects, keep the following guidelines in mind:

- **Power Regulation**: For continuous 24/7 projects (like the RTC Clock or Temp Monitor), power the Arduino via the USB port using a branded 5V adapter rather than a high-voltage barrel jack (e.g., 12V), as the internal voltage regulator can heat up under continuous load.
- **Enclosures**: Do not leave prototype projects inside tight, combustible cardboard boxes. Use custom plastic enclosures or 3D-printed boxes with ventilation holes.
- **Wiring Cleanliness**: Ensure that no exposed wires or solder joints can short-circuit. Use heat-shrink tubing and cable ties to secure jumper wires.
- **Conduits**: Never run low-voltage Arduino wires in the same wall conduit or in close proximity to mains 230V AC wiring to avoid signal interference and safety hazards.

---

## 🚀 Getting Started

You can clone the repository using:

```bash
git https://github.com/rajjitlai/Minor-IoT-Projects
cd home-iot-systems
```

Choose any project folder and follow the instructions inside.

---

## 🎯 Extra: Competitions & Exhibitions

Some of these projects have been used or showcased in various tech competitions and hardware exhibitions. More information will be added in future updates.

## 📜 License

This project is licensed under the **MIT License**.  
You are free to use, modify, and distribute this project with proper attribution. See the [License](./License) file for details.

## 🙌 Credits

Created and developed by [Rajjit Laishram](https://rajjitlaishram.netlify.app/).  
Special thanks to the Arduino and open-source robotics communities.
