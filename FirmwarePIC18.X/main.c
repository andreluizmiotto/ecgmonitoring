/* 
 * File:   main.c
 * Author: andre
 *
 * Created on 3 de Setembro de 2020, 16:26
 */

// Necessário para utilizar o bootloader AFSmart
//#pragma orgall 0x1000

/** INCLUDES *******************************************************/
#include "config.h"
#include <pic18f4550.h>

#include "usart.h"
#include "timers.h"
#include "adc.h"

unsigned char ADC_Buffer[4];
unsigned int CODIGO = 0;
unsigned char HIGH;
unsigned char LOW;
#define LED LATB
void initMCU(void);
void MSdelay(unsigned int val);

void __interrupt() ISR()
{
    if(INTCONbits.TMR0IF == 1) { // Timer Interrupt Detected
        TMR0_Reset();
        
        HIGH = (CODIGO >> 8);
		LOW = CODIGO;

		if (CODIGO < 1023)
			CODIGO++;
		else
			CODIGO = 0;
		
        ADC_Buffer[0] = HIGH;
        ADC_Buffer[1] = LOW;
        
        USART_WriteChar('@');
		USART_WriteChar('#');
		USART_WriteChar('$');
        unsigned char checksum = 0x50;
        for(unsigned char index = 0; index <= 1; index++) 
		{
        	USART_WriteChar(ADC_Buffer[index]);
           	checksum ^= ADC_Buffer[index];
        }
        USART_WriteChar(checksum);	// Finalizador do pacote de dados por checksum.	  
    }
}
//-----------------------------------------------------------------------------
void main(void){
    //initMCU();    
    //ADC_Init();
    //USART_Init(115200);
	/*TMR0_Init(63035);*/       /* tcy = 4*(1/4000000) = 0.5e-6
                             * samplingRate = 400 Hz = 2.5e-3
                             * initialCount = 2.5e-3/0.5e-6 = 2500
                             * 65535 - 2500 = 63035 */
    
    //__delay_ms(500);

   // INTCONbits.PEIE	= 1;	// Habilita Interrupção de Periféricos do Microcontrolador.
//	INTCONbits.GIE	= 1;	// Habilita Interrupção Global.    
    
    OSCCON=0x72;        /* Use internal oscillator of 8MHz Frequency */
    TRISB=0x00;         /* Set direction of PORTB as OUTPUT to which LED is connected */
    while(1)
    {
        LED = 0xff;     /* Turn ON LED for 500 ms */
        MSdelay (500);
        LED = 0;        /* Turn OFF LED for 500 ms */
        MSdelay (500);
    }   
}

void initMCU(void)
{
    OSCCON = 0X72;
    //OSCCONbits.IRCF0 = 1;       // Oscillator set to 4MHz
    //OSCCONbits.IRCF1 = 1;
    //OSCCONbits.IRCF2 = 1;
    RCON = 0X80;                // Limpa o Registro de Reset
    ADCON1 = 0x0F;              // Digital I/O
    CMCON = 0x0F;               // Desabilita comparadorres
    
    TRISA = 0b00000000;
    TRISB = 0b00000000;
	TRISC = 0b00000000;
    TRISD = 0b00000000;
    TRISE = 0b00000000;    

    LATA = 0b00000000;
    LATB = 0b00000000;
    LATC = 0b00000000;
    LATD = 0b00000000;
    LATE = 0b00000000;
}

void MSdelay(unsigned int val)
{
 unsigned int i,j;
 for(i=0;i<val;i++)
     for(j=0;j<165;j++);  /*This count Provide delay of 1 ms for 8MHz Frequency */
 } 