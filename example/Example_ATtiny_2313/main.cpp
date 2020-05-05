// Example RuningLed on ATtiny 2313
// 
#include "avr/interrupt.h"
#include "timer.hpp"


mbl::size16_t clk = 0;		 // Счетчик деления частоты таймера
mbl::size16_t delay_clk = 0; // Счетчик задержки
bool delay_flag = false;

ISR(TIMER0_OVF_vect)
{
	clk++;
	if (delay_flag) // Если флаг задержки поднят
	delay_clk++;
	if(delay_clk >= 122) // Если счетчик переполнен, опускаем флаг
	delay_flag = false;
}


int main(void)
{
	// Инициализация регистров МК
	Timer tmr;
	mbl::RegisterSet<mbl::reg8_t>::n_static_ port_out(mcreg::PORTB_c);
	mbl::RegisterSet<mbl::reg8_t>::n_static_ pin_in(mcreg::PIND_c);
	
	tmr.SetNormal();			  // CTC Mod  таймера
	tmr.Divider(64);			  // Предварительное деление частоты таймера 4МГц/64
	tmr.OnInterruptOverflow();    // Разрешаем прерывание при переполнении
	
	DDRB = 0xFF; // Порт А работает на вывод тока
	DDRD = 0x00; // Порт C работает как токовый приемник
	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	mbl::size16_t busic_loop = 512;
	mbl::size16_t next_set = busic_loop;

	port_out[0] = 1;
	while(true){
		if(clk >= next_set){
			if(port_out.GetValue() == 0x80)
				port_out = 1;
			else
				port_out <<= 1;
			clk = 0;
		}
		if ( mbl::OnlySingleTrue(pin_in.GetValue()) & (!delay_flag) ) {
			delay_flag = true; // Поднять флаг задержки
			next_set = busic_loop >> mbl::ilog2(pin_in.GetValue());
			clk = 0;
		}
	}
}
