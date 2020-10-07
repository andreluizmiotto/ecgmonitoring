/*
 * File:   main.c
 * Author: André Luiz Miotto
 * Date: 01/10/2020
 */

#include "config_bits.h"        /*Header file for Configuration Bits*/
#include "eusart.h"
#include "timers.h"
#include <pic18f4550.h>         /*Header file PIC18f4550 definitions*/

void MSdelay(unsigned int);

unsigned char ADC_Buffer[4];
unsigned int CODIGO = 0;
unsigned char HIGH;
unsigned char LOW;

void main()
{
    OSCCON = 0x72;                /* Use internal oscillator of 8MHz Frequency */        
    
    //INTCONbits.GIE = 1;           /* Enable Global Interrupt */               
    //INTCONbits.PEIE = 1;          /* Enable Peripheral Interrupt */
    //INTCONbits.GIEH = 0;          /* Enable High priority interrupts */;
    //INTCONbits.GIEL = 1;          /* Enable Low priority interrupts */
    //INTCONbits.PEIE_GIEL = 1;     /* Enable Peripheral Interrupt */
    //INTCONbits.GIE_GIEH = 1;      /* Enable Peripheral Interrupt */
    //RCONbits.IPEN = 1;            /* Enable Interrupt priority */  
    
    /*INTCON2bits.RBPU = 1; 	// Desabilita o pull up

	INTCONbits.PEIE	= 1;	// Habilita Interrupção de Periféricos do Microcontrolador.
	INTCONbits.GIE	= 1;	// Habilita Interrupção Global.
	USART_Init(115200,1);
	TMR1_Init(0, 0, 0);
	TMR0_Init(76, 1);
	TMR3_Init(7936, 0, 0);

	ADCON1bits.PCFG3 = 1;
	ADCON1bits.PCFG2 = 1;
	ADCON1bits.PCFG1 = 1;
	ADCON1bits.PCFG0 = 1;
    */
    //TMR1_Init();  
    EUSART_Init(115200);
    EUSART_WriteChar('H');
    MSdelay(500);
    
    while(1)
    {
        EUSART_WriteChar('H');
        EUSART_WriteChar('e');
        EUSART_WriteChar('l');
        EUSART_WriteChar('l');
        EUSART_WriteChar('o');
        LATB = 0XFF;
        MSdelay (500);
        LATB = 0;
        MSdelay (500);
    }
}
//-----------------------------------------------------------------------------
/*void __interrupt() noPriorityIRS(void)
{
    
}
//-----------------------------------------------------------------------------
void __interrupt(high_priority) highPriorityISR(void)
{
    EUSART_WriteChar('H');
    EUSART_WriteChar('E');
    EUSART_WriteChar('L');
    EUSART_WriteChar('L');
    if(T0IF){
        TMR1_Reset();
    }
}
//-----------------------------------------------------------------------------
void __interrupt(low_priority) lowPriorityISR(void)
{
    
}*/
//-----------------------------------------------------------------------------
void MSdelay(unsigned int val)
{
    unsigned int i,j;
    for(i=0;i<val;i++)
        for(j=0;j<165;j++);         /*This count Provide delay of 1 ms for 8MHz Frequency */
 } 
