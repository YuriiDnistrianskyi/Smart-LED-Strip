#ifndef RGBCOMMAND_H
#define RGBCOMMAND_H

#include "info.h"

extern CRGB leds[numLeds];

void RGBCommand(uint32_t valueRED, uint32_t valueGREEN, uint32_t valueBLUE) {
    for (int i = 0; i < numLeds; i++) {
        leds[i] = CRGB(valueRED, valueGREEN, valueBLUE);
    }

    FastLED.show();
}

#endif // RGBCOMMAND_H