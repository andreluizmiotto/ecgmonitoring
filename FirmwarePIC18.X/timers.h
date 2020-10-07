/* 
 * File:   timers.h
 * Author: andre
 *
 * Created on 3 de Setembro de 2020, 16:51
 */

#ifndef TIMERS_H
#define	TIMERS_H

#ifdef	__cplusplus
extern "C" {
#endif

void TMR0_Init(long initialCount);
void TMR0_Reset(void);

#ifdef	__cplusplus
}
#endif

#endif	/* TIMERS_H */

