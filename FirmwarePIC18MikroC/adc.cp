#line 1 "C:/Projects/BitBucketProjects/Firmwares e Supervisorios/AquisicaoSinaisECG/FirmwarePIC18MikroC/adc.c"
#line 1 "c:/projects/bitbucketprojects/firmwares e supervisorios/aquisicaosinaisecg/firmwarepic18mikroc/adc.h"
#line 10 "c:/projects/bitbucketprojects/firmwares e supervisorios/aquisicaosinaisecg/firmwarepic18mikroc/adc.h"
void ADC_Init(void);
void ADC_Read(int channel);
#line 9 "C:/Projects/BitBucketProjects/Firmwares e Supervisorios/AquisicaoSinaisECG/FirmwarePIC18MikroC/adc.c"
void ADC_Init(void)
{
 TRISA = 0b00000001;
 ADCON1 = 0b00001110;
 ADRESH = 0;
 ADRESL = 0;
}

void ADC_Read(int channel)
{
#line 20 "C:/Projects/BitBucketProjects/Firmwares e Supervisorios/AquisicaoSinaisECG/FirmwarePIC18MikroC/adc.c"
 ADCON0 = (ADCON0 & 0b11000011)|((channel<<2) & 0b00111100);
 ADCON0 |= ((1<<ADON)|(1<<GO));
 while (GO_bit == 1);
}
