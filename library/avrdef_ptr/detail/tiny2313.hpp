/* Определение указателей для микроконтроллеров AVR
 * Автор Reifat
 * GitHub Repository - https://github.com/Reifat
 * Последние изменения 04.05.2020.
*/

#ifndef TINY_2313_HPP
#define TINY_2313_HPP

#ifdef ATTINY_2313

#include <avr/io.h>

// include default definitions type
#include "metabit\definitions_type\definitions_type.hpp"

namespace mcreg { // namespace microcontrollers registers

#ifdef USIBR
	extern mbl::uint8ptr_t const USIBR_c = &USIBR;
#endif
#ifdef DIDR 
		extern mbl::uint8ptr_t const DIDR_c = &DIDR;
#endif
#ifdef UBRRH
		extern mbl::uint8ptr_t const UBRRH_c = &UBRRH;
#endif
#ifdef UCSRC
		extern mbl::uint8ptr_t const UCSRC_c = &UCSRC;
#endif
#ifdef PCMSK1
		extern mbl::uint8ptr_t const PCMSK1_c = &PCMSK1;
#endif
#ifdef PCMSK2
		extern mbl::uint8ptr_t const PCMSK2_c = &PCMSK2;
#endif
#ifdef PRR
		extern mbl::uint8ptr_t const PRR_c = &PRR;
#endif
#ifdef BODCR
		extern mbl::uint8ptr_t const BODCR_c = &BODCR;
#endif
#ifdef ACSR
		extern mbl::uint8ptr_t const ACSR_c = &ACSR;
#endif
#ifdef UBRRL 
		extern mbl::uint8ptr_t const UBRRL_c = &UBRRL;
#endif
#ifdef UCSRB
		extern mbl::uint8ptr_t const UCSRB_c = &UCSRB;
#endif
#ifdef UCSRA 
		extern mbl::uint8ptr_t const UCSRA_c = &UCSRA;
#endif
#ifdef UDR
		extern mbl::uint8ptr_t const UDR_c = &UDR;
#endif
#ifdef USICR
		extern mbl::uint8ptr_t const USICR_c = &USICR;
#endif
#ifdef USISR
		extern mbl::uint8ptr_t const USISR_c = &USISR;
#endif
#ifdef USIDR
		extern mbl::uint8ptr_t const USIDR_c = &USIDR;
#endif
#ifdef PIND
		extern mbl::uint8ptr_t const PIND_c = &PIND;
#endif
#ifdef DDRD
		extern mbl::uint8ptr_t const DDRD_c = &DDRD;
#endif
#ifdef PORTD
		extern mbl::uint8ptr_t const PORTD_c = &PORTD;
#endif
#ifdef GPIOR0
		extern mbl::uint8ptr_t const GPIOR0_c = &GPIOR0;
#endif
#ifdef GPIOR1
		extern mbl::uint8ptr_t const GPIOR1_c = &GPIOR1;
#endif
#ifdef GPIOR2
		extern mbl::uint8ptr_t const GPIOR2_c = &GPIOR2;
#endif
#ifdef PINB
		extern mbl::uint8ptr_t const PINB_c = &PINB;
#endif
#ifdef DDRB
		extern mbl::uint8ptr_t const DDRB_c = &DDRB;
#endif
#ifdef PORTB
		extern mbl::uint8ptr_t const PORTB_c = &PORTB;
#endif
#ifdef PINA
		extern mbl::uint8ptr_t const PINA_c = &PINA;
#endif
#ifdef DDRA
		extern mbl::uint8ptr_t const DDRA_c = &DDRA;
#endif
#ifdef PORTA
		extern mbl::uint8ptr_t const PORTA_c = &PORTA;
#endif
#ifdef EECR
		extern mbl::uint8ptr_t const EECR_c = &EECR;
#endif
#ifdef EEDR
		extern mbl::uint8ptr_t const EEDR_c = &EEDR;
#endif
#ifdef EEAR
		extern mbl::uint8ptr_t const EEAR_c = &EEAR;
#endif
#ifdef PCMSK
		extern mbl::uint8ptr_t const PCMSK_c = &PCMSK;
#endif
#ifdef WDTCR
		extern mbl::uint8ptr_t const WDTCR_c = &WDTCR;
#endif
#ifdef TCCR1C
		extern mbl::uint8ptr_t const TCCR1C_c = &TCCR1C;
#endif
#ifdef GTCCR
		extern mbl::uint8ptr_t const GTCCR_c = &GTCCR;
#endif
#ifdef ICR1
		extern mbl::uint16ptr_t const ICR1_c = &ICR1;
#endif
#ifdef ICR1L
		extern mbl::uint8ptr_t const ICR1L_c = &ICR1L;
#endif
#ifdef ICR1H
		extern mbl::uint8ptr_t const ICR1H_c = &ICR1H;
#endif 
#ifdef CLKPR 
		extern mbl::uint8ptr_t const CLKPR_c = &CLKPR;
#endif
#ifdef OCR1B
		extern mbl::uint16ptr_t const OCR1B_c = &OCR1B;
#endif
#ifdef OCR1BL
		extern mbl::uint8ptr_t const OCR1BL_c = &OCR1BL;
#endif
#ifdef OCR1BH
		extern mbl::uint8ptr_t const OCR1BH_c = &OCR1BH;
#endif
#ifdef OCR1A
		extern mbl::uint16ptr_t const OCR1A_c = &OCR1A;
#endif
#ifdef OCR1AL
		extern mbl::uint8ptr_t const OCR1AL_c = &OCR1AL;
#endif
#ifdef OCR1AH
		extern mbl::uint8ptr_t const OCR1AH_c = &OCR1AH;
#endif
#ifdef TCNT1
		extern mbl::uint16ptr_t const TCNT1_c = &TCNT1;
#endif
#ifdef TCNT1L
		extern mbl::uint8ptr_t const TCNT1L_c = &TCNT1L;
#endif
#ifdef TCNT1H
		extern mbl::uint8ptr_t const TCNT1H_c = &TCNT1H;
#endif
#ifdef TCCR1B
		extern mbl::uint8ptr_t const TCCR1B_c = &TCCR1B;
#endif
#ifdef TCCR1A
		extern mbl::uint8ptr_t const TCCR1A_c = &TCCR1A;
#endif
#ifdef TCCR0A
		extern mbl::uint8ptr_t const TCCR0A_c = &TCCR0A;
#endif
#ifdef OSCCAL
		extern mbl::uint8ptr_t const OSCCAL_c = &OSCCAL;
#endif
#ifdef TCNT0
		extern mbl::uint8ptr_t const TCNT0_c = &TCNT0;
#endif
#ifdef TCCR0B
		extern mbl::uint8ptr_t const TCCR0B_c = &TCCR0B;
#endif
#ifdef MCUSR
		extern mbl::uint8ptr_t const MCUSR_c = &MCUSR;
#endif
#ifdef MCUCR
		extern mbl::uint8ptr_t const MCUCR_c = &MCUCR;
#endif
#ifdef OCR0A
		extern mbl::uint8ptr_t const OCR0A_c = &OCR0A;
#endif
#ifdef SPMCSR
		extern mbl::uint8ptr_t const SPMCSR_c = &SPMCSR;
#endif
#ifdef TIFR
		extern mbl::uint8ptr_t const TIFR_c = &TIFR;
#endif
#ifdef TIMSK
		extern mbl::uint8ptr_t const TIMSK_c = &TIMSK;
#endif
#ifdef EIFR
		extern mbl::uint8ptr_t const EIFR_c = &EIFR;
#endif
#ifdef GIFR
		extern mbl::uint8ptr_t const GIFR_c = &GIFR;
#endif
#ifdef GIMSK
		extern mbl::uint8ptr_t const GIMSK_c = &GIMSK;
#endif
#ifdef OCR0B
		extern mbl::uint8ptr_t const OCR0B_c = &OCR0B;
#endif

} // end namespace mcreg
#endif // end if ATTINY_2313
#endif // end if TINY_2313_HPP