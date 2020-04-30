/* Определение указателей для микроконтроллеров AVR
 * Автор Reifat
 * GitHub Repository - https://github.com/Reifat
 * Последние изменения 30.04.2020.
*/
#ifndef AVRDEF_HPP
#define AVRDEF_HPP
#include <avr/io.h>
// include default definitions type
#ifndef DEFINITIONS_TYPE_HPP
#include "metabit\definitions_type\definitions_type.hpp"
#endif

// definitions const pointer on register for AVR;
namespace mcreg // mcreg - namespace microcontroller registers;
{
	/* Registers and associated bit numbers */

#ifdef PINA
		   mbl::uint8ptr_t		 pin_a	 = &PINA;
	extern mbl::uint8ptr_t const pin_a_c = &PINA;
#endif
#ifdef DDRA
		   mbl::uint8ptr_t		 ddr_a   = &DDRA;
	extern mbl::uint8ptr_t const ddr_a_c = &DDRA;
#endif
#ifdef PORTA
		   mbl::uint8ptr_t		 port_a   = &PORTA;
	extern mbl::uint8ptr_t const port_a_c = &PORTA;
#endif

#ifdef PINB
		   mbl::uint8ptr_t		 pin_b   = &PINB;
	extern mbl::uint8ptr_t const pin_b_c = &PINB;
#endif
#ifdef DDRB
		   mbl::uint8ptr_t		 ddr_b   = &DDRB;
	extern mbl::uint8ptr_t const ddr_b_c = &DDRB;
#endif
#ifdef PORTB
		   mbl::uint8ptr_t		 port_b   = &PORTB;
	extern mbl::uint8ptr_t const port_b_c = &PORTB;
#endif
#ifdef PINC
		   mbl::uint8ptr_t		 pin_c   = &PINC;
	extern mbl::uint8ptr_t const pin_c_c = &PINC;
#endif
#ifdef DDRC
		   mbl::uint8ptr_t		 ddr_c   = &DDRC;
	extern mbl::uint8ptr_t const ddr_c_c = &DDRC;
#endif
#ifdef PORTC
		   mbl::uint8ptr_t		 port_c   = &PORTC;
	extern mbl::uint8ptr_t const port_c_c = &PORTC;
#endif
#ifdef PIND
		   mbl::uint8ptr_t		 pin_d   = &PIND;
	extern mbl::uint8ptr_t const pin_d_c = &PIND;
#endif
#ifdef DDRD
		   mbl::uint8ptr_t		 ddr_d   = &DDRD;
	extern mbl::uint8ptr_t const ddr_d_c = &DDRD;
#endif
#ifdef PORTD
		   mbl::uint8ptr_t		 port_d   = &PORTD;
	extern mbl::uint8ptr_t const port_d_c = &PORTD;
#endif
#ifdef PINE
		   mbl::uint8ptr_t		 pin_e   = &PINE;
	extern mbl::uint8ptr_t const pin_e_c = &PINE;
#endif
#ifdef DDRE
		   mbl::uint8ptr_t		 ddr_e   = &DDRE;
	extern mbl::uint8ptr_t const ddr_e_c = &DDRE;
#endif
#ifdef PORTE
		   mbl::uint8ptr_t		 port_e   = &PORTE;
	extern mbl::uint8ptr_t const port_e_c = &PORTE;
#endif
#ifdef PINF
		   mbl::uint8ptr_t		 pin_f   = &PINF;
	extern mbl::uint8ptr_t const pin_f_c = &PINF;
#endif
#ifdef DDRF
		   mbl::uint8ptr_t		 ddr_f   = &DDRF;
	extern mbl::uint8ptr_t const ddr_f_c = &DDRF;
#endif
#ifdef PORTF
		   mbl::uint8ptr_t		 port_f   = &PORTF;
	extern mbl::uint8ptr_t const port_f_c = &PORTF;
#endif
#ifdef PING
		   mbl::uint8ptr_t		 pin_g   = &PING;
	extern mbl::uint8ptr_t const pin_g_c = &PING;
#endif
#ifdef DDRG
		   mbl::uint8ptr_t		 ddr_g   = &DDRG;
	extern mbl::uint8ptr_t const ddr_g_c = &DDRG;
#endif
#ifdef PORTG
		   mbl::uint8ptr_t		 port_g   = &PORTG;
	extern mbl::uint8ptr_t const port_g_c = &PORTG;
#endif
#ifdef TIFR
		   mbl::uint8ptr_t		 tifr   = &TIFR;
	extern mbl::uint8ptr_t const tifr_c = &TIFR;
#endif
#ifdef TIFR0
		   mbl::uint8ptr_t		 tifr_0   = &TIFR0;
	extern mbl::uint8ptr_t const tifr_0_c = &TIFR0;
#endif
#ifdef TIFR1
		   mbl::uint8ptr_t		 tifr_1   = &TIFR1;
	extern mbl::uint8ptr_t const tifr_1_c = &TIFR1;
#endif
#ifdef TIFR2
		   mbl::uint8ptr_t		 tifr_2   = &TIFR2;
	extern mbl::uint8ptr_t const tifr_2_c = &TIFR2;
#endif
#ifdef TIFR3
		   mbl::uint8ptr_t		 tifr_3   = &TIFR3;
	extern mbl::uint8ptr_t const tifr_3_c = &TIFR3;
#endif
#ifdef TIFR4
		   mbl::uint8ptr_t		 tifr_4   = &TIFR4;
	extern mbl::uint8ptr_t const tifr_4_c = &TIFR4;
#endif
#ifdef TIFR5
		   mbl::uint8ptr_t		 tifr_5   = &TIFR5;
	extern mbl::uint8ptr_t const tifr_5_c = &TIFR5;
#endif
#ifdef PCIFR
		   mbl::uint8ptr_t		 pcifr   = &PCIFR;
	extern mbl::uint8ptr_t const pcifr_c = &PCIFR;
#endif
#ifdef EIFR
		   mbl::uint8ptr_t		 eifr   = &EIFR;
	extern mbl::uint8ptr_t const eifr_c = &EIFR;
#endif
#ifdef EIMSK
		   mbl::uint8ptr_t		 eimsk   = &EIMSK;
	extern mbl::uint8ptr_t const eimsk_c = &EIMSK;
#endif
#ifdef GPIOR0
		   mbl::uint8ptr_t		 gpior_0   = &GPIOR0;
	extern mbl::uint8ptr_t const gpior_0_c = &GPIOR0;
#endif
#ifdef EECR
		   mbl::uint8ptr_t		 eecr   = &EECR;
	extern mbl::uint8ptr_t const eecr_c = &EECR;
#endif
#ifdef EEDR
		   mbl::uint8ptr_t		 eedr   = &EEDR;
	extern mbl::uint8ptr_t const eedr_c = &EEDR;
#endif

