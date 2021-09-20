
#ifndef TIMER_
#define TIMER_

#include <avr/io.h>
#define F_CPU 16000000ul
#include <util/delay.h>
#include <avr/interrupt.h>

#define SETBIT(REG,BIT)  (REG |= 1 << BIT)
#define CLRBIT(REG,BIT)  (REG &= ~(1 << BIT))
#define TOGBIT(REG,BIT)  (REG ^= 1 << BIT)
#define READBIT(REG,BIT)  ((Reg >> BIT) & 1)


void TIMER0_init();
void TIMER0_prescaler_1024_init();
void TIMER0_freq_init();
void set_freq(uint8_t x);
void TIMER_stop();
void TIMER_start();

#endif /* TIMER_ */