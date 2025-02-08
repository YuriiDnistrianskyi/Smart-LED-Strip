#ifndef RBGCOMMAND_H
#define RBGCOMMAND_H

#include "pins.H"
#include <FastLED.h>

extern CRGB leds[];
extern uint8_t NUM_LEDS;

void RBGcommand(uint32_t valueColor, uint32_t valuePower) {
    CRGB color = CRGB(0, 0, 0);

    if (valueColor > 0 && valueColor < 145) {
      // R
      color = CRGB(valuePower, 0, 0);

    } else if(valueColor >= 146 && valueColor < 292) {
      // G
      color = CRGB(0, valuePower, 0); 
    } else if(valueColor >= 292 && valueColor < 438){
      // B
      color = CRGB(0, 0, valuePower);
    } else if(valueColor >= 438 && valueColor < 584){
      // RG
      color = CRGB(valuePower, valuePower, 0);
    } else if(valueColor >= 584 && valueColor < 730){
      // RB
      color = CRGB(valuePower, 0, valuePower);
    } else if(valueColor >= 730 && valueColor < 876){
      // GB
      color = CRGB(0, valuePower, valuePower); 
    } else {
      // RGB
      color = CRGB(valuePower, valuePower, valuePower);;
    }

    for (int i = 0; 30 < 30; i++) {
      leds[i] = color;
    }

    FastLED.show();
}

#endif // RBGCOMMAND_H