	/* Combine EEARL and EEARH */
#ifdef EEAR
		   mbl::uint16ptr_t		  eear   = &EEAR;
	extern mbl::uint16ptr_t const eear_c = &EEAR;
#endif
#ifdef EEARL
		   mbl::uint8ptr_t		 eear_l   = &EEARL;
	extern mbl::uint8ptr_t const eear_l_c = &EEARL;
#endif
#ifdef EEARH
		   mbl::uint8ptr_t		 eear_h   = &EEARH;
	extern mbl::uint8ptr_t const eear_h_c = &EEARH;
#endif

	/* 6-char sequence denoting where to find the EEPROM registers in memory space.
	   Adresses denoted in hex syntax with uppercase letters. Used by the EEPROM
	   subroutines.
	   First two letters:  EECR address.
	   Second two letters: EEDR address.
	   Last two letters:   EEAR address.  */
#ifdef GTCCR
		   mbl::uint8ptr_t		 gtccr   = &GTCCR;
	extern mbl::uint8ptr_t const gtccr_c = &GTCCR;
#endif
#ifdef TCCR0
		   mbl::uint8ptr_t		 tccr_0   = &TCCR0;
	extern mbl::uint8ptr_t const tccr_0_c = &TCCR0;
#endif
#ifdef TCCR0A
		   mbl::uint8ptr_t		 tccr_0_a   = &TCCR0A;
	extern mbl::uint8ptr_t const tccr_0_a_c = &TCCR0A;
#endif
#ifdef TCCR0B
		   mbl::uint8ptr_t		 tccr_0_b   = &TCCR0B;
	extern mbl::uint8ptr_t const tccr_0_b_c = &TCCR0B;
#endif
#ifdef TCNT0
		   mbl::uint8ptr_t		 tcnt_0   = &TCNT0;
	extern mbl::uint8ptr_t const tcnt_0_c = &TCNT0;
#endif
#ifdef OCR0
		   mbl::uint8ptr_t		 ocr_0   = &OCR0;
	extern mbl::uint8ptr_t const ocr_0_c = &OCR0;
#endif
#ifdef OCR0A
		   mbl::uint8ptr_t		 ocr_0_a   = &OCR0A;
	extern mbl::uint8ptr_t const ocr_0_a_c = &OCR0A;
#endif
#ifdef OCR0B
		   mbl::uint8ptr_t		 ocr_0_b   = &OCR0B;
	extern mbl::uint8ptr_t const ocr_0_b_c = &OCR0B;
#endif

	/* Reserved [0x29] */
#ifdef GPIOR1
		   mbl::uint8ptr_t		 gpior_1   = &GPIOR1;
	extern mbl::uint8ptr_t const gpior_1_c = &GPIOR1;
#endif
#ifdef GPIOR2
		   mbl::uint8ptr_t		 gpior_2   = &GPIOR2;
	extern mbl::uint8ptr_t const gpior_2_c = &GPIOR2;
#endif
#ifdef SPCR
		   mbl::uint8ptr_t		 spcr   = &SPCR;
	extern mbl::uint8ptr_t const spcr_c = &SPCR;
#endif
#ifdef SPSR
		   mbl::uint8ptr_t		 spsr   = &SPSR;
	extern mbl::uint8ptr_t const spsr_c = &SPSR;
#endif
#ifdef SPDR
		   mbl::uint8ptr_t		 spdr   = &SPDR;
	extern mbl::uint8ptr_t const spdr_c = &SPDR;
#endif

	/* Reserved [0x2F] */
#ifdef ACSR
		   mbl::uint8ptr_t		 acsr   = &ACSR;
	extern mbl::uint8ptr_t const acsr_c = &ACSR;
#endif
#ifdef MONDR
		   mbl::uint8ptr_t		 mondr   = &MONDR;
	extern mbl::uint8ptr_t const mondr_c = &MONDR;
#endif
#ifdef OCDR
		   mbl::uint8ptr_t		 ocdr   = &OCDR;
	extern mbl::uint8ptr_t const ocdr_c = &OCDR;
#endif

	/* Reserved [0x32] */
#ifdef SMCR
		   mbl::uint8ptr_t		 smcr   = &SMCR;
	extern mbl::uint8ptr_t const smcr_c = &SMCR;
#endif
#ifdef MCUSR
		   mbl::uint8ptr_t		 mcusr   = &MCUSR;
	extern mbl::uint8ptr_t const mcusr_c = &MCUSR;
#endif
#ifdef MCUCR
		   mbl::uint8ptr_t		 mcucr   = &MCUCR;
	extern mbl::uint8ptr_t const mcucr_c = &MCUCR;
#endif

