#include <FastLED.h>

#include "../include/config.h"
#include "../include/color.h"
#include "../include/ledsFunctions.h"

void lightingLeds(Color colorForLeds)
{
    FastLED.clear();
    for (int i = 0; i < NUMBER_OF_LEDS; i++)
    {
        leds[i] = CRGB(colorForLeds.red, colorForLeds.green, colorForLeds.blue);
    }
    FastLED.show();
}

void clearLeds()
{
    FastLED.clear();
    FastLED.show();
}
