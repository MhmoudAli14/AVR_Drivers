
#include "timer.h"


void TIMER0_init(){
	TCCR0 |= 1<<FOC0 | 1<<CS00;
	TIMSK |= 1<<TOIE0 ;
	sei();	// SETBIT(SREG,7);
}

void TIMER0_prescaler_1024_init(){
	TCCR0 |= 1<<FOC0 | 1<<CS00 | 1<<CS02;
	TIMSK |= 1<<TOIE0 ;
	sei();	// SETBIT(SREG,7);
}


void TIMER0_freq_init(){
	TCCR0 |= 1<<FOC0 | 1<<CS00 | 1<<WGM01 | 1<<COM00;
	SETBIT(DDRB, 3);
}

void set_freq(uint8_t x){
	OCR0 = x;	
}

void TIMER_stop(){
	CLRBIT(PORTD,4);
	CLRBIT(PORTD,5);
}

void TIMER_start(){
	SETBIT(PORTD,4);
	SETBIT(PORTD,5);
}
