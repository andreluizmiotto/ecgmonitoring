opt subtitle "Microchip Technology Omniscient Code Generator v1.44 (Free mode) build 201709140600"

opt pagewidth 120

	opt lm

	processor	16F877A
opt include "E:\Program Files (x86)\Microchip\xc8\v1.44\include\16f877a.cgen.inc"
clrc	macro
	bcf	3,0
	endm
clrz	macro
	bcf	3,2
	endm
setc	macro
	bsf	3,0
	endm
setz	macro
	bsf	3,2
	endm
skipc	macro
	btfss	3,0
	endm
skipz	macro
	btfss	3,2
	endm
skipnc	macro
	btfsc	3,0
	endm
skipnz	macro
	btfsc	3,2
	endm
# 52 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
INDF equ 00h ;# 
# 59 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
TMR0 equ 01h ;# 
# 66 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
PCL equ 02h ;# 
# 73 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
STATUS equ 03h ;# 
# 159 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
FSR equ 04h ;# 
# 166 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
PORTA equ 05h ;# 
# 216 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
PORTB equ 06h ;# 
# 278 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
PORTC equ 07h ;# 
# 340 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
PORTD equ 08h ;# 
# 402 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
PORTE equ 09h ;# 
# 434 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
PCLATH equ 0Ah ;# 
# 454 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
INTCON equ 0Bh ;# 
# 532 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
PIR1 equ 0Ch ;# 
# 594 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
PIR2 equ 0Dh ;# 
# 634 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
TMR1 equ 0Eh ;# 
# 641 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
TMR1L equ 0Eh ;# 
# 648 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
TMR1H equ 0Fh ;# 
# 655 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
T1CON equ 010h ;# 
# 730 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
TMR2 equ 011h ;# 
# 737 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
T2CON equ 012h ;# 
# 808 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
SSPBUF equ 013h ;# 
# 815 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
SSPCON equ 014h ;# 
# 885 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
CCPR1 equ 015h ;# 
# 892 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
CCPR1L equ 015h ;# 
# 899 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
CCPR1H equ 016h ;# 
# 906 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
CCP1CON equ 017h ;# 
# 964 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
RCSTA equ 018h ;# 
# 1059 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
TXREG equ 019h ;# 
# 1066 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
RCREG equ 01Ah ;# 
# 1073 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
CCPR2 equ 01Bh ;# 
# 1080 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
CCPR2L equ 01Bh ;# 
# 1087 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
CCPR2H equ 01Ch ;# 
# 1094 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
CCP2CON equ 01Dh ;# 
# 1152 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
ADRESH equ 01Eh ;# 
# 1159 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
ADCON0 equ 01Fh ;# 
# 1255 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
OPTION_REG equ 081h ;# 
# 1325 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
TRISA equ 085h ;# 
# 1375 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
TRISB equ 086h ;# 
# 1437 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
TRISC equ 087h ;# 
# 1499 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
TRISD equ 088h ;# 
# 1561 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
TRISE equ 089h ;# 
# 1618 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
PIE1 equ 08Ch ;# 
# 1680 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
PIE2 equ 08Dh ;# 
# 1720 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
PCON equ 08Eh ;# 
# 1754 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
SSPCON2 equ 091h ;# 
# 1816 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
PR2 equ 092h ;# 
# 1823 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
SSPADD equ 093h ;# 
# 1830 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
SSPSTAT equ 094h ;# 
# 1999 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
TXSTA equ 098h ;# 
# 2080 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
SPBRG equ 099h ;# 
# 2087 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
CMCON equ 09Ch ;# 
# 2157 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
CVRCON equ 09Dh ;# 
# 2222 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
ADRESL equ 09Eh ;# 
# 2229 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
ADCON1 equ 09Fh ;# 
# 2288 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
EEDATA equ 010Ch ;# 
# 2295 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
EEADR equ 010Dh ;# 
# 2302 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
EEDATH equ 010Eh ;# 
# 2309 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
EEADRH equ 010Fh ;# 
# 2316 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
EECON1 equ 018Ch ;# 
# 2361 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
EECON2 equ 018Dh ;# 
# 52 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
INDF equ 00h ;# 
# 59 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
TMR0 equ 01h ;# 
# 66 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
PCL equ 02h ;# 
# 73 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
STATUS equ 03h ;# 
# 159 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
FSR equ 04h ;# 
# 166 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
PORTA equ 05h ;# 
# 216 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
PORTB equ 06h ;# 
# 278 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
PORTC equ 07h ;# 
# 340 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
PORTD equ 08h ;# 
# 402 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
PORTE equ 09h ;# 
# 434 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
PCLATH equ 0Ah ;# 
# 454 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
INTCON equ 0Bh ;# 
# 532 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
PIR1 equ 0Ch ;# 
# 594 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
PIR2 equ 0Dh ;# 
# 634 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
TMR1 equ 0Eh ;# 
# 641 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
TMR1L equ 0Eh ;# 
# 648 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
TMR1H equ 0Fh ;# 
# 655 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
T1CON equ 010h ;# 
# 730 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
TMR2 equ 011h ;# 
# 737 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
T2CON equ 012h ;# 
# 808 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
SSPBUF equ 013h ;# 
# 815 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
SSPCON equ 014h ;# 
# 885 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
CCPR1 equ 015h ;# 
# 892 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
CCPR1L equ 015h ;# 
# 899 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
CCPR1H equ 016h ;# 
# 906 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
CCP1CON equ 017h ;# 
# 964 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
RCSTA equ 018h ;# 
# 1059 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
TXREG equ 019h ;# 
# 1066 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
RCREG equ 01Ah ;# 
# 1073 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
CCPR2 equ 01Bh ;# 
# 1080 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
CCPR2L equ 01Bh ;# 
# 1087 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
CCPR2H equ 01Ch ;# 
# 1094 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
CCP2CON equ 01Dh ;# 
# 1152 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
ADRESH equ 01Eh ;# 
# 1159 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
ADCON0 equ 01Fh ;# 
# 1255 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
OPTION_REG equ 081h ;# 
# 1325 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
TRISA equ 085h ;# 
# 1375 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
TRISB equ 086h ;# 
# 1437 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
TRISC equ 087h ;# 
# 1499 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
TRISD equ 088h ;# 
# 1561 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
TRISE equ 089h ;# 
# 1618 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
PIE1 equ 08Ch ;# 
# 1680 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
PIE2 equ 08Dh ;# 
# 1720 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
PCON equ 08Eh ;# 
# 1754 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
SSPCON2 equ 091h ;# 
# 1816 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
PR2 equ 092h ;# 
# 1823 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
SSPADD equ 093h ;# 
# 1830 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
SSPSTAT equ 094h ;# 
# 1999 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
TXSTA equ 098h ;# 
# 2080 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
SPBRG equ 099h ;# 
# 2087 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
CMCON equ 09Ch ;# 
# 2157 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
CVRCON equ 09Dh ;# 
# 2222 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
ADRESL equ 09Eh ;# 
# 2229 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
ADCON1 equ 09Fh ;# 
# 2288 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
EEDATA equ 010Ch ;# 
# 2295 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
EEADR equ 010Dh ;# 
# 2302 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
EEDATH equ 010Eh ;# 
# 2309 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
EEADRH equ 010Fh ;# 
# 2316 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
EECON1 equ 018Ch ;# 
# 2361 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
EECON2 equ 018Dh ;# 
# 52 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
INDF equ 00h ;# 
# 59 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
TMR0 equ 01h ;# 
# 66 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
PCL equ 02h ;# 
# 73 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
STATUS equ 03h ;# 
# 159 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
FSR equ 04h ;# 
# 166 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
PORTA equ 05h ;# 
# 216 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
PORTB equ 06h ;# 
# 278 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
PORTC equ 07h ;# 
# 340 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
PORTD equ 08h ;# 
# 402 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
PORTE equ 09h ;# 
# 434 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
PCLATH equ 0Ah ;# 
# 454 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
INTCON equ 0Bh ;# 
# 532 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
PIR1 equ 0Ch ;# 
# 594 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
PIR2 equ 0Dh ;# 
# 634 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
TMR1 equ 0Eh ;# 
# 641 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
TMR1L equ 0Eh ;# 
# 648 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
TMR1H equ 0Fh ;# 
# 655 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
T1CON equ 010h ;# 
# 730 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
TMR2 equ 011h ;# 
# 737 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
T2CON equ 012h ;# 
# 808 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
SSPBUF equ 013h ;# 
# 815 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
SSPCON equ 014h ;# 
# 885 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
CCPR1 equ 015h ;# 
# 892 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
CCPR1L equ 015h ;# 
# 899 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
CCPR1H equ 016h ;# 
# 906 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
CCP1CON equ 017h ;# 
# 964 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
RCSTA equ 018h ;# 
# 1059 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
TXREG equ 019h ;# 
# 1066 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
RCREG equ 01Ah ;# 
# 1073 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
CCPR2 equ 01Bh ;# 
# 1080 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
CCPR2L equ 01Bh ;# 
# 1087 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
CCPR2H equ 01Ch ;# 
# 1094 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
CCP2CON equ 01Dh ;# 
# 1152 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
ADRESH equ 01Eh ;# 
# 1159 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
ADCON0 equ 01Fh ;# 
# 1255 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
OPTION_REG equ 081h ;# 
# 1325 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
TRISA equ 085h ;# 
# 1375 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
TRISB equ 086h ;# 
# 1437 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
TRISC equ 087h ;# 
# 1499 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
TRISD equ 088h ;# 
# 1561 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
TRISE equ 089h ;# 
# 1618 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
PIE1 equ 08Ch ;# 
# 1680 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
PIE2 equ 08Dh ;# 
# 1720 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
PCON equ 08Eh ;# 
# 1754 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
SSPCON2 equ 091h ;# 
# 1816 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
PR2 equ 092h ;# 
# 1823 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
SSPADD equ 093h ;# 
# 1830 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
SSPSTAT equ 094h ;# 
# 1999 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
TXSTA equ 098h ;# 
# 2080 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
SPBRG equ 099h ;# 
# 2087 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
CMCON equ 09Ch ;# 
# 2157 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
CVRCON equ 09Dh ;# 
# 2222 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
ADRESL equ 09Eh ;# 
# 2229 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
ADCON1 equ 09Fh ;# 
# 2288 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
EEDATA equ 010Ch ;# 
# 2295 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
EEADR equ 010Dh ;# 
# 2302 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
EEDATH equ 010Eh ;# 
# 2309 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
EEADRH equ 010Fh ;# 
# 2316 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
EECON1 equ 018Ch ;# 
# 2361 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
EECON2 equ 018Dh ;# 
# 52 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
INDF equ 00h ;# 
# 59 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
TMR0 equ 01h ;# 
# 66 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
PCL equ 02h ;# 
# 73 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
STATUS equ 03h ;# 
# 159 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
FSR equ 04h ;# 
# 166 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
PORTA equ 05h ;# 
# 216 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
PORTB equ 06h ;# 
# 278 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
PORTC equ 07h ;# 
# 340 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
PORTD equ 08h ;# 
# 402 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
PORTE equ 09h ;# 
# 434 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
PCLATH equ 0Ah ;# 
# 454 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
INTCON equ 0Bh ;# 
# 532 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
PIR1 equ 0Ch ;# 
# 594 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
PIR2 equ 0Dh ;# 
# 634 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
TMR1 equ 0Eh ;# 
# 641 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
TMR1L equ 0Eh ;# 
# 648 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
TMR1H equ 0Fh ;# 
# 655 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
T1CON equ 010h ;# 
# 730 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
TMR2 equ 011h ;# 
# 737 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
T2CON equ 012h ;# 
# 808 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
SSPBUF equ 013h ;# 
# 815 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
SSPCON equ 014h ;# 
# 885 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
CCPR1 equ 015h ;# 
# 892 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
CCPR1L equ 015h ;# 
# 899 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
CCPR1H equ 016h ;# 
# 906 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
CCP1CON equ 017h ;# 
# 964 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
RCSTA equ 018h ;# 
# 1059 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
TXREG equ 019h ;# 
# 1066 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
RCREG equ 01Ah ;# 
# 1073 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
CCPR2 equ 01Bh ;# 
# 1080 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
CCPR2L equ 01Bh ;# 
# 1087 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
CCPR2H equ 01Ch ;# 
# 1094 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
CCP2CON equ 01Dh ;# 
# 1152 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
ADRESH equ 01Eh ;# 
# 1159 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
ADCON0 equ 01Fh ;# 
# 1255 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
OPTION_REG equ 081h ;# 
# 1325 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
TRISA equ 085h ;# 
# 1375 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
TRISB equ 086h ;# 
# 1437 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
TRISC equ 087h ;# 
# 1499 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
TRISD equ 088h ;# 
# 1561 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
TRISE equ 089h ;# 
# 1618 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
PIE1 equ 08Ch ;# 
# 1680 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
PIE2 equ 08Dh ;# 
# 1720 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
PCON equ 08Eh ;# 
# 1754 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
SSPCON2 equ 091h ;# 
# 1816 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
PR2 equ 092h ;# 
# 1823 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
SSPADD equ 093h ;# 
# 1830 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
SSPSTAT equ 094h ;# 
# 1999 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
TXSTA equ 098h ;# 
# 2080 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
SPBRG equ 099h ;# 
# 2087 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
CMCON equ 09Ch ;# 
# 2157 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
CVRCON equ 09Dh ;# 
# 2222 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
ADRESL equ 09Eh ;# 
# 2229 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
ADCON1 equ 09Fh ;# 
# 2288 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
EEDATA equ 010Ch ;# 
# 2295 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
EEADR equ 010Dh ;# 
# 2302 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
EEDATH equ 010Eh ;# 
# 2309 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
EEADRH equ 010Fh ;# 
# 2316 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
EECON1 equ 018Ch ;# 
# 2361 "E:\Program Files (x86)\Microchip\xc8\v1.44\include\pic16f877a.h"
EECON2 equ 018Dh ;# 
	FNCALL	_main,_ADC_Init
	FNCALL	_main,_TIMER1_Init
	FNCALL	_main,_TIMER1_Set
	FNCALL	_main,_USART_Init
	FNCALL	_main,_USART_WriteString
	FNCALL	_USART_WriteString,_USART_WriteChar
	FNCALL	_USART_Init,___aldiv
	FNROOT	_main
	FNCALL	_ISR,_ADC_Read
	FNCALL	_ISR,i1_TIMER1_Set
	FNCALL	_ISR,i1_USART_WriteChar
	FNCALL	_ISR,i1_USART_WriteString
	FNCALL	i1_USART_WriteString,i1_USART_WriteChar
	FNCALL	intlevel1,_ISR
	global	intlevel1
	FNROOT	intlevel1
	global	_ADC_Buffer
	global	_TMR1
