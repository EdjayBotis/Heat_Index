#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <RTClib.h>
#include <DHT.h>
#include "heatIndexPic.h"

#define DHTPIN 4
#define BUZZER_PIN 13

#define LED_RED 2
#define LED_ORANGE 5
#define LED_YELLOW 19

#define TFT_CS    14
#define TFT_RST   26
#define TFT_DC    27
#define TFT_MOSI  23
#define TFT_CLK   18

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RST);
DHT dht(DHTPIN, DHT22);
RTC_DS3231 rtc;

void setup() {
    pinMode(BUZZER_PIN, OUTPUT);
    pinMode(LED_RED, OUTPUT);
    pinMode(LED_ORANGE, OUTPUT);
    pinMode(LED_YELLOW, OUTPUT);

    Serial.begin(115200);
    rtc.begin();
    dht.begin();
    tft.begin();
    
    tft.fillScreen(ILI9341_BLACK);
    tft.setRotation(1);
    tft.setTextColor(ILI9341_GREEN);
    tft.setTextSize(3);
    tft.setCursor(0, 50);
    tft.println("HEAT INDEX: ");

    tft.setTextColor(ILI9341_BLUE);
    tft.setTextSize(2);
    tft.setCursor(0, 185);
    tft.print("Hum:");

    tft.setTextColor(ILI9341_RED);
    tft.setTextSize(2);
    tft.setCursor(150, 185);
    tft.print("Temp:");
    
    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(2);
    tft.setCursor(0, 140);
    tft.println("Degree Celcius");

    tft.setTextSize(1);
    tft.setCursor(90, 230);
    tft.drawLine(0,225,320,225,ILI9341_WHITE);
    tft.println("BY BSABE 3M2: GROUP 2");

    tft.drawBitmap(170,35,heatIndexPic,150,150,ILI9341_WHITE);

}

void loop() {
        float temp = dht.readTemperature();
        float hum = dht.readHumidity();
        float heatIndex = dht.computeHeatIndex(temp, hum, false);
        DateTime now = rtc.now();
        uint8_t day = now.dayOfTheWeek();

        tft.setTextColor(ILI9341_WHITE,ILI9341_BLACK);
        tft.setTextSize(2);
        tft.setCursor(0, 10);
        tft.print(now.hour());
        tft.print(":");
        tft.print(now.minute());
        tft.print(":");
        tft.print(now.second());

        tft.setCursor(130, 10);
        tft.print(daysOfWeek[day]);

        tft.setCursor(210, 10);
        tft.print(now.year());
        tft.print("/");
        tft.print(now.month());
        tft.print("/");
        tft.print(now.day());

        tft.setTextColor(ILI9341_WHITE,ILI9341_BLACK);
        tft.setTextSize(6);
        tft.setCursor(0, 90);
        tft.println(heatIndex, 1);

        tft.setTextSize(3);
        tft.setTextColor(ILI9341_WHITE,ILI9341_BLACK);
        tft.setCursor(50, 180);
        tft.print(hum, 1);
        tft.print("%");

        tft.setTextColor(ILI9341_WHITE,ILI9341_BLACK);
        tft.setTextSize(3);
        tft.setCursor(220, 180);
        tft.print(temp, 1);
        tft.print("C");
        
    if (heatIndex >= 52) {
        tone(BUZZER_PIN, 500);
        delay(1000);
        noTone(BUZZER_PIN);
        delay(1000); 
        digitalWrite(LED_RED, HIGH);
        digitalWrite(LED_ORANGE, LOW);
        digitalWrite(LED_YELLOW, LOW);

    } else if (heatIndex >= 42) {
        tone(BUZZER_PIN, 400);
        delay(700);
        noTone(BUZZER_PIN);
        delay(700); 
        digitalWrite(LED_RED, LOW);
        digitalWrite(LED_ORANGE, HIGH);
        digitalWrite(LED_YELLOW, LOW);
    
    } else if (heatIndex >= 33){
        noTone(BUZZER_PIN);
        digitalWrite(LED_RED, LOW);
        digitalWrite(LED_ORANGE, LOW);
        digitalWrite(LED_YELLOW, HIGH);
        
    } else {
        noTone(BUZZER_PIN);
        digitalWrite(LED_RED, LOW);
        digitalWrite(LED_ORANGE, LOW);
        digitalWrite(LED_YELLOW, LOW);
  
    }
}
