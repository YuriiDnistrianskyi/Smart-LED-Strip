#include "pins.h"
#include "RBGcommand.h"

unsigned long lastDebounceTime = 0;
const long debounceTime = 50;

bool buttonState = 0;
uint32_t potValueColor = 0;
uint32_t potValuePower = 128;

void buttonFunc() {
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
  attachInterrupt(digitalPinToInterrupt(buttonPin), buttonFunc, FALLING);
}


void loop() {
  buttonState ? potValueColor = analogRead(potPin) : potValuePower = analogRead(potPin)/4;

  RBGcommand(potValueColor, potValuePower);
}
