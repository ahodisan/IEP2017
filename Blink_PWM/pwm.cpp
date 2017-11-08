#include "pwm.h"
#include <bcm2835.h>

PWMM::PWMM(int f, int fact)
{
    this->freq = f;
    this->fact_umplere = this->freq * fact / 100;
    bcm2835_pwm_set_clock(BCM2835_PWM_CLOCK_DIVIDER_16);
    bcm2835_pwm_set_mode(0, 1, 1);  //PWM_CHANNEL = 0
    bcm2835_pwm_set_range(0, f);
    bcm2835_pwm_set_data(0, this->fact_umplere);
}

void PWMM::set(int freq, int duty_cycle)
{
    this->freq = freq;
    this->fact_umplere = this->freq * duty_cycle / 100;
    bcm2835_pwm_set_range(0, this->freq);
    bcm2835_pwm_set_data(0, this->fact_umplere);
}
int PWMM::getFreq()
{
    return this->freq;
}

int PWMM::getFactUmplere()
{
    return (this->fact_umplere * 100) / this->freq;  //reverse of the above formula
}
