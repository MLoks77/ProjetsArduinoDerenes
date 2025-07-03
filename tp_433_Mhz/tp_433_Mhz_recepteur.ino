
#include <VirtualWire.h>
const byte PIN_LED_A=7;
const char* CMD_BUTTON_A="SD1";
const byte PIN_LED_SD2=4;
const char* CMD_BUTTON_SD2="SD2";
const char* CMD_BUTTON_SD3="Bonjour";
int x=0;
void setup() {
  Serial.begin(9600);
  pinMode(PIN_LED_A, OUTPUT);
  digitalWrite(PIN_LED_A, LOW);
  pinMode(PIN_LED_SD2, OUTPUT);
  digitalWrite(PIN_LED_SD2, LOW);
  vw_setup(2000);
  vw_rx_start();
  Serial.println("Go !");
}
void loop() {
  byte message[VW_MAX_MESSAGE_LEN];
  byte taille_message= VW_MAX_MESSAGE_LEN;
  vw_wait_rx();  
  if(vw_get_message(message,&taille_message))
  { 
    x=0;
    if(strcmp((char*)message,CMD_BUTTON_A)==0){
      digitalWrite(PIN_LED_A, !digitalRead(PIN_LED_A));
      Serial.println("BASCULER LED A");}   
    if(strcmp((char*)message,CMD_BUTTON_SD2)==0){
      digitalWrite(PIN_LED_SD2, !digitalRead(PIN_LED_SD2));
      Serial.println("BASCULER LED SD2");}
    if(strcmp((char*)message,CMD_BUTTON_SD3)==0){
      Serial.println((byte) message);
      while(x<8){
        digitalWrite(PIN_LED_A, HIGH);
        digitalWrite(PIN_LED_SD2, LOW);
        delay(500);
        digitalWrite(PIN_LED_A, LOW);
        digitalWrite(PIN_LED_SD2, HIGH);
        delay(500);
        x++;
        
      
      }
      
      
      
    }
      
      
    
  }

}
