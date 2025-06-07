# Real-Time Heat Index Sensor (ESP32 Project)

This project is a **real-time heat index monitoring system** built using an ESP32 microcontroller. It reads temperature and humidity data from a DHT22 sensor, calculates the heat index, and displays the results on an OLED screen. It also features an RTC module for timestamping, a buzzer and LED for alerts, and a swtich to on and off it.

## Components Used

- **ESP32 Dev Board** – main microcontroller
- **DHT22** – digital temperature & humidity sensor
- **DS3231 RTC Module** – real-time clock
- **2.8inch TFT Display** – visual output for temp, humidity, time, and heat index
- **Buzzer** – alert on high heat index
- **LED** – visual alert for warning threshold
- **Rocker Switch - 2P** – for manual reset or user interaction
- **Power Source** – I use 3.7V Lipo Battery, and TP4056 for charging the battery and MT3608 to boost 3.7V to 5V
- **Electrolytic Capacitor** - 100uF and 10uF
- **Ceramic Capacitor** - 0.1uF
- **Terminal Block** - 2 pins


##  Wiring Diagram 
![image](https://github.com/user-attachments/assets/df6f4c74-a707-45eb-8ada-111e06f888dc)

You Can Also Use the gerber file to order my custom PCB in this project 

![image](https://github.com/user-attachments/assets/8fd550dd-31af-45d2-92c6-87f99ccc0514)
![image](https://github.com/user-attachments/assets/523357f3-42cf-4e04-906f-f2bbaa054410)


Made by Edjay,
Feel free to copy, modify and improve it


