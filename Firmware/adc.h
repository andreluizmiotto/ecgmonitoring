#ifndef ADC_H       // Prevents cyclic recursion
#define ADC_H

void ADC_Init();
void ADC_Read(unsigned short channel);

#endif