#ifndef TIMERS_H       // Prevents cyclic recursion
#define TIMERS_H

void TIMER0_Init();
void TIMER0_Set(unsigned char count);
void TIMER1_Init();
void TIMER1_Set(unsigned int count);

#endif