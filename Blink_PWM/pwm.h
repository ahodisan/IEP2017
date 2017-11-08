#ifndef PWMM_H
#define PWMM_H
#include<stdint.h>

class PWMM
{
public:
    PWMM(int freq, int fact_umplere);
    int freq;
    int fact_umplere;
    int getFreq();
    int getFactUmplere();
    void set(int freq, int duty_cycle);
};

#endif // PWMM_H
