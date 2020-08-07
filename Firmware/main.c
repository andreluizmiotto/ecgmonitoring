#include "config.h"
#include <xc.h>
#include <stdlib.h>
#include <Math.h>

#include "usart.h"
#include "adc.h"
#include "timers.h"

// Vari�veis globais do sistema.
unsigned char ADC_Buffer[4];
unsigned int CODIGO = 0;
unsigned char HIGH;
unsigned char LOW;

float tempo_periodo = 0.002; // Necess�rio configurar o TIMER para gerar interrup��o a cada 2ms
float t = 0;
float pi = 3.141592653589793;
float valor = 0;

unsigned int tipoSinal = 0;

void interrupt ISR(void)
{
	// Interrup��o do TIMER1 para a frequ�ncia de amostragem do sistema.
	if(PIR1bits.TMR1IF) 
	{
        PIR1bits.TMR1IF = 0;		// Resetar a flag do TIMER1 para uma nova contagem.

		// TIMER1_Set(42496);   		// Frequ�ncia de amostragem de 250 Hz.
		// Ajustar prescaler ao utilizar 250Hz -> 00
		//TIMER1_Set(7936); // 100 ms -> prescaler 1:8
		//TIMER1_Set(56320); // 500Hz
		TIMER1_Set(54016); // 400Hz
		//TIMER1_Set(50178); // 300Hz
		//TIMER1_Set(0); // 70Hz

        
        // Leitura do canal AN0.
/*		ADC_Read(0);
        ADC_Buffer[0] = ADRESH;
        ADC_Buffer[1] = ADRESL;
        
        // Leitura do canal AN1.
		ADC_Read(1);
        ADC_Buffer[2] = ADRESH;
        ADC_Buffer[3] = ADRESL;

*/
// CODIGO DE TESTE - 0 a 1023 -----------------
		HIGH = (CODIGO >> 8);
		LOW = CODIGO;

		if (CODIGO < 1023)
			CODIGO++;
		else
			CODIGO = 0;

		ADC_Buffer[0] = HIGH;
        ADC_Buffer[1] = LOW;

		HIGH = (CODIGO >> 8);
		LOW = CODIGO;

		if (CODIGO < 1023)
			CODIGO++;
		else
			CODIGO = 0;

        ADC_Buffer[2] = HIGH;
        ADC_Buffer[3] = LOW;
/*
// CODIGO DE TESTE - SENO -----------------
		valor = (sin(2 * pi * 10 * t) * 2.5) + 2.5;
		CODIGO = (valor * 1023)/5;
		ADC_Buffer[0] = (CODIGO >> 8);
		ADC_Buffer[1] = CODIGO;

		if (t < 0.998)
			t = t + tempo_periodo;
		else
			t = 0;

		valor = (sin(2 * pi * 10 * t) * 2.5) + 2.5;
		CODIGO = (valor * 1023)/5;
		ADC_Buffer[2] = (CODIGO >> 8);
		ADC_Buffer[3] = CODIGO;

		if (t < 0.998)
			t = t + tempo_periodo;
		else
			t = 0;
*/
		USART_WriteChar('@');
		USART_WriteChar('#');
		USART_WriteChar('$');
        unsigned char checksum = 0x50;
        for(unsigned char index = 0; index <= 3; index++) 
		{
        	USART_WriteChar(ADC_Buffer[index]);
           	checksum ^= ADC_Buffer[index];
        }

        USART_WriteChar(checksum);	// Finalizador do pacote de dados por checksum.	
	}		
}
//-----------------------------------------------------------------------------
void main(void)
{
	// Inicializa��o das portas do microcontrolador.
    TRISA	= 0b00000011;	// Configura��o dos canais anal�gicos do PORTA.
    PORTA	= 0b00000011;  	// Inicializa��o dos canais anal�gicos do PORTA.
    TRISB	= 0b00000000;	// Configura��o das entradas/sa�das do PORTB.
    PORTB	= 0b00000000;  	// Inicializa��o das entradas/sa�das do PORTB.
	TRISC	= 0b10000000;	// Configura��o das entradas/sa�das do PORTC.
    PORTC	= 0b11000000;  	// Inicializa��o das entradas/sa�das do PORTC.

	// Inicializa��o do m�dulo PWM do microcontrolador.
	USART_Init(115200);	// Inicializa��o da USART passando a velocidade e o modo de transmiss�o.
	TIMER1_Init();			// Inicializa��o das configura��es do TIMER1.
	ADC_Init();				// Inicializa��o do conversor A/D.

	// Inicializa��o dos par�metros de configura��o do TIMER1.
	TIMER1_Set(54016); 		// Frequ�ncia de amostragem de 400Hz.

	// Ativa��o das interrup��es do microcontrolador.
	INTCONbits.PEIE	= 1;	// Habilita Interrup��o de Perif?ricos do Microcontrolador.
	INTCONbits.GIE	= 1;	// Habilita Interrup��o Global.

	while(1)
	{	

	}
}
//-----------------------------------------------------------------------------
