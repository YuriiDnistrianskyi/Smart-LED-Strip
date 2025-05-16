#ifndef INITPINS_H
#define INITPINS_H

#include <Arduino.h>

extern void notifyClients();
extern bool goLighting;
extern bool flagSetLeds;
extern bool flagStopLeds;
extern volatile bool buttonState;

void setGoLighting();
void IRAM_ATTR handleButton();
void initPins();

#endif // INITPINS_H