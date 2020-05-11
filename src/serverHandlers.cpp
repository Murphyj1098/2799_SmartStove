#include <Arduino.h>

#include "initialization.h"
#include "serverHandlers.h"

// reponds to GET request to root page
void handleRoot(void)
{
    server.send(200, "plain/text", "Hello");
}

// reponds to GET request with state of stove (GPIO0)
void handleState(void)
{
    String state;
    if(stoveState)
        state = "on";
    else if(!stoveState)
        state = "off";

    server.send(200, "text/plain", state);
}

// on POST turns off the stove with motor (GPIO2)
void handleMotor(void)
{
    server.send(200, "plain/text", "\0");

    if(stoveState)                  // turn off stove
        analogWrite(MOTOR, 512); 
}