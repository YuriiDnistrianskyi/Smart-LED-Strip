#ifndef LIGHTINGLED_H
#define LIGHTINGLED_H

#include <Arduino.h>
#include <FastLED.h>

#include "config.h"

extern CRGB leds[numberOfLeds];

void lightingLed(uint8_t valueRed, uint8_t valueGreen, uint8_t valueBlue);

#endif // LIGHTINGLED_H