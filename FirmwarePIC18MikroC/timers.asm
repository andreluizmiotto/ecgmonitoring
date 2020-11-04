
_TIMER0_Init:

;timers.c,10 :: 		void TIMER0_Init(void)
;timers.c,16 :: 		T0CON = 0b10001000;
	MOVLW       136
	MOVWF       T0CON+0 
;timers.c,17 :: 		INTCON.TMR0IE = 1;
	BSF         INTCON+0, 5 
;timers.c,18 :: 		}
L_end_TIMER0_Init:
	RETURN      0
; end of _TIMER0_Init

_TIMER0_Set:

;timers.c,20 :: 		void TIMER0_Set(unsigned int initialCount)
;timers.c,22 :: 		TMR0L = initialCount >> 8;
	MOVF        FARG_TIMER0_Set_initialCount+1, 0 
	MOVWF       R0 
	CLRF        R1 
	MOVF        R0, 0 
	MOVWF       TMR0L+0 
;timers.c,23 :: 		TMR0H = initialCount;
	MOVF        FARG_TIMER0_Set_initialCount+0, 0 
	MOVWF       TMR0H+0 
;timers.c,24 :: 		}
L_end_TIMER0_Set:
	RETURN      0
; end of _TIMER0_Set

_TIMER1_Init:

;timers.c,26 :: 		void TIMER1_Init(void)
;timers.c,29 :: 		T1CON.RD16    = 1;    // 16-Bit Read/Write Mode Enable bit (0-8bits, 1-16bits).
	BSF         T1CON+0, 7 
;timers.c,30 :: 		T1CON.T1RUN   = 1;    // Timer1 System Clock Status bit.
	BSF         T1CON+0, 6 
;timers.c,31 :: 		T1CON.T1CKPS1 = 0;    // 11 = 1:8 Prescale value
	BCF         T1CON+0, 5 
;timers.c,32 :: 		T1CON.T1CKPS0 = 0;    // 10 = 1:4 Prescale value
	BCF         T1CON+0, 4 
;timers.c,35 :: 		T1CON.T1OSCEN = 0;
	BCF         T1CON+0, 3 
;timers.c,36 :: 		T1CON.T1SYNC  = 1;
	BSF         T1CON+0, 2 
;timers.c,37 :: 		T1CON.TMR1CS  = 0;    // Timer1 Clock Source Select bit (0-Fosc/4, 1-RC0/T1OSO/T13CKI pin).
	BCF         T1CON+0, 1 
;timers.c,38 :: 		T1CON.TMR1ON  = 1;    // Timer1 enabled
	BSF         T1CON+0, 0 
;timers.c,40 :: 		INTCON.TMR1IE = 1;    /* Enable Timer1 Overflow Interrupt */
	BSF         INTCON+0, 0 
;timers.c,41 :: 		INTCON.TMR1IF = 0;
	BCF         INTCON+0, 0 
;timers.c,42 :: 		PIE1.TMR1IE   = 1;    /* Enable Timer1 peripheral interrupt */
	BSF         PIE1+0, 0 
;timers.c,45 :: 		}
L_end_TIMER1_Init:
	RETURN      0
; end of _TIMER1_Init

_TIMER1_Reset:

;timers.c,47 :: 		void TIMER1_Reset(void)
;timers.c,49 :: 		TMR1L = 0x77;
	MOVLW       119
	MOVWF       TMR1L+0 
;timers.c,53 :: 		* 65535 - 5000 = 60535 */
	MOVLW       236
	MOVWF       TMR1H+0 
;timers.c,54 :: 		TMR1IF_bit = 0x00;
	BCF         TMR1IF_bit+0, BitPos(TMR1IF_bit+0) 
;timers.c,55 :: 		}
L_end_TIMER1_Reset:
	RETURN      0
; end of _TIMER1_Reset
