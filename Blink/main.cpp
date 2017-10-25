// blink.c
//
// Example program for bcm2835 library
// Blinks a pin on an off every 0.5 secs
//
// After installing bcm2835, you can build this
// with something like:
// gcc -o blink blink.c -l bcm2835
// sudo ./blink
//
// Or you can test it before installing with:
// gcc -o blink -I ../../src ../../src/bcm2835.c blink.c
// sudo ./blink
//
// Author: Mike McCauley
// Copyright (C) 2011 Mike McCauley
// $Id: RF22.h,v 1.21 2012/05/30 01:51:25 mikem Exp $

#include <bcm2835.h>
#include <stdio.h>
#include <pin.h>
// Blinks on RPi Plug P1 pin 11 (which is GPIO pin 17)
#define PIN RPI_GPIO_P1_11


//Implementați clasa Pin care să conțină numărul pinului, direcția,
//starea de pull-up (în caz ca e pin de input), și metode pentru get,
//set și change direction unde, în caz că pinul e output, set va scrie pe
//pin și get va citi valoarea scrisă, iar în caz de input, set nu face nimic,
//iar get va citi de pe pin. Metoda change direction schimb direcția pinului.


int main(int argc, char **argv)
{

    //Instantiate new Pin
    Pin *pin11 = NULL;
    pin11 = new Pin(PIN, 0, -1);
    // If you call this, it will not actually access the GPIO
    // Use for testing
    bcm2835_set_debug(1);
    if (!bcm2835_init())
      return 1;
    // Set the pin to be an output
    bcm2835_gpio_fsel(PIN, BCM2835_GPIO_FSEL_OUTP);
    // Blink
    while (1)
    {
        // Turn it on
        //bcm2835_gpio_write(PIN, HIGH);
        pin11->set(1);
        // wait a bit
        bcm2835_delay(500);

        // turn it off
        //bcm2835_gpio_write(PIN, LOW);
        pin11->set(0);
        // wait a bit
        bcm2835_delay(500);
    }
    bcm2835_close();
    return 0;
}
