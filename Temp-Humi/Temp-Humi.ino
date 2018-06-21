/*
 * Temp & Humidity Status with LCD, DHT11 Sensor
 * Made by Darkhost (darkhost225@gmail.com)
 * Required Library : DHT, LiquidCrystal
 * Last Update : 2018.06.22
 * DHT11 - 8
 * LCD - 3, 4, 10, 11, 12, 13
 * Serial Speed 9600 
 */
 
#include <DHT.h>
#include <LiquidCrystal.h>

// Module Setting
DHT dht(8, DHT11);
LiquidCrystal lcd(3, 4, 10, 11, 12, 13);

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Now Loading...");
}

void loop() {
  delay(2000);
  int err;
  int temp, humi;
  temp = dht.readTemperature();
  humi = dht.readHumidity();

  if(isnan(humi) || isnan(temp)) {
    lcd.clear();
    Serial.println("ERROR");
    lcd.print("Error");
    return;
  }
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp : ");
  lcd.print(temp);
  lcd.print(" C");
  lcd.setCursor(0, 1);
  lcd.print("Humi : ");
  lcd.print(humi);
  lcd.print(" %");
}
