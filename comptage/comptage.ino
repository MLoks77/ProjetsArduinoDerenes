int nomb=0;

void setup() 
{
 Serial.begin (9600);

 pinMode(7,INPUT);
 digitalWrite(7,LOW);
 pinMode(5,INPUT);
 digitalWrite(5,LOW);
 nomb=0;
}

void loop()
{
  if (digitalRead(7)==HIGH)
{
  nomb++;
  Serial.print("compteur=");
  Serial.println(nomb);
  delay(800);
}
  if (digitalRead(5)==HIGH)
{
  nomb--;
  Serial.print("compteur=");
  Serial.println(nomb);
  delay(800);
}
}
