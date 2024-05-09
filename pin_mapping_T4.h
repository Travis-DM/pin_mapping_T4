#ifndef _PIN_MAPPING_T4_H_
#define _PIN_MAPPING_T4_H_

#include <Arduino.h>



#define LED0ID      0X2A
#define LED1ID      0X2B
#define LED2ID      0X2C
#define LED3ID      0X2D

#define GPIORID     0X2E
#define GPIOWID     0X2F

#define VERSIONID   0X30

#define LCDID       0X31 

#define GETCFGID    0X32

#define USB_USARTID 0X3C
#define DEBUGID     0X3D

#define RESETID     0X3E

#define MEMORYID    0X3F

#define CAN0ID      0X40
#define CAN1ID      0X41
#define CAN2ID      0X42
#define CANFDID     0X43

#define LINID       0X44

#define SPI0ID      0X45
#define SPI1ID      0X46

#define USART0ID    0X47
#define USART1ID    0X48
#define USART2ID    0X49
#define USART3ID    0X4A
#define USART4ID    0X4B
#define USART5ID    0X4C
#define USART6ID    0X4D
#define USART7ID    0X4E

#define I2C0ID      0X4F
#define I2C1ID      0X50 
#define I2C2ID      0X51 

#define ETHERID     0X52

#define ADC0ID      0X53
#define ADC1ID      0X54
#define ADC2ID      0X55
#define ADC3ID      0X56
#define ADC4ID      0X57
#define ADC5ID      0X58
#define ADC6ID      0X59
#define ADC7ID      0X5A
#define ADC8ID      0X5B
#define ADC9ID      0X5C
#define ADCAID      0X5D
#define ADCBID      0X5E
#define ADCCID      0X5F
#define ADCDID      0X60
#define ADCEID      0X61
#define ADCFID      0X62
#define ADC10ID     0X63 
#define ADC11ID     0X64

#define PWM0ID      0X65 
#define PWM1ID      0X66
#define PWM2ID      0X67 
#define PWM3ID      0X68 
#define PWM4ID      0X69 
#define PWM5ID      0X6A 
#define PWM6ID      0X6B 
#define PWM7ID      0X6C 
#define PWM8ID      0X6D 
#define PWM9ID      0X6E 
#define PWMAID      0X6F 
#define PWMBID      0X70
#define PWMCID      0X71 
#define PWMDID      0X72 
#define PWMEID      0X73 
#define PWMFID      0X74 
#define PWM10ID     0X75 
#define PWM11ID     0X76 
#define PWM12ID     0X77
#define PWM13ID     0X78 
#define PWM14ID     0X79 
#define PWM15ID     0X7A 
#define PWM16ID     0X7B 
#define PWM17ID     0X7C 
#define PWM18ID     0X7D 
#define PWM19ID     0X7E 

#define HEARTBEAT   0X7F 


#define PACKED __attribute__ ((packed))

struct _serial_number_type
{
    uint8_t first;
    uint8_t second;
    uint8_t third;
    uint8_t forth;
}PACKED;
struct _firware_version_t
{
    uint8_t major;
    uint8_t minor;
    uint8_t bugfix;
    uint8_t test;
}PACKED;


struct _sys_info_t
{
    _serial_number_type serial_number;
    _serial_number_type board_id;
    _firware_version_t  firmware_ver;
    uint8_t             ports;
    uint8_t             usbconf;
    uint16_t            unused;
    uint16_t            memory_checksum;
    uint16_t            program_checksum;
}PACKED;

struct _sys_config_t
{
    _sys_info_t      sys_info;
    uint8_t   pin_config[42];
    uint8_t   pin_priority[42];
}PACKED;


#define _GPO        0x00
#define _GPI        0x01
#define _CAN        0x08 
#define _USART      0x0A
#define _LIN        0X0B 
#define _SPI        0x0C
#define _I2C        0x0E 
#define _ADC        0x10
#define _PWM        0x20
#define _LEDM0      0X40
#define _LEDM1      0X52



bool can0EN(void);
bool can1EN(void);
bool can2EN(void);

static uint8_t gpoCount;
static uint8_t gpiCount;
static uint8_t gpioCount;
static uint8_t adcCount;
static uint8_t pwmCount;


//static uint8_t gpo[40];
//static uint8_t gpi[40];
//static uint8_t adc_pin[16];
//static uint8_t pwm[29];


void parsePins(uint8_t *pinCon, int pinCount);
void parsePins(uint8_t *pinCon);
bool usart0EN(void);
bool usart1EN(void);
bool usart2EN(void);
bool usart3EN(void);
bool usart4EN(void);
bool usart5EN(void);
bool usart6EN(void);
bool usart7EN(void);

bool led0EN(void);
bool led1EN(void);
bool led2EN(void);
bool led3EN(void);

bool i2c0EN(void);
bool i2c1EN(void);
bool i2c2EN(void);

//
int getPinMap(uint8_t *pinCon);

_sys_config_t getSysConfig(void);
int getPriorityMap(uint8_t *priorityMap);

#endif
