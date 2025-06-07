#include <Adafruit_NeoPixel.h>

#include "../include/ledsFunctions.h"

#include "../include/config.h"
#include "../include/color.h"

extern Adafruit_NeoPixel strip;

void lightingLeds(Color colorLeds)
{
    strip.clear();
    for (int i = 0; i < NUMBER_OF_LEDS; i++)
    {
        strip.setPixelColor(i, strip.Color(colorLeds.red, colorLeds.green, colorLeds.blue));
    }
    strip.show();
}

void stopLeds()
{
    strip.clear();
    strip.show();
}
