#include "config.h"
#include "timers.h"
#include <xc.h>

//#define mcy (double)(1/_XTAL_FREQ)
//#define tcy (double)(4*mcy)

long FInitialCount;

void TMR0_Init(long initialCount)
{
    FInitialCount = initialCount;
     
    TMR0ON = 1;             // Timer0 Enabled
    T08BIT = 0;             // 16-bit mode
    T0CS = 0;               // Source clock (Timer0 as Timer)
    T0SE = 0;               // Source edge (low-to-high)
    PSA = 1;                // Prescaler not assigned
    T0PS2 = 0;              // Prescaler bits - don't care
    T0PS1 = 0;
    T0PS0 = 0;

    TMR0_Reset();
  
	INTCONbits.TMR0IF = 0;  // Clear timer interrupt flag
    INTCONbits.TMR0IE = 1;  // Enable interrupt
}

void TMR0_Reset(void)
{
    INTCONbits.TMR0IF = 0;      // Clear timer interrupt flag
    TMR0H = FInitialCount >> 8;  // Início da contagem
    TMR0L = FInitialCount;
}