#include <ESPAsyncWebServer.h>
#include <ArduinoJson.h>
#include <LittleFS.h>
#include <EEPROM.h>

#include "../include/initServer.h"

#include "../include/Color.h"

extern Color colorLeds;
extern void setGoLighting();
extern bool goLighting;
extern bool flagSetLeds;
extern bool flagStopLeds;

AsyncWebServer server(80);
AsyncWebSocket ws("/ws");

void setGoLighting()
{
    goLighting = !goLighting;
    goLighting ? flagSetLeds = true : flagStopLeds = true;
}

void updateDB()
{
    File database = LittleFS.open("/database.txt", "a");
    if (!database)
    {
        Serial.println("Database is not opened");
        return;
    }

    String data = "\nTime: " + String(millis() / 1000) + " seconds\n" +
                  "R: " + String(colorLeds.red) +
                  " G: " + String(colorLeds.green) +
                  " B: " + String(colorLeds.blue);

    database.print(data);
    database.close();
}

void notifyClients()
{
    StaticJsonDocument<200> doc;

    doc["red"] = colorLeds.red;
    doc["green"] = colorLeds.green;
    doc["blue"] = colorLeds.blue;

    doc["button"] = goLighting;
    String json;
    serializeJson(doc, json);
    ws.textAll(json);
}

void handleWebSocket(AsyncWebSocket* ws, AsyncWebSocketClient* client, AwsEventType type, void* arg, uint8_t* data, size_t len)
{
    if (type == WS_EVT_DATA)
    {
        data[len] = 0;
        StaticJsonDocument<200> doc;
        DeserializationError error = deserializeJson(doc, (const char*)data);

        if (!error)
        {
            if (doc["red"])
            {
                colorLeds.red = doc["red"];
                colorLeds.green = doc["green"];
                colorLeds.blue = doc["blue"];
                EEPROM.put(0, colorLeds);
                EEPROM.commit();

                flagSetLeds = true;
                updateDB();
            }

            if (doc["setState"])
            {
                setGoLighting();
            }

            notifyClients();
        }
    }
}

void initServer()
{
    if (!LittleFS.begin())
    {
        Serial.println("LittleFS dont mount");
        return;
    }

    ws.onEvent(handleWebSocket);
    server.addHandler(&ws);

    server.on("/", HTTP_GET, [](AsyncWebServerRequest* request)
    {
        request->send(LittleFS, "/index.html", "text/html");
    });

    server.on("/style.css", HTTP_GET, [](AsyncWebServerRequest* request)
    {
        request->send(LittleFS, "/style.css", "text/css");
    });

    server.on("/script.js", HTTP_GET, [](AsyncWebServerRequest* request)
    {
        request->send(LittleFS, "/script.js", "application/javascript");
    });

    server.on("/database", HTTP_GET, [](AsyncWebServerRequest* request)
    {
        request->send(LittleFS, "/database.txt", "text/plain");
    });

    server.on("/favicon.ico", HTTP_GET, [](AsyncWebServerRequest* request){
        request->send(200, "text/plain", "Favicon");
    });    

    server.begin();
}
