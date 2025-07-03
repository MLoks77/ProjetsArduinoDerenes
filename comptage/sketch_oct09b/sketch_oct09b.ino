 int nomb=0;

void setup() {
 Serial.begin(9600);
 Serial.print("essai de capteur IR");
 pinMode (11,INPUT); // capteur IR sur pin 11 numerique 
 pinMode (12,INPUT); // capteur IR sur pin 11 numerique
 digitalWrite(11,HIGH);
 digitalWrite(12,HIGH);
 nomb=0;

}

void loop() {
// Serial.println(ir); // 0 si obstacle proche ( sous le seuil )
                       // 1 si pas obstacle 



 if ((digitalRead(11)==LOW)&&(digitalRead(12)==HIGH))
 { delay(100);
          if((digitalRead(11)==HIGH)&&(digitalRead(12)==LOW))
       {
       nomb++;
       Serial.print("compteur=");
       Serial.println(nomb);
       }     
 }
 else
  if ((digitalRead(11)==LOW)&&(digitalRead(12)==HIGH))
 { delay(100);
          if((digitalRead(11)==HIGH)&&(digitalRead(12)==LOW))
       {
       nomb--;
       Serial.print("compteur=");
       Serial.println(nomb);
       }     
 }

 digitalWrite(11,HIGH);
 digitalWrite(12,HIGH);         
          
}