_TMR1	set	0xE
	global	_T1CONbits
_T1CONbits	set	0x10
	global	_TMR0
_TMR0	set	0x1
	global	_ADCON0bits
_ADCON0bits	set	0x1F
	global	_RCREG
_RCREG	set	0x1A
	global	_TXREG
_TXREG	set	0x19
	global	_RCSTAbits
_RCSTAbits	set	0x18
	global	_INTCONbits
_INTCONbits	set	0xB
	global	_PORTC
_PORTC	set	0x7
	global	_PORTB
_PORTB	set	0x6
	global	_PORTA
_PORTA	set	0x5
	global	_ADRESH
_ADRESH	set	0x1E
	global	_PIR1bits
_PIR1bits	set	0xC
	global	_OERR
_OERR	set	0xC1
	global	_OPTION_REGbits
_OPTION_REGbits	set	0x81
	global	_ADCON1bits
_ADCON1bits	set	0x9F
	global	_PIE1bits
_PIE1bits	set	0x8C
	global	_TXSTAbits
_TXSTAbits	set	0x98
	global	_SPBRG
_SPBRG	set	0x99
	global	_TRISC
_TRISC	set	0x87
	global	_TRISB
_TRISB	set	0x86
	global	_TRISA
_TRISA	set	0x85
	global	_ADRESL
_ADRESL	set	0x9E
psect	strings,class=STRING,delta=2,noexec
global __pstrings
__pstrings:
stringtab:
	global    __stringtab
__stringtab:
;	String table - string pointers are 1 byte each
stringcode:stringdir:
movlw high(stringdir)
movwf pclath
movf fsr,w
incf fsr
	addwf pc
	global __stringbase
__stringbase:
	retlw	0
psect	strings
	global    __end_of__stringtab
__end_of__stringtab:
	
STR_3:	
	retlw	10
	retlw	13
	retlw	32	;' '
	retlw	45	;'-'
	retlw	45	;'-'
	retlw	45	;'-'
	retlw	45	;'-'
	retlw	45	;'-'
	retlw	45	;'-'
	retlw	45	;'-'
	retlw	32	;' '
	retlw	69	;'E'
	retlw	83	;'S'
	retlw	84	;'T'
	retlw	79	;'O'
	retlw	85	;'U'
	retlw	82	;'R'
	retlw	79	;'O'
	retlw	32	;' '
	retlw	68	;'D'
	retlw	69	;'E'
	retlw	32	;' '
	retlw	80	;'P'
	retlw	73	;'I'
	retlw	76	;'L'
	retlw	72	;'H'
	retlw	65	;'A'
	retlw	32	;' '
	retlw	45	;'-'
	retlw	45	;'-'
	retlw	45	;'-'
	retlw	45	;'-'
	retlw	45	;'-'
	retlw	45	;'-'
	retlw	45	;'-'
	retlw	32	;' '
	retlw	10
	retlw	13
	retlw	32	;' '
	retlw	0
psect	strings
	
STR_2:	
	retlw	73	;'I'
	retlw	110	;'n'
	retlw	105	;'i'
	retlw	99	;'c'
	retlw	105	;'i'
	retlw	97	;'a'
	retlw	108	;'l'
	retlw	105	;'i'
	retlw	122	;'z'
	retlw	97	;'a'
	retlw	110	;'n'
	retlw	100	;'d'
	retlw	111	;'o'
	retlw	32	;' '
	retlw	85	;'U'
	retlw	83	;'S'
	retlw	65	;'A'
	retlw	82	;'R'
	retlw	84	;'T'
	retlw	46	;'.'
	retlw	46	;'.'
	retlw	46	;'.'
	retlw	0
psect	strings
	
STR_1:	
	retlw	35	;'#'
	retlw	36	;'$'
	retlw	58	;':'
	retlw	0
psect	strings
; #config settings
global __CFG_FOSC$HS
__CFG_FOSC$HS equ 0x0
global __CFG_WDTE$OFF
__CFG_WDTE$OFF equ 0x0
global __CFG_PWRTE$OFF
__CFG_PWRTE$OFF equ 0x0
global __CFG_BOREN$OFF
__CFG_BOREN$OFF equ 0x0
global __CFG_LVP$OFF
__CFG_LVP$OFF equ 0x0
global __CFG_CPD$OFF
__CFG_CPD$OFF equ 0x0
global __CFG_WRT$OFF
__CFG_WRT$OFF equ 0x0
global __CFG_CP$OFF
__CFG_CP$OFF equ 0x0
	file	"Firmware.as"
	line	#
psect cinit,class=CODE,delta=2
global start_initialization
start_initialization:

global __initialization
__initialization:
psect	bssCOMMON,class=COMMON,space=1,noexec
global __pbssCOMMON
__pbssCOMMON:
_ADC_Buffer:
       ds      4

	file	"Firmware.as"
	line	#
; Clear objects allocated to COMMON
psect cinit,class=CODE,delta=2,merge=1
	clrf	((__pbssCOMMON)+0)&07Fh
	clrf	((__pbssCOMMON)+1)&07Fh
	clrf	((__pbssCOMMON)+2)&07Fh
	clrf	((__pbssCOMMON)+3)&07Fh
psect cinit,class=CODE,delta=2,merge=1
global end_of_initialization,__end_of__initialization

;End of C runtime variable initialization code

