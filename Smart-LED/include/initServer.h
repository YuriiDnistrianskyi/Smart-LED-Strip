#ifndef INIT_SERVER_H
#define INIT_SERVER_H

#include <ESPAsyncWebServer.h>

void setGoLighting();
void notifyClients();
void handleWebSocket(AsyncWebSocket* ws, AsyncWebSocketClient* client, AwsEventType type, void* arg, uint8_t* data, size_t len);
void initServer();

#endif // INIT_SERVER_H
