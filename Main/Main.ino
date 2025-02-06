#include "pins.h"

unsigned long lastDebounceTime = 0;
const long debounceTime = 50;

bool buttonState = 0;
int potValue = 0;

void func() {
  unsigned long currentTime = millis();

  if (currentTime - lastDebounceTime > debounceTime) {
    buttonState = !buttonState;
    lastDebounceTime = currentTime;
  }
}

void setup() {
  pinMode(ledPinBlue, OUTPUT);
  pinMode(ledPinGreen, OUTPUT);
  pinMode(ledPinRed, OUTPUT);

  pinMode(buttonPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(buttonPin), func, FALLING);
}

void loop() {
  potValue = analogRead(potPin);

  if(buttonState == 1) {

    if (potValue < 170) {
      // R
      digitalWrite(ledPinRed, HIGH);
      digitalWrite(ledPinGreen, LOW);
      digitalWrite(ledPinBlue, LOW);
    } else if(potValue >= 170 && potValue < 340) {
      // G
      digitalWrite(ledPinRed, LOW);
      digitalWrite(ledPinGreen, HIGH);
      digitalWrite(ledPinBlue, LOW);
    } else if(potValue >= 340 && potValue < 510){
      // B
      digitalWrite(ledPinRed, LOW);
      digitalWrite(ledPinGreen, LOW);
      digitalWrite(ledPinBlue, HIGH);
    } else if(potValue >= 510 && potValue < 680){
      // RG
      digitalWrite(ledPinRed, HIGH);
      digitalWrite(ledPinGreen, HIGH);
      digitalWrite(ledPinBlue, LOW);
    } else if(potValue >= 680 && potValue < 850){
      // RB
      digitalWrite(ledPinRed, HIGH);
      digitalWrite(ledPinGreen, LOW);
      digitalWrite(ledPinBlue, HIGH);
    } else if(potValue >= 859 && potValue < 1000){
      // GB
      digitalWrite(ledPinRed, LOW);
      digitalWrite(ledPinGreen, HIGH);
      digitalWrite(ledPinBlue, HIGH);
    } else {
      digitalWrite(ledPinRed, HIGH);
      digitalWrite(ledPinGreen, HIGH);
      digitalWrite(ledPinBlue, HIGH);
    }

  } else {
    digitalWrite(ledPinRed, LOW);
    digitalWrite(ledPinGreen, LOW);
    digitalWrite(ledPinBlue, LOW);
  }
  

/*
 switch (buttonState) {
  case 0: digitalWrite(ledPinBlue, HIGH); digitalWrite(ledPinGreen, LOW); digitalWrite(ledPinRed, LOW); break;
  case 1: digitalWrite(ledPinGreen, HIGH); digitalWrite(ledPinBlue, LOW); digitalWrite(ledPinRed, LOW); break;
  case 2: digitalWrite(ledPinRed, HIGH); digitalWrite(ledPinBlue, LOW); digitalWrite(ledPinGreen, LOW); break;
 }
*/
}
