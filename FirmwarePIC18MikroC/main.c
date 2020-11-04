#pragma orgall 0x1000

/*
 * File:   main.c
 * Author: André Luiz Miotto
 * Date: 01/10/2020
 */
 
#include "eusart.h"
#include "timers.h"
#include "adc.h"

unsigned char ADC_Buffer[4];
unsigned char checksum = 0x50;
unsigned char index = 0;

unsigned int CODIGO = 0;
unsigned HIGH;
unsigned LOW;

/*void interrupt() iv 0x0008 ics ICS_AUTO
{
  if (TMR1IF_bit) {
     contador++;
     if (contador >= 400) {
        contador = 0;
     }
     TIMER1_Reset();
     EUSART_WriteChar('W');
  }
}*/

void main(void) org 0x1000
{
    OSCCON = 0x72;                /* Use internal oscillator of 8MHz Frequency */
    PEIE_bit = 1;                 /* Enable Peripheral Interrupt */
    GIE_bit = 1;                  /* Enable Global Interrupt */
    CMCON = 0x07;                 /* Disable comparators */
    
    EUSART_Init(115200);
    TIMER1_Init();
    ADC_Init();

    Delay_ms(500);

    while(1)
    {
        Delay_ms(5);
/*        if (TMR1IF_bit) {
            TIMER1_Reset();
/*            ADC_Read(0);
            ADC_Buffer[0] = ADRESH;
            ADC_Buffer[1] = ADRESL;
*/
        HIGH = (CODIGO >> 8);
	LOW = CODIGO;

	if (CODIGO < 1023)
	   CODIGO++;
	else
            CODIGO = 0;

        ADC_Buffer[0] = HIGH;
        ADC_Buffer[1] = LOW;

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