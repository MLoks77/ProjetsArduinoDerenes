const int ledPin = 13; // Broche LED
int brightness = 0;  
int fadeAmount = 5;  
unsigned long previousMillis = 0;
int mode = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {

  if (millis() - previousMillis >= 5000) {
    previousMillis = millis();
    mode = (mode + 1) % 3; 
  }

  switch (mode) {
    case 0:
      blinkPattern();
      break;
    case 1:
      fadeLED();       
      break;
    case 2:
      customSequence();
      break;
  }
}

void blinkPattern() {
  digitalWrite(ledPin, HIGH);
  delay(200);
  digitalWrite(ledPin, LOW);
  delay(200);
  digitalWrite(ledPin, HIGH);
  delay(50);
  digitalWrite(ledPin, LOW);
  delay(50);
}

void fadeLED() {
  analogWrite(ledPin, brightness);
  brightness += fadeAmount;
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount; 
  }
  delay(30);
}

void customSequence() {
  int pattern[] = {50, 150, 255, 100, 0, 255, 0};
  int patternLength = sizeof(pattern) / sizeof(pattern[0]);

  for (int i = 0; i < patternLength; i++) {
    analogWrite(ledPin, pattern[i]);
    delay(300);
  }
}