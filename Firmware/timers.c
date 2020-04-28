#include "config.h"
#include <xc.h>

#include "timers.h"

void TIMER0_Init()
{
	OPTION_REGbits.T0CS = 0;
	OPTION_REGbits.T0SE = 0;
	OPTION_REGbits.PSA  = 0;
	OPTION_REGbits.PS2  = 1;	// Prescaler 111 = 256.
	OPTION_REGbits.PS1  = 1;
	OPTION_REGbits.PS0  = 1;
	INTCONbits.TMR0IF   = 0;	// Overflow Interrupt Flag bit.
	INTCONbits.TMR0IE   = 1;	// Overflow Interrupt Enable bit
}
//-----------------------------------------------------------------------------
void TIMER0_Set(unsigned char count)
{
	TMR0 = count;		// Timer 1 initial value
}
//-----------------------------------------------------------------------------
void TIMER1_Init()
{
	// Timer 1 Initialization
	T1CONbits.T1CKPS1 = 0; 		// Timer1 Input Clock Prescale Select bits.
	T1CONbits.T1CKPS0 = 0;  	// Timer1 Input Clock Prescale Select bits.
	T1CONbits.T1OSCEN = 1;  	// Timer1 Oscillator Enable Control bit = Enabled
	T1CONbits.nT1SYNC = 1;		// Timer1 External Clock Input Synchronization Control bit = Disabled
	T1CONbits.TMR1CS  = 0;		// Timer1 Clock Source Select bit = Internal clock (FOSC/4)
	T1CONbits.TMR1ON  = 1;		// Timer1 On bit = Timer1 Enabled		
	PIE1bits.TMR1IE   = 1;		// TMR1 Overflow Interrupt Enable bit = Enabled
	PIR1bits.TMR1IF   = 0;		// TMR1 Overflow Interrupt Flag bit = TMR1 register did not overflow
}
//-----------------------------------------------------------------------------
void TIMER1_Set(unsigned int count)
{
	TMR1 = count;		// TMR1 initial value.
}