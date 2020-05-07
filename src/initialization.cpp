#include <Arduino.h>

#include "initialization.h"
#include "serverHandlers.h"

ESP8266WebServer server(255);    // Webserver object that listens for HTTP request on port 255

// initialize GPIO
void gpioInit(void)
{
    pinMode(SWITCH, INPUT);
    pinMode(STOVE, OUTPUT);
}

// initialize WiFi using WiFiManager
void wifiInit(void)
{
    WiFiManager wifiManager;

    // IPAddress _ip = IPAddress(192, 168, 1, 22);     // device's ip (subject to change for ESP-01 v. NodeMCU)
    // IPAddress _gw = IPAddress(192, 168, 1, 1);      // router ip
    // IPAddress _sn = IPAddress(255, 255, 255, 0);    // subnet mask

    // wifiManager.setSTAStaticIPConfig(_ip, _gw, _sn);

    wifiManager.autoConnect();

    Serial.println('\n');
    Serial.print("Connected to ");
    Serial.println(WiFi.SSID());              // Print SSID
    Serial.print("IP address:\t");
    Serial.println(WiFi.localIP());           // Print IP Address of ESP8266
}

// initialize and start web server
void serverInit(void)
{
    server.on("/StoveState", HTTP_GET, handleState);
    server.on("/StoveMotor", HTTP_POST, handleMotor);

    server.onNotFound([](){           // Handle unknown URIs
      server.send(404, "text/plain", "404: Not found");
      });

    server.begin();                   // Start the server

    Serial.println("HTTP server started");
}
