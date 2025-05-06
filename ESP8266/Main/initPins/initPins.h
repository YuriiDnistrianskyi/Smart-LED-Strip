#ifndef INITPINS_H
#define INITPINS_H

#include <FastLED.h>

#include "pins.h"
#include "../espServer/initWiFi.h"

#define DEBOUNCE_TIME 50

extern void notifyClients();
extern bool buttonState;
extern bool flagSetLeds;
extern bool flagStopLeds;

const uint8_t numberOfLeds = 30; // 60
CRGB leds[numberOfLeds];

volatile uint32_t lastDebounceTime = 0;

void setButtonState()
{
    buttonState = !buttonState;
    buttonState ? flagSetLeds = 1 : flagStopLeds = 1;
}

void IRAM_ATTR handleButton()
{
    uint32_t nowTime = millis();

    if((nowTime - lastDebounceTime) > DEBOUNCE_TIME)
    {
        // Serial.println("Button");
        lastDebounceTime = nowTime;
        notifyClients();
    }
}

void initPins()
{
    FastLED.addLeds<WS2812B, ledPin, GRB>(leds, numberOfLeds);
    FastLED.clear();
    FastLED.show();

    pinMode(buttonPin, INPUT);
    attachInterrupt(digitalPinToInterrupt(buttonPin), handleButton, FALLING);    
}

#endif // INITPINS_H