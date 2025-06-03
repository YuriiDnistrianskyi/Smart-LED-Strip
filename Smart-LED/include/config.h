#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>

inline const uint8_t ledPin = D4;
inline const uint8_t buttonPin = D2; //

inline const uint8_t NUMBER_OF_LEDS = 30; // 60

inline const uint32_t DEBOUNCE_TIME = 500000; // ms //

inline const uint8_t EEPROM_SIZE = 16;

inline const char* ssid = "Test";
inline const char* password = "123123123";

#endif //CONFIG_H
