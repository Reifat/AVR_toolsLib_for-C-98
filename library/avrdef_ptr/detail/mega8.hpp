/* Определение указателей для микроконтроллеров AVR
 * Автор Reifat
 * GitHub Repository - https://github.com/Reifat
 * Последние изменения 04.05.2020.
*/

#ifndef MEGA_8_HPP
#define MEGA_8_HPP

#ifdef ATMEGA_8

#include <avr/io.h>

// include default definitions type
#include "metabit\definitions_type\definitions_type.hpp"

namespace mcreg { // namespace microcontrollers registers

	extern mbl::uint8ptr_t const PINB_ptr = &PINB;

	extern mbl::uint8ptr_t const DDRB_ptr = &DDRB;

	extern mbl::uint8ptr_t const PORTB_ptr = &PORTB;

	extern mbl::uint8ptr_t const PINC_ptr = &PINC;

	extern mbl::uint8ptr_t const DDRC_ptr = &DDRC;

	extern mbl::uint8ptr_t const PORTC_ptr = &PORTC;

	extern mbl::uint8ptr_t const PIND_ptr = &PIND;

	extern mbl::uint8ptr_t const DDRD_ptr = &DDRD;

	extern mbl::uint8ptr_t const PORTD_ptr = &PORTD;

	extern mbl::uint8ptr_t const TIFR0_ptr = &TIFR0;

	extern mbl::uint8ptr_t const TIFR1_ptr = &TIFR1;

	extern mbl::uint8ptr_t const PCIFR_ptr = &PCIFR;

	extern mbl::uint8ptr_t const EIFR_ptr = &EIFR;

	extern mbl::uint8ptr_t const EIMSK_ptr = &EIMSK;

	extern mbl::uint8ptr_t const GPIOR0_ptr = &GPIOR0;

	extern mbl::uint8ptr_t const EECR_ptr = &EECR;

	extern mbl::uint8ptr_t const EEDR_ptr = &EEDR;

	extern mbl::uint8ptr_t const EEAR_ptr = &EEAR;

	extern mbl::uint8ptr_t const EEARL_ptr = &EEARL;

	extern mbl::uint8ptr_t const EEARH_ptr = &EEARH;

	extern mbl::uint8ptr_t const GTCCR_ptr = &GTCCR;

	extern mbl::uint8ptr_t const TCCR0A_ptr = &TCCR0A;

	extern mbl::uint8ptr_t const TCCR0B_ptr = &TCCR0B;

	extern mbl::uint8ptr_t const TCNT0_ptr = &TCNT0;

	extern mbl::uint8ptr_t const OCR0A_ptr = &OCR0A;

	extern mbl::uint8ptr_t const OCR0B_ptr = &OCR0B;

	extern mbl::uint8ptr_t const PLLCSR_ptr = &PLLCSR;

	extern mbl::uint8ptr_t const GPIOR1_ptr = &GPIOR1;

	extern mbl::uint8ptr_t const GPIOR2_ptr = &GPIOR2;

	extern mbl::uint8ptr_t const SPCR_ptr = &SPCR;

	extern mbl::uint8ptr_t const SPSR_ptr = &SPSR;

	extern mbl::uint8ptr_t const SPDR_ptr = &SPDR;

	extern mbl::uint8ptr_t const ACSR_ptr = &ACSR;

	extern mbl::uint8ptr_t const DWDR_ptr = &DWDR;

	extern mbl::uint8ptr_t const SMCR_ptr = &SMCR;

	extern mbl::uint8ptr_t const MCUSR_ptr = &MCUSR;

	extern mbl::uint8ptr_t const MCUCR_ptr = &MCUCR;

	extern mbl::uint8ptr_t const SPMCSR_ptr = &SPMCSR;

	extern mbl::uint8ptr_t const EIND_ptr = &EIND;

	extern mbl::uint8ptr_t const WDTCSR_ptr = &WDTCSR;

	extern mbl::uint8ptr_t const CLKPR_ptr = &CLKPR;

	extern mbl::uint8ptr_t const WDTCKD_ptr = &WDTCKD;

	extern mbl::uint8ptr_t const REGCR_ptr = &REGCR;

	extern mbl::uint8ptr_t const PRR0_ptr = &PRR0;

	extern mbl::uint8ptr_t const PRR1_ptr = &PRR1;

	extern mbl::uint8ptr_t const OSCCAL_ptr = &OSCCAL;

	extern mbl::uint8ptr_t const PCICR_ptr = &PCICR;

	extern mbl::uint8ptr_t const EICRA_ptr = &EICRA;

	extern mbl::uint8ptr_t const EICRB_ptr = &EICRB;

	extern mbl::uint8ptr_t const PCMSK0_ptr = &PCMSK0;

	extern mbl::uint8ptr_t const PCMSK1_ptr = &PCMSK1;

