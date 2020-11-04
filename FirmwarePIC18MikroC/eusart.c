/* 
 * File: eusart.c
 * Author: André Luiz Miotto
 * Date: 01/10/2020
 */

#include "eusart.h"
#define _XTAL_FREQ 8000000

void EUSART_Init(long baudRate)
{
    /* The EUSART control will automatically reconfigure the pin from input to output as needed.*/
    TRISC.RC6 = 1;         // Tx
    TRISC.RC7 = 1;         // Rx
    
    /* if ((BRG16 == 0) && (BRGH == 0))
          SPBRG = (int)(_XTAL_FREQ / (64 * baudRate)) - 1;
     * if ((BRG16 ^ BRGH) == 1)
          SPBRG = (int)(_XTAL_FREQ / (16 * baudRate)) - 1;
     * if ((BRG16 == 1) && (BRGH == 1))
          SPBRG = (int)(_XTAL_FREQ / (4 * baudRate)) - 1; */
    SPBRG = (int)(_XTAL_FREQ / (4 * baudRate)) - 1;
    
    // TXSTA - Transmit 0x26
    TXSTA.CSRC = 0;           // Clock source - assync = don't care
    TXSTA.TX9 = 0;            // 8-bit transmission
    TXSTA.TXEN = 1;           // Enable transmission
    TXSTA.SYNC = 0;           // Assynchronous mode
    TXSTA.SENDB = 0;          // Sync break transmission completed
    TXSTA.BRGH = 1;           // High-speed mode
    TXSTA.TRMT = 0;           // Transmit shift register empty
    TXSTA.TX9D = 0;           // 9-bit transmit data
    
    // RCSTA - Receive 0x90
    RCSTA.SPEN = 1;           // Serial port enable bit
    RCSTA.RX9 = 0;            // 8-bit receive
    RCSTA.SREN = 0;           // Single receibe - assync = don't care
    RCSTA.CREN = 1;           // Enable continuous receiver
    RCSTA.ADDEN = 0;          // Adress detect - assync = don't care
    RCSTA.FERR = 0;           // Framing error
    RCSTA.OERR = 0;           // Overrun error enabled
    RCSTA.RX9D = 0;           // 9-bit receive data
    
    // BAUDCON
    BAUDCON.ABDOVF = 0;
    BAUDCON.RCIDL  = 0;
    BAUDCON.RXDTP  = 0;
    BAUDCON.TXCKP  = 0;
    BAUDCON.BRG16  = 1;         // 16-bit baud
    BAUDCON.WUE    = 0;
    BAUDCON.ABDEN  = 0;
}
//-----------------------------------------------------------------------------
void EUSART_WriteChar(unsigned char EUSARTData)
{
    Delay_1ms();
    while(!TXIF);         // Wait
    TXREG = EUSARTData;   // Send character
}
//-----------------------------------------------------------------------------