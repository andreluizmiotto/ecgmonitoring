/* 
 * File: config_bits.h 
 * Author: André Luiz Miotto
 * Date: 01/10/2020
 */

#include "timers.h"

void TMR1_Init(void)
{
    TMR1IE = 1;		/* Enable Timer1 Overflow Interrupt */
    TMR1IF = 0;
    TMR1IP = 0;     /* Enable Timer1 high priority interrupt */
    
    /* Enable 16-bit TMR1 register, no pre-scale, internal clock, timer OFF */
    T1CON = 0x80;		

    TMR1 = 0xEC77;  /* tcy = 4*(1/8000000) = 0.5e-6
                     * samplingRate = 400 Hz = 2.5e-3
                     * initialCount = 2.5e-3/0.5e-6 = 5000
                     * 65535 - 5000 = 60535 */
    TMR1ON = 1;		/* Turn ON Timer1 */
}

void TMR1_Reset(void)
{
    TMR1 = 0xEC77;
    PIR1bits.TMR1IF = 0;  /* Make Timer1 Overflow Flag to '0' */
}