	/* Reserved [0x36] */
#ifdef SPMCSR
		   mbl::uint8ptr_t		 spmcsr   = &SPMCSR;
	extern mbl::uint8ptr_t const spmcsr_c = &SPMCSR;
#endif

	/* Reserved [0x38..0x3A] */
#ifdef RAMPZ
		   mbl::uint8ptr_t		 rampz   = &RAMPZ;
	extern mbl::uint8ptr_t const rampz_c = &RAMPZ;
#endif
#ifdef EIND
		   mbl::uint8ptr_t		 eind   = &EIND;
	extern mbl::uint8ptr_t const eind_c = &EIND;
#endif

	/* SP [0x3D..0x3E] */
	/* SREG [0x3F] */
#ifdef WDTCSR
		   mbl::uint8ptr_t		 wdtcsr   = &WDTCSR;
	extern mbl::uint8ptr_t const wdtcsr_c = &WDTCSR;
#endif
#ifdef CLKPR
		   mbl::uint8ptr_t		 clkpr   = &CLKPR;
	extern mbl::uint8ptr_t const clkpr_c = &CLKPR;
#endif

	/* Reserved [0x62..0x63] */
#ifdef PRR0
		   mbl::uint8ptr_t		 prr_0   = &PRR0;
	extern mbl::uint8ptr_t const prr_0_c = &PRR0;
#endif
#ifdef PRR1
		   mbl::uint8ptr_t		 prr_1   = &PRR1;
	extern mbl::uint8ptr_t const prr_1_c = &PRR1;
#endif

#ifdef OSCCAL
		   mbl::uint8ptr_t		 osccal   = &OSCCAL;
	extern mbl::uint8ptr_t const osccal_c = &OSCCAL;
#endif

	/* Reserved [0x67] */
#ifdef PCICR
		   mbl::uint8ptr_t		 pcicr   = &PCICR;
	extern mbl::uint8ptr_t const pcicr_c = &PCICR;
#endif
#ifdef EICRA
		   mbl::uint8ptr_t		 eicr_a   = &EICRA;
	extern mbl::uint8ptr_t const eicr_a_c = &EICRA;
#endif
#ifdef EICRB
		   mbl::uint8ptr_t		 eicr_b   = &EICRB;
	extern mbl::uint8ptr_t const eicr_b_c = &EICRB;
#endif
#ifdef PCMSK0
		   mbl::uint8ptr_t		 pcmsk_0   = &PCMSK0;
	extern mbl::uint8ptr_t const pcmsk_0_c = &PCMSK0;
#endif
#ifdef PCMSK1
		   mbl::uint8ptr_t		 pcmsk_1   = &PCMSK1;
	extern mbl::uint8ptr_t const pcmsk_1_c = &PCMSK1;
#endif
#ifdef PCMSK2
		   mbl::uint8ptr_t		 pcmsk_2   = &PCMSK2;
	extern mbl::uint8ptr_t const pcmsk_2_c = &PCMSK2;
#endif
#ifdef TIMSK
		   mbl::uint8ptr_t		 timsk   = &TIMSK;
	extern mbl::uint8ptr_t const timsk_c = &TIMSK;
#endif
#ifdef TIMSK0
		   mbl::uint8ptr_t		 timsk_0   = &TIMSK0;
	extern mbl::uint8ptr_t const timsk_0_c = &TIMSK0;
#endif
#ifdef TIMSK1
		   mbl::uint8ptr_t		 timsk_1   = &TIMSK1;
	extern mbl::uint8ptr_t const timsk_1_c = &TIMSK1;
#endif
#ifdef TIMSK2
		   mbl::uint8ptr_t		 timsk_2   = &TIMSK2;
	extern mbl::uint8ptr_t const timsk_2_c = &TIMSK2;
#endif
#ifdef TIMSK3
		   mbl::uint8ptr_t		 timsk_3   = &TIMSK3;
	extern mbl::uint8ptr_t const timsk_3_c = &TIMSK3;
#endif
#ifdef TIMSK4
		   mbl::uint8ptr_t		 timsk_4   = &TIMSK4;
	extern mbl::uint8ptr_t const timsk_4_c = &TIMSK4;
#endif
#ifdef TIMSK5
		   mbl::uint8ptr_t		 timsk_5   = &TIMSK5;
	extern mbl::uint8ptr_t const timsk_5_c = &TIMSK5;
#endif
#ifdef XMCRA
		   mbl::uint8ptr_t		 xmcr_a   = &XMCRA;
	extern mbl::uint8ptr_t const xmcr_a_c = &XMCRA;
#endif
#ifdef XMCRB
		   mbl::uint8ptr_t		 xmcr_b   = &XMCRB;
	extern mbl::uint8ptr_t const xmcr_b_c = &XMCRB;
#endif

	/* Reserved [0x76..0x77] */

