#ifndef INITWIFI_H
#define INITWIFI_H

#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <ArduinoJson.h>

#include "infoWiFi.h"
#include "html.h"

AsyncWebServer server(80);
AsyncWebSocket ws("/ws");

extern void setButtonState();
extern uint8_t valueRed;
extern uint8_t valueGreen;
extern uint8_t valueBlue;
extern bool buttonState;
extern bool flagSetLeds;
extern bool flagStopLeds;

void notifyClients()
{
    StaticJsonDocument<200> doc;
    doc["red"] = valueRed;
    doc["green"] = valueGreen;
    doc["blue"] = valueBlue;
    doc["button"] = buttonState;
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
                // Serial.println("Set color");
                valueRed = doc["red"];
                valueGreen = doc["green"];
                valueBlue = doc["blue"];
                flagSetLeds = 1;
            }

            if (doc["setState"])
            {
                // Serial.println("Button on sait");
                setButtonState();
            }

            notifyClients();
        }
    }
}

void initWiFi()
{
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED)
    {
        Serial.println("Connecting...");
        delay(1000);
    }
    Serial.println("Connected");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());

    server.addHandler(&ws);
    ws.onEvent(handleWebSocket);

    server.on("/", HTTP_GET, [](AsyncWebServerRequest* request)
    {
        request->send(200, "text/html", html);
    });

    server.on("/favicon.ico", HTTP_GET, [](AsyncWebServerRequest* request){
        request->send(200, "text/plain", "Favicon");
    });    

    server.begin();
}

#endif // INITWIFI_H