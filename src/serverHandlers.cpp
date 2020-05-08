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

}

// on POST turns off the stove with motor (GPIO2)
void handleMotor(void)
{

}