/*
Ce programme Arduino réalise un compteur simple à l'aide de deux boutons.
- Un bouton (sur la broche 7) incrémente la variable compteur à chaque appui.
- Un autre bouton (sur la broche 5) décrémente la variable compteur à chaque appui.
Le résultat est affiché sur le moniteur série.
Un délai de 800 ms évite les rebonds lors de l'appui sur les boutons.
*/
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