	/* Combine ADCL and ADCH */
#ifdef ADC
		   mbl::uint16ptr_t		  adc   = &ADC;
	extern mbl::uint16ptr_t const adc_c = &ADC;
#endif
#ifdef ADCW
		   mbl::uint16ptr_t		  adc_w   = &ADCW;
	extern mbl::uint16ptr_t const adc_w_c = &ADCW;
#endif
#ifdef ADCL
		   mbl::uint8ptr_t		 adc_l   = &ADCL;
	extern mbl::uint8ptr_t const adc_l_c = &ADCL;
#endif
#ifdef ADCH
		   mbl::uint8ptr_t		 adc_h   = &ADCH;
	extern mbl::uint8ptr_t const adc_h_c = &ADCH;
#endif
#ifdef ADCSRA
		   mbl::uint8ptr_t		 adcsr_a   = &ADCSRA;
	extern mbl::uint8ptr_t const adcsr_a_c = &ADCSRA;
#endif
#ifdef ADCSRB
		   mbl::uint8ptr_t		 adcsr_b   = &ADCSRB;
	extern mbl::uint8ptr_t const adcsr_b_c = &ADCSRB;
#endif
#ifdef ADMUX
		   mbl::uint8ptr_t	     admux   = &ADMUX;
	extern mbl::uint8ptr_t const admux_c = &ADMUX;
#endif
#ifdef DIDR0
		   mbl::uint8ptr_t		 didr_0   = &DIDR0;
	extern mbl::uint8ptr_t const didr_0_c = &DIDR0;
#endif
#ifdef DIDR1
		   mbl::uint8ptr_t		 didr_1   = &DIDR1;
	extern mbl::uint8ptr_t const didr_1_c = &DIDR1;
#endif
#ifdef DIDR2
		   mbl::uint8ptr_t		 didr_2   = &DIDR2;
	extern mbl::uint8ptr_t const didr_2_c = &DIDR2;
#endif
#ifdef TCCR1A
		   mbl::uint8ptr_t		 tccr_1_a   = &TCCR1A;
	extern mbl::uint8ptr_t const tccr_1_a_c = &TCCR1A;
#endif
#ifdef TCCR1B
		   mbl::uint8ptr_t		 tccr_1_b   = &TCCR1B;
	extern mbl::uint8ptr_t const tccr_1_b_c = &TCCR1B;
#endif
#ifdef TCCR1C
		   mbl::uint8ptr_t		 tccr_1_c   = &TCCR1C;
	extern mbl::uint8ptr_t const tccr_1_c_c = &TCCR1C;
#endif

	/* Reserved [0x83] */

	/* Combine TCNT1L and TCNT1H */
#ifdef TCNT1
		   mbl::uint16ptr_t		  tcnt_1   = &TCNT1;
	extern mbl::uint16ptr_t const tcnt_1_c = &TCNT1;
#endif
#ifdef TCNT1L
		   mbl::uint8ptr_t		 tcnt_1_l   = &TCNT1L;
	extern mbl::uint8ptr_t const tcnt_1_l_c = &TCNT1L;
#endif
#ifdef TCNT1H
		   mbl::uint8ptr_t		 tcnt_1_h   = &TCNT1H;
	extern mbl::uint8ptr_t const tcnt_1_h_c = &TCNT1H;
#endif

	/* Combine ICR1L and ICR1H */
#ifdef ICR1
		   mbl::uint16ptr_t		  icr_1   = &ICR1;
	extern mbl::uint16ptr_t const icr_1_c = &ICR1;
#endif
#ifdef ICR1L
		   mbl::uint8ptr_t		 icr_1_l   = &ICR1L;
	extern mbl::uint8ptr_t const icr_1_l_c = &ICR1L;
#endif
#ifdef ICR1H
		   mbl::uint8ptr_t		 icr_1_h   = &ICR1H;
	extern mbl::uint8ptr_t const icr_1_h_c = &ICR1H;
#endif

	/* Combine OCR1AL and OCR1AH */
#ifdef OCR1A
		   mbl::uint16ptr_t		  ocr_1_a   = &OCR1A;
	extern mbl::uint16ptr_t const ocr_1_a_c = &OCR1A;
#endif
#ifdef OCR1AL
		   mbl::uint8ptr_t		 ocr_1_a_l   = &OCR1AL;
	extern mbl::uint8ptr_t const ocr_1_a_l_c = &OCR1AL;
#endif
#ifdef OCR1AH
		   mbl::uint8ptr_t		 ocr_1_a_h   = &OCR1AH;
	extern mbl::uint8ptr_t const ocr_1_a_h_c = &OCR1AH;
#endif

	/* Combine OCR1BL and OCR1BH */
#ifdef OCR1B
		   mbl::uint16ptr_t		  ocr_1_b   = &OCR1B;
	extern mbl::uint16ptr_t const ocr_1_b_c = &OCR1B;
#endif
#ifdef OCR1BL
		   mbl::uint8ptr_t		 ocr_1_b_l   = &OCR1BL;
	extern mbl::uint8ptr_t const ocr_1_b_l_c = &OCR1BL;
#endif
#ifdef OCR1BH
		   mbl::uint8ptr_t		 ocr_1_b_h   = &OCR1BH;
	extern mbl::uint8ptr_t const ocr_1_b_h_c = &OCR1BH;
#endif

	/* Combine OCR1CL and OCR1CH */
#ifdef OCR1C
		   mbl::uint16ptr_t		  ocr_1_c   = &OCR1C;
	extern mbl::uint16ptr_t const ocr_1_c_c = &OCR1C;
#endif
#ifdef OCR1CL
		   mbl::uint8ptr_t		 ocr_1_c_l   = &OCR1CL;
	extern mbl::uint8ptr_t const ocr_1_c_l_c = &OCR1CL;
#endif
#ifdef OCR1CH
		   mbl::uint8ptr_t		 ocr_1_c_h   = &OCR1CH;
	extern mbl::uint8ptr_t const ocr_1_c_h_c = &OCR1CH;
#endif

	/* Reserved [0x8E..0x8F] */
#ifdef TCCR3A
		   mbl::uint8ptr_t		 tccr_3_a   = &TCCR3A;
	extern mbl::uint8ptr_t const tccr_3_a_c = &TCCR3A;
#endif
#ifdef TCCR3B
		   mbl::uint8ptr_t		 tccr_3_b   = &TCCR3B;
	extern mbl::uint8ptr_t const tccr_3_b_c = &TCCR3B;
#endif
#ifdef TCCR3C
		   mbl::uint8ptr_t		 tccr_3_c   = &TCCR3C;
	extern mbl::uint8ptr_t const tccr_3_c_c = &TCCR3C;
#endif

