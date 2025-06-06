#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>

#include "../include/initWiFi.h"

#include "../include/config.h"
#include "../include/color.h"
#include "../include/initServer.h"

IPAddress local_IP(192, 168, 0, 100);
IPAddress gateway(192, 168, 0, 1);
IPAddress subnet(255, 255, 255, 0);

void initWiFi()
{
    WiFi.softAPConfig(local_IP, gateway, subnet);
    WiFi.softAP(ssidESP, passwordESP);

    initServer();
}