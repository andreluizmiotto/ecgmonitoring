/* 
 * Author: André Luiz Miotto
 * Date: 14/10/2020
 */
  
#ifndef EUSART_H
#define EUSART_H

void EUSART_Init(long baudRate);
void EUSART_WriteChar(unsigned char EUSARTData);

#endif /* EUSART_H */