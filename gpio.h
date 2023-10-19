#ifndef _GPIO_H_
#define _GPIO_H_

#include <Arduino.h>

class Gpio
{
private:
    bool readable;
    bool writeable;
    bool enabled;
    int pin;

public:
    void Setup(uint8_t spin, bool read);
    uint8_t Read();
    void Write(uint8_t val);
    void SetPin(uint8_t spin);
    Gpio(/* args */);
    ~Gpio();
};



extern Gpio gpio[42];

#endif