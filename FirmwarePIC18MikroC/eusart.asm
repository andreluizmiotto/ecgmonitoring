
_EUSART_Init:

;eusart.c,10 :: 		void EUSART_Init(long baudRate)
;eusart.c,13 :: 		TRISC.RC6 = 1;         // Tx
	BSF         TRISC+0, 6 
;eusart.c,14 :: 		TRISC.RC7 = 1;         // Rx
	BSF         TRISC+0, 7 
;eusart.c,22 :: 		SPBRG = (int)(_XTAL_FREQ / (4 * baudRate)) - 1;
	MOVF        FARG_EUSART_Init_baudRate+0, 0 
	MOVWF       R4 
	MOVF        FARG_EUSART_Init_baudRate+1, 0 
	MOVWF       R5 
	MOVF        FARG_EUSART_Init_baudRate+2, 0 
	MOVWF       R6 
	MOVF        FARG_EUSART_Init_baudRate+3, 0 
	MOVWF       R7 
	RLCF        R4, 1 
	BCF         R4, 0 
	RLCF        R5, 1 
	RLCF        R6, 1 
	RLCF        R7, 1 
	RLCF        R4, 1 
	BCF         R4, 0 
	RLCF        R5, 1 
	RLCF        R6, 1 
	RLCF        R7, 1 
	MOVLW       0
	MOVWF       R0 
	MOVLW       18
	MOVWF       R1 
	MOVLW       122
	MOVWF       R2 
	MOVLW       0
	MOVWF       R3 
	CALL        _Div_32x32_S+0, 0
	DECF        R0, 0 
	MOVWF       SPBRG+0 
;eusart.c,25 :: 		TXSTA.CSRC = 0;           // Clock source - assync = don't care
	BCF         TXSTA+0, 7 
;eusart.c,26 :: 		TXSTA.TX9 = 0;            // 8-bit transmission
	BCF         TXSTA+0, 6 
;eusart.c,27 :: 		TXSTA.TXEN = 1;           // Enable transmission
	BSF         TXSTA+0, 5 
;eusart.c,28 :: 		TXSTA.SYNC = 0;           // Assynchronous mode
	BCF         TXSTA+0, 4 
;eusart.c,29 :: 		TXSTA.SENDB = 0;          // Sync break transmission completed
	BCF         TXSTA+0, 3 
;eusart.c,30 :: 		TXSTA.BRGH = 1;           // High-speed mode
	BSF         TXSTA+0, 2 
;eusart.c,31 :: 		TXSTA.TRMT = 0;           // Transmit shift register empty
	BCF         TXSTA+0, 1 
;eusart.c,32 :: 		TXSTA.TX9D = 0;           // 9-bit transmit data
	BCF         TXSTA+0, 0 
;eusart.c,35 :: 		RCSTA.SPEN = 1;           // Serial port enable bit
	BSF         RCSTA+0, 7 
;eusart.c,36 :: 		RCSTA.RX9 = 0;            // 8-bit receive
	BCF         RCSTA+0, 6 
;eusart.c,37 :: 		RCSTA.SREN = 0;           // Single receibe - assync = don't care
	BCF         RCSTA+0, 5 
;eusart.c,38 :: 		RCSTA.CREN = 1;           // Enable continuous receiver
	BSF         RCSTA+0, 4 
;eusart.c,39 :: 		RCSTA.ADDEN = 0;          // Adress detect - assync = don't care
	BCF         RCSTA+0, 3 
;eusart.c,40 :: 		RCSTA.FERR = 0;           // Framing error
	BCF         RCSTA+0, 2 
;eusart.c,41 :: 		RCSTA.OERR = 0;           // Overrun error enabled
	BCF         RCSTA+0, 1 
;eusart.c,42 :: 		RCSTA.RX9D = 0;           // 9-bit receive data
	BCF         RCSTA+0, 0 
;eusart.c,45 :: 		BAUDCON.ABDOVF = 0;
	BCF         BAUDCON+0, 7 
;eusart.c,46 :: 		BAUDCON.RCIDL  = 0;
	BCF         BAUDCON+0, 6 
;eusart.c,47 :: 		BAUDCON.RXDTP  = 0;
	BCF         BAUDCON+0, 5 
;eusart.c,48 :: 		BAUDCON.TXCKP  = 0;
	BCF         BAUDCON+0, 4 
;eusart.c,49 :: 		BAUDCON.BRG16  = 1;         // 16-bit baud
	BSF         BAUDCON+0, 3 
;eusart.c,50 :: 		BAUDCON.WUE    = 0;
	BCF         BAUDCON+0, 1 
;eusart.c,51 :: 		BAUDCON.ABDEN  = 0;
	BCF         BAUDCON+0, 0 
;eusart.c,52 :: 		}
L_end_EUSART_Init:
	RETURN      0
; end of _EUSART_Init

_EUSART_WriteChar:

;eusart.c,54 :: 		void EUSART_WriteChar(unsigned char EUSARTData)
;eusart.c,56 :: 		Delay_1ms();
	CALL        _Delay_1ms+0, 0
;eusart.c,57 :: 		while(!TXIF);         // Wait
L_EUSART_WriteChar1:
;eusart.c,58 :: 		TXREG = EUSARTData;   // Send character
	MOVF        FARG_EUSART_WriteChar_EUSARTData+0, 0 
	MOVWF       TXREG+0 
;eusart.c,59 :: 		}
L_end_EUSART_WriteChar:
	RETURN      0
; end of _EUSART_WriteChar
