# RFID Smart Attendance Monitoring System

An automated attendance management system built with **Arduino Uno** and **RFID technology** that eliminates manual attendance marking, reduces errors, and prevents proxy attendance.

## 📌 Overview
This project automates attendance tracking using RFID technology and Arduino Uno. It replaces manual roll calls and paper registers with an efficient, error-free digital system.

## ✨ Features
- 🔑 RFID tag scanning for unique user identification
- 📟 LCD display showing real-time attendance status  
- ⏱️ RTC module for accurate timestamp logging
- 💡 LED indicator for successful attendance confirmation
- 📊 Database integration for record storage
- 🔒 Prevents buddy punching/fraudulent attendance

## 🛠️ Hardware Required
| Component | Quantity |
|-----------|----------|
| Arduino Uno | 1 |
| MFRC522 RFID Reader | 1 |
| RFID Tags/Cards | Multiple |
| 16x2 LCD Display | 1 |
| DS3231 RTC Module | 1 |
| LED (Green) | 1 |
| Buzzer (Optional) | 1 |
| Breadboard & Jumper Wires | As needed |
| 9V/12V Power Supply | 1 |

## 💻 Software Required
- Arduino IDE
- MySQL / SQLite
- Required Libraries:
  - MFRC522.h
  - SPI.h
  - Wire.h
  - LiquidCrystal_I2C.h
  - RTClib.h

## 🔌 Circuit Connections
