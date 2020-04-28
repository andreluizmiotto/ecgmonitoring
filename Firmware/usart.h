#ifndef USART_H   	// Prevents cyclic recursion
#define USART_H

void USART_Init(long BaudRate);
void USART_WriteChar(unsigned char USART_Data);
void USART_WriteString(const char *str);
unsigned char USART_ReceiveChar(void);

#endif