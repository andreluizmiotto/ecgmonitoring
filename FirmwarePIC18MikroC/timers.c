/* 
 * File: timers.c
 * Author: André Luiz Miotto
 * Date: 01/10/2020
 */

#include "timers.h"

//-----------------------------------------------------------------------------
void TIMER0_Init(void)
{
   /* Timer0 ON
    * 16 bit mode
    * Timer mode
    * No pre-scale */
    T0CON = 0b10001000;
    INTCON.TMR0IE = 1;
}
//-----------------------------------------------------------------------------
void TIMER0_Set(unsigned int initialCount)
{
    TMR0L = initialCount >> 8;
    TMR0H = initialCount;
}
//-----------------------------------------------------------------------------
void TIMER1_Init(void)
{   
    // T1CON register
    T1CON.RD16    = 1;    // 16-Bit Read/Write Mode Enable bit (0-8bits, 1-16bits).
    T1CON.T1RUN   = 1;    // Timer1 System Clock Status bit.
    T1CON.T1CKPS1 = 0;    // 11 = 1:8 Prescale value
    T1CON.T1CKPS0 = 0;    // 10 = 1:4 Prescale value
                          // 01 = 1:2 Prescale value
                          // 00 = 1:1 Prescale value
    T1CON.T1OSCEN = 0;
    T1CON.T1SYNC  = 1;
    T1CON.TMR1CS  = 0;    // Timer1 Clock Source Select bit (0-Fosc/4, 1-RC0/T1OSO/T13CKI pin).
    T1CON.TMR1ON  = 1;    // Timer1 enabled
    
    INTCON.TMR1IE = 1;    /* Enable Timer1 Overflow Interrupt */
    INTCON.TMR1IF = 0;
    PIE1.TMR1IE   = 1;    /* Enable Timer1 peripheral interrupt */

    TIMER1_Reset;
}
//-----------------------------------------------------------------------------
void TIMER1_Reset(void)
{
    TMR1L = 0x77;
    TMR1H = 0xEC; /* 0xEC77 = tcy = 4*(1/8000000) = 0.5e-6
                   * samplingRate = 400 Hz = 2.5e-3
                   * initialCount = 2.5e-3/0.5e-6 = 5000
                   * 65535 - 5000 = 60535 */
    TMR1IF_bit = 0x00;
}
//-----------------------------------------------------------------------------