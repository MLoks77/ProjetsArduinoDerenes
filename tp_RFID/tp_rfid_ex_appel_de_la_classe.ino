/*
Ce programme utilise un module RFID pour contrôler l'accès à l'aide de badges.
- Il lit l'UID d'un badge RFID et le compare à deux clés maîtres prédéfinies.
- Si l'UID correspond, il active un servo-moteur (ouverture), allume une LED verte et joue une mélodie sur un buzzer.
- Sinon, il allume brièvement une LED rouge.
- Le système utilise également la bibliothèque Servo pour contrôler un moteur et la bibliothèque RFID pour la lecture des badges.
*/
#include <SPI.h>
#include "RFID.h"
#include <Servo.h>
int Buzzer = 8;
const char LED_ROUGE=2;
const char LED_VERTE=3; 
Servo myservo;
RFID monModuleRFID (10,9); 
int UID[5];
int MASTERKEY[5] = {58,240,226,158,182}; // Numéro du badge à détecter
int UID2[5];
int MASTERKEY2[5] ={26,148,10,159,27};
void setup()
{
Serial.begin(9600);
SPI.begin();
monModuleRFID.init(); 
pinMode(LED_ROUGE,OUTPUT);
pinMode(LED_VERTE,OUTPUT);
pinMode(Buzzer,OUTPUT);
digitalWrite(LED_ROUGE,LOW);
digitalWrite(LED_VERTE,LOW);
pinMode(6,OUTPUT);
myservo.attach(6);
}
void loop()
{
  myservo.write(0);
  delay(1000);

  
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
  if(UID[0]==MASTERKEY[0]
     &&UID[1]==MASTERKEY[1]
     &&UID[2]==MASTERKEY[2]
     &&UID[3]==MASTERKEY[3]
     &&UID[4]==MASTERKEY[4]
     ||UID2[5]==MASTERKEY2[5])
    

     
    {
      digitalWrite(LED_VERTE,HIGH);
     myservo.write(180);
     
     tone(Buzzer,440);
     delay(500);
     tone(Buzzer,440);
     delay(500);
     tone(Buzzer,440);
     delay(500);
     tone(Buzzer,349);
     delay(350);
     tone(Buzzer,523);
     delay(150);
     tone(Buzzer,440);
     delay(500);
     tone(Buzzer,349);
     delay(350);
     tone(Buzzer,523);
     delay(150);
     tone(Buzzer,440);
     delay(650);
     noTone(Buzzer);
     delay(500);
     
     digitalWrite(LED_VERTE,LOW);}
   else
    {digitalWrite(LED_ROUGE,HIGH);
     delay(500);
     digitalWrite(LED_ROUGE,LOW);}
     
monModuleRFID.halt();
}
delay(1);
}}

    
  
