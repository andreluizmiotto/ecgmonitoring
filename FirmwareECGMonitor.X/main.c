/*
 * Author: André Luiz Miotto
 * Created on 14 de Outubro de 2020, 23:25
 */

#include "config_bits.h"
#include "eusart.h"
#include "timers.h"
#include "adc.h"

unsigned char ADC_Buffer[4];
unsigned char checksum = 0x50;
unsigned char index = 0;

void initMCU(void);

//-----------------------------------------------------------------------------
void __interrupt(high_priority) highPriorityInterrupt(void) 
{
    if (PIR1bits.TMR1IF) {
        TIMER1_Reset();
        
        ADC_Read(0);
        
        ADC_Buffer[0] = ADRESH;
        ADC_Buffer[1] = ADRESL;

        EUSART_WriteChar('@');
        EUSART_WriteChar('#');
        EUSART_WriteChar('$');
        
        checksum = 0x50;
        for(index = 0; index <= 1; index++) {
           EUSART_WriteChar(ADC_Buffer[index]);
           checksum ^= ADC_Buffer[index];
        }
        EUSART_WriteChar(checksum);	// Finalizador do pacote de dados por checksum.
    }
}
//-----------------------------------------------------------------------------
void main(void) {
    
//    initMCU();
    EUSART_Init(115200);
    TIMER1_Init();
    ADC_Init();
    
    __delay_ms(500);
    
    INTCONbits.PEIE = 1;                 /* Enable Peripheral Interrupt */
    INTCONbits.GIE = 1;                  /* Enable Global Interrupt */
    
    while (1) {

    }
    
    return;
}
//-----------------------------------------------------------------------------
void initMCU(void)
{
    RCON = 0x80;                /* Clen reset registers */
    CMCON = 0x07;               /* Disable comparators */
    
    TRISA = 0b00000000;
    TRISB = 0b00000000;
	TRISC = 0b00000011;
    TRISD = 0b00000000;
    TRISE = 0b00000000;    

    LATA = 0b00000000;
    LATB = 0b00000000;
    LATC = 0b00000000;
    LATD = 0b00000000;
    LATE = 0b00000000;
}
//-----------------------------------------------------------------------------