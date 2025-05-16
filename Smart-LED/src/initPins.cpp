#include <FastLED.h>

#include "../include/config.h"
#include "../include/initPins.h"

CRGB leds[NUMBER_OF_LEDS];
volatile uint32_t lastDebounceTime = 0;

void setGoLighting()
{
    goLighting = !goLighting;
    goLighting ? flagSetLeds = true : flagStopLeds = true;
}

void IRAM_ATTR handleButton()
{
    uint32_t nowTime = micros();

    if((nowTime - lastDebounceTime) > DEBOUNCE_TIME)
    {
        lastDebounceTime = nowTime;
        buttonState = !buttonState;
    }
}

void initPins()
{
    FastLED.addLeds<WS2812B, ledPin, GRB>(leds, NUMBER_OF_LEDS);
    FastLED.clear();
    FastLED.show();

    pinMode(buttonPin, INPUT);
    attachInterrupt(digitalPinToInterrupt(buttonPin), handleButton, RISING);    
}