#ifndef LEDSFUNCTIONS_H
#define LEDSFUNCTIONS_H

#include <Arduino.h>
#include <FastLED.h>

#include "config.h"
#include "color.h"

extern CRGB leds[NUMBER_OF_LEDS];

void lightingLeds(Color colorForLeds);

void clearLeds();

#endif // LEDSFUNCTIONS_H