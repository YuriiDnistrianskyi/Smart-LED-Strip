#include <Adafruit_NeoPixel.h>

#include "../include/initPins.h"

#include "../include/config.h"
#include "../include/color.h"

extern Color colorLeds;
extern void lightingLeds(Color colorLeds);

Adafruit_NeoPixel strip(NUMBER_OF_LEDS, ledPin, NEO_GRB + NEO_KHZ800);

void initPins()
{
    strip.begin();
    strip.show();
    strip.setBrightness(50);
    lightingLeds(colorLeds);
    Serial.println("init Pins ok");
}
