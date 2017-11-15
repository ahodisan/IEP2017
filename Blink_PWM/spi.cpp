#include "serial.h"
#include "spi.h"
#include <stdint.h>
#include <bcm2835.h>

SPI::SPI(uint8_t BitOrder, uint8_t DataMode, uint16_t ClockDivider, uint8_t chipSelect, uint8_t ChipSelectPolarity)
{
    bcm2835_spi_setBitOrder(BitOrder);      // The default
    bcm2835_spi_setDataMode(DataMode);                   // The default
    bcm2835_spi_setClockDivider(ClockDivider); // The default
    bcm2835_spi_chipSelect(chipSelect);                      // The default
    bcm2835_spi_setChipSelectPolarity(chipSelect, ChipSelectPolarity);      // the default
}

uint8_t SPI::transfer(uint8_t data)
{

    return bcm2835_spi_transfer(data);
}

