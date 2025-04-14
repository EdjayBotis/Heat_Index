# 🌡Real-Time Heat Index Sensor (ESP32 Project)

This project is a **real-time heat index monitoring system** built using an ESP32 microcontroller. It reads temperature and humidity data from a DHT22 sensor, calculates the heat index, and displays the results on an OLED screen. It also features an RTC module for timestamping, a buzzer and LED for alerts, and a button for manual resets or interaction.

## Components Used

- **ESP32 Dev Board** – main microcontroller
- **DHT22** – digital temperature & humidity sensor
- **DS3231 RTC Module** – real-time clock
- **OLED Display (128x64, I2C)** – visual output for temp, humidity, time, and heat index
- **Buzzer** – alert on high heat index
- **LED** – visual alert for warning threshold
- **Tactile Switch** – for manual reset or user interaction
- **Power Source** – USB or 5V battery pack

## 🔧 Features

- 📅 Real-time display with date & time
- Measure temperature and humidity reading and Calculate Heat index
- Buzzer + LED alert system for high heat index
- Data displayed without needing a PC/laptop

## 🖥️ How It Works

1. ESP32 reads data from the **DHT22 sensor**
2. Calculates the **heat index** based on the temp and humidity
3. Reads time from **RTC module**
4. Displays all info on **OLED screen**
5. If heat index crosses a threshold:
   - LED lights up
   - Buzzer sounds

## 💡 Setup & Wiring

> Components are soldered to provide a durable, display-ready setup.

Example Wiring Summary:
- **DHT22** → VCC to 3.3V, DATA to GPIO4, GND to GND
- **OLED** → SDA to GPIO21, SCL to GPIO22
- **RTC** → SDA to GPIO21, SCL to GPIO22
- **Buzzer** → Positive to GPIO27, Negative to GND
- **LED** → Anode to GPIO26 (with resistor), Cathode to GND
- **Button** → One leg to GPIO25, other to GND


Made with Edjay


