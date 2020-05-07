#ifndef INITIALIZATION_H
#define INITIALIZATION_H

/* libraries */
#include "ESP8266WebServer.h"
#include "WiFiManager.h"

/*constants*/
#define STOVE  3    // GPIO0 pin -> Stove PWM
#define SWITCH 5    // GPIO2 pin -> Switch State

/*shared global variables*/
extern ESP8266WebServer server;      // Webserver object that listens for HTTP request on port 255

/*function prototypes*/
// initialize GPIO
void gpioInit(void);

// initialize WiFi using WiFiManager
void wifiInit(void);

// initialize and start web server
void serverInit(void);

#endif