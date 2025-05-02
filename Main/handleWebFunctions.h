#ifndef HANDLE_H
#define HANDLE_H

#include <ESPAsyncWebServer.h>
#include <ArduinoJson.h>

extern uint8_t valueRed;
extern uint8_t valueGreen;
extern uint8_t valueBlue;
extern bool buttonState;
extern AsyncWebSocket ws;


void setButtonState() {
  buttonState = !buttonState;
}


void notifyClient() {
  StaticJsonDocument<200> doc;
  doc["red"] = valueRed;
  doc["green"] = valueGreen;
  doc["blue"] = valueBlue;
  doc["button"] = buttonState;
  String json;
  serializeJson(doc, json);
  ws.textAll(json);
}


void handleWebSocketLED(AsyncWebSocket* ws, AsyncWebSocketClient* client, AwsEventType type, void* arg, uint8_t* data, size_t len) {
  if (type == WS_EVT_DATA) {
    data[len] = 0;
    StaticJsonDocument<200> doc;
    DeserializationError error = deserializeJson(doc, (const char*)data);

    if (!error) {
      if (doc["red"]) {
        valueRed = doc["red"];
        valueGreen = doc["green"];
        valueBlue = doc["blue"];
      }

      if (doc["button"] == 1) {
        setButtonState();
      }

      notifyClient();
    }
  }
}

#endif // HANDLE_H
