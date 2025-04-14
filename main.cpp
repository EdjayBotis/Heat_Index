#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <RTClib.h>
#include <DHT.h>

#define DHTPIN 4
#define SWITCH_PIN 15
#define BUZZER_PIN 18

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

const unsigned char theIcon [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 
	0x00, 0x03, 0x00, 0x00, 0x01, 0x80, 0x18, 0x00, 0x03, 0xe0, 0x10, 0x00, 0x04, 0x27, 0x80, 0x00, 
	0x04, 0x34, 0xc0, 0x00, 0x04, 0x30, 0x60, 0x00, 0x04, 0x30, 0x66, 0x00, 0x04, 0x30, 0x60, 0x00, 
	0x04, 0x37, 0xc0, 0x00, 0x05, 0xb7, 0x80, 0x00, 0x05, 0xb0, 0x18, 0x00, 0x05, 0xb1, 0x08, 0x40, 
	0x05, 0xb3, 0x00, 0xc0, 0x05, 0xb3, 0x00, 0xe0, 0x05, 0xb0, 0x01, 0xf0, 0x05, 0xb0, 0x03, 0xf0, 
	0x05, 0xb0, 0x03, 0xf8, 0x0d, 0x98, 0x07, 0xfc, 0x1b, 0xe8, 0x06, 0xec, 0x17, 0xec, 0x0e, 0xde, 
	0x17, 0xf4, 0x0f, 0xbe, 0x17, 0xe4, 0x0f, 0x7e, 0x13, 0xec, 0x0e, 0x4e, 0x19, 0xc8, 0x07, 0xfc, 
	0x0c, 0x30, 0x07, 0xf8, 0x03, 0xe0, 0x01, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
DHT dht(DHTPIN, DHT22);
RTC_DS1307 rtc;

void displayData();
void displayOff();
bool checkDanger(float temp, float hum);

void setup() {
    pinMode(SWITCH_PIN, INPUT_PULLUP);
    pinMode(BUZZER_PIN, OUTPUT);
    Serial.begin(115200);

    if (!rtc.begin()) {
        Serial.println("Couldn't find RTC");
        while (1);
    }

    dht.begin();

    if (!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        Serial.println("SSD1306 allocation failed");
        while (1);
    }

    oled.clearDisplay();
    oled.setCursor(10, 7);
    oled.setTextSize(2);
    oled.setTextColor(WHITE);
    oled.print("BSABE 3M2");

    oled.setTextSize(1);
    oled.setCursor(15, 30);
    oled.print("Altar,Botis");
    oled.setCursor(15, 40);
    oled.print("Buendia,Pineda");
    oled.setCursor(15, 50);
    oled.print("Reonico,Salamea");
    oled.display();
    delay(3000);
}

void loop() {
    if (digitalRead(SWITCH_PIN) == LOW) {
        displayData();
    } else {
        digitalWrite(BUZZER_PIN, LOW);
        displayOff();
    }
    delay(2000);
}

void displayData() {
    float temp = dht.readTemperature();
    float hum = dht.readHumidity();
    float heatIndex = dht.computeHeatIndex(temp, hum, false);
    DateTime now = rtc.now();

    oled.clearDisplay();
    oled.setTextSize(1);
    oled.setTextColor(WHITE);

    oled.setCursor(5, 0);
    oled.print(now.year());
    oled.print("-");
    oled.print(now.month());
    oled.print("-");
    oled.print(now.day());

    oled.setCursor(80, 0);
    oled.print(now.hour());
    oled.print(":");
    oled.print(now.minute());
    oled.print(":");
    oled.print(now.second());

    // Heat index
    oled.setCursor(0, 15);
    oled.print("Heat Index:");
    oled.setTextSize(2);
    oled.setCursor(10, 25);
    oled.print(heatIndex, 1);
    oled.drawCircle(65,25,2,WHITE);
    oled.println(" C");

    oled.setTextSize(1);
    oled.setCursor(0, 50);
    oled.print("Temp:");
    oled.print(temp, 1);
    oled.println("C");
    oled.setCursor(70, 50);
    oled.print("Hum:");
    oled.print(hum, 1);
    oled.println("%");

    oled.drawBitmap(90, 12, theIcon, 32, 32, WHITE);

    oled.display();

    checkDanger(temp, hum);

}

bool checkDanger(float temp, float hum) {
    bool danger = (temp > 40 || temp < 0 || hum < 20 || hum > 90);
    digitalWrite(BUZZER_PIN, danger ? HIGH : LOW);
    return danger;
}

void displayOff() {
    oled.clearDisplay();
    oled.display();
}
