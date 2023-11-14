#include <Arduino.h>
#include "pwm.h"
#include "teensy_map.h"


PWM::PWM(/* args */)
{
    enabled = false;
}

PWM::~PWM()
{
}

void PWM::Setup(int pin, uint8_t s_pID)
{
    Setup(pin,s_pID,8);
}
void PWM::Setup(int s_pin, uint8_t s_pID, uint8_t res)
{
    pID = s_pID;
    pin = s_pin;
    Set_Resolution (res);
}
void PWM::Write(uint16_t value)
{
    debugger.msg(3,"Writing %x to pin %d",value,pin);
    analogWrite(pin,value);
}
void PWM::Set_Resolution(uint8_t res)
{
    analogWriteResolution(res);
}