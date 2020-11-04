
_main:

;main.c,33 :: 		void main(void) org 0x1000
;main.c,35 :: 		OSCCON = 0x72;                /* Use internal oscillator of 8MHz Frequency */
	MOVLW       114
	MOVWF       OSCCON+0 
;main.c,36 :: 		PEIE_bit = 1;                 /* Enable Peripheral Interrupt */
	BSF         PEIE_bit+0, BitPos(PEIE_bit+0) 
;main.c,37 :: 		GIE_bit = 1;                  /* Enable Global Interrupt */
	BSF         GIE_bit+0, BitPos(GIE_bit+0) 
;main.c,38 :: 		CMCON = 0x07;                 /* Disable comparators */
	MOVLW       7
	MOVWF       CMCON+0 
;main.c,40 :: 		EUSART_Init(115200);
	MOVLW       0
	MOVWF       FARG_EUSART_Init_baudRate+0 
	MOVLW       194
	MOVWF       FARG_EUSART_Init_baudRate+1 
	MOVLW       1
	MOVWF       FARG_EUSART_Init_baudRate+2 
	MOVLW       0
	MOVWF       FARG_EUSART_Init_baudRate+3 
	CALL        _EUSART_Init+0, 0
;main.c,41 :: 		TIMER1_Init();
	CALL        _TIMER1_Init+0, 0
;main.c,42 :: 		ADC_Init();
	CALL        _ADC_Init+0, 0
;main.c,44 :: 		Delay_ms(500);
	MOVLW       6
	MOVWF       R11, 0
	MOVLW       19
	MOVWF       R12, 0
	MOVLW       173
	MOVWF       R13, 0
L_main0:
	DECFSZ      R13, 1, 1
	BRA         L_main0
	DECFSZ      R12, 1, 1
	BRA         L_main0
	DECFSZ      R11, 1, 1
	BRA         L_main0
	NOP
	NOP
;main.c,46 :: 		while(1)
L_main1:
;main.c,48 :: 		Delay_ms(5);
	MOVLW       13
	MOVWF       R12, 0
	MOVLW       251
	MOVWF       R13, 0
L_main3:
	DECFSZ      R13, 1, 1
	BRA         L_main3
	DECFSZ      R12, 1, 1
	BRA         L_main3
	NOP
	NOP
;main.c,55 :: 		HIGH = (CODIGO >> 8);
	MOVF        _CODIGO+1, 0 
	MOVWF       _HIGH+0 
	CLRF        _HIGH+1 
;main.c,56 :: 		LOW = CODIGO;
	MOVF        _CODIGO+0, 0 
	MOVWF       _LOW+0 
	MOVF        _CODIGO+1, 0 
	MOVWF       _LOW+1 
;main.c,58 :: 		if (CODIGO < 1023)
	MOVLW       3
	SUBWF       _CODIGO+1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main10
	MOVLW       255
	SUBWF       _CODIGO+0, 0 
L__main10:
	BTFSC       STATUS+0, 0 
	GOTO        L_main4
;main.c,59 :: 		CODIGO++;
	INFSNZ      _CODIGO+0, 1 
	INCF        _CODIGO+1, 1 
	GOTO        L_main5
L_main4:
;main.c,61 :: 		CODIGO = 0;
	CLRF        _CODIGO+0 
	CLRF        _CODIGO+1 
L_main5:
;main.c,63 :: 		ADC_Buffer[0] = HIGH;
	MOVF        _HIGH+0, 0 
	MOVWF       _ADC_Buffer+0 
;main.c,64 :: 		ADC_Buffer[1] = LOW;
	MOVF        _LOW+0, 0 
	MOVWF       _ADC_Buffer+1 
;main.c,66 :: 		EUSART_WriteChar('@');
	MOVLW       64
	MOVWF       FARG_EUSART_WriteChar_EUSARTData+0 
	CALL        _EUSART_WriteChar+0, 0
;main.c,67 :: 		EUSART_WriteChar('#');
	MOVLW       35
	MOVWF       FARG_EUSART_WriteChar_EUSARTData+0 
	CALL        _EUSART_WriteChar+0, 0
;main.c,68 :: 		EUSART_WriteChar('$');
	MOVLW       36
	MOVWF       FARG_EUSART_WriteChar_EUSARTData+0 
	CALL        _EUSART_WriteChar+0, 0
;main.c,69 :: 		checksum = 0x50;
	MOVLW       80
	MOVWF       _checksum+0 
;main.c,70 :: 		for(index = 0; index <= 1; index++) {
	CLRF        _index+0 
L_main6:
	MOVF        _index+0, 0 
	SUBLW       1
	BTFSS       STATUS+0, 0 
	GOTO        L_main7
;main.c,71 :: 		EUSART_WriteChar(ADC_Buffer[index]);
	MOVLW       _ADC_Buffer+0
	MOVWF       FSR0L+0 
	MOVLW       hi_addr(_ADC_Buffer+0)
	MOVWF       FSR0L+1 
	MOVF        _index+0, 0 
	ADDWF       FSR0L+0, 1 
	BTFSC       STATUS+0, 0 
	INCF        FSR0L+1, 1 
	MOVF        POSTINC0+0, 0 
	MOVWF       FARG_EUSART_WriteChar_EUSARTData+0 
	CALL        _EUSART_WriteChar+0, 0
;main.c,72 :: 		checksum ^= ADC_Buffer[index];
	MOVLW       _ADC_Buffer+0
	MOVWF       FSR2L+0 
	MOVLW       hi_addr(_ADC_Buffer+0)
	MOVWF       FSR2L+1 
	MOVF        _index+0, 0 
	ADDWF       FSR2L+0, 1 
	BTFSC       STATUS+0, 0 
	INCF        FSR2L+1, 1 
	MOVF        POSTINC2+0, 0 
	XORWF       _checksum+0, 1 
;main.c,70 :: 		for(index = 0; index <= 1; index++) {
	INCF        _index+0, 1 
;main.c,73 :: 		}
	GOTO        L_main6
L_main7:
;main.c,74 :: 		EUSART_WriteChar(checksum);	// Finalizador do pacote de dados por checksum.
	MOVF        _checksum+0, 0 
	MOVWF       FARG_EUSART_WriteChar_EUSARTData+0 
	CALL        _EUSART_WriteChar+0, 0
;main.c,75 :: 		}
	GOTO        L_main1
;main.c,76 :: 		}
L_end_main:
	GOTO        $+0
; end of _main
