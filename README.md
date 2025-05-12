# Real-Time Heat Index Sensor (ESP32 Project)

This project is a **real-time heat index monitoring system** built using an ESP32 microcontroller. It reads temperature and humidity data from a DHT22 sensor, calculates the heat index, and displays the results on an OLED screen. It also features an RTC module for timestamping, a buzzer and LED for alerts, and a swtich to on and off it.

## Components Used

- **ESP32 Dev Board** – main microcontroller
- **DHT22** – digital temperature & humidity sensor
- **DS3231 RTC Module** – real-time clock
- **OLED Display (128x64, I2C)** – visual output for temp, humidity, time, and heat index
- **Buzzer** – alert on high heat index
- **LED** – visual alert for warning threshold
- **Tactile Switch** – for manual reset or user interaction
- **Power Source** – USB or 5V battery pack


##  Setup & Wiring
 Wiring Summary:
- **DHT22** → VCC to 3.3V, DATA to GPIO4, GND to GND
- **OLED** → SDA to GPIO21, SCL to GPIO22
- **RTC** → SDA to GPIO21, SCL to GPIO22
- **Buzzer** → Positive to GPIO27, Negative to GND
- **LED** → Anode to GPIO26 (with resistor), Cathode to GND
- **Button** → One leg to GPIO25, other to GND



Made with Edjay
Feel free to copy, modify and improve it


