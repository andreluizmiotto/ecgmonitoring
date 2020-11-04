
_ADC_Init:

;adc.c,9 :: 		void ADC_Init(void)
;adc.c,11 :: 		TRISA = 0b00000001;       /* AN0 as input port */
	MOVLW       1
	MOVWF       TRISA+0 
;adc.c,12 :: 		ADCON1 = 0b00001110;       /* AN0 as analog input port */
	MOVLW       14
	MOVWF       ADCON1+0 
;adc.c,13 :: 		ADRESH = 0;               /*Flush ADC output Register*/
	CLRF        ADRESH+0 
;adc.c,14 :: 		ADRESL = 0;
	CLRF        ADRESL+0 
;adc.c,15 :: 		}
L_end_ADC_Init:
	RETURN      0
; end of _ADC_Init

_ADC_Read:

;adc.c,17 :: 		void ADC_Read(int channel)
;adc.c,20 :: 		* and ADC is disabled i.e ADON = 0 */
	MOVLW       195
	ANDWF       ADCON0+0, 0 
	MOVWF       R2 
	MOVF        FARG_ADC_Read_channel+0, 0 
	MOVWF       R0 
	RLCF        R0, 1 
	BCF         R0, 0 
	RLCF        R0, 1 
	BCF         R0, 0 
	MOVLW       60
	ANDWF       R0, 1 
	MOVF        R0, 0 
	IORWF       R2, 0 
	MOVWF       ADCON0+0 
;adc.c,21 :: 		ADCON0 |= ((1<<ADON)|(1<<GO));                              /* Enable ADC and start conversion*/
	MOVLW       3
	IORWF       ADCON0+0, 1 
;adc.c,22 :: 		while (GO_bit == 1);                                  /* Wait for End of conversion i.e. Go/done'=0 conversion completed */
L_ADC_Read0:
	BTFSS       GO_bit+0, BitPos(GO_bit+0) 
	GOTO        L_ADC_Read1
	GOTO        L_ADC_Read0
L_ADC_Read1:
;adc.c,23 :: 		}
L_end_ADC_Read:
	RETURN      0
; end of _ADC_Read
