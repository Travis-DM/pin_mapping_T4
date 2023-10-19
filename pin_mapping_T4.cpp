#include <Arduino.h>
#include "teensy_map.h"
#include "pin_mapping_T4.h"
#include "analog.h"
#include "gpio.h"
#include "pwm.h"

bool busart0EN;
bool busart1EN;
bool busart2EN;
bool busart3EN;
bool busart4EN;
bool busart5EN;
bool busart6EN;
bool busart7EN;


bool bcan0EN;
bool bcan1EN;
bool bcan2EN;

bool bled0EN;
bool bled1EN;
bool bled2EN;
bool bled3EN;

bool bi2c0EN;
bool bi2c1EN;
bool bi2c2EN;

void parsePins(u_int8_t *pinCon)
{
    parsePins(pinCon, 42);
}


void parsePins(u_int8_t *pinCon, int pinCount){
    busart0EN = false;
    busart1EN = false;
    busart2EN = false;
    busart3EN = false;
    busart4EN = false;
    busart5EN = false;
    busart6EN = false;
    busart7EN = false;

    bcan0EN = false;
    bcan1EN = false;
    bcan2EN = false;

    bled0EN = false;
    bled1EN = false;
    bled2EN = false;
    bled3EN = false;

    bi2c0EN = false;
    bi2c1EN = false;
    bi2c2EN = false;

    gpoCount = 0;
    gpiCount = 0;
    gpioCount = 0;
    adcCount = 0;
    pwmCount = 0;


    for(int x = 0; x < pinCount;x++)
    {
        gpio[x].SetPin(x);
        switch (pinCon[x])
        {
        case _GPO:
            gpio[x].Setup(x,false);
            gpoCount++;
            gpioCount++;
            debug.printf("Pin: %d is Set as digital output\n",x);
            break;
        case _GPI:
            gpio[x].Setup(x,true);
            gpiCount++;
            gpioCount++;
            debug.printf("Pin: %d is Set as digital input\n",x);
            break;
        case _CAN:
            debug.printf("Pin: %d is Set as CAN\n",x);
            switch (x)
            {
                case 0:
                case 1:
                    bcan1EN = true;
                    debug.println("CAN1 Enabled");
                    break;
                case 22:
                case 23:
                    bcan0EN = true;
                    debug.println("CAN0 Enabled");
                    break;
                case 30:
                case 31:
                    bcan2EN = true;
                    debug.println("CAN2 Enabled");
                    break;
            }
            break;
        case _LEDM0:
            debug.printf("Pin: %d is Set as LED\n",x);
            
            pinMode(x,OUTPUT);
            bled0EN = true;
            break;
        case _USART:
            debug.printf("Pin: %d is Set as USART\n",x);
            switch (x)
            {
                case 0:
                case 1:
                    //read config
                    USART0.begin(115200);
                    busart0EN = true;
                    debug.println("USART0 Enabled");
                    break;
                case 7:
                case 8:
                    USART1.begin(115200);
                    busart1EN = true;
                    debug.println("USART1 Enabled");
                    break;
                case 14:
                case 15:
                    USART2.begin(115200);
                    busart2EN = true;
                    debug.println("USART2 Enabled");
                    break;
                case 16:
                case 17:
                    USART3.begin(115200);
                    busart3EN = true;
                    debug.println("USART3 Enabled");
                    break;
                case 20:
                case 21:
                    USART4.begin(115200);
                    busart4EN = true;
                    debug.println("USART4 Enabled");
                    break;
                case 24:
                case 25:
                    //USART0.begin(115200);
                    //usart0EN = true;
                    debug.println("Error USART5 Is USED for I2C");
                    break;
                case 28:
                case 29:
                    USART6.begin(115200);
                    busart6EN = true;
                    debug.println("USART6 Enabled");
                    break;
                case 34:
                case 35:
                    USART7.begin(115200);
                    busart7EN = true;
                    debug.println("USART7 Enabled");
                    break;  
            }
            break;
            case _LIN:
            debug.printf("Pin: %d is Set as LIN\n",x);
            switch (x)
            {
                case 0:
                case 1:
                    USART0.begin(115200);
                    busart0EN = true;
                    debug.println("LIN0 Enabled");
                    break;
                case 7:
                case 8:
                    USART1.begin(115200);
                    busart1EN = true;
                    debug.println("LIN1 Enabled");
                    break;
                case 14:
                case 15:
                    USART2.begin(115200);
                    busart2EN = true;
                    debug.println("LIN2 Enabled");
                    break;
                case 16:
                case 17:
                    USART3.begin(115200);
                    busart3EN = true;
                    debug.println("LIN3 Enabled");
                    break;
                case 20:
                case 21:
                    USART4.begin(115200);
                    busart4EN = true;
                    debug.println("LIN4 Enabled");
                    break;
                case 24:
                case 25:
                    //USART0.begin(115200);
                    //usart0EN = true;
                    debug.println("Error USART5 Is USED for I2C");
                    break;
                case 28:
                case 29:
                    USART6.begin(115200);
                    busart6EN = true;
                    debug.println("LIN6 Enabled");
                    break;
                case 34:
                case 35:
                    USART7.begin(115200);
                    busart7EN = true;
                    debug.println("LIN7 Enabled");
                    break;  
            }
            break;
        case _SPI:
            debug.printf("Pin: %d is Set as SPI\n",x);
            break;
        case _I2C:
            switch (x)
            {
            case 18:
            case 19:
                bi2c0EN = true;
                debug.printf("Pin: %d is Set as I2C0\n",x);
                break;
            case 16:
            case 17:
                bi2c1EN = true;
                debug.printf("Pin: %d is Set as I2C1\n",x);
                break;
            case 24:
            case 25:
                bi2c2EN = true;
                debug.printf("Pin: %d is Set as I2C2\n",x);
                break;
            default:
                break;
            }
            debug.printf("Pin: %d is Set as I2C\n",x);
            break;
        case _ADC:
            analog[adcCount].Setup(x,adcCount);
            adcCount++;
            debug.printf("Pin: %d is Set as ADC\n",x);
            break;
        case _PWM:
            pwm[pwmCount].Setup(x,x+PWM0ID);
            pwmCount++;
            debug.printf("Pin: %d is Set as PWM\n",x);
            break;
        default:
            debug.printf("Pin: %d is Unknown\n",x);
            break;
        }
    }
    debug.printf("There are %d digital out pins\n",gpoCount);
    debug.printf("There are %d digital in pins\n",gpiCount);
    debug.printf("There are %d analog in pins\n",adcCount);
    debug.printf("There are %d pwm pins\n",pwmCount);

}

bool usart0EN(void)
{
    return busart0EN;
}
bool usart1EN(void)
{
    return busart1EN;
}
bool usart2EN(void)
{
    return busart2EN;
}
bool usart3EN(void)
{
    return busart3EN;
}
bool usart4EN(void)
{
    return busart4EN;
}
bool usart5EN(void)
{
    return busart5EN;
}
bool usart6EN(void)
{
    return busart6EN;
}
bool usart7EN(void)
{
    return busart7EN;
}


bool can0EN(void)
{
    return bcan0EN;
}
bool can1EN(void)
{
    return bcan1EN;
}
bool can2EN(void)
{
    return bcan2EN;
}

bool led0EN(void)
{
    return bled0EN;
}

bool led1EN(void)
{
    return bled1EN;
}

bool led2EN(void)
{
    return bled2EN;
}

bool led3EN(void)
{
    return bled3EN;
}

bool i2c0EN(void)
{
    return bi2c0EN;
}

bool i2c1EN(void)
{
    return bi2c1EN;
}

bool i2c2EN(void)
{
    return bi2c2EN;
}
