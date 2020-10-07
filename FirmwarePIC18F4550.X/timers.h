/* 
 * File: config_bits.h 
 * Author: André Luiz Miotto
 * Date: 01/10/2020
 */
 
#ifndef TIMERS_H
#define	TIMERS_H

#include <xc.h> // include processor files - each processor file is guarded.  

void TMR1_Init(void);
void TMR1_Reset(void);

#endif	/* TIMERS_H */

