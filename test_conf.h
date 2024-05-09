#ifndef _TEST_CONF_H_
#define _TEST_CONF_H_

#include <array>
#include "pin_mapping_T4.h"

#define vPMFile

//This is used to store configurations and variables used for testing when not using a full hardware set


namespace testConf
{

    constexpr std::array<uint8_t, 42> pinTestArray = 
    {
        0x08,         //IO 0
        0x08,         //IO 1
        0x00,         //IO 2
        0x00,         //IO 3
        0x00,         //IO 4
        0x00,         //IO 5
        0x00,         //IO 6
        0x0A,         //IO 7
        0x0A,         //IO 8
        0x20,         //IO 9
        0x20,         //IO 10
        0x20,         //IO 11
        0x00,         //IO 12
        0x00,         //IO 13
        0x10,         //IO 14
        0x10,         //IO 15
        0x10,         //IO 16
        0x00,         //IO 17
        0x00,         //IO 18
        0x00,         //IO 19
        0x00,         //IO 20
        0x00,         //IO 21
        0x08,         //IO 22
        0x08,         //IO 23
        0x0E,         //IO 24
        0x0E,         //IO 25
        0xFF,         //IO 26
        0xFF,         //IO 27
        0xFF,         //IO 28
        0xFF,         //IO 29
        0xFF,         //IO 30
        0xFF,         //IO 31
        0xFF,         //IO 32
        0xFF,         //IO 33
        0xFF,         //IO 34
        0xFF,         //IO 35
        0xFF,         //IO 36
        0xFF,         //IO 37
        0xFF,         //IO 38
        0xFF,         //IO 39
        0xFF,         //IO 40
        0xFF          //IO 40
    };

    constexpr std::array<uint8_t, 42> priorityTestArray = 
    {
        2,
        2,
        3,
        3,
        3,
        3,
        3,
        2,
        2,
        2,
        2,
        2,
        2,
        3,
        3,
        3,
        2,
        3,
        3,
        3,
        2,
        2,
        1,
        1,
        2,
        2,
        2,
        3,
        3,
        3,
        2,
        2,
        2,
        2,
        2,
        2,
        2,
        3,
        2,
        3,
        2,
        2
    };

    

    uint8_t sn_first = 55;
    uint8_t sn_second = 88;
    uint8_t sn_third = 27;
    uint8_t sn_forth = 62;
 
    uint8_t fw_major = 0;
    uint8_t fw_minor = 1;
    uint8_t fw_bugfix = 12;
    uint8_t fw_test = 1;

    uint8_t numPorts = 2;
    uint8_t usbConf = 1;

    uint16_t mChecksum = 0x55;
    uint16_t pChecksum = 0xAA;

    uint8_t bi_first = 05;
    uint8_t bi_second = 44;
    uint8_t bi_third = 82;
    uint8_t bi_forth = 12;


}


#endif