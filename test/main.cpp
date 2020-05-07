/* ���� ��������� ��� ���������� ������������������
 * ������������� asm ���� ������������.
 * ������������ ��� ���������� ����� � ��� �� ���������.
 * ���������� � �������������� ������ �������� RegisterSet � �������.
 * ������������ ������ ���������������� ��������� (.hex ����)
 * � ����� ������ �� ���������� ���������.
 *
 * ����� ����������� �
 * GNU C v5.4 (Atmel studio 7)
 */

// * ��� ������ ����� ������� ���������� �� ������ �����
	//#define RECORD_WORD_TEST
	//#define LOGICAL_OPERATION_TEST
	//#define ARITHMETIC_OPERATIONS_TEST
	#define COMPLEX_TEST

/* �� ��������� �������� ���������� �������� � ����������� ������
 * RegisterSet.
 * ��� ��������� ������� ���������� ������� ����������� � ������� "ORDINARY"
 */
	//#define ORDINARY

#ifdef RECORD_WORD_TEST
#ifndef ORDINARY
// ������ ����� � �������/
// ������ ����� �� �������� � ����������

#define ATTINY_2313
#include "metabit/metabit.hpp"
#include "avrdef_ptr/avrdef_ptr.hpp"

unsigned char var = 0;
int main(void)
{
	// �������� �������� ����������� �� ��������
	const mbl::RegisterSet<mbl::reg8_t>::n_static_ port_b(mcreg::PORTB_ptr);
	const mbl::RegisterSet<mbl::reg8_t>::n_static_ pin_d(mcreg::PIND_ptr);
	
	while(true){
		port_b = 0x55;
		var	   = pin_d;
	}
}

#else // if define ordinary

// ������ ����� � �������/
// ������ ����� �� �������� � ����������
// ������� ����������
#include "avr/io.h"

unsigned char var = 0;
int main(){
	
	while(true){
		PORTB = 0x55;
		var	  = PIND;
	}
}
#endif
#endif // end record word test

#ifdef LOGICAL_OPERATION_TEST
#ifndef ORDINARY
// ���������� / ��������� ��������
#define ATTINY_2313
#include "metabit/metabit.hpp"
#include "avrdef_ptr/avrdef_ptr.hpp"

int main(void)
{
	// �������� �������� ����������� �� ��������
	const mbl::RegisterSet<mbl::reg8_t>::n_static_ pin_a(mcreg::PINA_ptr);
	const mbl::RegisterSet<mbl::reg8_t>::n_static_ port_b(mcreg::PORTB_ptr);
	const mbl::RegisterSet<mbl::reg8_t>::n_static_ pin_d(mcreg::PIND_ptr);
	while(true){
		// ���������� ��������
		!(pin_d == 0xFF);
		(pin_d != 0xFF)  || (pin_a > 0xF0);
		(pin_d <  0xFF)  && (pin_a >= 0xF0);
		(pin_d <= 0xF0);
		// ������� ��������
		port_b = ~port_b;
		port_b &= (1 << 3);
		port_b |= (1 << 4);
		port_b ^= (1 << 5);
		port_b <<= 2;
		port_b >>= 4;
	}
}

#else // if define ordinary

// ����������/ ��������� ��������
// ������� ����������
#include "avr/io.h"

unsigned char var = 0;
int main(){
	
	while(true){
		// ���������� ��������
		!(PIND == 0xFF);
		(PIND != 0xFF)  || (PINA > 0xF0);
		(PIND <  0xFF)  && (PINA >= 0xF0);
		(PIND <= 0xF0);
		// ������� ��������
		PORTB = ~PORTB;
		PORTB &= (1 << 3);
		PORTB |= (1 << 4);
		PORTB ^= (1 << 5);
		PORTB <<= 2;
		PORTB >>= 4;
	}
}
#endif
#endif // end logical operation test

#ifdef ARITHMETIC_OPERATIONS_TEST
#ifndef ORDINARY
// �������������� ��������
#define ATTINY_2313
#include "metabit/metabit.hpp"
#include "avrdef_ptr/avrdef_ptr.hpp"

