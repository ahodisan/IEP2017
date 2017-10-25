#include "pin.h"
#include "bcm2835.h"

Pin::Pin(int numar,int directia,int stare )
{

     this->numar=numar;
     this->directia=directia;
     this->stare=stare;

}
void Pin::set(int p)
{
    if(this->directia==0)
        //we can write it only if the pin is for output (directia==0)
    {
         bcm2835_gpio_write(this->numar, p); //if p==1 => ON; if p==0 => OFF
    }

}
int Pin::get(int stare)
{
    int result;

    if(this->directia == 0)  //output pin
    {
        result = this->stare;
    }
    else  //input pin => pull-up state
    {
        result  = bcm2835_gpio_lev(this->numar);
    }
    return result;
}

void Pin::change()
{
    if(this->directia==0)
        // output pin
    {

    bcm2835_gpio_fsel(this->numar, BCM2835_GPIO_FSEL_INPT); //make it an input pin

    }
    else
    {
      bcm2835_gpio_fsel(this->numar, BCM2835_GPIO_FSEL_OUTP); //make it an output pin

    }


}
