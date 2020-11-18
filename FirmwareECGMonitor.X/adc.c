/* 
 * Author: André Luiz Miotto
 * Date: 14/10/2020
 */

#include "adc.h"
#include "config_bits.h"

//-----------------------------------------------------------------------------
void ADC_Init(void)
{
    TRISA = 0b000000001;        // AN0 as analog input 
    ADCON0bits.ADON = 1;        // Enable A/D conversion 
    ADCON1bits.VCFG = 0b00;     // Ref voltage Vdd/Vss 
    ADCON1bits.PCFG = 0b1110;   // AN0 as analog 
    ADCON2bits.ADCS = 0b110;    // A/D clock: Fosc/64 
    ADCON2bits.ACQT = 0b110;    // Acquisition time: 16 TAD 
    ADCON2bits.ADFM = 0b1;      // Left justified 
    ADRESH = 0;       			// Flushes ADC result high register
    ADRESL = 0;                 // Flushes ADC result low register
}
//-----------------------------------------------------------------------------
void ADC_Read(unsigned char channel)
{
    ADCON0bits.CHS = channel;   // Set A/D read channel
    ADCON0bits.GO = 1;          // Start A/D conversion
    while(!ADCON0bits.GODONE);  // Wait for End of conversion
}
//-----------------------------------------------------------------------------