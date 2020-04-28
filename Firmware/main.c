#include "config.h"
#include <xc.h>
#include <stdlib.h>

#include "usart.h"
#include "adc.h"
#include "timers.h"

// Vari�veis globais do sistema.
unsigned char ADC_Buffer[4];
unsigned int codigo = 0;

void interrupt ISR(void)
{
	// Interrup��o do TIMER1 para a frequ�ncia de amostragem do sistema.
	if(PIR1bits.TMR1IF) 
	{
        PIR1bits.TMR1IF = 0;		// Resetar a flag do TIMER1 para uma nova contagem.

		TIMER1_Set(42496);   		// Frequ�ncia de amostragem de 250 Hz.
        
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
	TIMER1_Set(42496); 		// Frequ�ncia de amostragem de 250 Hz.

	// Ativa��o das interrup��es do microcontrolador.
	INTCONbits.PEIE	= 1;	// Habilita Interrup��o de Perif?ricos do Microcontrolador.
	INTCONbits.GIE	= 1;	// Habilita Interrup��o Global.

	USART_WriteString("Inicializando USART...");	// Inicializador do pacote de dados.

	while(1)
	{	

	}
}
//-----------------------------------------------------------------------------
