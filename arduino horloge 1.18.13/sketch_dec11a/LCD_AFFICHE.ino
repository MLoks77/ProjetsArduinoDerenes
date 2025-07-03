void lcdaffiche() {
  
  if(millis()%1000==0){ 
Serial.println(time.gettime("d-m-Y"));
Serial.println(time.gettime("H:i:s"));
Serial.print(i);
lcd.setCursor(1,0);
lcd.print(time.gettime("D,d-m-Y"));
lcd.setCursor(2,1);
lcd.print(time.gettime("H:i:s"));
i++;
}
if ( (i>5) && (i<10) ){lcd.setRGB(255,0,0);}
if ( (i>10) && (i<60) ){lcd.setRGB(0,0,255);}
}
