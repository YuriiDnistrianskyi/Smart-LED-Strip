#include <LittleFS.h>

#include "../include/updateDB.h"
#include "../include/color.h"

extern Color colorLeds;

void updateDB()
{
    File db = LittleFS.open("/database.txt", "r");
    if (!db)
    {
        Serial.println("Database is not opened (r)");
        return;
    }

    Serial.println(db.size());
    uint32_t dbSize = db.size();
    db.close();

    String data = "T: " + String(millis() / 1000) +
                  " R: " + String(colorLeds.red) +
                  " G: " + String(colorLeds.green) +
                  " B: " + String(colorLeds.blue);

    File dbUpdate;
    if (dbSize > 10000)
    {
        dbUpdate = LittleFS.open("/database.txt", "w");
    }
    else
    {
        dbUpdate = LittleFS.open("/database.txt", "a");
    }

    if (!dbUpdate)
    {
        Serial.println("Database is not opened (w/a)");
        return;
    }

    dbUpdate.println(data);
    dbUpdate.close();
}
