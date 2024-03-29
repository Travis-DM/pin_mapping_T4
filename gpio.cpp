#include <Arduino.h>
#include "gpio.h"
#include "teensy_map.h"

void Gpio::Setup(uint8_t spin, bool read)
{
    pin = spin;
    enabled = true;
    if (!read)
    {
        writeable = true;
        pinMode(spin,OUTPUT);
    }
    readable = true;
}
void Gpio::SetPin(uint8_t spin)
{
    pin = spin;
}
uint8_t Gpio::Read()
{
    uint8_t packet[2];
    
    packet[0] = pin;
    if (enabled)
    {
        if(digitalRead(pin) == HIGH)
        {
            //Send 1
            packet[1] = 1;
        }
        else
        {
            packet[1] = 0;
        }
    }
    else
    {
        packet[1] = 0X02;
    }
    //hostInterface.write((byte*)packet,2);
    return packet[1];
}

void Gpio::Write(uint8_t val)
{
    uint8_t packet[1];
    packet[0] = pin;

    if (writeable)
    {
        if(val == 0)
        {
            digitalWrite(pin,LOW);
            packet[1] = 0;
        }
        else
        {
            digitalWrite(pin,HIGH);
            packet[1] = 1;
        }
    }
    else if(readable)
    {
            packet[1] = 0x03;
    }
    else
    {
        packet[1] = 0X01;
    }
    //hostInterface.write((byte*)packet,2);
}


Gpio::Gpio(/* args */)
{
    readable = false;
    writeable = false;
    enabled = false;
}

Gpio::~Gpio()
{
}