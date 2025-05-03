#include <Arduino.h>

#include "initPins/initPins.h"
#include "espServer/initWifi.h"
#include "LED/lightingLED.h"

bool buttonState = 0;

uint8_t valueRed = 150;
uint8_t valueGreen = 150;
uint8_t valueBlue = 150;
bool flagSetLeds = 0;
bool flagStopLeds = 0;

void setup()
{
    Serial.begin(115200);
    initPins();
    initWiFi();
}

void loop()
{
    if (buttonState == 1)
    {
        if (flagSetLeds == 1)
        {
            lightingLed(valueRed, valueGreen, valueBlue);
            flagSetLeds = 0;
        }
    }
    else
    {
        if (flagStopLeds == 1)
        {
            FastLED.clear();
            flagStopLeds = 0;
        }
    }
}
