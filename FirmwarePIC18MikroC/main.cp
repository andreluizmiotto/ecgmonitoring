#line 1 "C:/Projects/BitBucketProjects/Firmwares e Supervisorios/AquisicaoSinaisECG/FirmwarePIC18MikroC/main.c"
#pragma orgall 0x1000
#line 1 "c:/projects/bitbucketprojects/firmwares e supervisorios/aquisicaosinaisecg/firmwarepic18mikroc/eusart.h"
#line 10 "c:/projects/bitbucketprojects/firmwares e supervisorios/aquisicaosinaisecg/firmwarepic18mikroc/eusart.h"
void EUSART_Init(long baudRate);
void EUSART_WriteChar(unsigned char EUSARTData);
#line 1 "c:/projects/bitbucketprojects/firmwares e supervisorios/aquisicaosinaisecg/firmwarepic18mikroc/timers.h"
#line 11 "c:/projects/bitbucketprojects/firmwares e supervisorios/aquisicaosinaisecg/firmwarepic18mikroc/timers.h"
void TIMER0_Init(void);
void TIMER0_Set(unsigned int initialCount);


void TIMER1_Init(void);
void TIMER1_Reset(void);
#line 1 "c:/projects/bitbucketprojects/firmwares e supervisorios/aquisicaosinaisecg/firmwarepic18mikroc/adc.h"
#line 10 "c:/projects/bitbucketprojects/firmwares e supervisorios/aquisicaosinaisecg/firmwarepic18mikroc/adc.h"
void ADC_Init(void);
void ADC_Read(int channel);
#line 13 "C:/Projects/BitBucketProjects/Firmwares e Supervisorios/AquisicaoSinaisECG/FirmwarePIC18MikroC/main.c"
unsigned char ADC_Buffer[4];
unsigned char checksum = 0x50;
unsigned char index = 0;

unsigned int CODIGO = 0;
unsigned HIGH;
unsigned LOW;
#line 33 "C:/Projects/BitBucketProjects/Firmwares e Supervisorios/AquisicaoSinaisECG/FirmwarePIC18MikroC/main.c"
void main(void) org 0x1000
{
 OSCCON = 0x72;
 PEIE_bit = 1;
 GIE_bit = 1;
 CMCON = 0x07;

 EUSART_Init(115200);
 TIMER1_Init();
 ADC_Init();

 Delay_ms(500);

 while(1)
 {
 Delay_ms(5);
#line 55 "C:/Projects/BitBucketProjects/Firmwares e Supervisorios/AquisicaoSinaisECG/FirmwarePIC18MikroC/main.c"
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
 EUSART_WriteChar(checksum);
 }
}
