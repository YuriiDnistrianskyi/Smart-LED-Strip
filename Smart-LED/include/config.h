#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>

inline const uint8_t ledPin = D6; 

inline const uint8_t NUMBER_OF_LEDS = 30; // 60

inline const uint32_t DEBOUNCE_TIME = 500000; // ms //

inline const uint8_t EEPROM_SIZE = 16;

inline const char* ssidESP = "Smart-LED (192.168.0.100)";
inline const char* passwordESP = "123123123";

#endif //CONFIG_H
