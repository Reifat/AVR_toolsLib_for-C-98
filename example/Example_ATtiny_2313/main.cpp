// Example RuningLed on ATtiny 2313
#include "avr/interrupt.h"
#include "timer_tiny_2313.hpp"

mbl::size16_t clk = 0;		 // Счетчик делителя программного таймера
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
	mbl::RegisterSet<mbl::reg8_t>::n_static_ port_out(mcreg::PORTB_ptr);
	mbl::RegisterSet<mbl::reg8_t>::n_static_ pin_in(mcreg::PIND_ptr);
	
	tmr.SetNormal();			  // Normal Mod  таймера
	tmr.Divider(64);			  // Предварительное деление частоты таймера 4МГц/64
	tmr.OnInterruptOverflow();    // Разрешаем прерывание при переполнении
	
	DDRB = 0xFF; // Порт B работает на вывод тока
	DDRD = 0x00; // Порт D работает как токовый приемник
	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	mbl::size16_t loop = 512;		// Программный делитель счетчика счетчика 4МГц/64/256/512 = 0,47Гц
	mbl::size16_t now_loop = loop;  // Действующий делитель счетчика

	port_out[0] = 1;
	while(true){
		if(clk >= now_loop){
			if(port_out.GetValue() == 0x80)
				port_out = 1;
			else
				port_out <<= 1; // Переключить LED диода
			clk = 0;
		}
		if ( mbl::OnlySingleTrue(pin_in.GetValue()) && (!delay_flag) ) {
			delay_flag = true; // Поднять флаг задержки
			now_loop = loop >> mbl::ilog2(pin_in.GetValue());
			clk = 0;
		}
	}
}