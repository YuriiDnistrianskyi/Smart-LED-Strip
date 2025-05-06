#include <Arduino.h>
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <FastLED.h>
#include <ArduinoJson.h>

#include "pins.h"
#include "info.h"
#include "RGBCommand.h"
#include "html.h"
#include "handleWebFunctions.h"

AsyncWebServer server(80);
AsyncWebSocket ws("/ws");
CRGB leds[numLeds];

uint8_t valueRed = 250;
uint8_t valueGreen = 125;
uint8_t valueBlue = 100;
bool buttonState = 0;

bool buttonSet = 0;

long lastDebounceTime = 0;
const long debounceTime = 50;


void onClickButton() {
  if((millis() - lastDebounceTime) > debounceTime){
    buttonSet = 1;
    lastDebounceTime = millis();
  }
}


void setup() {
  Serial.begin(115200);
  Serial.println("Go");

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.println("Wifi to connected...");
    delay(1000);
  }
  Serial.println("Connected");
  Serial.println("IP Address: ");
  Serial.println(WiFi.localIP());

  FastLED.addLeds<WS2812, ledPin, GRB>(leds, numLeds);
  FastLED.clear();
  FastLED.show();

  pinMode(buttonPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(buttonPin), onClickButton, FALLING);

  server.addHandler(&ws);
  ws.onEvent(handleWebSocketLED);

  server.on("/", HTTP_GET, [](AsyncWebServerRequest* request) {
    request->send_P(200, "text/html", html);
  });

  server.on("/favicon.ico", HTTP_GET, [](AsyncWebServerRequest* request) {
    request->send_P(200, "text/plain", html);
  });

  server.begin();
}


void loop() {
  if (buttonSet == 1) {
    buttonSet = 0;
    setButtonState();
    notifyClient();
  }
  

  if (buttonState == 1) {
    RGBCommand(valueRed, valueGreen, valueBlue);
  } else {
    RGBCommand(0, 0, 0);
  }
}
