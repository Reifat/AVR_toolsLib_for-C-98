/* Определение указателей для микроконтроллеров AVR
 * Автор Reifat
 * GitHub Repository - https://github.com/Reifat
 * Последние изменения 04.05.2020.
*/

#ifndef MEGA_16_HPP
#define MEGA_16_HPP

#ifdef ATMEGA_16

#include <avr/io.h>
// include default definitions type
#include "metabit\definitions_type\definitions_type.hpp"

namespace mcreg { // namespace microcontrollers registers
	
extern mbl::uint8ptr_t const TWBR_ptr = &TWBR;

extern mbl::uint8ptr_t const TWSR_ptr = &TWSR;

extern mbl::uint8ptr_t const TWAR_ptr = &TWAR;
	
extern mbl::uint8ptr_t const TWDR_ptr = &TWDR;
	
extern mbl::uint16ptr_t const  ADC_ptr = &ADC;

extern mbl::uint16ptr_t const ADCW_ptr = &ADCW;

extern mbl::uint8ptr_t const ADCL_ptr = &ADCL;

extern mbl::uint8ptr_t const ADCH_ptr = &ADCH;

extern mbl::uint8ptr_t const ADCSRA_ptr = &ADCSRA;

extern mbl::uint8ptr_t const ADMUX_ptr = &ADMUX;

extern mbl::uint8ptr_t const ACSR_ptr = &ACSR;

extern mbl::uint8ptr_t const UBRRL_ptr = &UBRRL;

extern mbl::uint8ptr_t const UCSRB_ptr = &UCSRB;

extern mbl::uint8ptr_t const UCSRA_ptr = &UCSRA;

extern mbl::uint8ptr_t const UDR_ptr = &UDR;

extern mbl::uint8ptr_t const SPCR_ptr = &SPCR;

extern mbl::uint8ptr_t const SPSR_ptr = &SPSR;

extern mbl::uint8ptr_t const SPDR_ptr = &SPDR;

extern mbl::uint8ptr_t const PIND_ptr = &PIND;

extern mbl::uint8ptr_t const DDRD_ptr = &DDRD;

extern mbl::uint8ptr_t const PORTD_ptr = &PORTD;

extern mbl::uint8ptr_t const PINC_ptr = &PINC;

extern mbl::uint8ptr_t const DDRC_ptr = &DDRC;

extern mbl::uint8ptr_t const PORTC_ptr = &PORTC;

extern mbl::uint8ptr_t const PINB_ptr = &PINB;

extern mbl::uint8ptr_t const DDRB_ptr = &DDRB;

extern mbl::uint8ptr_t const PORTB_ptr = &PORTB;

extern mbl::uint8ptr_t const PINA_ptr = &PINA;

extern mbl::uint8ptr_t const DDRA_ptr = &DDRA;

extern mbl::uint8ptr_t const PORTA_ptr = &PORTA;

extern mbl::uint8ptr_t const EECR_ptr = &EECR;

extern mbl::uint8ptr_t const EEDR_ptr = &EEDR;

extern mbl::uint16ptr_t const EEAR_ptr = &EEAR;

extern mbl::uint8ptr_t const EEARL_ptr = &EEARL;

extern mbl::uint8ptr_t const EEARH_ptr = &EEARH;

extern mbl::uint8ptr_t const UCSRC_ptr = &UCSRC;

extern mbl::uint8ptr_t const UBRRH_ptr = &UBRRH;

extern mbl::uint8ptr_t const WDTCR_ptr = &WDTCR;

extern mbl::uint8ptr_t const ASSR_ptr = &ASSR;

extern mbl::uint8ptr_t const OCR2_ptr = &OCR2;

extern mbl::uint8ptr_t const TCNT2_ptr = &TCNT2;

extern mbl::uint8ptr_t const TCCR2_ptr = &TCCR2;

extern mbl::uint16ptr_t const ICR1_ptr = &ICR1;

extern mbl::uint8ptr_t const ICR1L_ptr = &ICR1L;

extern mbl::uint8ptr_t const ICR1H_ptr = &ICR1H;

extern mbl::uint16ptr_t const OCR1B_ptr = &OCR1B;

extern mbl::uint8ptr_t const OCR1BL_ptr = &OCR1BL;

extern mbl::uint8ptr_t const OCR1BH_ptr = &OCR1BH;

extern mbl::uint16ptr_t const OCR1A_ptr = &OCR1A;

extern mbl::uint8ptr_t const OCR1AL_ptr = &OCR1AL;

extern mbl::uint8ptr_t const OCR1AH_ptr = &OCR1AH;

extern mbl::uint16ptr_t const TCNT1_ptr = &TCNT1;

extern mbl::uint8ptr_t const TCNT1L_ptr = &TCNT1L;

extern mbl::uint8ptr_t const TCNT1H_ptr = &TCNT1H;

extern mbl::uint8ptr_t const TCCR1B_ptr = &TCCR1B;

extern mbl::uint8ptr_t const TCCR1A_ptr = &TCCR1A;

extern mbl::uint8ptr_t const SFIOR_ptr = &SFIOR;

extern mbl::uint8ptr_t const OSCCAL_ptr = &OSCCAL;

extern mbl::uint8ptr_t const OCDR_ptr = &OCDR;

extern mbl::uint8ptr_t const TCNT0_ptr = &TCNT0;

extern mbl::uint8ptr_t const TCCR0_ptr = &TCCR0;

extern mbl::uint8ptr_t const MCUCSR_ptr = &MCUCSR;

extern mbl::uint8ptr_t const MCUCR_ptr = &MCUCR;

extern mbl::uint8ptr_t const TWCR_ptr = &TWCR;

extern mbl::uint8ptr_t const SPMCR_ptr = &SPMCR;

extern mbl::uint8ptr_t const TIFR_ptr = &TIFR;

extern mbl::uint8ptr_t const TIMSK_ptr = &TIMSK;

extern mbl::uint8ptr_t const GIFR_ptr = &GIFR;

extern mbl::uint8ptr_t const GICR_ptr = &GICR;

extern mbl::uint8ptr_t const OCR0_ptr = &OCR0;
	
} // end namespace mcreg
#endif // end if define ATMEGA_16
#endif // end if define MEGA_16_HPP 	