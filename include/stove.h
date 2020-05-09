#ifndef STOVE_H
#define STOVE_H

/* libraries */


/*constants*/


/*shared global variables*/


/*function prototypes*/
// turns off stove
void turnStove(void);

// called when switch changes state - updates state and turns off motor if on
ICACHE_RAM_ATTR void switch_ISR(void);

/*Stove class declaration*/
class stove
{
    private:
    bool state;

    public:
    stove();                            // default constructor
    stove(bool state);                  // constructor

    bool getState();                    // getter
    void setState(bool stoveState);     // setter
};

#endif