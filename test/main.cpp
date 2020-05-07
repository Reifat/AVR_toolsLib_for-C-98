/* Тест программы для вычисления производительности
 * генерируемого asm кода компилятором.
 * Сравнивается две реализации одной и той же программы.
 * Реализация с использованием класса оболочки RegisterSet и обычная.
 * Сравнивается размер скомпилированной программы (.hex файл)
 * и число циклов на выполнение программы.
 *
 * Тесты проводились в
 * GNU C v5.4 (Atmel studio 7)
 */

// * Для выбора теста уберите коментарий на нужном тесте
	//#define RECORD_WORD_TEST
	//#define LOGICAL_OPERATION_TEST
	//#define ARITHMETIC_OPERATIONS_TEST
	#define COMPLEX_TEST

/* По умолчанию включена реализация программ с применением класса
 * RegisterSet.
 * Для включения обычной реализации уберите комментарий с макроса "ORDINARY"
 */
	//#define ORDINARY

#ifdef RECORD_WORD_TEST
#ifndef ORDINARY
// Запись слова в регистр/
// Запись слова из регистра в переменную

#define ATTINY_2313
#include "metabit/metabit.hpp"
#include "avrdef_ptr/avrdef_ptr.hpp"

unsigned char var = 0;
int main(void)
{
	// Создание объектов ссылающихся на регистры
	const mbl::RegisterSet<mbl::reg8_t>::n_static_ port_b(mcreg::PORTB_ptr);
	const mbl::RegisterSet<mbl::reg8_t>::n_static_ pin_d(mcreg::PIND_ptr);
	
	while(true){
		port_b = 0x55;
		var	   = pin_d;
	}
}

#else // if define ordinary

// Запись слова в регистр/
// Запись слова из регистра в переменную
// Обычная реализация
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
// Логические / побитовые операции
#define ATTINY_2313
#include "metabit/metabit.hpp"
#include "avrdef_ptr/avrdef_ptr.hpp"

int main(void)
{
	// Создание объектов ссылающихся на регистры
	const mbl::RegisterSet<mbl::reg8_t>::n_static_ pin_a(mcreg::PINA_ptr);
	const mbl::RegisterSet<mbl::reg8_t>::n_static_ port_b(mcreg::PORTB_ptr);
	const mbl::RegisterSet<mbl::reg8_t>::n_static_ pin_d(mcreg::PIND_ptr);
	while(true){
		// Логические операции
		!(pin_d == 0xFF);
		(pin_d != 0xFF)  || (pin_a > 0xF0);
		(pin_d <  0xFF)  && (pin_a >= 0xF0);
		(pin_d <= 0xF0);
		// Битовые операции
		port_b = ~port_b;
		port_b &= (1 << 3);
		port_b |= (1 << 4);
		port_b ^= (1 << 5);
		port_b <<= 2;
		port_b >>= 4;
	}
}

#else // if define ordinary

// Логические/ побитовые операции
// Обычная реализация
#include "avr/io.h"

unsigned char var = 0;
int main(){
	
	while(true){
		// Логические операции
		!(PIND == 0xFF);
		(PIND != 0xFF)  || (PINA > 0xF0);
		(PIND <  0xFF)  && (PINA >= 0xF0);
		(PIND <= 0xF0);
		// Битовые операции
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
// Арифметические операции
#define ATTINY_2313
#include "metabit/metabit.hpp"
#include "avrdef_ptr/avrdef_ptr.hpp"

int main(void)
{
	// Создание объектов ссылающихся на регистры
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

// Арифметические операции
// Обычная реализация
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

// Комплексный тест
#define ATTINY_2313
#include "metabit/metabit.hpp"
#include "avrdef_ptr/avrdef_ptr.hpp"

unsigned char var = 0;
int main(void)
{
	// Создание объектов ссылающихся на регистры
	const mbl::RegisterSet<mbl::reg8_t>::n_static_ pin_a(mcreg::PINA_ptr);
	const mbl::RegisterSet<mbl::reg8_t>::n_static_ port_b(mcreg::PORTB_ptr);
	const mbl::RegisterSet<mbl::reg8_t>::n_static_ pin_d(mcreg::PIND_ptr);
	while(true){
		// Запись слова в регистр, из регистра * * * * * * * * * * * 
		port_b = 0x55;
		var	   = pin_d;
		// Логические операции / побитовые операции * * * * * * * * *
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
		// Арифметические операции * * * * * * * * * * * * * * * * *
		port_b = pin_a++;
		port_b = pin_a - pin_d + 0x33;
		port_b = pin_a--;
		port_b = (--pin_a) + (++pin_d);
		port_b = pin_d % 4;
		port_b = pin_d % 2;
	}
}

#else // if define ORDINARY

// Комплексный тест
// Обычная реализация
#include "avr/io.h"

unsigned char var = 0;
int main(){
	
	while(true){
		// Запись слова в регистр, из регистра * * * * * * * * * * * 
		PORTB = 0x55;
		var	  = PIND;
		// Логические операции / побитовые операции * * * * * * * * *
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
		// Арифметические операции * * * * * * * * * * * * * * * *
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
