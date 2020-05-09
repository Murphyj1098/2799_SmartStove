#include <Arduino.h>

#include "initialization.h"
#include "stove.h"

// Stove class definition
stove::stove()                      // default constructor
{
    state = false;
}

stove::stove(bool stoveState)       // constructor
{
    state = stoveState;
};

bool stove::getState()
{
    return state;
}

void stove::setState(bool stoveState)
{
    state = stoveState;
}


// Turn off stove when called && stove is "on"
void turnStove(void)
{
    if(Stove1.getState())
        analogWrite(MOTOR, 512);   
}

// called when switch changes state - updates state and turns off motor if on
ICACHE_RAM_ATTR void switch_ISR(void)
{
    Stove1.setState(digitalRead(SWITCH));
    if(!digitalRead(SWITCH))
        analogWrite(MOTOR, 0);
}