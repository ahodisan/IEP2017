#ifndef SPI_H
#define SPI_H

#include <stdint.h>
#include "serial.h"

class SPI: public Serial
{
    SPI(uint8_t BitOrder, uint8_t DataMode, uint16_t ClockDivider, uint8_t chipSelect, uint8_t ChipSelectPolarity);
    uint8_t transfer(uint8_t data);
};


#endif // SPI_H

