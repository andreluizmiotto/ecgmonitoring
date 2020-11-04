#line 1 "C:/Projects/BitBucketProjects/Firmwares e Supervisorios/AquisicaoSinaisECG/FirmwarePIC18MikroC/eusart.c"
#line 1 "c:/projects/bitbucketprojects/firmwares e supervisorios/aquisicaosinaisecg/firmwarepic18mikroc/eusart.h"
#line 10 "c:/projects/bitbucketprojects/firmwares e supervisorios/aquisicaosinaisecg/firmwarepic18mikroc/eusart.h"
void EUSART_Init(long baudRate);
void EUSART_WriteChar(unsigned char EUSARTData);
#line 10 "C:/Projects/BitBucketProjects/Firmwares e Supervisorios/AquisicaoSinaisECG/FirmwarePIC18MikroC/eusart.c"
void EUSART_Init(long baudRate)
{

 TRISC.RC6 = 1;
 TRISC.RC7 = 1;
#line 22 "C:/Projects/BitBucketProjects/Firmwares e Supervisorios/AquisicaoSinaisECG/FirmwarePIC18MikroC/eusart.c"
 SPBRG = (int)( 8000000  / (4 * baudRate)) - 1;


 TXSTA.CSRC = 0;
 TXSTA.TX9 = 0;
 TXSTA.TXEN = 1;
 TXSTA.SYNC = 0;
 TXSTA.SENDB = 0;
 TXSTA.BRGH = 1;
 TXSTA.TRMT = 0;
 TXSTA.TX9D = 0;


 RCSTA.SPEN = 1;
 RCSTA.RX9 = 0;
 RCSTA.SREN = 0;
 RCSTA.CREN = 1;
 RCSTA.ADDEN = 0;
 RCSTA.FERR = 0;
 RCSTA.OERR = 0;
 RCSTA.RX9D = 0;


 BAUDCON.ABDOVF = 0;
 BAUDCON.RCIDL = 0;
 BAUDCON.RXDTP = 0;
 BAUDCON.TXCKP = 0;
 BAUDCON.BRG16 = 1;
 BAUDCON.WUE = 0;
 BAUDCON.ABDEN = 0;
}

void EUSART_WriteChar(unsigned char EUSARTData)
{
 Delay_1ms();
 while(!TXIF);
 TXREG = EUSARTData;
}