	/* Reserved [0x93] */

	/* Combine TCNT3L and TCNT3H */
#ifdef TCNT3
		   mbl::uint16ptr_t		  tcnt_3   = &TCNT3;
	extern mbl::uint16ptr_t const tcnt_3_c = &TCNT3;
#endif
#ifdef TCNT3L
		   mbl::uint8ptr_t		 tcnt_3_l   = &TCNT3L;
	extern mbl::uint8ptr_t const tcnt_3_l_c = &TCNT3L;
#endif
#ifdef TCNT3H
		   mbl::uint8ptr_t		 tcnt_3_h   = &TCNT3H;
	extern mbl::uint8ptr_t const tcnt_3_h_c = &TCNT3H;
#endif

	/* Combine ICR3L and ICR3H */
#ifdef ICR3
		   mbl::uint16ptr_t		  icr_3   = &ICR3;
	extern mbl::uint16ptr_t const icr_3_c = &ICR3;
#endif
#ifdef ICR3L
		   mbl::uint8ptr_t		 icr_3_l   = &ICR3L;
	extern mbl::uint8ptr_t const icr_3_l_c = &ICR3L;
#endif
#ifdef ICR3H
		   mbl::uint8ptr_t		 icr_3_h   = &ICR3H;
	extern mbl::uint8ptr_t const icr_3_h_c = &ICR3H;
#endif

	/* Combine OCR3AL and OCR3AH */
#ifdef OCR3A
		   mbl::uint16ptr_t		  ocr_3_a   = &OCR3A;
	extern mbl::uint16ptr_t const ocr_3_a_c = &OCR3A;
#endif
#ifdef OCR3AL
		   mbl::uint8ptr_t		 ocr_3_a_l   = &OCR3AL;
	extern mbl::uint8ptr_t const ocr_3_a_l_c = &OCR3AL;
#endif
#ifdef OCR3AH
		   mbl::uint8ptr_t		 ocr_3_a_h   = &OCR3AH;
	extern mbl::uint8ptr_t const ocr_3_a_h_c = &OCR3AH;
#endif

	/* Combine OCR3BL and OCR3BH */
#ifdef OCR3B
		   mbl::uint16ptr_t		  ocr_3_b   = &OCR3B;
	extern mbl::uint16ptr_t const ocr_3_b_c = &OCR3B;
#endif
#ifdef OCR3BL
		   mbl::uint8ptr_t		 ocr_3_b_l   = &OCR3BL;
	extern mbl::uint8ptr_t const ocr_3_b_l_c = &OCR3BL;
#endif
#ifdef OCR3BH
		   mbl::uint8ptr_t		 ocr_3_b_h   = &OCR3BH;
	extern mbl::uint8ptr_t const ocr_3_b_h_c = &OCR3BH;
#endif

	/* Combine OCR3CL and OCR3CH */
#ifdef OCR3C
		   mbl::uint16ptr_t		  ocr_3_c   = &OCR3C;
	extern mbl::uint16ptr_t const ocr_3_c_c = &OCR3C;
#endif
#ifdef OCR3CL
		   mbl::uint8ptr_t		 ocr_3_c_l   = &OCR3CL;
	extern mbl::uint8ptr_t const ocr_3_c_l_c = &OCR3CL;
#endif
#ifdef OCR3CH
		   mbl::uint8ptr_t		 ocr_3_c_h   = &OCR3CH;
	extern mbl::uint8ptr_t const ocr_3_c_h_c = &OCR3CH;
#endif

	/* Reserved [0x9E..0x9F] */
#ifdef TCCR4A
		   mbl::uint8ptr_t		 tccr_4_a   = &TCCR4A;
	extern mbl::uint8ptr_t const tccr_4_a_c = &TCCR4A;
#endif
#ifdef TCCR4B
		   mbl::uint8ptr_t		 tccr4_b   = &TCCR4B;
	extern mbl::uint8ptr_t const tccr4_b_c = &TCCR4B;
#endif
#ifdef TCCR4C
		   mbl::uint8ptr_t		 tccr_4_c   = &TCCR4C;
	extern mbl::uint8ptr_t const tccr_4_c_c = &TCCR4C;
#endif

	/* Reserved [0xA3] */

	/* Combine TCNT4L and TCNT4H */
#ifdef TCNT4
		   mbl::uint16ptr_t		  tcnt_4   = &TCNT4;
	extern mbl::uint16ptr_t const tcnt_4_c = &TCNT4;
#endif
#ifdef TCNT4L
		   mbl::uint8ptr_t		 tcnt_4_l   = &TCNT4L;
	extern mbl::uint8ptr_t const tcnt_4_l_c = &TCNT4L;
#endif
#ifdef TCNT4H
		   mbl::uint8ptr_t		 tcnt_4_h   = &TCNT4H;
	extern mbl::uint8ptr_t const tcnt_4_h_c = &TCNT4H;
#endif

	/* Combine ICR4L and ICR4H */
#ifdef ICR4
		   mbl::uint16ptr_t		  icr_4   = &ICR4;
	extern mbl::uint16ptr_t const icr_4_c = &ICR4;
#endif
#ifdef ICR4L
		   mbl::uint8ptr_t		 icr_4_l   = &ICR4L;
	extern mbl::uint8ptr_t const icr_4_l_c = &ICR4L;
#endif
#ifdef ICR4H
		   mbl::uint8ptr_t		 icr_4_h   = &ICR4H;
	extern mbl::uint8ptr_t const icr_4_h_c = &ICR4H;
#endif

