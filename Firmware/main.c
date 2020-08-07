#include "config.h"
#include <xc.h>
#include <stdlib.h>
#include <Math.h>

#include "usart.h"
#include "adc.h"
#include "timers.h"

// Variáveis globais do sistema.
unsigned char ADC_Buffer[4];
unsigned int CODIGO = 0;
unsigned char HIGH;
unsigned char LOW;

float tempo_periodo = 0.002; // Necessário configurar o TIMER para gerar interrupção a cada 2ms
float t = 0;
float pi = 3.141592653589793;
float valor = 0;

unsigned int tipoSinal = 0;

void interrupt ISR(void)
{
	// Interrupção do TIMER1 para a frequência de amostragem do sistema.
	if(PIR1bits.TMR1IF) 
	{
        PIR1bits.TMR1IF = 0;		// Resetar a flag do TIMER1 para uma nova contagem.

		// TIMER1_Set(42496);   		// Frequência de amostragem de 250 Hz.
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
	// Inicialização das portas do microcontrolador.
    TRISA	= 0b00000011;	// Configuração dos canais analógicos do PORTA.
    PORTA	= 0b00000011;  	// Inicialização dos canais analógicos do PORTA.
    TRISB	= 0b00000000;	// Configuração das entradas/saídas do PORTB.
    PORTB	= 0b00000000;  	// Inicialização das entradas/saídas do PORTB.
	TRISC	= 0b10000000;	// Configuração das entradas/saídas do PORTC.
    PORTC	= 0b11000000;  	// Inicialização das entradas/saídas do PORTC.

	// Inicialização do módulo PWM do microcontrolador.
	USART_Init(115200);	// Inicialização da USART passando a velocidade e o modo de transmissão.
	TIMER1_Init();			// Inicialização das configurações do TIMER1.
	ADC_Init();				// Inicialização do conversor A/D.

	// Inicialização dos parâmetros de configuração do TIMER1.
	TIMER1_Set(54016); 		// Frequência de amostragem de 400Hz.

	// Ativação das interrupções do microcontrolador.
	INTCONbits.PEIE	= 1;	// Habilita Interrupção de Perif?ricos do Microcontrolador.
	INTCONbits.GIE	= 1;	// Habilita Interrupção Global.

	while(1)
	{	

	}
}
//-----------------------------------------------------------------------------