end_of_initialization:
__end_of__initialization:
clrf status
ljmp _main	;jump to C main() function
psect	cstackCOMMON,class=COMMON,space=1,noexec
global __pcstackCOMMON
__pcstackCOMMON:
?_ADC_Read:	; 1 bytes @ 0x0
?_USART_WriteString:	; 1 bytes @ 0x0
?_USART_WriteChar:	; 1 bytes @ 0x0
?_TIMER1_Init:	; 1 bytes @ 0x0
?_ADC_Init:	; 1 bytes @ 0x0
?_ISR:	; 1 bytes @ 0x0
?_main:	; 1 bytes @ 0x0
?i1_USART_WriteChar:	; 1 bytes @ 0x0
??i1_USART_WriteChar:	; 1 bytes @ 0x0
?i1_USART_WriteString:	; 1 bytes @ 0x0
?i1_TIMER1_Set:	; 1 bytes @ 0x0
	global	i1USART_WriteChar@USART_Data
i1USART_WriteChar@USART_Data:	; 1 bytes @ 0x0
	global	ADC_Read@channel
ADC_Read@channel:	; 2 bytes @ 0x0
	global	i1TIMER1_Set@count
i1TIMER1_Set@count:	; 2 bytes @ 0x0
	ds	1
??i1_USART_WriteString:	; 1 bytes @ 0x1
	ds	1
??_ADC_Read:	; 1 bytes @ 0x2
??i1_TIMER1_Set:	; 1 bytes @ 0x2
	global	i1USART_WriteString@str
i1USART_WriteString@str:	; 1 bytes @ 0x2
	ds	1
??_ISR:	; 1 bytes @ 0x3
	ds	5
	global	ISR@checksum
ISR@checksum:	; 1 bytes @ 0x8
	ds	1
	global	ISR@index
ISR@index:	; 1 bytes @ 0x9
	ds	1
psect	cstackBANK0,class=BANK0,space=1,noexec
global __pcstackBANK0
__pcstackBANK0:
?_TIMER1_Set:	; 1 bytes @ 0x0
??_USART_WriteChar:	; 1 bytes @ 0x0
??_TIMER1_Init:	; 1 bytes @ 0x0
??_ADC_Init:	; 1 bytes @ 0x0
	global	?___aldiv
?___aldiv:	; 4 bytes @ 0x0
	global	USART_WriteChar@USART_Data
USART_WriteChar@USART_Data:	; 1 bytes @ 0x0
	global	TIMER1_Set@count
TIMER1_Set@count:	; 2 bytes @ 0x0
	global	___aldiv@divisor
___aldiv@divisor:	; 4 bytes @ 0x0
	ds	1
??_USART_WriteString:	; 1 bytes @ 0x1
	ds	1
??_TIMER1_Set:	; 1 bytes @ 0x2
	global	USART_WriteString@str
USART_WriteString@str:	; 1 bytes @ 0x2
	ds	2
	global	___aldiv@dividend
___aldiv@dividend:	; 4 bytes @ 0x4
	ds	4
??___aldiv:	; 1 bytes @ 0x8
	ds	1
	global	___aldiv@counter
___aldiv@counter:	; 1 bytes @ 0x9
	ds	1
	global	___aldiv@sign
___aldiv@sign:	; 1 bytes @ 0xA
	ds	1
	global	___aldiv@quotient
___aldiv@quotient:	; 4 bytes @ 0xB
	ds	4
?_USART_Init:	; 1 bytes @ 0xF
	global	USART_Init@BaudRate
USART_Init@BaudRate:	; 4 bytes @ 0xF
	ds	4
??_USART_Init:	; 1 bytes @ 0x13
	ds	5
	global	USART_Init@BR
USART_Init@BR:	; 1 bytes @ 0x18
	ds	1
??_main:	; 1 bytes @ 0x19
;!
;!Data Sizes:
;!    Strings     67
;!    Constant    0
;!    Data        0
;!    BSS         4
;!    Persistent  0
;!    Stack       0
;!
;!Auto Spaces:
;!    Space          Size  Autos    Used
;!    COMMON           14     10      14
;!    BANK0            80     25      25
;!    BANK1            80      0       0
;!    BANK3            96      0       0
;!    BANK2            96      0       0

;!
;!Pointer List with Targets:
;!
;!    USART_WriteString@str	PTR const unsigned char  size(1) Largest target is 40
;!		 -> STR_3(CODE[40]), STR_2(CODE[23]), STR_1(CODE[4]), 
;!


;!
;!Critical Paths under _main in COMMON
;!
;!    None.
;!
;!Critical Paths under _ISR in COMMON
;!
;!    _ISR->_ADC_Read
;!    _ISR->i1_USART_WriteString
;!    i1_USART_WriteString->i1_USART_WriteChar
;!
;!Critical Paths under _main in BANK0
;!
;!    _main->_USART_Init
;!    _USART_WriteString->_USART_WriteChar
;!    _USART_Init->___aldiv
;!
;!Critical Paths under _ISR in BANK0
;!
;!    None.
;!
;!Critical Paths under _main in BANK1
;!
;!    None.
;!
;!Critical Paths under _ISR in BANK1
;!
;!    None.
;!
;!Critical Paths under _main in BANK3
;!
;!    None.
;!
;!Critical Paths under _ISR in BANK3
;!
;!    None.
;!
;!Critical Paths under _main in BANK2
;!
;!    None.
;!
;!Critical Paths under _ISR in BANK2
;!
;!    None.

;;
;;Main: autosize = 0, tempsize = 0, incstack = 0, save=0
;;

;!
;!Call Graph Tables:
;!
;! ---------------------------------------------------------------------------------
;! (Depth) Function   	        Calls       Base Space   Used Autos Params    Refs
;! ---------------------------------------------------------------------------------
;! (0) _main                                                 0     0      0     819
;!                           _ADC_Init
;!                        _TIMER1_Init
;!                         _TIMER1_Set
;!                         _USART_Init
;!                  _USART_WriteString
;! ---------------------------------------------------------------------------------
;! (1) _USART_WriteString                                    2     2      0     157
;!                                              1 BANK0      2     2      0
;!                    _USART_WriteChar
;! ---------------------------------------------------------------------------------
;! (2) _USART_WriteChar                                      1     1      0      22
;!                                              0 BANK0      1     1      0
;! ---------------------------------------------------------------------------------
;! (1) _USART_Init                                          10     6      4     538
;!                                             15 BANK0     10     6      4
;!                            ___aldiv
;! ---------------------------------------------------------------------------------
;! (2) ___aldiv                                             15     7      8     428
;!                                              0 BANK0     15     7      8
;! ---------------------------------------------------------------------------------
;! (1) _TIMER1_Set                                           2     0      2     124
;!                                              0 BANK0      2     0      2
;! ---------------------------------------------------------------------------------
;! (1) _TIMER1_Init                                          0     0      0       0
;! ---------------------------------------------------------------------------------
;! (1) _ADC_Init                                             0     0      0       0
;! ---------------------------------------------------------------------------------
;! Estimated maximum stack depth 2
;! ---------------------------------------------------------------------------------
;! (Depth) Function   	        Calls       Base Space   Used Autos Params    Refs
;! ---------------------------------------------------------------------------------
;! (3) _ISR                                                  7     7      0     401
;!                                              3 COMMON     7     7      0
;!                           _ADC_Read
;!                       i1_TIMER1_Set
;!                  i1_USART_WriteChar
;!                i1_USART_WriteString
;! ---------------------------------------------------------------------------------
;! (4) i1_USART_WriteString                                  2     2      0      67
;!                                              1 COMMON     2     2      0
;!                  i1_USART_WriteChar
;! ---------------------------------------------------------------------------------
;! (5) i1_USART_WriteChar                                    1     1      0      22
;!                                              0 COMMON     1     1      0
;! ---------------------------------------------------------------------------------
;! (4) i1_TIMER1_Set                                         2     0      2      48
;!                                              0 COMMON     2     0      2
;! ---------------------------------------------------------------------------------
;! (4) _ADC_Read                                             3     1      2     150
;!                                              0 COMMON     3     1      2
;! ---------------------------------------------------------------------------------
;! Estimated maximum stack depth 5
;! ---------------------------------------------------------------------------------
;!
;! Call Graph Graphs:
;!
;! _main (ROOT)
;!   _ADC_Init
;!   _TIMER1_Init
;!   _TIMER1_Set
;!   _USART_Init
;!     ___aldiv
;!   _USART_WriteString
;!     _USART_WriteChar
;!
;! _ISR (ROOT)
;!   _ADC_Read
;!   i1_TIMER1_Set
;!   i1_USART_WriteChar
;!   i1_USART_WriteString
;!     i1_USART_WriteChar
;!

;! Address spaces:

;!Name               Size   Autos  Total    Cost      Usage
;!BITCOMMON            E      0       0       0        0.0%
;!EEDATA             100      0       0       0        0.0%
;!NULL                 0      0       0       0        0.0%
;!CODE                 0      0       0       0        0.0%
;!COMMON               E      A       E       1      100.0%
;!BITSFR0              0      0       0       1        0.0%
;!SFR0                 0      0       0       1        0.0%
;!BITSFR1              0      0       0       2        0.0%
;!SFR1                 0      0       0       2        0.0%
;!STACK                0      0       0       2        0.0%
;!ABS                  0      0      27       3        0.0%
;!BITBANK0            50      0       0       4        0.0%
;!BITSFR3              0      0       0       4        0.0%
;!SFR3                 0      0       0       4        0.0%
;!BANK0               50     19      19       5       31.3%
;!BITSFR2              0      0       0       5        0.0%
;!SFR2                 0      0       0       5        0.0%
;!BITBANK1            50      0       0       6        0.0%
;!BANK1               50      0       0       7        0.0%
;!BITBANK3            60      0       0       8        0.0%
;!BANK3               60      0       0       9        0.0%
;!BITBANK2            60      0       0      10        0.0%
;!BANK2               60      0       0      11        0.0%
;!DATA                 0      0      27      12        0.0%

	global	_main

