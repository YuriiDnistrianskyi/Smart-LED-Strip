#ifndef INITPINS_H
#define INITPINS_H

#include "pins.h"

#define DEBOUNCE_TIME 50

extern bool programState;

const uint8_t numLeds = 30; // 60
CRGB leds[numLeds];

volatile uint32_t lastDebounceTime = 0;

void IRAM_ATTR handleButton()
{
    uint32_t nowTime = millis();

    if((nowTime - lastDebounceTime) > DEBOUNCE_TIME)
    {
        lastDebounceTime = nowTime;
        programState = !programState;
    }
}

void initPins()
{
    // FastLED.addLeds<WS2812, ledPin, GRB>(leds, numLeds);
    // FastLED.clear();
    // FastLED.show();

    pinMode(buttonPin, INPUT);
    attachInterrupt(digitalPinToInterrupt(buttonPin), handleButton, FALLING);    
}

#endif // INITPINS_H