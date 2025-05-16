#include <Arduino.h>

#include "../include/config.h"
#include "../include/color.h"
#include "../include/initPins.h"
#include "../include/initWiFi.h"
#include "../include/getData.h"
#include "../include/ledsFunctions.h"
// #include "../include/lightingLED.h"

Color colorLeds;

// uint8_t valueRed = 150;
// uint8_t valueGreen = 150;
// uint8_t valueBlue = 150;

bool goLighting = true;
bool flagSetLeds = true;
bool flagStopLeds = false;
volatile bool buttonState = false;

void setup()
{
    Serial.begin(115200);
    initWiFi();
    initPins();
    getData();
}

void loop()
{
    if (buttonState == true) 
    {
        buttonState = false;
        setGoLighting();
        notifyClients();
    }


    if (goLighting == true)
    {
        // if (flagSetLeds == true)
        // {
            lightingLeds(colorLeds);
            // lightingLed(valueRed, valueGreen, valueBlue);
        //     flagSetLeds = false;
        // }
    }
    else
    {
        // if (flagStopLeds == true)
        // {
            clearLeds();
            // lightingLed(0, 0, 0);
        //     flagStopLeds = false;
        // }
    }
}
