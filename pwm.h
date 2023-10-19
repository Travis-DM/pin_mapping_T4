#ifndef _PWM_H_
#define _PWM_H_
#include <Arduino.h>

class PWM
{
private:
    bool enabled;
    int pin;
    uint8_t pID;

public:
    PWM(/* args */);
    ~PWM();
    void Setup(int pin, uint8_t s_pID);
    void Setup(int pin, uint8_t s_pID, uint8_t res);
    void Write(uint16_t value);
    void Set_Resolution(uint8_t res);
};  


extern PWM pwm[29];

void pwm_test ();

#endif