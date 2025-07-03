#include <Servo.h>
Servo rotation;
Servo inclinaison;
int pin1 = A1;
int pin2 = A2;
int pin3 = A3;
int angleMax = 90;
int angle_rota=90;
int angleMin = 45;
int angle_inclinaison=90;
void setup()
{
  Serial.begin(9600);
  rotation.attach(8);
  inclinaison.attach(9);
}

void loop()
{
   if (analogRead(pin1) > analogRead(pin2)+20){
    angle_rota=angle_rota+5;
    rotation.write(angle_rota);
    Serial.print("test1");}
   else{ 
     if(analogRead(pin2) > analogRead(pin1)+20){
       angle_rota=angle_rota-5;
       rotation.write(angle_rota);
       Serial.print("test2");}}
   if (analogRead(pin3) > analogRead(pin2)+20){
    angle_inclinaison=constrain(angle_inclinaison, 45, 90);
    angle_inclinaison=angle_inclinaison+5;
    inclinaison.write(angle_inclinaison);
    Serial.print("test3");}
   else{ 
     if(analogRead(pin2) > analogRead(pin3)+20){
       angle_inclinaison=constrain(angle_inclinaison, angleMin, 90);
       angle_inclinaison=angle_inclinaison-5;
       inclinaison.write(angle_inclinaison);
       Serial.print("test4");}}
  delay(1000);}
    
