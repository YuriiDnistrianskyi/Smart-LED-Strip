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

    String data = "T: " + String(millis() / 1000) +
                  " R: " + String(colorLeds.red) +
                  " G: " + String(colorLeds.green) +
                  " B: " + String(colorLeds.blue);

    Serial.println(db.size());

    if (db.size() > 100000)
    {
        db.close();
        File dbWrite = LittleFS.open("/database.txt", "w");
        if (!dbWrite)
        {
            Serial.println("Database is not opened (w)");
            return;
        }
        dbWrite.println(data);
        dbWrite.close();
    }
    else
    {
        db.close();
        File dbAppend = LittleFS.open("/database.txt", "a");
        if (!dbAppend)
        {
            Serial.println("Database is not opened (a)");
            return;
        }
        dbAppend.println(data);
    }
}
