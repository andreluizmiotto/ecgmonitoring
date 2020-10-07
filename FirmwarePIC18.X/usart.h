/* 
 * File:   usart.h
 * Author: andre
 *
 * Created on 3 de Setembro de 2020, 16:51
 */

#ifndef USART_H
#define	USART_H

#ifdef	__cplusplus
extern "C" {
#endif

void USART_Init(long baudRate);
void USART_WriteChar(unsigned char USARTData);

#ifdef	__cplusplus
}
#endif

#endif	/* USART_H */