;; *************** function _main *****************
;; Defined at:
;;		line 45 in file "C:\Projects\BitBucketProjects\Firmwares e Supervisorios\AquisicaoSinais\Firmware\main.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;                  1    wreg      void 
;; Registers used:
;;		wreg, fsr0l, fsr0h, status,2, status,0, pclath, cstack
;; Tracked objects:
;;		On entry : B00/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK3   BANK2
;;      Params:         0       0       0       0       0
;;      Locals:         0       0       0       0       0
;;      Temps:          0       0       0       0       0
;;      Totals:         0       0       0       0       0
;;Total ram usage:        0 bytes
;; Hardware stack levels required when called:    5
;; This function calls:
;;		_ADC_Init
;;		_TIMER1_Init
;;		_TIMER1_Set
;;		_USART_Init
;;		_USART_WriteString
;; This function is called by:
;;		Startup code after reset
;; This function uses a non-reentrant model
;;
psect	maintext,global,class=CODE,delta=2,split=1,group=0
	file	"C:\Projects\BitBucketProjects\Firmwares e Supervisorios\AquisicaoSinais\Firmware\main.c"
	line	45
global __pmaintext
__pmaintext:	;psect for function _main
psect	maintext
	file	"C:\Projects\BitBucketProjects\Firmwares e Supervisorios\AquisicaoSinais\Firmware\main.c"
	line	45
	global	__size_of_main
	__size_of_main	equ	__end_of_main-_main
	
_main:	
;incstack = 0
	opt	stack 3
; Regs used in _main: [wreg-fsr0h+status,2+status,0+pclath+cstack]
	line	48
	
l947:	
;main.c: 48: TRISA = 0b00000011;
	movlw	low(03h)
	bsf	status, 5	;RP0=1, select bank1
	bcf	status, 6	;RP1=0, select bank1
	movwf	(133)^080h	;volatile
	line	49
;main.c: 49: PORTA = 0b00000011;
	movlw	low(03h)
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	movwf	(5)	;volatile
	line	50
	
l949:	
;main.c: 50: TRISB = 0b00000000;
	bsf	status, 5	;RP0=1, select bank1
	bcf	status, 6	;RP1=0, select bank1
	clrf	(134)^080h	;volatile
	line	51
	
l951:	
;main.c: 51: PORTB = 0b00000000;
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	clrf	(6)	;volatile
	line	52
;main.c: 52: TRISC = 0b10000000;
	movlw	low(080h)
	bsf	status, 5	;RP0=1, select bank1
	bcf	status, 6	;RP1=0, select bank1
	movwf	(135)^080h	;volatile
	line	53
;main.c: 53: PORTC = 0b11000000;
	movlw	low(0C0h)
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	movwf	(7)	;volatile
	line	56
	
l953:	
;main.c: 56: USART_Init(115200);
	movlw	0
	movwf	(USART_Init@BaudRate+3)
	movlw	01h
	movwf	(USART_Init@BaudRate+2)
	movlw	0C2h
	movwf	(USART_Init@BaudRate+1)
	movlw	0
	movwf	(USART_Init@BaudRate)

	fcall	_USART_Init
	line	57
;main.c: 57: TIMER1_Init();
	fcall	_TIMER1_Init
	line	58
;main.c: 58: ADC_Init();
	fcall	_ADC_Init
	line	61
	
l955:	
;main.c: 61: TIMER1_Set(42496);
	movlw	0
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	movwf	(TIMER1_Set@count)
	movlw	0A6h
	movwf	((TIMER1_Set@count))+1
	fcall	_TIMER1_Set
	line	64
	
l957:	
;main.c: 64: INTCONbits.PEIE = 1;
	bsf	(11),6	;volatile
	line	65
	
l959:	
;main.c: 65: INTCONbits.GIE = 1;
	bsf	(11),7	;volatile
	line	67
	
l961:	
;main.c: 67: USART_WriteString("Inicializando USART...");
	movlw	(low((((STR_2)-__stringbase)|8000h)))&0ffh
	fcall	_USART_WriteString
	line	69
;main.c: 69: while(1)
	
l49:	
	line	72
