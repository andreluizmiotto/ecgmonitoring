#line 1 "C:/Projects/BitBucketProjects/Firmwares e Supervisorios/AquisicaoSinaisECG/FirmwarePIC18MikroC/timers.c"
#line 1 "c:/projects/bitbucketprojects/firmwares e supervisorios/aquisicaosinaisecg/firmwarepic18mikroc/timers.h"
#line 11 "c:/projects/bitbucketprojects/firmwares e supervisorios/aquisicaosinaisecg/firmwarepic18mikroc/timers.h"
void TIMER0_Init(void);
void TIMER0_Set(unsigned int initialCount);


void TIMER1_Init(void);
void TIMER1_Reset(void);
#line 10 "C:/Projects/BitBucketProjects/Firmwares e Supervisorios/AquisicaoSinaisECG/FirmwarePIC18MikroC/timers.c"
void TIMER0_Init(void)
{
#line 16 "C:/Projects/BitBucketProjects/Firmwares e Supervisorios/AquisicaoSinaisECG/FirmwarePIC18MikroC/timers.c"
 T0CON = 0b10001000;
 INTCON.TMR0IE = 1;
}

void TIMER0_Set(unsigned int initialCount)
{
 TMR0L = initialCount >> 8;
 TMR0H = initialCount;
}

void TIMER1_Init(void)
{

 T1CON.RD16 = 1;
 T1CON.T1RUN = 1;
 T1CON.T1CKPS1 = 0;
 T1CON.T1CKPS0 = 0;


 T1CON.T1OSCEN = 0;
 T1CON.T1SYNC = 1;
 T1CON.TMR1CS = 0;
 T1CON.TMR1ON = 1;

 INTCON.TMR1IE = 1;
 INTCON.TMR1IF = 0;
 PIE1.TMR1IE = 1;

 TIMER1_Reset;
}

void TIMER1_Reset(void)
{
 TMR1L = 0x77;
#line 53 "C:/Projects/BitBucketProjects/Firmwares e Supervisorios/AquisicaoSinaisECG/FirmwarePIC18MikroC/timers.c"
 TMR1H = 0xEC;
 TMR1IF_bit = 0x00;
}
