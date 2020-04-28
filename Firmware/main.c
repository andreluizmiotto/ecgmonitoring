#include "config.h"
#include <xc.h>
#include <stdlib.h>

#include "usart.h"
#include "adc.h"
#include "timers.h"

// Variáveis globais do sistema.
unsigned char ADC_Buffer[4];
unsigned int codigo = 0;

void interrupt ISR(void)
{
	// Interrupção do TIMER1 para a frequência de amostragem do sistema.
	if(PIR1bits.TMR1IF) 
	{
        PIR1bits.TMR1IF = 0;		// Resetar a flag do TIMER1 para uma nova contagem.

		TIMER1_Set(42496);   		// Frequência de amostragem de 250 Hz.
        
        // Leitura do canal AN0.
/*		ADC_Read(0);
        ADC_Buffer[0] = ADRESH;
        ADC_Buffer[1] = ADRESL;
        
        // Leitura do canal AN1.
		ADC_Read(1);
        ADC_Buffer[2] = ADRESH;
        ADC_Buffer[3] = ADRESL;
*/
		ADC_Buffer[0] = ('#');
		ADC_Buffer[1] = ('$');
		ADC_Buffer[2] = (':');
		
		ADC_Buffer[3] = (codigo >> 8);
        ADC_Buffer[4] = codigo;

		codigo++;
		if (codigo > 1023)
			codigo = 0;

        ADC_Buffer[5] = (codigo >> 8);
        ADC_Buffer[6] = codigo;

		codigo++;
		if (codigo > 1023)
			codigo = 0;
		        
		// Pacote de dados com as amostras coletadas.
//        USART_WriteString("#$:");	// Inicializador do pacote de dados.

        unsigned char checksum = 0x20;
        for(unsigned char index = 0; index < 7; index++) 
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
	TIMER1_Set(42496); 		// Frequência de amostragem de 250 Hz.

	// Ativação das interrupções do microcontrolador.
	INTCONbits.PEIE	= 1;	// Habilita Interrupção de Perif?ricos do Microcontrolador.
	INTCONbits.GIE	= 1;	// Habilita Interrupção Global.

	USART_WriteString("Inicializando USART...");	// Inicializador do pacote de dados.

	while(1)
	{	

	}
}
//-----------------------------------------------------------------------------
