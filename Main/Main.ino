#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>
#include <FastLED.h>

#include "pins.h"
#include "info.h"
#include "RGBCommand.h"
#include "html.h"

WebServer server(80);
CRGB leds[numLeds];


void handleRoot() {
  server.send(200, "text/html", html);
}

void setup() {
  FastLED.addLeds<WS2812, ledPin, GRB>(leds, numLeds);
  FastLED.clear();
  FastLED.show();

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

  server.on("/", handleRoot);
  server.begin();
}

void loop() {
  server.handleClient();
  
  RGBCommand(100, 100, 100);
}
