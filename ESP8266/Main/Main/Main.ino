#include <Arduino.h>
//#include <WiFi.h>
#include <FastLED.h>

#include "initPins/initPins.h"
#include "espServer/initWifi.h"

bool programState = 0;

void setup()
{
    Serial.begin(115200);
    initPins();
    initWiFi();
}

void loop()
{
    if (programState == 1)
    {
        Serial.println("Go");
    }
    else 
    {
        Serial.println("Stop");
    }

}