	extern mbl::uint8ptr_t const TIMSK0_ptr = &TIMSK0;

	extern mbl::uint8ptr_t const TIMSK1_ptr = &TIMSK1;

	extern mbl::uint8ptr_t const DIDR1_ptr = &DIDR1;

	extern mbl::uint8ptr_t const TCCR1A_ptr = &TCCR1A;

	extern mbl::uint8ptr_t const TCCR1B_ptr = &TCCR1B;

	extern mbl::uint8ptr_t const TCCR1C_ptr = &TCCR1C;

	extern mbl::uint8ptr_t const TCNT1_ptr = &TCNT1;

	extern mbl::uint8ptr_t const TCNT1L_ptr = &TCNT1L;

	extern mbl::uint8ptr_t const TCNT1H_ptr = &TCNT1H;

	extern mbl::uint8ptr_t const ICR1_ptr = &ICR1;

	extern mbl::uint8ptr_t const ICR1L_ptr = &ICR1L;

	extern mbl::uint8ptr_t const ICR1H_ptr = &ICR1H;

	extern mbl::uint8ptr_t const OCR1A_ptr = &OCR1A;

	extern mbl::uint8ptr_t const OCR1AL_ptr = &OCR1AL;

	extern mbl::uint8ptr_t const OCR1AH_ptr = &OCR1AH;

	extern mbl::uint8ptr_t const OCR1B_ptr = &OCR1B;

	extern mbl::uint8ptr_t const OCR1BL_ptr = &OCR1BL;

	extern mbl::uint8ptr_t const OCR1BH_ptr = &OCR1BH;

	extern mbl::uint8ptr_t const OCR1C_ptr = &OCR1C;

	extern mbl::uint8ptr_t const OCR1CL_ptr = &OCR1CL;

	extern mbl::uint8ptr_t const OCR1CH_ptr = &OCR1CH;

	extern mbl::uint8ptr_t const UCSR1A_ptr = &UCSR1A;

	extern mbl::uint8ptr_t const UCSR1B_ptr = &UCSR1B;

	extern mbl::uint8ptr_t const UCSR1C_ptr = &UCSR1C;

	extern mbl::uint8ptr_t const UCSR1D_ptr = &UCSR1D;

	extern mbl::uint8ptr_t const UBRR1_ptr = &UBRR1;

	extern mbl::uint8ptr_t const UBRR1L_ptr = &UBRR1L;

	extern mbl::uint8ptr_t const UBRR1H_ptr = &UBRR1H;

	extern mbl::uint8ptr_t const UDR1_ptr = &UDR1;

	extern mbl::uint8ptr_t const CLKSEL0_ptr = &CLKSEL0;

	extern mbl::uint8ptr_t const CLKSEL1_ptr = &CLKSEL1;

	extern mbl::uint8ptr_t const CLKSTA_ptr = &CLKSTA;

	extern mbl::uint8ptr_t const USBCON_ptr = &USBCON;

	extern mbl::uint8ptr_t const UDCON_ptr = &UDCON;

	extern mbl::uint8ptr_t const UDINT_ptr = &UDINT;

	extern mbl::uint8ptr_t const UDIEN_ptr = &UDIEN;

	extern mbl::uint8ptr_t const UDADDR_ptr = &UDADDR;

	extern mbl::uint8ptr_t const UDFNUM_ptr = &UDFNUM;

	extern mbl::uint8ptr_t const UDFNUML_ptr = &UDFNUML;

	extern mbl::uint8ptr_t const UDFNUMH_ptr = &UDFNUMH;

	extern mbl::uint8ptr_t const UDMFN_ptr = &UDMFN;

	extern mbl::uint8ptr_t const UEINTX_ptr = &UEINTX;

	extern mbl::uint8ptr_t const UENUM_ptr = &UENUM;

	extern mbl::uint8ptr_t const UERST_ptr = &UERST;

	extern mbl::uint8ptr_t const UECONX_ptr = &UECONX;

	extern mbl::uint8ptr_t const UECFG0X_ptr = &UECFG0X;

	extern mbl::uint8ptr_t const UECFG1X_ptr = &UECFG1X;

	extern mbl::uint8ptr_t const UESTA0X_ptr = &UESTA0X;

	extern mbl::uint8ptr_t const UESTA1X_ptr = &UESTA1X;

	extern mbl::uint8ptr_t const UEIENX_ptr = &UEIENX;

	extern mbl::uint8ptr_t const UEDATX_ptr = &UEDATX;

	extern mbl::uint8ptr_t const UEBCLX_ptr = &UEBCLX;

	extern mbl::uint8ptr_t const UEINT_ptr = &UEINT;

	extern mbl::uint8ptr_t const UPOE_ptr = &UPOE;

} // end namespace mcreg
#endif // end if define ATMEGA_8
#endif // end if define MEGA_8_HPP 