	/* Combine OCR4AL and OCR4AH */
#ifdef OCR4A
		   mbl::uint16ptr_t		  ocr_4_a   = &OCR4A;
	extern mbl::uint16ptr_t const ocr_4_a_c = &OCR4A;
#endif
#ifdef OCR4AL
		   mbl::uint8ptr_t		 ocr_4_a_l   = &OCR4AL;
	extern mbl::uint8ptr_t const ocr_4_a_l_c = &OCR4AL;
#endif
#ifdef OCR4AH
		   mbl::uint8ptr_t		 ocr_4_a_h   = &OCR4AH;
	extern mbl::uint8ptr_t const ocr_4_a_h_c = &OCR4AH;
#endif

	/* Combine OCR4BL and OCR4BH */
#ifdef OCR4B
		   mbl::uint16ptr_t		  ocr_4_b   = &OCR4B;
	extern mbl::uint16ptr_t const ocr_4_b_c = &OCR4B;
#endif
#ifdef OCR4BL
		   mbl::uint8ptr_t		 ocr_4_b_l   = &OCR4BL;
	extern mbl::uint8ptr_t const ocr_4_b_l_c = &OCR4BL;
#endif
#ifdef OCR4BH
		   mbl::uint8ptr_t		 ocr_4_b_h   = &OCR4BH;
	extern mbl::uint8ptr_t const ocr_4_b_h_c = &OCR4BH;
#endif

	/* Combine OCR4CL and OCR4CH */
#ifdef OCR4C
		   mbl::uint16ptr_t		  ocr_4_c   = &OCR4C;
	extern mbl::uint16ptr_t const ocr_4_c_c = &OCR4C;
#endif
#ifdef OCR4CL
		   mbl::uint8ptr_t		 ocr_4_c_l   = &OCR4CL;
	extern mbl::uint8ptr_t const ocr_4_c_l_c = &OCR4CL;
#endif
#ifdef OCR4CH
		   mbl::uint8ptr_t		 ocr_4_c_h   = &OCR4CH;
	extern mbl::uint8ptr_t const ocr_4_c_h_c = &OCR4CH;
#endif

	/* Reserved [0xAE..0xAF] */
#ifdef TCCR2A
		   mbl::uint8ptr_t		 tccr_2_a   = &TCCR2A;
	extern mbl::uint8ptr_t const tccr_2_a_c = &TCCR2A;
#endif
#ifdef TCNT2
		   mbl::uint8ptr_t		 tcnt_2   = &TCNT2;
	extern mbl::uint8ptr_t const tcnt_2_c = &TCNT2;
#endif
#ifdef OCR2A
		   mbl::uint8ptr_t		 ocr_2_a   = &OCR2A;
	extern mbl::uint8ptr_t const ocr_2_a_c = &OCR2A;
#endif
#ifdef OCR2B
		   mbl::uint8ptr_t		 ocr_2_b   = &OCR2B;
	extern mbl::uint8ptr_t const ocr_2_b_c = &OCR2B;
#endif

	/* Reserved [0xB5] */
#ifdef ASSR
		   mbl::uint8ptr_t		 assr   = &ASSR;
	extern mbl::uint8ptr_t const assr_c = &ASSR;
#endif

	/* Reserved [0xB7] */
#ifdef TWBR
		   mbl::uint8ptr_t		 tw_br   = &TWBR;
	extern mbl::uint8ptr_t const tw_br_c = &TWBR;
#endif
#ifdef TWSR
		   mbl::uint8ptr_t		 tw_sr   = &TWSR;
	extern mbl::uint8ptr_t const tw_sr_c = &TWSR;
#endif
#ifdef TWAR
		   mbl::uint8ptr_t		 tw_ar   = &TWAR;
	extern mbl::uint8ptr_t const tw_ar_c = &TWAR;
#endif
#ifdef TWDR
		   mbl::uint8ptr_t		 tw_dr   = &TWDR;
	extern mbl::uint8ptr_t const tw_dr_c = &TWDR;
#endif
#ifdef TWCR
		   mbl::uint8ptr_t		 tw_cr   = &TWCR;
	extern mbl::uint8ptr_t const tw_cr_c = &TWCR;
#endif
#ifdef TWAMR
		   mbl::uint8ptr_t		 twa_mr   = &TWAMR;
	extern mbl::uint8ptr_t const twa_mr_c = &TWAMR;
#endif

	/* Reserved [0xBE..0xBF] */
#ifdef UCSR0A
		   mbl::uint8ptr_t		 ucsr_0_a   = &UCSR0A;
	extern mbl::uint8ptr_t const ucsr_0_a_c = &UCSR0A;
#endif
#ifdef UCSR0B 
		   mbl::uint8ptr_t		 ucsr_0_b   = &UCSR0B;
	extern mbl::uint8ptr_t const ucsr_0_b_c = &UCSR0B;
#endif
#ifdef UCSR0C
		   mbl::uint8ptr_t		 ucsr_0_c   = &UCSR0C;
	extern mbl::uint8ptr_t const ucsr_0_c_c = &UCSR0C;
#endif

	/* Reserved [0xC3] */

	/* Combine UBRR0L and UBRR0H */
#ifdef UBRR0
		   mbl::uint16ptr_t		  ubrr_0   = &UBRR0;
	extern mbl::uint16ptr_t const ubrr_0_c = &UBRR0;
#endif
#ifdef UBRR0L
		   mbl::uint8ptr_t		 ubrr_0_l   = &UBRR0L;
	extern mbl::uint8ptr_t const ubrr_0_l_c = &UBRR0L;
#endif
#ifdef UBRR0H
		   mbl::uint8ptr_t		 ubrr_0_h   = &UBRR0H;
	extern mbl::uint8ptr_t const ubrr_0_h_c = &UBRR0H;
#endif
#ifdef UDR0
		   mbl::uint8ptr_t		 udr_0   = &UDR0;
	extern mbl::uint8ptr_t const udr_0_c = &UDR0;
#endif

