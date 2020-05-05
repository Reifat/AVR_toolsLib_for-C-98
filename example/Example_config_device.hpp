#ifndef CONFIG_DEVICE_HPP_
#define CONFIG_DEVICE_HPP_
#include "timer.hpp"
namespace conf{
	typedef  const mbl::RegisterSet<mbl::reg8_t>::static_ Type;
}

struct CMC{
	static const Timer tmr;
	static conf::Type port_out;
	static conf::Type pin_in;
};
const Timer CMC::tmr = Timer();
conf::Type CMC::port_out = conf::Type(mcreg::PORTB_c);
conf::Type CMC::pin_in = conf::Type(mcreg::PIND_c);



#endif /* CONFIG_DEVICE_H_ */

/*
An example implementation:
 
#include "avr/interrupt.h"
#include "config_device.hpp"

mbl::size16_t clk = 0;
ISR(TIMER0_COMPA_vect)
{
	clk++;
}

int main(void)
{
	CMC::tmr.SetNormal();			  // Normal Mod  таймера
	CMC::tmr.Divider(1024);			  // Предварительное деление частоты таймера 4МГц/1024
	CMC::tmr.OCR_Set(0xFF);			  // Регистр сравнения равен 255
	CMC::tmr.OnInterruptCoincidence(); // Разрешаем прерывание при совпадении
	
	DDRB = 0xFF; // Порт А работает на вывод тока
	DDRD = 0x00; // Порт C работает как токовый приемник
	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	mbl::size16_t busic_loop = 2;
	mbl::size16_t next_set = busic_loop;

	CMC::port_out[0] = 1;
	while(true){
		if(clk >= next_set){
			if(CMC::port_out.GetValue() == 0x80)
			CMC::port_out = 1;
			else
			CMC::port_out <<= 1;
			clk = 0;
		}
		if ( mbl::OnlySingleTrue(CMC::pin_in.GetValue()) ) {
			next_set = busic_loop << mbl::ilog2(CMC::pin_in.GetValue());
			clk = 0;
		}
	}
}

*/