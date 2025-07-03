#include <rgb_lcd.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <iarduino_RTC.h>
#include "iarduino_RTC.h"

LiquidCrystal_I2C LCD(0x27,16,2);
iarduino_RTC time (RTC_DS1302,7,5,6);
rgb_lcd lcd;

int pinLed1 = 2;
int pinLed2 = 3;
int i = 0;

void setup() 
{
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.setRGB(0,0,255);
  LCD.init();
  LCD.backlight();
   
time.begin();
time.settime(00,17,12,15,12,23,3);   // SEC MIN H 2DATE mois anne jour

}

void loop() {
lcdaffiche();
if(millis()%1000==0){ // toute les secondes
allumeled();} // les leds font bug le system

}
