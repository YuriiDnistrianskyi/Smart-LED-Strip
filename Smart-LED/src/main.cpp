#include <Arduino.h>

#include "../include/color.h"
#include "../include/initPins.h"
#include "../include/initWiFi.h"
#include "../include/getData.h"
#include "../include/ledsFunctions.h"

bool goLighting = true;
Color colorLeds;

bool flagSetLeds = true;
bool flagStopLeds = false;
bool flagNotifyClients = false;

void setup()
{
    Serial.begin(115200);
    getData();
    initPins();
    initWiFi();
}

void loop()
{
    if (flagNotifyClients == true)
    {
        notifyClients();
        flagNotifyClients = false;
    }
    
    if (goLighting == true)
    {
        if (flagSetLeds == true)
        {
            lightingLeds(colorLeds);
            flagSetLeds = false;
        }
    }
    else
    {
        if (flagStopLeds == true)
        {
            stopLeds();
            flagStopLeds = false;
        }
    }
}