;main.c: 70: {
	
l50:	
	line	69
	goto	l49
	
l51:	
	line	73
	
l52:	
	global	start
	ljmp	start
	opt stack 0
GLOBAL	__end_of_main
	__end_of_main:
	signat	_main,89
	global	_USART_WriteString

;; *************** function _USART_WriteString *****************
;; Defined at:
;;		line 48 in file "C:\Projects\BitBucketProjects\Firmwares e Supervisorios\AquisicaoSinais\Firmware\usart.c"
;; Parameters:    Size  Location     Type
;;  str             1    wreg     PTR const unsigned char 
;;		 -> STR_3(40), STR_2(23), STR_1(4), 
;; Auto vars:     Size  Location     Type
;;  str             1    2[BANK0 ] PTR const unsigned char 
;;		 -> STR_3(40), STR_2(23), STR_1(4), 
;; Return value:  Size  Location     Type
;;                  1    wreg      void 
;; Registers used:
;;		wreg, fsr0l, fsr0h, status,2, status,0, pclath, cstack
;; Tracked objects:
;;		On entry : 0/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK3   BANK2
;;      Params:         0       0       0       0       0
;;      Locals:         0       1       0       0       0
;;      Temps:          0       1       0       0       0
;;      Totals:         0       2       0       0       0
;;Total ram usage:        2 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    4
;; This function calls:
;;		_USART_WriteChar
;; This function is called by:
;;		_main
;;		_USART_ReceiveChar
;; This function uses a non-reentrant model
;;
psect	text1,local,class=CODE,delta=2,merge=1,group=0
	file	"C:\Projects\BitBucketProjects\Firmwares e Supervisorios\AquisicaoSinais\Firmware\usart.c"
	line	48
global __ptext1
__ptext1:	;psect for function _USART_WriteString
psect	text1
	file	"C:\Projects\BitBucketProjects\Firmwares e Supervisorios\AquisicaoSinais\Firmware\usart.c"
	line	48
	global	__size_of_USART_WriteString
	__size_of_USART_WriteString	equ	__end_of_USART_WriteString-_USART_WriteString
	
_USART_WriteString:	
;incstack = 0
	opt	stack 3
; Regs used in _USART_WriteString: [wreg-fsr0h+status,2+status,0+pclath+cstack]
;USART_WriteString@str stored from wreg
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	movwf	(USART_WriteString@str)
	line	51
	
l851:	
;usart.c: 51: while(*str != '\0')
	goto	l857
	
l83:	
	line	54
	
l853:	
;usart.c: 52: {
;usart.c: 54: USART_WriteChar(*str);
	movf	(USART_WriteString@str),w
	movwf	fsr0
	fcall	stringdir
	fcall	_USART_WriteChar
	line	55
	
l855:	
;usart.c: 55: str++;
	movlw	low(01h)
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	movwf	(??_USART_WriteString+0)+0
	movf	(??_USART_WriteString+0)+0,w
	addwf	(USART_WriteString@str),f
	goto	l857
	line	56
	
l82:	
	line	51
	
l857:	
	movf	(USART_WriteString@str),w
	movwf	fsr0
	fcall	stringdir
	xorlw	0
	skipz
	goto	u341
	goto	u340
u341:
	goto	l853
u340:
	goto	l85
	
l84:	
	line	57
	
l85:	
	return
	opt stack 0
GLOBAL	__end_of_USART_WriteString
	__end_of_USART_WriteString:
	signat	_USART_WriteString,4217
	global	_USART_WriteChar

;; *************** function _USART_WriteChar *****************
;; Defined at:
;;		line 42 in file "C:\Projects\BitBucketProjects\Firmwares e Supervisorios\AquisicaoSinais\Firmware\usart.c"
;; Parameters:    Size  Location     Type
;;  USART_Data      1    wreg     unsigned char 
;; Auto vars:     Size  Location     Type
;;  USART_Data      1    0[BANK0 ] unsigned char 
;; Return value:  Size  Location     Type
;;                  1    wreg      void 
;; Registers used:
;;		wreg
;; Tracked objects:
;;		On entry : 0/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK3   BANK2
;;      Params:         0       0       0       0       0
;;      Locals:         0       1       0       0       0
;;      Temps:          0       0       0       0       0
;;      Totals:         0       1       0       0       0
;;Total ram usage:        1 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    3
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_USART_WriteString
;; This function uses a non-reentrant model
;;
psect	text2,local,class=CODE,delta=2,merge=1,group=0
	line	42
global __ptext2
__ptext2:	;psect for function _USART_WriteChar
psect	text2
	file	"C:\Projects\BitBucketProjects\Firmwares e Supervisorios\AquisicaoSinais\Firmware\usart.c"
	line	42
	global	__size_of_USART_WriteChar
	__size_of_USART_WriteChar	equ	__end_of_USART_WriteChar-_USART_WriteChar
	
_USART_WriteChar:	
;incstack = 0
	opt	stack 3
; Regs used in _USART_WriteChar: [wreg]
;USART_WriteChar@USART_Data stored from wreg
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	movwf	(USART_WriteChar@USART_Data)
	line	44
	
l793:	
;usart.c: 44: while(!PIR1bits.TXIF);
	goto	l76
	
l77:	
	
l76:	
	btfss	(12),4	;volatile
	goto	u211
	goto	u210
u211:
	goto	l76
u210:
	goto	l795
	
l78:	
	line	45
	
l795:	
;usart.c: 45: TXREG = USART_Data;
	movf	(USART_WriteChar@USART_Data),w
	movwf	(25)	;volatile
	line	46
	
l79:	
	return
	opt stack 0
GLOBAL	__end_of_USART_WriteChar
	__end_of_USART_WriteChar:
	signat	_USART_WriteChar,4217
	global	_USART_Init

;; *************** function _USART_Init *****************
;; Defined at:
;;		line 6 in file "C:\Projects\BitBucketProjects\Firmwares e Supervisorios\AquisicaoSinais\Firmware\usart.c"
;; Parameters:    Size  Location     Type
;;  BaudRate        4   15[BANK0 ] long 
;; Auto vars:     Size  Location     Type
;;  BR              1   24[BANK0 ] unsigned char 
;; Return value:  Size  Location     Type
;;                  1    wreg      void 
;; Registers used:
;;		wreg, status,2, status,0, pclath, cstack
;; Tracked objects:
;;		On entry : 0/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK3   BANK2
;;      Params:         0       4       0       0       0
;;      Locals:         0       1       0       0       0
;;      Temps:          0       5       0       0       0
;;      Totals:         0      10       0       0       0
;;Total ram usage:       10 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    4
;; This function calls:
;;		___aldiv
;; This function is called by:
;;		_main
;; This function uses a non-reentrant model
;;
psect	text3,local,class=CODE,delta=2,merge=1,group=0
	line	6
global __ptext3
__ptext3:	;psect for function _USART_Init
psect	text3
	file	"C:\Projects\BitBucketProjects\Firmwares e Supervisorios\AquisicaoSinais\Firmware\usart.c"
	line	6
	global	__size_of_USART_Init
	__size_of_USART_Init	equ	__end_of_USART_Init-_USART_Init
	
_USART_Init:	
;incstack = 0
	opt	stack 3
; Regs used in _USART_Init: [wreg+status,2+status,0+pclath+cstack]
	line	12
	
l859:	
;usart.c: 12: unsigned char BR = 0;
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	clrf	(USART_Init@BR)
	line	15
	
l861:	
;usart.c: 15: BR = (18432000 / (16 * BaudRate)) - 1;
	movf	(USART_Init@BaudRate),w
	movwf	(??_USART_Init+0)+0
	movf	(USART_Init@BaudRate+1),w
	movwf	((??_USART_Init+0)+0+1)
	movf	(USART_Init@BaudRate+2),w
	movwf	((??_USART_Init+0)+0+2)
	movf	(USART_Init@BaudRate+3),w
	movwf	((??_USART_Init+0)+0+3)
	movlw	04h
u355:
	clrc
	rlf	(??_USART_Init+0)+0,f
	rlf	(??_USART_Init+0)+1,f
	rlf	(??_USART_Init+0)+2,f
	rlf	(??_USART_Init+0)+3,f
u350:
	addlw	-1
	skipz
	goto	u355
	movf	3+(??_USART_Init+0)+0,w
	movwf	(___aldiv@divisor+3)
	movf	2+(??_USART_Init+0)+0,w
	movwf	(___aldiv@divisor+2)
	movf	1+(??_USART_Init+0)+0,w
	movwf	(___aldiv@divisor+1)
	movf	0+(??_USART_Init+0)+0,w
	movwf	(___aldiv@divisor)

	movlw	01h
	movwf	(___aldiv@dividend+3)
	movlw	019h
	movwf	(___aldiv@dividend+2)
	movlw	040h
	movwf	(___aldiv@dividend+1)
	movlw	0
	movwf	(___aldiv@dividend)

	fcall	___aldiv
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	movf	(0+(?___aldiv)),w
	addlw	0FFh
	movwf	(??_USART_Init+4)+0
	movf	(??_USART_Init+4)+0,w
	movwf	(USART_Init@BR)
	line	16
	
l863:	
;usart.c: 16: SPBRG = BR;
	movf	(USART_Init@BR),w
	bsf	status, 5	;RP0=1, select bank1
	bcf	status, 6	;RP1=0, select bank1
	movwf	(153)^080h	;volatile
	line	19
	
l865:	
;usart.c: 19: TXSTAbits.CSRC = 0;
	bcf	(152)^080h,7	;volatile
	line	20
	
l867:	
;usart.c: 20: TXSTAbits.TX9 = 0;
	bcf	(152)^080h,6	;volatile
	line	21
	
l869:	
;usart.c: 21: TXSTAbits.TXEN = 1;
	bsf	(152)^080h,5	;volatile
	line	22
	
l871:	
;usart.c: 22: TXSTAbits.SYNC = 0;
	bcf	(152)^080h,4	;volatile
	line	23
	
l873:	
;usart.c: 23: TXSTAbits.BRGH = 1;
	bsf	(152)^080h,2	;volatile
	line	24
	
l875:	
;usart.c: 24: TXSTAbits.TRMT = 1;
	bsf	(152)^080h,1	;volatile
	line	25
	
l877:	
;usart.c: 25: TXSTAbits.TX9D = 0;
	bcf	(152)^080h,0	;volatile
	line	28
	
l879:	
;usart.c: 28: RCSTAbits.SPEN = 1;
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	bsf	(24),7	;volatile
	line	29
	
l881:	
;usart.c: 29: RCSTAbits.RX9 = 0;
	bcf	(24),6	;volatile
	line	30
	
l883:	
;usart.c: 30: RCSTAbits.SREN = 0;
	bcf	(24),5	;volatile
	line	31
	
l885:	
;usart.c: 31: RCSTAbits.CREN = 1;
	bsf	(24),4	;volatile
	line	32
	
l887:	
;usart.c: 32: RCSTAbits.ADDEN = 0;
	bcf	(24),3	;volatile
	line	33
	
l889:	
;usart.c: 33: RCSTAbits.FERR = 0;
	bcf	(24),2	;volatile
	line	34
	
l891:	
;usart.c: 34: RCSTAbits.OERR = 0;
	bcf	(24),1	;volatile
	line	35
	
l893:	
;usart.c: 35: RCSTAbits.RX9D = 0;
	bcf	(24),0	;volatile
	line	38
	
l895:	
;usart.c: 38: PIE1bits.RCIE = 1;
	bsf	status, 5	;RP0=1, select bank1
	bcf	status, 6	;RP1=0, select bank1
	bsf	(140)^080h,5	;volatile
	line	39
	
l897:	
;usart.c: 39: PIR1bits.RCIF = 0;
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	bcf	(12),5	;volatile
	line	40
	
l73:	
	return
	opt stack 0
GLOBAL	__end_of_USART_Init
	__end_of_USART_Init:
	signat	_USART_Init,4217
	global	___aldiv

;; *************** function ___aldiv *****************
;; Defined at:
;;		line 6 in file "E:\Program Files (x86)\Microchip\xc8\v1.44\sources\common\aldiv.c"
;; Parameters:    Size  Location     Type
;;  divisor         4    0[BANK0 ] long 
;;  dividend        4    4[BANK0 ] long 
;; Auto vars:     Size  Location     Type
;;  quotient        4   11[BANK0 ] long 
;;  sign            1   10[BANK0 ] unsigned char 
;;  counter         1    9[BANK0 ] unsigned char 
;; Return value:  Size  Location     Type
;;                  4    0[BANK0 ] long 
;; Registers used:
;;		wreg, status,2, status,0
;; Tracked objects:
;;		On entry : 0/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK3   BANK2
;;      Params:         0       8       0       0       0
;;      Locals:         0       6       0       0       0
;;      Temps:          0       1       0       0       0
;;      Totals:         0      15       0       0       0
;;Total ram usage:       15 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    3
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_USART_Init
;; This function uses a non-reentrant model
;;
psect	text4,local,class=CODE,delta=2,merge=1,group=2
	file	"E:\Program Files (x86)\Microchip\xc8\v1.44\sources\common\aldiv.c"
	line	6
global __ptext4
__ptext4:	;psect for function ___aldiv
psect	text4
	file	"E:\Program Files (x86)\Microchip\xc8\v1.44\sources\common\aldiv.c"
	line	6
	global	__size_of___aldiv
	__size_of___aldiv	equ	__end_of___aldiv-___aldiv
	
___aldiv:	
;incstack = 0
	opt	stack 3
; Regs used in ___aldiv: [wreg+status,2+status,0]
	line	14
	
l797:	
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	clrf	(___aldiv@sign)
	line	15
	
l799:	
	btfss	(___aldiv@divisor+3),7
	goto	u221
	goto	u220
u221:
	goto	l274
u220:
	line	16
	
l801:	
	comf	(___aldiv@divisor),f
	comf	(___aldiv@divisor+1),f
	comf	(___aldiv@divisor+2),f
	comf	(___aldiv@divisor+3),f
	incf	(___aldiv@divisor),f
	skipnz
	incf	(___aldiv@divisor+1),f
	skipnz
	incf	(___aldiv@divisor+2),f
	skipnz
	incf	(___aldiv@divisor+3),f
	line	17
	clrf	(___aldiv@sign)
	incf	(___aldiv@sign),f
	line	18
	
l274:	
	line	19
	btfss	(___aldiv@dividend+3),7
	goto	u231
	goto	u230
u231:
	goto	l807
u230:
	line	20
	
l803:	
	comf	(___aldiv@dividend),f
	comf	(___aldiv@dividend+1),f
	comf	(___aldiv@dividend+2),f
	comf	(___aldiv@dividend+3),f
	incf	(___aldiv@dividend),f
	skipnz
	incf	(___aldiv@dividend+1),f
	skipnz
	incf	(___aldiv@dividend+2),f
	skipnz
	incf	(___aldiv@dividend+3),f
	line	21
	
l805:	
	movlw	low(01h)
	movwf	(??___aldiv+0)+0
	movf	(??___aldiv+0)+0,w
	xorwf	(___aldiv@sign),f
	goto	l807
	line	22
	
l275:	
	line	23
	
l807:	
	movlw	high highword(0)
	movwf	(___aldiv@quotient+3)
	movlw	low highword(0)
	movwf	(___aldiv@quotient+2)
	movlw	high(0)
	movwf	(___aldiv@quotient+1)
	movlw	low(0)
	movwf	(___aldiv@quotient)

	line	24
	
l809:	
	movf	(___aldiv@divisor+3),w
	iorwf	(___aldiv@divisor+2),w
	iorwf	(___aldiv@divisor+1),w
	iorwf	(___aldiv@divisor),w
	skipnz
	goto	u241
	goto	u240
u241:
	goto	l829
u240:
	line	25
	
l811:	
	clrf	(___aldiv@counter)
	incf	(___aldiv@counter),f
	line	26
	goto	l815
	
l278:	
	line	27
	
l813:	
	movlw	01h
	movwf	(??___aldiv+0)+0
u255:
	clrc
	rlf	(___aldiv@divisor),f
	rlf	(___aldiv@divisor+1),f
	rlf	(___aldiv@divisor+2),f
	rlf	(___aldiv@divisor+3),f
	decfsz	(??___aldiv+0)+0
	goto	u255
	line	28
	movlw	low(01h)
	movwf	(??___aldiv+0)+0
	movf	(??___aldiv+0)+0,w
	addwf	(___aldiv@counter),f
	goto	l815
	line	29
	
l277:	
	line	26
	
l815:	
	btfss	(___aldiv@divisor+3),(31)&7
	goto	u261
	goto	u260
u261:
	goto	l813
u260:
	goto	l817
	
l279:	
	goto	l817
	line	30
	
l280:	
	line	31
	
l817:	
	movlw	01h
	movwf	(??___aldiv+0)+0
u275:
	clrc
	rlf	(___aldiv@quotient),f
	rlf	(___aldiv@quotient+1),f
	rlf	(___aldiv@quotient+2),f
	rlf	(___aldiv@quotient+3),f
	decfsz	(??___aldiv+0)+0
	goto	u275
	line	32
	
l819:	
	movf	(___aldiv@divisor+3),w
	subwf	(___aldiv@dividend+3),w
	skipz
	goto	u285
	movf	(___aldiv@divisor+2),w
	subwf	(___aldiv@dividend+2),w
	skipz
	goto	u285
	movf	(___aldiv@divisor+1),w
	subwf	(___aldiv@dividend+1),w
	skipz
	goto	u285
	movf	(___aldiv@divisor),w
	subwf	(___aldiv@dividend),w
u285:
	skipc
	goto	u281
	goto	u280
u281:
	goto	l825
u280:
	line	33
	
l821:	
	movf	(___aldiv@divisor),w
	subwf	(___aldiv@dividend),f
	movf	(___aldiv@divisor+1),w
	skipc
	incfsz	(___aldiv@divisor+1),w
	subwf	(___aldiv@dividend+1),f
	movf	(___aldiv@divisor+2),w
	skipc
	incfsz	(___aldiv@divisor+2),w
	subwf	(___aldiv@dividend+2),f
	movf	(___aldiv@divisor+3),w
	skipc
	incfsz	(___aldiv@divisor+3),w
	subwf	(___aldiv@dividend+3),f
	line	34
	
l823:	
	bsf	(___aldiv@quotient)+(0/8),(0)&7
	goto	l825
	line	35
	
l281:	
	line	36
	
l825:	
	movlw	01h
u295:
	clrc
	rrf	(___aldiv@divisor+3),f
	rrf	(___aldiv@divisor+2),f
	rrf	(___aldiv@divisor+1),f
	rrf	(___aldiv@divisor),f
	addlw	-1
	skipz
	goto	u295

	line	37
	
l827:	
	movlw	01h
	subwf	(___aldiv@counter),f
	btfss	status,2
	goto	u301
	goto	u300
u301:
	goto	l817
u300:
	goto	l829
	
l282:	
	goto	l829
	line	38
	
l276:	
	line	39
	
l829:	
	movf	((___aldiv@sign)),w
	btfsc	status,2
	goto	u311
	goto	u310
u311:
	goto	l833
u310:
	line	40
	
l831:	
	comf	(___aldiv@quotient),f
	comf	(___aldiv@quotient+1),f
	comf	(___aldiv@quotient+2),f
	comf	(___aldiv@quotient+3),f
	incf	(___aldiv@quotient),f
	skipnz
	incf	(___aldiv@quotient+1),f
	skipnz
	incf	(___aldiv@quotient+2),f
	skipnz
	incf	(___aldiv@quotient+3),f
	goto	l833
	
l283:	
	line	41
	
l833:	
	movf	(___aldiv@quotient+3),w
	movwf	(?___aldiv+3)
	movf	(___aldiv@quotient+2),w
	movwf	(?___aldiv+2)
	movf	(___aldiv@quotient+1),w
	movwf	(?___aldiv+1)
	movf	(___aldiv@quotient),w
	movwf	(?___aldiv)

	goto	l284
	
l835:	
	line	42
	
l284:	
	return
	opt stack 0
GLOBAL	__end_of___aldiv
	__end_of___aldiv:
	signat	___aldiv,8316
	global	_TIMER1_Set

;; *************** function _TIMER1_Set *****************
;; Defined at:
;;		line 36 in file "C:\Projects\BitBucketProjects\Firmwares e Supervisorios\AquisicaoSinais\Firmware\timers.c"
;; Parameters:    Size  Location     Type
;;  count           2    0[BANK0 ] unsigned int 
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;                  1    wreg      void 
;; Registers used:
;;		wreg
;; Tracked objects:
;;		On entry : 0/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK3   BANK2
;;      Params:         0       2       0       0       0
;;      Locals:         0       0       0       0       0
;;      Temps:          0       0       0       0       0
;;      Totals:         0       2       0       0       0
;;Total ram usage:        2 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    3
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_main
;; This function uses a non-reentrant model
;;
psect	text5,local,class=CODE,delta=2,merge=1,group=0
	file	"C:\Projects\BitBucketProjects\Firmwares e Supervisorios\AquisicaoSinais\Firmware\timers.c"
	line	36
global __ptext5
__ptext5:	;psect for function _TIMER1_Set
psect	text5
	file	"C:\Projects\BitBucketProjects\Firmwares e Supervisorios\AquisicaoSinais\Firmware\timers.c"
	line	36
	global	__size_of_TIMER1_Set
	__size_of_TIMER1_Set	equ	__end_of_TIMER1_Set-_TIMER1_Set
	
_TIMER1_Set:	
;incstack = 0
	opt	stack 4
; Regs used in _TIMER1_Set: [wreg]
	line	38
	
l841:	
;timers.c: 38: TMR1 = count;
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	movf	(TIMER1_Set@count+1),w
	movwf	(14+1)	;volatile
	movf	(TIMER1_Set@count),w
	movwf	(14)	;volatile
	line	39
	
l135:	
	return
	opt stack 0
GLOBAL	__end_of_TIMER1_Set
	__end_of_TIMER1_Set:
	signat	_TIMER1_Set,4217
	global	_TIMER1_Init

;; *************** function _TIMER1_Init *****************
;; Defined at:
;;		line 23 in file "C:\Projects\BitBucketProjects\Firmwares e Supervisorios\AquisicaoSinais\Firmware\timers.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;                  1    wreg      void 
;; Registers used:
;;		None
;; Tracked objects:
;;		On entry : 0/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK3   BANK2
;;      Params:         0       0       0       0       0
;;      Locals:         0       0       0       0       0
;;      Temps:          0       0       0       0       0
;;      Totals:         0       0       0       0       0
;;Total ram usage:        0 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    3
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_main
;; This function uses a non-reentrant model
;;
psect	text6,local,class=CODE,delta=2,merge=1,group=0
	line	23
global __ptext6
__ptext6:	;psect for function _TIMER1_Init
psect	text6
	file	"C:\Projects\BitBucketProjects\Firmwares e Supervisorios\AquisicaoSinais\Firmware\timers.c"
	line	23
	global	__size_of_TIMER1_Init
	__size_of_TIMER1_Init	equ	__end_of_TIMER1_Init-_TIMER1_Init
	
_TIMER1_Init:	
;incstack = 0
	opt	stack 4
; Regs used in _TIMER1_Init: []
	line	26
	
l899:	
;timers.c: 26: T1CONbits.T1CKPS1 = 0;
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	bcf	(16),5	;volatile
	line	27
;timers.c: 27: T1CONbits.T1CKPS0 = 0;
	bcf	(16),4	;volatile
	line	28
;timers.c: 28: T1CONbits.T1OSCEN = 1;
	bsf	(16),3	;volatile
	line	29
;timers.c: 29: T1CONbits.nT1SYNC = 1;
	bsf	(16),2	;volatile
	line	30
;timers.c: 30: T1CONbits.TMR1CS = 0;
	bcf	(16),1	;volatile
	line	31
;timers.c: 31: T1CONbits.TMR1ON = 1;
	bsf	(16),0	;volatile
	line	32
;timers.c: 32: PIE1bits.TMR1IE = 1;
	bsf	status, 5	;RP0=1, select bank1
	bcf	status, 6	;RP1=0, select bank1
	bsf	(140)^080h,0	;volatile
	line	33
;timers.c: 33: PIR1bits.TMR1IF = 0;
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	bcf	(12),0	;volatile
	line	34
	
l132:	
	return
	opt stack 0
GLOBAL	__end_of_TIMER1_Init
	__end_of_TIMER1_Init:
	signat	_TIMER1_Init,89
	global	_ADC_Init

;; *************** function _ADC_Init *****************
;; Defined at:
;;		line 6 in file "C:\Projects\BitBucketProjects\Firmwares e Supervisorios\AquisicaoSinais\Firmware\adc.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;                  1    wreg      void 
;; Registers used:
;;		None
;; Tracked objects:
;;		On entry : 0/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK3   BANK2
;;      Params:         0       0       0       0       0
;;      Locals:         0       0       0       0       0
;;      Temps:          0       0       0       0       0
;;      Totals:         0       0       0       0       0
;;Total ram usage:        0 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    3
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_main
;; This function uses a non-reentrant model
;;
psect	text7,local,class=CODE,delta=2,merge=1,group=0
	file	"C:\Projects\BitBucketProjects\Firmwares e Supervisorios\AquisicaoSinais\Firmware\adc.c"
	line	6
global __ptext7
__ptext7:	;psect for function _ADC_Init
psect	text7
	file	"C:\Projects\BitBucketProjects\Firmwares e Supervisorios\AquisicaoSinais\Firmware\adc.c"
	line	6
	global	__size_of_ADC_Init
	__size_of_ADC_Init	equ	__end_of_ADC_Init-_ADC_Init
	
_ADC_Init:	
;incstack = 0
	opt	stack 4
; Regs used in _ADC_Init: []
	line	9
	
l901:	
;adc.c: 9: ADCON1bits.ADFM = 1;
	bsf	status, 5	;RP0=1, select bank1
	bcf	status, 6	;RP1=0, select bank1
	bsf	(159)^080h,7	;volatile
	line	10
;adc.c: 10: ADCON1bits.PCFG3 = 0;
	bcf	(159)^080h,3	;volatile
	line	11
;adc.c: 11: ADCON1bits.PCFG2 = 0;
	bcf	(159)^080h,2	;volatile
	line	12
;adc.c: 12: ADCON1bits.PCFG1 = 0;
	bcf	(159)^080h,1	;volatile
	line	13
;adc.c: 13: ADCON1bits.PCFG0 = 0;
	bcf	(159)^080h,0	;volatile
	line	17
;adc.c: 17: ADCON0bits.ADCS1 = 1;
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	bsf	(31),7	;volatile
	line	18
;adc.c: 18: ADCON0bits.ADCS0 = 0;
	bcf	(31),6	;volatile
	line	21
;adc.c: 21: PIE1bits.ADIE = 0;
	bsf	status, 5	;RP0=1, select bank1
	bcf	status, 6	;RP1=0, select bank1
	bcf	(140)^080h,6	;volatile
	line	22
;adc.c: 22: PIR1bits.ADIF = 0;
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	bcf	(12),6	;volatile
	line	23
	
l103:	
	return
	opt stack 0
GLOBAL	__end_of_ADC_Init
	__end_of_ADC_Init:
	signat	_ADC_Init,89
	global	_ISR

;; *************** function _ISR *****************
;; Defined at:
;;		line 12 in file "C:\Projects\BitBucketProjects\Firmwares e Supervisorios\AquisicaoSinais\Firmware\main.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;  index           1    9[COMMON] unsigned char 
;;  checksum        1    8[COMMON] unsigned char 
;; Return value:  Size  Location     Type
;;                  1    wreg      void 
;; Registers used:
;;		wreg, fsr0l, fsr0h, status,2, status,0, pclath, cstack
;; Tracked objects:
;;		On entry : 0/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK3   BANK2
;;      Params:         0       0       0       0       0
;;      Locals:         2       0       0       0       0
;;      Temps:          5       0       0       0       0
;;      Totals:         7       0       0       0       0
;;Total ram usage:        7 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    2
;; This function calls:
;;		_ADC_Read
;;		i1_TIMER1_Set
;;		i1_USART_WriteChar
;;		i1_USART_WriteString
;; This function is called by:
;;		Interrupt level 1
;; This function uses a non-reentrant model
;;
psect	text8,local,class=CODE,delta=2,merge=1,group=0
	file	"C:\Projects\BitBucketProjects\Firmwares e Supervisorios\AquisicaoSinais\Firmware\main.c"
	line	12
global __ptext8
__ptext8:	;psect for function _ISR
psect	text8
	file	"C:\Projects\BitBucketProjects\Firmwares e Supervisorios\AquisicaoSinais\Firmware\main.c"
	line	12
	global	__size_of_ISR
	__size_of_ISR	equ	__end_of_ISR-_ISR
	
_ISR:	
;incstack = 0
	opt	stack 3
; Regs used in _ISR: [wreg-fsr0h+status,2+status,0+pclath+cstack]
psect	intentry,class=CODE,delta=2
global __pintentry
__pintentry:
global interrupt_function
interrupt_function:
	global saved_w
	saved_w	set	btemp+0
	movwf	saved_w
	swapf	status,w
	movwf	(??_ISR+1)
	movf	fsr0,w
	movwf	(??_ISR+2)
	movf	pclath,w
	movwf	(??_ISR+3)
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	movf	btemp+1,w
	movwf	(??_ISR+4)
	ljmp	_ISR
psect	text8
	line	15
	
i1l913:	
;main.c: 15: if(PIR1bits.TMR1IF)
	btfss	(12),0	;volatile
	goto	u37_21
	goto	u37_20
u37_21:
	goto	i1l44
u37_20:
	line	17
	
i1l915:	
;main.c: 16: {
;main.c: 17: PIR1bits.TMR1IF = 0;
	bcf	(12),0	;volatile
	line	19
	
i1l917:	
;main.c: 19: TIMER1_Set(42496);
	movlw	0
	movwf	(i1TIMER1_Set@count)
	movlw	0A6h
	movwf	((i1TIMER1_Set@count))+1
	fcall	i1_TIMER1_Set
	line	22
;main.c: 22: ADC_Read(0);
	movlw	0
	movwf	(ADC_Read@channel)
	movwf	(ADC_Read@channel+1)
	fcall	_ADC_Read
	line	23
	
i1l919:	
;main.c: 23: ADC_Buffer[0] = ADRESH;
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	movf	(30),w	;volatile
	movwf	(??_ISR+0)+0
	movf	(??_ISR+0)+0,w
	movwf	(_ADC_Buffer)
	line	24
	
i1l921:	
;main.c: 24: ADC_Buffer[1] = ADRESL;
	bsf	status, 5	;RP0=1, select bank1
	bcf	status, 6	;RP1=0, select bank1
	movf	(158)^080h,w	;volatile
	movwf	(??_ISR+0)+0
	movf	(??_ISR+0)+0,w
	movwf	0+(_ADC_Buffer)+01h
	line	27
;main.c: 27: ADC_Read(1);
	movlw	01h
	movwf	(ADC_Read@channel)
	movlw	0
	movwf	((ADC_Read@channel))+1
	fcall	_ADC_Read
	line	28
	
i1l923:	
;main.c: 28: ADC_Buffer[2] = ADRESH;
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	movf	(30),w	;volatile
	movwf	(??_ISR+0)+0
	movf	(??_ISR+0)+0,w
	movwf	0+(_ADC_Buffer)+02h
	line	29
	
i1l925:	
;main.c: 29: ADC_Buffer[3] = ADRESL;
	bsf	status, 5	;RP0=1, select bank1
	bcf	status, 6	;RP1=0, select bank1
	movf	(158)^080h,w	;volatile
	movwf	(??_ISR+0)+0
	movf	(??_ISR+0)+0,w
	movwf	0+(_ADC_Buffer)+03h
	line	32
	
i1l927:	
;main.c: 32: USART_WriteString("#$:");
	movlw	(low((((STR_1)-__stringbase)|8000h)))&0ffh
	fcall	i1_USART_WriteString
	line	34
	
i1l929:	
;main.c: 34: unsigned char checksum = 61;
	movlw	low(03Dh)
	movwf	(??_ISR+0)+0
	movf	(??_ISR+0)+0,w
	movwf	(ISR@checksum)
	line	35
	
i1l931:	
;main.c: 35: for(unsigned char index = 0; index < 4; index++)
	clrf	(ISR@index)
	
i1l933:	
	movlw	low(04h)
	subwf	(ISR@index),w
	skipc
	goto	u38_21
	goto	u38_20
u38_21:
	goto	i1l937
u38_20:
	goto	i1l945
	
i1l935:	
	goto	i1l945
	line	36
	
i1l42:	
	line	37
	
i1l937:	
;main.c: 36: {
;main.c: 37: USART_WriteChar(ADC_Buffer[index]);
	movf	(ISR@index),w
	addlw	low(_ADC_Buffer|((0x00)<<8))&0ffh
	movwf	fsr0
	movf	indf,w
	fcall	i1_USART_WriteChar
	line	38
	
i1l939:	
;main.c: 38: checksum ^= ADC_Buffer[index];
	movf	(ISR@index),w
	addlw	low(_ADC_Buffer|((0x00)<<8))&0ffh
	movwf	fsr0
	movf	indf,w
	movwf	(??_ISR+0)+0
	movf	(??_ISR+0)+0,w
	xorwf	(ISR@checksum),f
	line	35
	
i1l941:	
	movlw	low(01h)
	movwf	(??_ISR+0)+0
	movf	(??_ISR+0)+0,w
	addwf	(ISR@index),f
	
i1l943:	
	movlw	low(04h)
	subwf	(ISR@index),w
	skipc
	goto	u39_21
	goto	u39_20
u39_21:
	goto	i1l937
u39_20:
	goto	i1l945
	
i1l43:	
	line	41
	
i1l945:	
;main.c: 39: }
;main.c: 41: USART_WriteChar(checksum);
	movf	(ISR@checksum),w
	fcall	i1_USART_WriteChar
	goto	i1l44
	line	42
	
i1l41:	
	line	43
	
i1l44:	
	movf	(??_ISR+4),w
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	movwf	btemp+1
	movf	(??_ISR+3),w
	movwf	pclath
	movf	(??_ISR+2),w
	movwf	fsr0
	swapf	(??_ISR+1)^0FFFFFF80h,w
	movwf	status
	swapf	saved_w,f
	swapf	saved_w,w
	retfie
	opt stack 0
GLOBAL	__end_of_ISR
	__end_of_ISR:
	signat	_ISR,89
	global	i1_USART_WriteString

;; *************** function i1_USART_WriteString *****************
;; Defined at:
;;		line 48 in file "C:\Projects\BitBucketProjects\Firmwares e Supervisorios\AquisicaoSinais\Firmware\usart.c"
;; Parameters:    Size  Location     Type
;;  str             1    wreg     PTR const unsigned char 
;;		 -> STR_3(40), STR_2(23), STR_1(4), 
;; Auto vars:     Size  Location     Type
;;  str             1    2[COMMON] PTR const unsigned char 
;;		 -> STR_3(40), STR_2(23), STR_1(4), 
;; Return value:  Size  Location     Type
;;                  1    wreg      void 
;; Registers used:
;;		wreg, fsr0l, fsr0h, status,2, status,0, pclath, cstack
;; Tracked objects:
;;		On entry : 0/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK3   BANK2
;;      Params:         0       0       0       0       0
;;      Locals:         1       0       0       0       0
;;      Temps:          1       0       0       0       0
;;      Totals:         2       0       0       0       0
;;Total ram usage:        2 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    1
;; This function calls:
;;		i1_USART_WriteChar
;; This function is called by:
;;		_ISR
;; This function uses a non-reentrant model
;;
psect	text9,local,class=CODE,delta=2,merge=1,group=0
	file	"C:\Projects\BitBucketProjects\Firmwares e Supervisorios\AquisicaoSinais\Firmware\usart.c"
	line	48
global __ptext9
__ptext9:	;psect for function i1_USART_WriteString
psect	text9
	file	"C:\Projects\BitBucketProjects\Firmwares e Supervisorios\AquisicaoSinais\Firmware\usart.c"
	line	48
	global	__size_ofi1_USART_WriteString
	__size_ofi1_USART_WriteString	equ	__end_ofi1_USART_WriteString-i1_USART_WriteString
	
i1_USART_WriteString:	
;incstack = 0
	opt	stack 3
; Regs used in i1_USART_WriteString: [wreg-fsr0h+status,2+status,0+pclath+cstack]
;i1USART_WriteString@str stored from wreg
	movwf	(i1USART_WriteString@str)
	line	51
	
i1l903:	
;usart.c: 51: while(*str != '\0')
	goto	i1l909
	
i1l83:	
	line	54
	
i1l905:	
;usart.c: 52: {
;usart.c: 54: USART_WriteChar(*str);
	movf	(i1USART_WriteString@str),w
	movwf	fsr0
	fcall	stringdir
	fcall	i1_USART_WriteChar
	line	55
	
i1l907:	
;usart.c: 55: str++;
	movlw	low(01h)
	movwf	(??i1_USART_WriteString+0)+0
	movf	(??i1_USART_WriteString+0)+0,w
	addwf	(i1USART_WriteString@str),f
	goto	i1l909
	line	56
	
i1l82:	
	line	51
	
i1l909:	
	movf	(i1USART_WriteString@str),w
	movwf	fsr0
	fcall	stringdir
	xorlw	0
	skipz
	goto	u36_21
	goto	u36_20
u36_21:
	goto	i1l905
u36_20:
	goto	i1l85
	
i1l84:	
	line	57
	
i1l85:	
	return
	opt stack 0
GLOBAL	__end_ofi1_USART_WriteString
	__end_ofi1_USART_WriteString:
	signat	i1_USART_WriteString,89
	global	i1_USART_WriteChar

;; *************** function i1_USART_WriteChar *****************
;; Defined at:
;;		line 42 in file "C:\Projects\BitBucketProjects\Firmwares e Supervisorios\AquisicaoSinais\Firmware\usart.c"
;; Parameters:    Size  Location     Type
;;  USART_Data      1    wreg     unsigned char 
;; Auto vars:     Size  Location     Type
;;  USART_Data      1    0[COMMON] unsigned char 
;; Return value:  Size  Location     Type
;;                  1    wreg      void 
;; Registers used:
;;		wreg
;; Tracked objects:
;;		On entry : 0/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK3   BANK2
;;      Params:         0       0       0       0       0
;;      Locals:         1       0       0       0       0
;;      Temps:          0       0       0       0       0
;;      Totals:         1       0       0       0       0
;;Total ram usage:        1 bytes
;; Hardware stack levels used:    1
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_ISR
;;		i1_USART_WriteString
;; This function uses a non-reentrant model
;;
psect	text10,local,class=CODE,delta=2,merge=1,group=0
	line	42
global __ptext10
__ptext10:	;psect for function i1_USART_WriteChar
psect	text10
	file	"C:\Projects\BitBucketProjects\Firmwares e Supervisorios\AquisicaoSinais\Firmware\usart.c"
	line	42
	global	__size_ofi1_USART_WriteChar
	__size_ofi1_USART_WriteChar	equ	__end_ofi1_USART_WriteChar-i1_USART_WriteChar
	
i1_USART_WriteChar:	
;incstack = 0
	opt	stack 3
; Regs used in i1_USART_WriteChar: [wreg]
;i1USART_WriteChar@USART_Data stored from wreg
	movwf	(i1USART_WriteChar@USART_Data)
	line	44
	
i1l837:	
;usart.c: 44: while(!PIR1bits.TXIF);
	goto	i1l76
	
i1l77:	
	
i1l76:	
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	btfss	(12),4	;volatile
	goto	u32_21
	goto	u32_20
u32_21:
	goto	i1l76
u32_20:
	goto	i1l839
	
i1l78:	
	line	45
	
i1l839:	
;usart.c: 45: TXREG = USART_Data;
	movf	(i1USART_WriteChar@USART_Data),w
	movwf	(25)	;volatile
	line	46
	
i1l79:	
	return
	opt stack 0
GLOBAL	__end_ofi1_USART_WriteChar
	__end_ofi1_USART_WriteChar:
	signat	i1_USART_WriteChar,89
	global	i1_TIMER1_Set

;; *************** function i1_TIMER1_Set *****************
;; Defined at:
;;		line 36 in file "C:\Projects\BitBucketProjects\Firmwares e Supervisorios\AquisicaoSinais\Firmware\timers.c"
;; Parameters:    Size  Location     Type
;;  count           2    0[COMMON] unsigned int 
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;                  1    wreg      void 
;; Registers used:
;;		wreg
;; Tracked objects:
;;		On entry : 0/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK3   BANK2
;;      Params:         2       0       0       0       0
;;      Locals:         0       0       0       0       0
;;      Temps:          0       0       0       0       0
;;      Totals:         2       0       0       0       0
;;Total ram usage:        2 bytes
;; Hardware stack levels used:    1
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_ISR
;; This function uses a non-reentrant model
;;
psect	text11,local,class=CODE,delta=2,merge=1,group=0
	file	"C:\Projects\BitBucketProjects\Firmwares e Supervisorios\AquisicaoSinais\Firmware\timers.c"
	line	36
global __ptext11
__ptext11:	;psect for function i1_TIMER1_Set
psect	text11
	file	"C:\Projects\BitBucketProjects\Firmwares e Supervisorios\AquisicaoSinais\Firmware\timers.c"
	line	36
	global	__size_ofi1_TIMER1_Set
	__size_ofi1_TIMER1_Set	equ	__end_ofi1_TIMER1_Set-i1_TIMER1_Set
	
i1_TIMER1_Set:	
;incstack = 0
	opt	stack 4
; Regs used in i1_TIMER1_Set: [wreg]
	line	38
	
i1l911:	
;timers.c: 38: TMR1 = count;
	movf	(i1TIMER1_Set@count+1),w
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	movwf	(14+1)	;volatile
	movf	(i1TIMER1_Set@count),w
	movwf	(14)	;volatile
	line	39
	
i1l135:	
	return
	opt stack 0
GLOBAL	__end_ofi1_TIMER1_Set
	__end_ofi1_TIMER1_Set:
	signat	i1_TIMER1_Set,89
	global	_ADC_Read

;; *************** function _ADC_Read *****************
;; Defined at:
;;		line 25 in file "C:\Projects\BitBucketProjects\Firmwares e Supervisorios\AquisicaoSinais\Firmware\adc.c"
;; Parameters:    Size  Location     Type
;;  channel         2    0[COMMON] unsigned short 
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;                  1    wreg      void 
;; Registers used:
;;		wreg, status,2, status,0
;; Tracked objects:
;;		On entry : 0/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK3   BANK2
;;      Params:         2       0       0       0       0
;;      Locals:         0       0       0       0       0
;;      Temps:          1       0       0       0       0
;;      Totals:         3       0       0       0       0
;;Total ram usage:        3 bytes
;; Hardware stack levels used:    1
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_ISR
;; This function uses a non-reentrant model
;;
psect	text12,local,class=CODE,delta=2,merge=1,group=0
	file	"C:\Projects\BitBucketProjects\Firmwares e Supervisorios\AquisicaoSinais\Firmware\adc.c"
	line	25
global __ptext12
__ptext12:	;psect for function _ADC_Read
psect	text12
	file	"C:\Projects\BitBucketProjects\Firmwares e Supervisorios\AquisicaoSinais\Firmware\adc.c"
	line	25
	global	__size_of_ADC_Read
	__size_of_ADC_Read	equ	__end_of_ADC_Read-_ADC_Read
	
_ADC_Read:	
;incstack = 0
	opt	stack 4
; Regs used in _ADC_Read: [wreg+status,2+status,0]
	line	27
	
i1l843:	
;adc.c: 27: ADCON0bits.CHS = channel;
	movf	(ADC_Read@channel),w
	movwf	(??_ADC_Read+0)+0
	rlf	(??_ADC_Read+0)+0,f
	rlf	(??_ADC_Read+0)+0,f
	rlf	(??_ADC_Read+0)+0,f
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	movf	(31),w	;volatile
	xorwf	(??_ADC_Read+0)+0,w
	andlw	not (((1<<3)-1)<<3)
	xorwf	(??_ADC_Read+0)+0,w
	movwf	(31)	;volatile
	line	28
	
i1l845:	
;adc.c: 28: ADCON0bits.ADON = 1;
	bsf	(31),0	;volatile
	line	30
	
i1l847:	
;adc.c: 30: _delay((unsigned long)((10)*(18432000/4000000.0)));
	opt asmopt_push
opt asmopt_off
	movlw	15
movwf	((??_ADC_Read+0)+0),f
	u41_27:
decfsz	(??_ADC_Read+0)+0,f
	goto	u41_27
opt asmopt_pop

	line	32
	
i1l849:	
;adc.c: 32: ADCON0bits.GO = 1;
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	bsf	(31),2	;volatile
	line	33
;adc.c: 33: while(ADCON0bits.GO_DONE);
	goto	i1l106
	
i1l107:	
	
i1l106:	
	btfsc	(31),2	;volatile
	goto	u33_21
	goto	u33_20
u33_21:
	goto	i1l106
u33_20:
	
i1l108:	
	line	35
;adc.c: 35: PIR1bits.ADIF = 0;
	bcf	(12),6	;volatile
	line	36
	
i1l109:	
	return
	opt stack 0
GLOBAL	__end_of_ADC_Read
	__end_of_ADC_Read:
	signat	_ADC_Read,4217
global	___latbits
___latbits	equ	2
	global	btemp
	btemp set 07Eh

	DABS	1,126,2	;btemp
	global	wtemp0
	wtemp0 set btemp+0
	end
