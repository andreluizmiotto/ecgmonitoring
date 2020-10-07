#include "config.h"
#include "usart.h"
#include <xc.h>

void USART_Init(long baudRate)
{
    TRISC7 = 1;         // Rx
    TRISC6 = 1;         // Tx
    
    // TXSTA - Transmit 0x24
    CSRC = 0;           // Clock source - assync = don't care
    TX9 = 0;            // 8-bit transmission
    TXEN = 1;           // Enable transmission
    SYNC = 0;           // Assynchronous mode
    SENDB = 0;          // Sync break transmission completed
    BRGH = 1;           // High-speed mode
    TRMT = 0;           // Transmit shift register empty
    TX9D = 0;           // 9-bit transmit data
    
    // RCSTA - Receive 0x90
    SPEN = 1;           // Serial port enable bit
    RX9 = 0;            // 8-bit receive
    SREN = 0;           // Single receibe - assync = don't care
    CREN = 1;           // Enable continuous receiver
    ADDEN = 0;          // Adress detect - assync = don't care
    FERR = 0;           // Framing error
    OERR = 0;           // Overrun error enabled
    RX9D = 0;           // 9-bit receive data
    
    BRG16 = 1;          // 16-bit baud
    
    if ((BRG16 == 0) && (BRGH == 0))
        SPBRG = (int)(_XTAL_FREQ / (64 * baudRate)) - 1;
    if ((BRG16 ^ BRGH) == 1)
        SPBRG = (int)(_XTAL_FREQ / (16 * baudRate)) - 1;
    if ((BRG16 == 1) && (BRGH == 1))
        SPBRG = (int)(_XTAL_FREQ / (4 * baudRate)) - 1;        
}

//-----------------------------------------------------------------------------

void USART_WriteChar(unsigned char USARTData)
{
    while(!TXIF);        // Wait 
    TXREG = USARTData;   // Send character
}

//-----------------------------------------------------------------------------