	/* Reserved [0xC7] */
#ifdef UCSR1A
		   mbl::uint8ptr_t		 ucsr_1_a   = &UCSR1A;
	extern mbl::uint8ptr_t const ucsr_1_a_c = &UCSR1A;
#endif
#ifdef UCSR1B
		   mbl::uint8ptr_t		 ucsr_1_b   = &UCSR1B;
	extern mbl::uint8ptr_t const ucsr_1_b_c = &UCSR1B;
#endif
#ifdef UCSR1C
		   mbl::uint8ptr_t		 ucsr_1_c   = &UCSR1C;
	extern mbl::uint8ptr_t const ucsr_1_c_c = &UCSR1C;
#endif

	/* Reserved [0xCB] */

	/* Combine UBRR1L and UBRR1H */
#ifdef UBRR1
		   mbl::uint16ptr_t		  ubrr_1   = &UBRR1;
	extern mbl::uint16ptr_t const ubrr_1_c = &UBRR1;
#endif
#ifdef UBRR1L
		   mbl::uint8ptr_t		 ubrr_1_l   = &UBRR1L;
	extern mbl::uint8ptr_t const ubrr_1_l_c = &UBRR1L;
#endif
#ifdef UBRR1H
		   mbl::uint8ptr_t		 ubrr_1_h   = &UBRR1H;
	extern mbl::uint8ptr_t const ubrr_1_h_c = &UBRR1H;
#endif
#ifdef UDR1
		   mbl::uint8ptr_t		 udr_1   = &UDR1;
	extern mbl::uint8ptr_t const udr_1_c = &UDR1;
#endif

	/* Reserved [0xCF] */
#ifdef UCSR2A
		   mbl::uint8ptr_t		 ucsr_2_a   = &UCSR2A;
	extern mbl::uint8ptr_t const ucsr_2_a_c = &UCSR2A;
#endif
#ifdef UCSR2B
		   mbl::uint8ptr_t		 ucsr_2_b   = &UCSR2B;
	extern mbl::uint8ptr_t const ucsr_2_b_c = &UCSR2B;
#endif
#ifdef UCSR2C
		   mbl::uint8ptr_t		 ucsr_2_c   = &UCSR2C;
	extern mbl::uint8ptr_t const ucsr_2_c_c = &UCSR2C;
#endif

	/* Reserved [0xD3] */

	/* Combine UBRR2L and UBRR2H */
#ifdef UBRR2
		   mbl::uint16ptr_t		  ubrr_2   = &UBRR2;
	extern mbl::uint16ptr_t const ubrr_2_c = &UBRR2;
#endif
#ifdef UBRR2L
		   mbl::uint8ptr_t		 ubrr_2_l   = &UBRR2L;
	extern mbl::uint8ptr_t const ubrr_2_l_c = &UBRR2L;
#endif
#ifdef UBRR2H
		   mbl::uint8ptr_t		 ubrr_2_h   = &UBRR2H;
	extern mbl::uint8ptr_t const ubrr_2_h_c = &UBRR2H;
#endif
#ifdef UDR2
		   mbl::uint8ptr_t		 udr_2   = &UDR2;
	extern mbl::uint8ptr_t const udr_2_c = &UDR2;
#endif

	/* Reserved [0xD7..0xFF] */
#ifdef PINH
		   mbl::uint8ptr_t		 pin_h   = &PINH;
	extern mbl::uint8ptr_t const pin_h_c = &PINH;
#endif
#ifdef DDRH
		   mbl::uint8ptr_t		 ddr_h   = &DDRH;
	extern mbl::uint8ptr_t const ddr_h_c = &DDRH;
#endif
#ifdef PORTH
		   mbl::uint8ptr_t		 port_h   = &PORTH;
	extern mbl::uint8ptr_t const port_h_c = &PORTH;
#endif
#ifdef PINJ
		   mbl::uint8ptr_t		 pin_j   = &PINJ;
	extern mbl::uint8ptr_t const pin_j_c = &PINJ;
#endif
#ifdef DDRJ
		   mbl::uint8ptr_t		 ddr_j   = &DDRJ;
	extern mbl::uint8ptr_t const ddr_j_c = &DDRJ;
#endif
#ifdef PORTJ
		   mbl::uint8ptr_t		 port_j   = &PORTJ;
	extern mbl::uint8ptr_t const port_j_c = &PORTJ;
#endif
#ifdef PINK
		   mbl::uint8ptr_t		 pin_k   = &PINK;
	extern mbl::uint8ptr_t const pin_k_c = &PINK;
#endif
#ifdef DDRK
		   mbl::uint8ptr_t		 ddr_k   = &DDRK;
	extern mbl::uint8ptr_t const ddr_k_c = &DDRK;
#endif
#ifdef PORTK
		   mbl::uint8ptr_t		 port_k   = &PORTK;
	extern mbl::uint8ptr_t const port_k_c = &PORTK;
#endif
#ifdef PINL
		   mbl::uint8ptr_t		 pin_l   = &PINL;
	extern mbl::uint8ptr_t const pin_l_c = &PINL;
#endif
#ifdef DDRL
		   mbl::uint8ptr_t		 ddr_l   = &DDRL;
	extern mbl::uint8ptr_t const ddr_l_c = &DDRL;
#endif
#ifdef PORTL
		   mbl::uint8ptr_t		 port_l   = &PORTL;
	extern mbl::uint8ptr_t const port_l_c = &PORTL;
#endif
	/* Reserved [0x10C..0x11F] */
#ifdef TCCR5A
		   mbl::uint8ptr_t		 tccr_5_a   = &TCCR5A;
	extern mbl::uint8ptr_t const tccr_5_a_c = &TCCR5A;
#endif
#ifdef TCCR5B
		   mbl::uint8ptr_t		 tccr_5_b   = &TCCR5B;
	extern mbl::uint8ptr_t const tccr_5_b_c = &TCCR5B;
#endif
#ifdef TCCR5C
		   mbl::uint8ptr_t		 tccr_5_c   = &TCCR5C;
	extern mbl::uint8ptr_t const tccr_5_c_c = &TCCR5C;
#endif
	/* Reserved [0x123] */

