/*
 * File: adc.c
 * Author: André Luiz Miotto
 * Date: 01/10/2020
 */

#include "adc.h"
#include "config_bits.h"
#include <xc.h>


void ADC_Init(void)
{    
    TRISA = 0b00000001;       /* AN0 as input port */
    ADCON1 = 0b00001110;      /* AN0 as analog input port */
    /*ADCON2 = 0b10011010;      /* Vref+ = VDD and Vref- = Vss */
    ADRESH = 0;               /* Flush ADC output Register */
    ADRESL = 0;   
}
//-----------------------------------------------------------------------------
void ADC_Read(int channel)
{
    /* Channel 0 is selected i.e.(CHS3CHS2CHS1CHS0=0000) & ADC is disabled */
    ADCON0 =(ADCON0 & 0b11000011)|((channel<<2) & 0b00111100);  
    
    ADCON0 |= ((1<<ADON)|(1<<GO));	/*Enable ADC and start conversion*/

    /* Wait for End of conversion i.e. Go/done'=0 conversion completed */
    while(ADCON0bits.GO_nDONE==1);
}