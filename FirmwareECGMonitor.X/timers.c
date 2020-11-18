/*  
 * Author: André Luiz Miotto
 * Date: 14/10/2020
 */

#include "timers.h"
#include "config_bits.h"

//-----------------------------------------------------------------------------
void TIMER1_Init(void)
{   
	// T1CON register
	T1CONbits.RD16 = 1;    // Read/Write mode enable bit (0 = 8 bits, 1 = 16 bits).
	T1RUN   = 1;           // System clock status bit.
	T1CKPS1 = 0;           // 11 = 1:8 Prescale value
	T1CKPS0 = 0;           // 10 = 1:4 Prescale value
	                       // 01 = 1:2 Prescale value
	                       // 00 = 1:1 Prescale value
	T1OSCEN = 0;           // Oscillator enable bit
	T1SYNC  = 0;           // External clock input synchronization (only if TMR1CS = 1)
	TMR1CS  = 0;           /* Clock source select bit 
	                          (0 = internal clock). */
	TMR1ON  = 1;           // Enable Timer1
	
	TMR1IE = 1;            // Enable Timer1 overflow interrupt
	TMR1IF = 0x00;         // Clears the overflow interrupt flag bit 
}
//-----------------------------------------------------------------------------
void TIMER1_Reset(void)
{
    TMR1L = 0xCF;
    TMR1H = 0x8A; /* 0xEC77 = tcy = 4*(1/8000000) = 0.5e-6
                   * samplingRate = 400 Hz = 2.5e-3
                   * initialCount = 2.5e-3/0.5e-6 = 5000
                   * 65535 - 5000 = 60535 */
    
                 /* 0x8ACF = tcy = 4*(1/48000000) = 83.33e-9
                   * samplingRate = 400 Hz = 2.5e-3
                   * initialCount = 2.5e-3/83.33e-9 = 30000
                   * 65535 - 30000 = 35535 */
    
                /* 0x159F = tcy = 4*(1/48000000) = 83.3333e-9
                   * samplingRate = 200 Hz = 5e-3
                   * initialCount = 5e-3/83.3333e-9 = 60000
                   * 65535 - 60000 = 5535 */
    TMR1IF = 0x00;
}
//-----------------------------------------------------------------------------
