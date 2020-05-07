#include <Arduino.h>

#include "initialization.h"

#include "WiFiManager.h"

ESP8266WebServer server(80);    // Webserver object that listens for HTTP request on port 80

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
  server.onNotFound([](){           // Handle unknown URIs
      server.send(404, "text/plain", "404: Not found");
      });

  server.begin();                   // Start the server

  Serial.println("HTTP server started");
}
