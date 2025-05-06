#ifndef LIGHTINGLED_H
#define LIGHTINGLED_H

extern const uint8_t numberOfLeds;
extern CRGB leds[numberOfLeds];

void lightingLed(uint8_t valueRed, uint8_t valueGreen, uint8_t valueBlue)
{
    FastLED.clear();
    for (int i = 0; i < numberOfLeds; i++)
    {
        leds[i] = CRGB(valueRed, valueGreen, valueBlue);
    }
    FastLED.show();
}


#endif // LIGHTINGLED_H