/*
 * File: adc.c
 * Author: André Luiz Miotto
 * Date: 01/10/2020
 */

#include "adc.h"

void ADC_Init(void)
{    
    TRISA = 0b00000001;       /* AN0 as input port */
    ADCON1 = 0b00001110;       /* AN0 as analog input port */
    ADRESH = 0;               /*Flush ADC output Register*/
    ADRESL = 0;   
}
//-----------------------------------------------------------------------------
void ADC_Read(int channel)
{
    ADCON0 = (ADCON0 & 0b11000011)|((channel<<2) & 0b00111100); /* Channel 0 is selected i.e (CHS3CHS2CHS1CHS0=0000)
                                                                 * and ADC is disabled i.e ADON = 0 */
    ADCON0 |= ((1<<ADON)|(1<<GO));                              /* Enable ADC and start conversion*/
    while (GO_bit == 1);                                  /* Wait for End of conversion i.e. Go/done'=0 conversion completed */
}