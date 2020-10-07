/* 
 * File:   adc.h
 * Author: andre
 *
 * Created on 9 de Setembro de 2020, 19:22
 */

#ifndef ADC_H
#define	ADC_H

#ifdef	__cplusplus
extern "C" {
#endif

void ADC_Init(void);
void ADC_Read(int channel);

#ifdef	__cplusplus
}
#endif

#endif	/* ADC_H */

