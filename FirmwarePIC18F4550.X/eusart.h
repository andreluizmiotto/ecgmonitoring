/* 
 * File: config_bits.h 
 * Author: André Luiz Miotto
 * Date: 01/10/2020
 */
  
#ifndef EUSART_H
#define	EUSART_H

#include <xc.h> // include processor files - each processor file is guarded.  

void EUSART_Init(long baudRate);
void EUSART_WriteChar(unsigned char EUSARTData);

#endif	/* EUSART_H */

