/*
Ce programme permet de contrôler une prise électrique (ou une lampe) via un signal radio 433 MHz.
- Il utilise la bibliothèque RCSwitch pour envoyer des codes ON/OFF.
- L'utilisateur envoie une commande via le port série : 1 pour allumer, 0 pour éteindre.
- Le code correspondant est transmis par radio pour piloter la prise.
*/
#include <RCSwitch.h>
RCSwitch mySwitch = RCSwitch();

unsigned long Lampe_OFF = 0b010101010101010100010100;
unsigned long Lampe_ON = 0b010101010101010100010101;
void setup() {
  Serial.begin(9600);   
 word w;
}

void loop() {
if(Serial.available())
    {w = Serial.read();
    Serial.flush();}
 if w=1 {
  Serial.println("allume");
  mySwitch.send(Lampe_ON,24);}
 if w=0{
  Serial.println("eteint");
  mySwitch.send(Lampe_OFF,24);}
}
