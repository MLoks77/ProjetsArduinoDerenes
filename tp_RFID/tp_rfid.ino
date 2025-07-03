#include <SPI.h>
#include "RFID.h"
RFID monModuleRFID (10,9); 
int UID[4]; 
void setup()
{
Serial.begin(9600);
SPI.begin();
monModuleRFID.init(); 
}
void loop()
{
if (monModuleRFID.isCard()){
  if (monModuleRFID.readCardSerial()){ 
  Serial.print("\n");
  Serial.print("L'UID est: ");
  for(int i=0;i<=4;i++)
   {
    UID[i]=monModuleRFID.serNum[i]; 
    Serial.print(UID[i],DEC);
    Serial.print(".");
    Serial.print("");}
monModuleRFID.halt();
}
delay(1);
}}

    
  
