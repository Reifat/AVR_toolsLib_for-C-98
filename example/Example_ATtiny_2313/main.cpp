// Example RuningLed on ATtiny 2313
// 
#include "avr/interrupt.h"
#include "timer.hpp"


mbl::size16_t clk = 0;		 // ������� ������� ������� �������
mbl::size16_t delay_clk = 0; // ������� ��������
bool delay_flag = false;

ISR(TIMER0_OVF_vect)
{
	clk++;
	if (delay_flag) // ���� ���� �������� ������
	delay_clk++;
	if(delay_clk >= 122) // ���� ������� ����������, �������� ����
	delay_flag = false;
}


int main(void)
{
	// ������������� ��������� ��
	Timer tmr;
	mbl::RegisterSet<mbl::reg8_t>::n_static_ port_out(mcreg::PORTB_c);
	mbl::RegisterSet<mbl::reg8_t>::n_static_ pin_in(mcreg::PIND_c);
	
	tmr.SetNormal();			  // CTC Mod  �������
	tmr.Divider(64);			  // ��������������� ������� ������� ������� 4���/64
	tmr.OnInterruptOverflow();    // ��������� ���������� ��� ������������
	
	DDRB = 0xFF; // ���� � �������� �� ����� ����
	DDRD = 0x00; // ���� C �������� ��� ������� ��������
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
			delay_flag = true; // ������� ���� ��������
			next_set = busic_loop >> mbl::ilog2(pin_in.GetValue());
			clk = 0;
		}
	}
}
