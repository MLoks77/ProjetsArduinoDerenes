#include <FastIO.h>
#include <I2CIO.h>
#include <LCD.h>
#include <LiquidCrystal.h>
#include <LiquidCrystal_I2C.h>
#include <LiquidCrystal_I2C_ByVac.h>
#include <LiquidCrystal_SI2C.h>
#include <LiquidCrystal_SR.h>
#include <LiquidCrystal_SR1W.h>
#include <LiquidCrystal_SR2W.h>
#include <LiquidCrystal_SR3W.h>
#include <SI2CIO.h>
#include <SoftI2CMaster.h>



void setup ()
{
  LCD.begin (16,2);
  LCD.setCursor (1,0);
  LCD.print ("Le LCD MARCHE");
}

void loop ()
{
  LCD.noDisplay();
  delay(500)
  LCD.Display ();
  delay(500);
}
