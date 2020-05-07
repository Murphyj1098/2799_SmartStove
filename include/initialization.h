#ifndef INITIALIZATION_H
#define INITIALIZATION_H

/*constants*/
#define STOVE  3    // GPIO0 pin -> Stove PWM
#define SWITCH 5    // GPIO2 pin -> Switch State

/*shared global variables*/


/*function prototypes*/
// initialize GPIO
void gpioInit(void);

#endif