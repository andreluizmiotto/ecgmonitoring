#include "config.h"
#include <xc.h>

#include "adc.h"

void ADC_Init() 
{
	// Set ADCON1 to A/D conversion.
	ADCON1bits.ADFM  = 1;
	ADCON1bits.PCFG3 = 0;
	ADCON1bits.PCFG2 = 0;
	ADCON1bits.PCFG1 = 0;
	ADCON1bits.PCFG0 = 0;

	// Set ADCON0 to A/D conversion.
	//ADCON1bits.ADCS2 = 1;
	ADCON0bits.ADCS1 = 1;
	ADCON0bits.ADCS0 = 0;

	// Set PIE1 and PIR1 registers to A/D conversion.
	PIE1bits.ADIE = 0;
    PIR1bits.ADIF = 0;
}
//-----------------------------------------------------------------------------
void ADC_Read(unsigned short channel) 
{
	ADCON0bits.CHS = channel;	// Set the channel to be read (the same of CHS2:CHS1:CHS0 in bits).
	ADCON0bits.ADON	= 1;		// Activate A/D converter module.

	__delay_us(10); 			// Delay for A/D converter suitability.

	ADCON0bits.GO = 1;			// Activate data conversion system.
	while(ADCON0bits.GO_DONE);	// Waits for data conversion
    
	PIR1bits.ADIF = 0;			// Clear the flag to a new conversion.
}