int main(void)
{
	// �������� �������� ����������� �� ��������
	const mbl::RegisterSet<mbl::reg8_t>::n_static_ pin_a(mcreg::PINA_ptr);
	const mbl::RegisterSet<mbl::reg8_t>::n_static_ port_b(mcreg::PORTB_ptr);
	const mbl::RegisterSet<mbl::reg8_t>::n_static_ pin_d(mcreg::PIND_ptr);
	
	while(true){
		port_b = pin_a++;
		port_b = pin_a - pin_d + 0x33;
		port_b = pin_a--;
		port_b = (--pin_a) + (++pin_d);
		port_b = pin_d % 4;
		port_b = pin_d % 2;
	}
}

#else // if define ordinary

// �������������� ��������
// ������� ����������
#include "avr/io.h"
int main(){
	
	while(true){
		PORTB = PINA++;
		PORTB = PINA - PIND + 0x33;
		PORTB = PINA--;
		PORTB = (--PINA) + (++PIND);
		PORTB = PIND / 4;
		PORTB = PIND % 2;
	}
}
#endif
#endif // end arithmetic operators test

#ifdef COMPLEX_TEST
#ifndef ORDINARY

// ����������� ����
#define ATTINY_2313
#include "metabit/metabit.hpp"
#include "avrdef_ptr/avrdef_ptr.hpp"

unsigned char var = 0;
int main(void)
{
	// �������� �������� ����������� �� ��������
	const mbl::RegisterSet<mbl::reg8_t>::n_static_ pin_a(mcreg::PINA_ptr);
	const mbl::RegisterSet<mbl::reg8_t>::n_static_ port_b(mcreg::PORTB_ptr);
	const mbl::RegisterSet<mbl::reg8_t>::n_static_ pin_d(mcreg::PIND_ptr);
	while(true){
		// ������ ����� � �������, �� �������� * * * * * * * * * * * 
		port_b = 0x55;
		var	   = pin_d;
		// ���������� �������� / ��������� �������� * * * * * * * * *
		!(pin_d == 0xFF);
		(pin_d != 0xFF)  || (pin_a > 0xF0);
		(pin_d <  0xFF)  && (pin_a >= 0xF0);
		(pin_d <= 0xF0);
		// * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
		port_b = ~port_b;
		port_b &= (1 << 3);
		port_b |= (1 << 4);
		port_b ^= (1 << 5);
		port_b <<= 2;
		port_b >>= 4;
		// �������������� �������� * * * * * * * * * * * * * * * * *
		port_b = pin_a++;
		port_b = pin_a - pin_d + 0x33;
		port_b = pin_a--;
		port_b = (--pin_a) + (++pin_d);
		port_b = pin_d % 4;
		port_b = pin_d % 2;
	}
}

#else // if define ORDINARY

// ����������� ����
// ������� ����������
#include "avr/io.h"

unsigned char var = 0;
int main(){
	
	while(true){
		// ������ ����� � �������, �� �������� * * * * * * * * * * * 
		PORTB = 0x55;
		var	  = PIND;
		// ���������� �������� / ��������� �������� * * * * * * * * *
		!(PIND == 0xFF);
		(PIND != 0xFF)  || (PINA > 0xF0);
		(PIND <  0xFF)  && (PINA >= 0xF0);
		(PIND <= 0xF0);
		// * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
		PORTB = ~PORTB;
		PORTB &= (1 << 3);
		PORTB |= (1 << 4);
		PORTB ^= (1 << 5);
		PORTB <<= 2;
		PORTB >>= 4;
		// �������������� �������� * * * * * * * * * * * * * * * *
		PORTB = PINA++;
		PORTB = PINA - PIND + 0x33;
		PORTB = PINA--;
		PORTB = (--PINA) + (++PIND);
		PORTB = PIND / 4;
		PORTB = PIND % 2;
	}
}
#endif
#endif // end Complex test
