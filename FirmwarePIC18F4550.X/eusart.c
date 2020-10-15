/* 
 * File: eusart.c
 * Author: André Luiz Miotto
 * Date: 01/10/2020
 */

#include "eusart.h"
#include "config_bits.h"

void EUSART_Init(long baudRate)
{
    /* The EUSART control will automatically reconfigure the pin from input to output as needed.*/
    TRISC6 = 1;         // Tx
    TRISC7 = 1;         // Rx
    
    /* if ((BRG16 == 0) && (BRGH == 0))
          SPBRG = (int)(_XTAL_FREQ / (64 * baudRate)) - 1;
     * if ((BRG16 ^ BRGH) == 1)
          SPBRG = (int)(_XTAL_FREQ / (16 * baudRate)) - 1;
     * if ((BRG16 == 1) && (BRGH == 1))
          SPBRG = (int)(_XTAL_FREQ / (4 * baudRate)) - 1; */
    SPBRG = (int)(_XTAL_FREQ / (4 * baudRate)) - 1;
    
    // TXSTA - Transmit 0x26
    TXSTA1bits.CSRC = 0;           // Clock source - assync = don't care
    TXSTA1bits.TX9 = 0;            // 8-bit transmission
    TXSTA1bits.TXEN = 1;           // Enable transmission
    TXSTA1bits.SYNC = 0;           // Assynchronous mode
    TXSTA1bits.SENDB = 0;          // Sync break transmission completed
    TXSTA1bits.BRGH = 1;           // High-speed mode
    TXSTA1bits.TRMT = 0;           // Transmit shift register empty
    TXSTA1bits.TX9D = 0;           // 9-bit transmit data
    
    // RCSTA - Receive 0x90
    RCSTAbits.SPEN = 1;           // Serial port enable bit
    RCSTAbits.RX9 = 0;            // 8-bit receive
    RCSTAbits.SREN = 0;           // Single receibe - assync = don't care
    RCSTAbits.CREN = 1;           // Enable continuous receiver
    RCSTAbits.ADDEN = 0;          // Adress detect - assync = don't care
    RCSTAbits.FERR = 0;           // Framing error
    RCSTAbits.OERR = 0;           // Overrun error enabled
    RCSTAbits.RX9D = 0;           // 9-bit receive data
    
    // BAUDCON
    BAUDCONbits.ABDOVF = 0;
    BAUDCONbits.RCIDL  = 0;
    BAUDCONbits.RXDTP  = 0;
    BAUDCONbits.TXCKP  = 0;
    BAUDCONbits.BRG16  = 1;       // 16-bit baud
    BAUDCONbits.WUE    = 0;
    BAUDCONbits.ABDEN  = 0;
}
//-----------------------------------------------------------------------------
void EUSART_WriteChar(unsigned char EUSARTData)
{
    while(!TXIF);         // Wait 
    TXREG = EUSARTData;   // Send character
}
//-----------------------------------------------------------------------------