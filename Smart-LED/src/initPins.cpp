#include <Adafruit_NeoPixel.h>

#include "../include/initPins.h"

#include "../include/config.h"
#include "../include/color.h"

extern Color colorLeds;
extern void notifyClients();
extern void lightingLeds(Color colorLeds);
extern bool goLighting;
extern bool flagSetLeds;
extern bool flagStopLeds;
extern bool flagNotifyClients;

Adafruit_NeoPixel strip(NUMBER_OF_LEDS, ledPin, NEO_GRB + NEO_KHZ800);
volatile uint32_t lastDebounceTime = 0;

void setGoLighting()
{
    goLighting = !goLighting;
    goLighting ? flagSetLeds = true : flagStopLeds = true;
}

void IRAM_ATTR handleButton()
{
    uint32_t nowTime = millis();

    if((nowTime - lastDebounceTime) > DEBOUNCE_TIME)
    {
        Serial.println("Button pressed");
        lastDebounceTime = nowTime;
        setGoLighting();
        flagNotifyClients = true;
    }
}

void initPins()
{
    pinMode(buttonPin, INPUT);
    attachInterrupt(digitalPinToInterrupt(buttonPin), handleButton, RISING);

    strip.begin();
    strip.show();
    strip.setBrightness(50);
    lightingLeds(colorLeds);
}
