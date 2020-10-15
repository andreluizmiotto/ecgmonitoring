/*
 * Author: André Luiz Miotto
 * Created on 14 de Outubro de 2020, 23:25
 */

#include "config_bits.h"
#include "eusart.h"
#include "timers.h"

unsigned char ADC_Buffer[4];
unsigned char checksum = 0x50;
unsigned char index = 0;

unsigned int CODIGO = 0;

//-----------------------------------------------------------------------------
void __interrupt(high_priority) highPriorityInterrupt(void) 
{
    if (PIR1bits.TMR1IF) {
        TIMER1_Reset();
        
        if (CODIGO < 1023)
           CODIGO++;
        else
            CODIGO = 0;

        ADC_Buffer[0] = (CODIGO >> 8);
        ADC_Buffer[1] = CODIGO;

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
    
    EUSART_Init(115200);
    TIMER1_Init();
    
    __delay_ms(500);
    
    INTCONbits.PEIE = 1;                 /* Enable Peripheral Interrupt */
    INTCONbits.GIE = 1;                  /* Enable Global Interrupt */
    
    while (1) {

    }
    
    return;
}
//-----------------------------------------------------------------------------