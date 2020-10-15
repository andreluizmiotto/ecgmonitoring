/* 
 * File: timers.h
 * Author: André Luiz Miotto
 * Date: 01/10/2020
 */
 
#ifndef TIMERS_H
#define TIMERS_H

/* Timer 0 */
void TIMER0_Init(void);
void TIMER0_Set(unsigned int initialCount);

/* Timer 1 */
void TIMER1_Init(void);
void TIMER1_Reset(void);

#endif /* TIMERS_H */