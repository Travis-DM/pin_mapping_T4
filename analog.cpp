#include <Arduino.h>
#include "analog.h"
#include <ADC.h>
#include <ADC_util.h>
#include "teensy_map.h"
#include "pin_mapping_T4.h"

extern ADC *adc;
Analog::Analog()
{
    enabled = false;
}
void Analog::Setup(int s_pin, uint8_t s_aID)
{
    pin = s_pin;
    aID = s_aID + ADC0ID;
    enabled = true;
}
uint16_t Analog::Read()
{
    //uint8_t packet[4];
    //packet[0] = aID;
    //packet[1] = 2;
    int value;
    if(enabled)
    {
        value = adc->analogRead(pin);
        //packet[2] = (value & 0xff00) >> 8;
        //packet[3] = (value & 0XFF);
    }
    else
    {
        //packet[2] = 0XFF;
        //packet[3] = 0XFF;
        value = 0xFFFF;
    }
    //SerialUSB2.printf("ADC %x:%x:%x\n\r",pin,aID,value);
    //hostInterface.write((byte*)packet,4);

    return value;
}
Analog::~Analog()
{

}
    