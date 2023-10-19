#ifndef _ANALOG_H_
#define _ANALOG_H_
#include <Arduino.h>

class Analog
{



public:

    Analog();
    void Setup(int pin, uint8_t s_aID);
    uint16_t Read();
    ~Analog();
    

private:
    
    bool enabled;
    int pin;
    uint8_t aID;


};

extern Analog analog[16];

#endif