	/* Combine TCNT5L and TCNT5H */
#ifdef TCNT5
		   mbl::uint16ptr_t		  tcnt_5   = &TCNT5;
	extern mbl::uint16ptr_t const tcnt_5_c = &TCNT5;
#endif
#ifdef TCNT5L
		   mbl::uint8ptr_t		 tcnt_5_l   = &TCNT5L;
	extern mbl::uint8ptr_t const tcnt_5_l_c = &TCNT5L;
#endif
#ifdef TCNT5H
		   mbl::uint8ptr_t		 tcnt_5_h   = &TCNT5H;
	extern mbl::uint8ptr_t const tcnt_5_h_c = &TCNT5H;
#endif
	/* Combine ICR5L and ICR5H */
#ifdef ICR5
		   mbl::uint16ptr_t		  icr_5   = &ICR5;
	extern mbl::uint16ptr_t const icr_5_c = &ICR5;
#endif
#ifdef ICR5L
		   mbl::uint8ptr_t		 icr_5_l   = &ICR5L;
	extern mbl::uint8ptr_t const icr_5_l_c = &ICR5L;
#endif
#ifdef ICR5H
		   mbl::uint8ptr_t		 icr_5_h   = &ICR5H;
	extern mbl::uint8ptr_t const icr_5_h_c = &ICR5H;
#endif

	/* Combine OCR5AL and OCR5AH */
#ifdef OCR5A
		   mbl::uint16ptr_t		  ocr_5_a   = &OCR5A;
	extern mbl::uint16ptr_t const ocr_5_a_c = &OCR5A;
#endif
#ifdef OCR5AL
		   mbl::uint8ptr_t		 ocr_5_a_l   = &OCR5AL;
	extern mbl::uint8ptr_t const ocr_5_a_l_c = &OCR5AL;
#endif
#ifdef OCR5AH
		   mbl::uint8ptr_t		 ocr_5_a_h   = &OCR5AH;
	extern mbl::uint8ptr_t const ocr_5_a_h_c = &OCR5AH;
#endif

	/* Combine OCR5BL and OCR5BH */
#ifdef OCR5B
		   mbl::uint16ptr_t		  ocr_5_b   = &OCR5B;
	extern mbl::uint16ptr_t const ocr_5_b_c = &OCR5B;
#endif
#ifdef OCR5BL
		   mbl::uint8ptr_t		 ocr_5_b_l   = &OCR5BL;
	extern mbl::uint8ptr_t const ocr_5_b_l_c = &OCR5BL;
#endif
#ifdef OCR5BH
		   mbl::uint8ptr_t		 ocr_5_b_h   = &OCR5BH;
	extern mbl::uint8ptr_t const ocr_5_b_h_c = &OCR5BH;
#endif
	/* Combine OCR5CL and OCR5CH */
#ifdef OCR5C
		   mbl::uint16ptr_t		  ocr_5_c   = &OCR5C;
	extern mbl::uint16ptr_t const ocr_5_c_c = &OCR5C;
#endif
#ifdef OCR5CL
		   mbl::uint8ptr_t		 ocr_5_c_l   = &OCR5CL;
	extern mbl::uint8ptr_t const ocr_5_c_l_c = &OCR5CL;
#endif
#ifdef OCR5CH
		   mbl::uint8ptr_t		 ocr_5_c_h   = &OCR5CH;
	extern mbl::uint8ptr_t const ocr_5_c_h_c = &OCR5CH;
#endif
	/* Reserved [0x12E..0x12F] */
#ifdef UCSR3A
		   mbl::uint8ptr_t		 ucsr_3_a   = &UCSR3A;
	extern mbl::uint8ptr_t const ucsr_3_a_c = &UCSR3A;
#endif
#ifdef UCSR3B
		   mbl::uint8ptr_t		 ucsr_3_b   = &UCSR3B;
	extern mbl::uint8ptr_t const ucsr_3_b_c = &UCSR3B;
#endif
#ifdef UCSR3C
		   mbl::uint8ptr_t		 ucsr_3_c   = &UCSR3C;
	extern mbl::uint8ptr_t const ucsr_3_c_c = &UCSR3C;
#endif   
	/* Reserved [0x133] */

	/* Combine UBRR3L and UBRR3H */
#ifdef UBRR3
		   mbl::uint16ptr_t		  ubrr_3   = &UBRR3;
	extern mbl::uint16ptr_t const ubrr_3_c = &UBRR3;
#endif
#ifdef UBRR3L
		   mbl::uint8ptr_t		 ubrr_3_l   = &UBRR3L;
	extern mbl::uint8ptr_t const ubrr_3_l_c = &UBRR3L;
#endif
#ifdef UBRR3H
		   mbl::uint8ptr_t		 ubrr_3_h   = &UBRR3H;
	extern mbl::uint8ptr_t const ubrr_3_h_c = &UBRR3H;
#endif
#ifdef UDR3
		   mbl::uint8ptr_t		 odr_3	 = &UDR3;
	extern mbl::uint8ptr_t const odr_3_c = &UDR3;
#endif 
}

#endif /*_AVRDEF_HPP*/