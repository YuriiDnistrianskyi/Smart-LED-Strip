#include <Arduino.h>

#include "include/config.h"
#include "include/initPins.h"
#include "include/initWiFi.h"
#include "include/lightingLED.h"

bool buttonState = true;

uint8_t valueRed = 150;
uint8_t valueGreen = 150;
uint8_t valueBlue = 150;
bool flagSetLeds = true;
bool flagStopLeds = false;

void setup()
{
    Serial.begin(115200);
    initPins();
    initWiFi();
}

void loop()
{
    if (buttonState == true)
    {
        // if (flagSetLeds == true)
        // {
            lightingLed(valueRed, valueGreen, valueBlue);
        //     flagSetLeds = false;
        // }
    }
    else
    {
        // if (flagStopLeds == true)
        // {
            lightingLed(0, 0, 0);
        //     flagStopLeds = false;
        // }
    }
}
