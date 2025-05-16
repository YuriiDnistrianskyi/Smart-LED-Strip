#include <EEPROM.h>

#include "../include/getData.h"

#include "../include/config.h"

void getData()
{ 
    EEPROM.begin(EEPROM_SIZE);
    EEPROM.get(0, colorLeds);

    if (colorLeds.initFlag != 1324) 
    {
        colorLeds.initFlag = 1324;
        colorLeds.red = 150;
        colorLeds.green = 0;
        colorLeds.blue = 0;

        EEPROM.put(0, colorLeds);
        EEPROM.commit();
    }

}