#include <FastLED.h>

#include "pins.h"
#include "RBGcommand.h"

#define NUM_LEDS 30 // 60

unsigned long lastDebounceTime = 0;
const long debounceTime = 50;

bool buttonState = 0;
uint32_t potValueColor = 0;
uint32_t lastValueColor = 0;
uint32_t potValuePower = 128;
uint32_t lastValuePower = 128;


CRGB leds[NUM_LEDS];

void buttonFunc() {
  unsigned long currentTime = millis();

  if (currentTime - lastDebounceTime > debounceTime) {
    buttonState = !buttonState;
    lastDebounceTime = currentTime;
  }
}


void setup() {
  pinMode(buttonPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(buttonPin), buttonFunc, FALLING);

  FastLED.addLeds<WS2812, ledPin, GRB>(leds, NUM_LEDS);
  FastLED.clear();
  FastLED.show();
}


void loop() {
  buttonState ? potValueColor = analogRead(potPin) : potValuePower = analogRead(potPin)/4;

  if (abs((int)lastValueColor - (int)potValueColor) > 10 || abs((int)lastValuePower - (int)potValuePower) > 10) {
    RBGcommand(potValueColor, potValuePower);
    lastValueColor = potValueColor;
    lastValuePower = potValuePower;
  }
}
