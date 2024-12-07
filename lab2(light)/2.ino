#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <RTClib.h>
#include <Adafruit_BMP085.h>

int h,m,s = 0;
RTC_DS1307 rtc;
LiquidCrystal_I2C LCD(0x27, 16, 2);
DHT dht(2, DHT22);
Adafruit_BMP085 bmp;

void setup() {
  dht.begin();
  LCD.init();
  LCD.backlight();
  bmp.begin();
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  LCD.setCursor(0,0);
  LCD.print(h);
  LCD.setCursor(0,1);
  LCD.print(t);
  LCD.print("C");
  time();
  LCD.setCursor(8,1);
  LCD.print(bmp.readPressure());
  LCD.print(" Pa");
  delay(5000);
  LCD.clear();
}

void time (){
  DateTime now = rtc.now();
  h = now.hour();
  m = now.minute();
  s = now.second();
  LCD.setCursor(7,0);
  LCD.setCursor(6,0);
  if(h<=9){
    LCD.print("0");
  }
  LCD.print(h);
  LCD.setCursor(8,0);
  LCD.print(":");

  LCD.setCursor(9,0);
  if(m<=9){
    LCD.print("0");
  }
  LCD.print(m);
  LCD.setCursor(11,0);
  LCD.print(":");

  LCD.setCursor(12,0);
  if(s<=9){
    LCD.print("0");
  }
  LCD.print(s);
}