#include <FastLED.h>

#include "../include/config.h"
#include "../include/initPins.h"

extern void notifyClients();
extern bool buttonState;
extern bool flagSetLeds;
extern bool flagStopLeds;

CRGB leds[numberOfLeds];
volatile uint32_t lastDebounceTime = 0;

void setButtonState()
{
    buttonState = !buttonState;
    buttonState ? flagSetLeds = true : flagStopLeds = true;
}

void IRAM_ATTR handleButton()
{
    uint32_t nowTime = millis();

    if((nowTime - lastDebounceTime) > DEBOUNCE_TIME)
    {
        Serial.println("Button");
        lastDebounceTime = nowTime;
        setButtonState();
        notifyClients();
    }
}

void initPins()
{
    FastLED.addLeds<WS2812B, ledPin, GRB>(leds, numberOfLeds);
    FastLED.clear();
    FastLED.show();

    pinMode(buttonPin, INPUT);
    attachInterrupt(digitalPinToInterrupt(buttonPin), handleButton, RISING);    
}