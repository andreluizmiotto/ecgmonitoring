#ifndef CONFIG_H        // Prevents cyclic recursion
#define CONFIG_H

#define _XTAL_FREQ	   	18432000 // Cristal de 18.432 Mhz.
#pragma config FOSC 	= HS	// Oscillator Selection bits (HS oscillator)
#pragma config WDTE 	= OFF   // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE 	= OFF   // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN 	= OFF   // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP 		= OFF   // Low-Voltage Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD 		= OFF   // Data EE Memory Code Protection bit (Code protection off)
#pragma config WRT 		= OFF   // Flash Program Memory Write Enable bits (Write protection off)
#pragma config CP 		= OFF   // Flash Program Memory Code Protection bit (Code protection off)

#endif