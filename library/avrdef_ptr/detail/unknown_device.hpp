/* Определение указателей для микроконтроллеров AVR
 * Автор Reifat
 * GitHub Repository - https://github.com/Reifat
 * Последние изменения 04.05.2020.
*/
#ifndef ATMEGA_16_HPP
#define ATMEGA_16_HPP

#ifdef ATMEGA_16

#include <avr/io.h>

// include default definitions type
#include "metabit\definitions_type\definitions_type.hpp"

// definitions const pointer on register for AVR;
namespace mcreg // mcreg - namespace microcontroller registers;
{
	/* Registers and associated bit numbers */

#ifdef PINA
	extern mbl::uint8ptr_t const pin_a_c = &PINA;
#endif
#ifdef DDRA
	extern mbl::uint8ptr_t const ddr_a_c = &DDRA;
#endif
#ifdef PORTA
	extern mbl::uint8ptr_t const port_a_c = &PORTA;
#endif

#ifdef PINB
	extern mbl::uint8ptr_t const pin_b_c = &PINB;
#endif
#ifdef DDRB
	extern mbl::uint8ptr_t const ddr_b_c = &DDRB;
#endif
#ifdef PORTB
	extern mbl::uint8ptr_t const port_b_c = &PORTB;
#endif
#ifdef PINC
	extern mbl::uint8ptr_t const pin_c_c = &PINC;
#endif
#ifdef DDRC
	extern mbl::uint8ptr_t const ddr_c_c = &DDRC;
#endif
#ifdef PORTC
	extern mbl::uint8ptr_t const port_c_c = &PORTC;
#endif
#ifdef PIND
	extern mbl::uint8ptr_t const pin_d_c = &PIND;
#endif
#ifdef DDRD
	extern mbl::uint8ptr_t const ddr_d_c = &DDRD;
#endif
#ifdef PORTD
	extern mbl::uint8ptr_t const port_d_c = &PORTD;
#endif
#ifdef PINE
	extern mbl::uint8ptr_t const pin_e_c = &PINE;
#endif
#ifdef DDRE
	extern mbl::uint8ptr_t const ddr_e_c = &DDRE;
#endif
#ifdef PORTE
	extern mbl::uint8ptr_t const port_e_c = &PORTE;
#endif
#ifdef PINF
	extern mbl::uint8ptr_t const pin_f_c = &PINF;
#endif
#ifdef DDRF
	extern mbl::uint8ptr_t const ddr_f_c = &DDRF;
#endif
#ifdef PORTF
	extern mbl::uint8ptr_t const port_f_c = &PORTF;
#endif
#ifdef PING
	extern mbl::uint8ptr_t const pin_g_c = &PING;
#endif
#ifdef DDRG
	extern mbl::uint8ptr_t const ddr_g_c = &DDRG;
#endif
#ifdef PORTG
	extern mbl::uint8ptr_t const port_g_c = &PORTG;
#endif
#ifdef TIFR
	extern mbl::uint8ptr_t const tifr_c = &TIFR;
#endif
#ifdef TIFR0
	extern mbl::uint8ptr_t const tifr_0_c = &TIFR0;
#endif
#ifdef TIFR1
	extern mbl::uint8ptr_t const tifr_1_c = &TIFR1;
#endif
#ifdef TIFR2
	extern mbl::uint8ptr_t const tifr_2_c = &TIFR2;
#endif
#ifdef TIFR3
	extern mbl::uint8ptr_t const tifr_3_c = &TIFR3;
#endif
#ifdef TIFR4
	extern mbl::uint8ptr_t const tifr_4_c = &TIFR4;
#endif
#ifdef TIFR5
	extern mbl::uint8ptr_t const tifr_5_c = &TIFR5;
#endif
#ifdef PCIFR
	extern mbl::uint8ptr_t const pcifr_c = &PCIFR;
#endif
#ifdef EIFR
	extern mbl::uint8ptr_t const eifr_c = &EIFR;
#endif
#ifdef EIMSK
	extern mbl::uint8ptr_t const eimsk_c = &EIMSK;
#endif
#ifdef GPIOR0
	extern mbl::uint8ptr_t const gpior_0_c = &GPIOR0;
#endif
#ifdef EECR
	extern mbl::uint8ptr_t const eecr_c = &EECR;
#endif
#ifdef EEDR
	extern mbl::uint8ptr_t const eedr_c = &EEDR;
#endif

	/* Combine EEARL and EEARH */
#ifdef EEAR
		   extern mbl::uint16ptr_t const eear_c = &EEAR;
#endif
#ifdef EEARL
	extern mbl::uint8ptr_t const eear_l_c = &EEARL;
#endif
#ifdef EEARH
	extern mbl::uint8ptr_t const eear_h_c = &EEARH;
#endif

	/* 6-char sequence denoting where to find the EEPROM registers in memory space.
	   Adresses denoted in hex syntax with uppercase letters. Used by the EEPROM
	   subroutines.
	   First two letters:  EECR address.
	   Second two letters: EEDR address.
	   Last two letters:   EEAR address.  */
#ifdef GTCCR
	extern mbl::uint8ptr_t const gtccr_c = &GTCCR;
#endif
#ifdef TCCR0
	extern mbl::uint8ptr_t const tccr_0_c = &TCCR0;
#endif
#ifdef TCCR0A
	extern mbl::uint8ptr_t const tccr_0_a_c = &TCCR0A;
#endif
#ifdef TCCR0B
	extern mbl::uint8ptr_t const tccr_0_b_c = &TCCR0B;
#endif
#ifdef TCNT0
	extern mbl::uint8ptr_t const tcnt_0_c = &TCNT0;
#endif
#ifdef OCR0
	extern mbl::uint8ptr_t const ocr_0_c = &OCR0;
#endif
#ifdef OCR0A
	extern mbl::uint8ptr_t const ocr_0_a_c = &OCR0A;
#endif
#ifdef OCR0B
	extern mbl::uint8ptr_t const ocr_0_b_c = &OCR0B;
#endif

	/* Reserved [0x29] */
#ifdef GPIOR1
	extern mbl::uint8ptr_t const gpior_1_c = &GPIOR1;
#endif
#ifdef GPIOR2
	extern mbl::uint8ptr_t const gpior_2_c = &GPIOR2;
#endif
#ifdef SPCR
	extern mbl::uint8ptr_t const spcr_c = &SPCR;
#endif
#ifdef SPSR
	extern mbl::uint8ptr_t const spsr_c = &SPSR;
#endif
#ifdef SPDR
	extern mbl::uint8ptr_t const spdr_c = &SPDR;
#endif

	/* Reserved [0x2F] */
#ifdef ACSR
	extern mbl::uint8ptr_t const acsr_c = &ACSR;
#endif
#ifdef MONDR
	extern mbl::uint8ptr_t const mondr_c = &MONDR;
#endif
#ifdef OCDR
	extern mbl::uint8ptr_t const ocdr_c = &OCDR;
#endif

	/* Reserved [0x32] */
#ifdef SMCR
	extern mbl::uint8ptr_t const smcr_c = &SMCR;
#endif
#ifdef MCUSR
	extern mbl::uint8ptr_t const mcusr_c = &MCUSR;
#endif
#ifdef MCUCR
	extern mbl::uint8ptr_t const mcucr_c = &MCUCR;
#endif

	/* Reserved [0x36] */
#ifdef SPMCSR
	extern mbl::uint8ptr_t const spmcsr_c = &SPMCSR;
#endif

	/* Reserved [0x38..0x3A] */
#ifdef RAMPZ
	extern mbl::uint8ptr_t const rampz_c = &RAMPZ;
#endif
#ifdef EIND
	extern mbl::uint8ptr_t const eind_c = &EIND;
#endif

	/* SP [0x3D..0x3E] */
	/* SREG [0x3F] */
#ifdef WDTCSR
	extern mbl::uint8ptr_t const wdtcsr_c = &WDTCSR;
#endif
#ifdef CLKPR
	extern mbl::uint8ptr_t const clkpr_c = &CLKPR;
#endif

	/* Reserved [0x62..0x63] */
#ifdef PRR0
	extern mbl::uint8ptr_t const prr_0_c = &PRR0;
#endif
#ifdef PRR1
	extern mbl::uint8ptr_t const prr_1_c = &PRR1;
#endif

#ifdef OSCCAL
	extern mbl::uint8ptr_t const osccal_c = &OSCCAL;
#endif

	/* Reserved [0x67] */
#ifdef PCICR
	extern mbl::uint8ptr_t const pcicr_c = &PCICR;
#endif
#ifdef EICRA
	extern mbl::uint8ptr_t const eicr_a_c = &EICRA;
#endif
#ifdef EICRB
	extern mbl::uint8ptr_t const eicr_b_c = &EICRB;
#endif
#ifdef PCMSK0
	extern mbl::uint8ptr_t const pcmsk_0_c = &PCMSK0;
#endif
#ifdef PCMSK1
	extern mbl::uint8ptr_t const pcmsk_1_c = &PCMSK1;
#endif
#ifdef PCMSK2
	extern mbl::uint8ptr_t const pcmsk_2_c = &PCMSK2;
#endif
#ifdef TIMSK
	extern mbl::uint8ptr_t const timsk_c = &TIMSK;
#endif
#ifdef TIMSK0
	extern mbl::uint8ptr_t const timsk_0_c = &TIMSK0;
#endif
#ifdef TIMSK1
	extern mbl::uint8ptr_t const timsk_1_c = &TIMSK1;
#endif
#ifdef TIMSK2
	extern mbl::uint8ptr_t const timsk_2_c = &TIMSK2;
#endif
#ifdef TIMSK3
	extern mbl::uint8ptr_t const timsk_3_c = &TIMSK3;
#endif
#ifdef TIMSK4
	extern mbl::uint8ptr_t const timsk_4_c = &TIMSK4;
#endif
#ifdef TIMSK5
	extern mbl::uint8ptr_t const timsk_5_c = &TIMSK5;
#endif
#ifdef XMCRA
	extern mbl::uint8ptr_t const xmcr_a_c = &XMCRA;
#endif
#ifdef XMCRB
	extern mbl::uint8ptr_t const xmcr_b_c = &XMCRB;
#endif

	/* Reserved [0x76..0x77] */

	/* Combine ADCL and ADCH */
#ifdef ADC
	extern mbl::uint16ptr_t const adc_c = &ADC;
#endif
#ifdef ADCW
	extern mbl::uint16ptr_t const adc_w_c = &ADCW;
#endif
#ifdef ADCL
	extern mbl::uint8ptr_t const adc_l_c = &ADCL;
#endif
#ifdef ADCH
	extern mbl::uint8ptr_t const adc_h_c = &ADCH;
#endif
#ifdef ADCSRA
	extern mbl::uint8ptr_t const adcsr_a_c = &ADCSRA;
#endif
#ifdef ADCSRB
	extern mbl::uint8ptr_t const adcsr_b_c = &ADCSRB;
#endif
#ifdef ADMUX
	extern mbl::uint8ptr_t const admux_c = &ADMUX;
#endif
#ifdef DIDR0
	extern mbl::uint8ptr_t const didr_0_c = &DIDR0;
#endif
#ifdef DIDR1
	extern mbl::uint8ptr_t const didr_1_c = &DIDR1;
#endif
#ifdef DIDR2
	extern mbl::uint8ptr_t const didr_2_c = &DIDR2;
#endif
#ifdef TCCR1A
	extern mbl::uint8ptr_t const tccr_1_a_c = &TCCR1A;
#endif
#ifdef TCCR1B
	extern mbl::uint8ptr_t const tccr_1_b_c = &TCCR1B;
#endif
#ifdef TCCR1C
	extern mbl::uint8ptr_t const tccr_1_c_c = &TCCR1C;
#endif

	/* Reserved [0x83] */

	/* Combine TCNT1L and TCNT1H */
#ifdef TCNT1
	extern mbl::uint16ptr_t const tcnt_1_c = &TCNT1;
#endif
#ifdef TCNT1L
	extern mbl::uint8ptr_t const tcnt_1_l_c = &TCNT1L;
#endif
#ifdef TCNT1H
	extern mbl::uint8ptr_t const tcnt_1_h_c = &TCNT1H;
#endif

	/* Combine ICR1L and ICR1H */
#ifdef ICR1
	extern mbl::uint16ptr_t const icr_1_c = &ICR1;
#endif
#ifdef ICR1L
	extern mbl::uint8ptr_t const icr_1_l_c = &ICR1L;
#endif
#ifdef ICR1H
	extern mbl::uint8ptr_t const icr_1_h_c = &ICR1H;
#endif

	/* Combine OCR1AL and OCR1AH */
#ifdef OCR1A
	extern mbl::uint16ptr_t const ocr_1_a_c = &OCR1A;
#endif
#ifdef OCR1AL
	extern mbl::uint8ptr_t const ocr_1_a_l_c = &OCR1AL;
#endif
#ifdef OCR1AH
	extern mbl::uint8ptr_t const ocr_1_a_h_c = &OCR1AH;
#endif

	/* Combine OCR1BL and OCR1BH */
#ifdef OCR1B
	extern mbl::uint16ptr_t const ocr_1_b_c = &OCR1B;
#endif
#ifdef OCR1BL
	extern mbl::uint8ptr_t const ocr_1_b_l_c = &OCR1BL;
#endif
#ifdef OCR1BH
	extern mbl::uint8ptr_t const ocr_1_b_h_c = &OCR1BH;
#endif

	/* Combine OCR1CL and OCR1CH */
#ifdef OCR1C
	extern mbl::uint16ptr_t const ocr_1_c_c = &OCR1C;
#endif
#ifdef OCR1CL
	extern mbl::uint8ptr_t const ocr_1_c_l_c = &OCR1CL;
#endif
#ifdef OCR1CH
	extern mbl::uint8ptr_t const ocr_1_c_h_c = &OCR1CH;
#endif

	/* Reserved [0x8E..0x8F] */
#ifdef TCCR3A
	extern mbl::uint8ptr_t const tccr_3_a_c = &TCCR3A;
#endif
#ifdef TCCR3B
	extern mbl::uint8ptr_t const tccr_3_b_c = &TCCR3B;
#endif
#ifdef TCCR3C
	extern mbl::uint8ptr_t const tccr_3_c_c = &TCCR3C;
#endif

	/* Reserved [0x93] */

	/* Combine TCNT3L and TCNT3H */
#ifdef TCNT3
	extern mbl::uint16ptr_t const tcnt_3_c = &TCNT3;
#endif
#ifdef TCNT3L
	extern mbl::uint8ptr_t const tcnt_3_l_c = &TCNT3L;
#endif
#ifdef TCNT3H
	extern mbl::uint8ptr_t const tcnt_3_h_c = &TCNT3H;
#endif

	/* Combine ICR3L and ICR3H */
#ifdef ICR3
	extern mbl::uint16ptr_t const icr_3_c = &ICR3;
#endif
#ifdef ICR3L
	extern mbl::uint8ptr_t const icr_3_l_c = &ICR3L;
#endif
#ifdef ICR3H
	extern mbl::uint8ptr_t const icr_3_h_c = &ICR3H;
#endif

	/* Combine OCR3AL and OCR3AH */
#ifdef OCR3A
	extern mbl::uint16ptr_t const ocr_3_a_c = &OCR3A;
#endif
#ifdef OCR3AL
	extern mbl::uint8ptr_t const ocr_3_a_l_c = &OCR3AL;
#endif
#ifdef OCR3AH
	extern mbl::uint8ptr_t const ocr_3_a_h_c = &OCR3AH;
#endif

	/* Combine OCR3BL and OCR3BH */
#ifdef OCR3B
	extern mbl::uint16ptr_t const ocr_3_b_c = &OCR3B;
#endif
#ifdef OCR3BL
	extern mbl::uint8ptr_t const ocr_3_b_l_c = &OCR3BL;
#endif
#ifdef OCR3BH
	extern mbl::uint8ptr_t const ocr_3_b_h_c = &OCR3BH;
#endif

	/* Combine OCR3CL and OCR3CH */
#ifdef OCR3C
	extern mbl::uint16ptr_t const ocr_3_c_c = &OCR3C;
#endif
#ifdef OCR3CL
	extern mbl::uint8ptr_t const ocr_3_c_l_c = &OCR3CL;
#endif
#ifdef OCR3CH
	extern mbl::uint8ptr_t const ocr_3_c_h_c = &OCR3CH;
#endif

	/* Reserved [0x9E..0x9F] */
#ifdef TCCR4A
	extern mbl::uint8ptr_t const tccr_4_a_c = &TCCR4A;
#endif
#ifdef TCCR4B
	extern mbl::uint8ptr_t const tccr4_b_c = &TCCR4B;
#endif
#ifdef TCCR4C
	extern mbl::uint8ptr_t const tccr_4_c_c = &TCCR4C;
#endif

	/* Reserved [0xA3] */

	/* Combine TCNT4L and TCNT4H */
#ifdef TCNT4
	extern mbl::uint16ptr_t const tcnt_4_c = &TCNT4;
#endif
#ifdef TCNT4L
	extern mbl::uint8ptr_t const tcnt_4_l_c = &TCNT4L;
#endif
#ifdef TCNT4H
	extern mbl::uint8ptr_t const tcnt_4_h_c = &TCNT4H;
#endif

	/* Combine ICR4L and ICR4H */
#ifdef ICR4
	extern mbl::uint16ptr_t const icr_4_c = &ICR4;
#endif
#ifdef ICR4L
	extern mbl::uint8ptr_t const icr_4_l_c = &ICR4L;
#endif
#ifdef ICR4H
	extern mbl::uint8ptr_t const icr_4_h_c = &ICR4H;
#endif

	/* Combine OCR4AL and OCR4AH */
#ifdef OCR4A
	extern mbl::uint16ptr_t const ocr_4_a_c = &OCR4A;
#endif
#ifdef OCR4AL
	extern mbl::uint8ptr_t const ocr_4_a_l_c = &OCR4AL;
#endif
#ifdef OCR4AH
	extern mbl::uint8ptr_t const ocr_4_a_h_c = &OCR4AH;
#endif

	/* Combine OCR4BL and OCR4BH */
#ifdef OCR4B
	extern mbl::uint16ptr_t const ocr_4_b_c = &OCR4B;
#endif
#ifdef OCR4BL
	extern mbl::uint8ptr_t const ocr_4_b_l_c = &OCR4BL;
#endif
#ifdef OCR4BH
	extern mbl::uint8ptr_t const ocr_4_b_h_c = &OCR4BH;
#endif

	/* Combine OCR4CL and OCR4CH */
#ifdef OCR4C
	extern mbl::uint16ptr_t const ocr_4_c_c = &OCR4C;
#endif
#ifdef OCR4CL
	extern mbl::uint8ptr_t const ocr_4_c_l_c = &OCR4CL;
#endif
#ifdef OCR4CH
	extern mbl::uint8ptr_t const ocr_4_c_h_c = &OCR4CH;
#endif

	/* Reserved [0xAE..0xAF] */
#ifdef TCCR2A
	extern mbl::uint8ptr_t const tccr_2_a_c = &TCCR2A;
#endif
#ifdef TCNT2
	extern mbl::uint8ptr_t const tcnt_2_c = &TCNT2;
#endif
#ifdef OCR2A
	extern mbl::uint8ptr_t const ocr_2_a_c = &OCR2A;
#endif
#ifdef OCR2B
	extern mbl::uint8ptr_t const ocr_2_b_c = &OCR2B;
#endif

	/* Reserved [0xB5] */
#ifdef ASSR
	extern mbl::uint8ptr_t const assr_c = &ASSR;
#endif

	/* Reserved [0xB7] */
#ifdef TWBR
	extern mbl::uint8ptr_t const tw_br_c = &TWBR;
#endif
#ifdef TWSR
	extern mbl::uint8ptr_t const tw_sr_c = &TWSR;
#endif
#ifdef TWAR
	extern mbl::uint8ptr_t const tw_ar_c = &TWAR;
#endif
#ifdef TWDR
	extern mbl::uint8ptr_t const tw_dr_c = &TWDR;
#endif
#ifdef TWCR
	extern mbl::uint8ptr_t const tw_cr_c = &TWCR;
#endif
#ifdef TWAMR
	extern mbl::uint8ptr_t const twa_mr_c = &TWAMR;
#endif

	/* Reserved [0xBE..0xBF] */
#ifdef UCSR0A
	extern mbl::uint8ptr_t const ucsr_0_a_c = &UCSR0A;
#endif
#ifdef UCSR0B 
	extern mbl::uint8ptr_t const ucsr_0_b_c = &UCSR0B;
#endif
#ifdef UCSR0C
	extern mbl::uint8ptr_t const ucsr_0_c_c = &UCSR0C;
#endif

	/* Reserved [0xC3] */

	/* Combine UBRR0L and UBRR0H */
#ifdef UBRR0
	extern mbl::uint16ptr_t const ubrr_0_c = &UBRR0;
#endif
#ifdef UBRR0L
	extern mbl::uint8ptr_t const ubrr_0_l_c = &UBRR0L;
#endif
#ifdef UBRR0H
	extern mbl::uint8ptr_t const ubrr_0_h_c = &UBRR0H;
#endif
#ifdef UDR0
	extern mbl::uint8ptr_t const udr_0_c = &UDR0;
#endif

	/* Reserved [0xC7] */
#ifdef UCSR1A
	extern mbl::uint8ptr_t const ucsr_1_a_c = &UCSR1A;
#endif
#ifdef UCSR1B
	extern mbl::uint8ptr_t const ucsr_1_b_c = &UCSR1B;
#endif
#ifdef UCSR1C
	extern mbl::uint8ptr_t const ucsr_1_c_c = &UCSR1C;
#endif

	/* Reserved [0xCB] */

	/* Combine UBRR1L and UBRR1H */
#ifdef UBRR1
	extern mbl::uint16ptr_t const ubrr_1_c = &UBRR1;
#endif
#ifdef UBRR1L
	extern mbl::uint8ptr_t const ubrr_1_l_c = &UBRR1L;
#endif
#ifdef UBRR1H
	extern mbl::uint8ptr_t const ubrr_1_h_c = &UBRR1H;
#endif
#ifdef UDR1
	extern mbl::uint8ptr_t const udr_1_c = &UDR1;
#endif

	/* Reserved [0xCF] */
#ifdef UCSR2A
	extern mbl::uint8ptr_t const ucsr_2_a_c = &UCSR2A;
#endif
#ifdef UCSR2B
	extern mbl::uint8ptr_t const ucsr_2_b_c = &UCSR2B;
#endif
#ifdef UCSR2C
	extern mbl::uint8ptr_t const ucsr_2_c_c = &UCSR2C;
#endif

	/* Reserved [0xD3] */

	/* Combine UBRR2L and UBRR2H */
#ifdef UBRR2
	extern mbl::uint16ptr_t const ubrr_2_c = &UBRR2;
#endif
#ifdef UBRR2L
	extern mbl::uint8ptr_t const ubrr_2_l_c = &UBRR2L;
#endif
#ifdef UBRR2H
	extern mbl::uint8ptr_t const ubrr_2_h_c = &UBRR2H;
#endif
#ifdef UDR2
	extern mbl::uint8ptr_t const udr_2_c = &UDR2;
#endif

	/* Reserved [0xD7..0xFF] */
#ifdef PINH
	extern mbl::uint8ptr_t const pin_h_c = &PINH;
#endif
#ifdef DDRH
	extern mbl::uint8ptr_t const ddr_h_c = &DDRH;
#endif
#ifdef PORTH
	extern mbl::uint8ptr_t const port_h_c = &PORTH;
#endif
#ifdef PINJ
	extern mbl::uint8ptr_t const pin_j_c = &PINJ;
#endif
#ifdef DDRJ
	extern mbl::uint8ptr_t const ddr_j_c = &DDRJ;
#endif
#ifdef PORTJ
	extern mbl::uint8ptr_t const port_j_c = &PORTJ;
#endif
#ifdef PINK
	extern mbl::uint8ptr_t const pin_k_c = &PINK;
#endif
#ifdef DDRK
	extern mbl::uint8ptr_t const ddr_k_c = &DDRK;
#endif
#ifdef PORTK
	extern mbl::uint8ptr_t const port_k_c = &PORTK;
#endif
#ifdef PINL
	extern mbl::uint8ptr_t const pin_l_c = &PINL;
#endif
#ifdef DDRL
	extern mbl::uint8ptr_t const ddr_l_c = &DDRL;
#endif
#ifdef PORTL
	extern mbl::uint8ptr_t const port_l_c = &PORTL;
#endif
	/* Reserved [0x10C..0x11F] */
#ifdef TCCR5A
	extern mbl::uint8ptr_t const tccr_5_a_c = &TCCR5A;
#endif
#ifdef TCCR5B
	extern mbl::uint8ptr_t const tccr_5_b_c = &TCCR5B;
#endif
#ifdef TCCR5C
	extern mbl::uint8ptr_t const tccr_5_c_c = &TCCR5C;
#endif
	/* Reserved [0x123] */

	/* Combine TCNT5L and TCNT5H */
#ifdef TCNT5
	extern mbl::uint16ptr_t const tcnt_5_c = &TCNT5;
#endif
#ifdef TCNT5L
	extern mbl::uint8ptr_t const tcnt_5_l_c = &TCNT5L;
#endif
#ifdef TCNT5H
	extern mbl::uint8ptr_t const tcnt_5_h_c = &TCNT5H;
#endif
	/* Combine ICR5L and ICR5H */
#ifdef ICR5
	extern mbl::uint16ptr_t const icr_5_c = &ICR5;
#endif
#ifdef ICR5L
	extern mbl::uint8ptr_t const icr_5_l_c = &ICR5L;
#endif
#ifdef ICR5H
	extern mbl::uint8ptr_t const icr_5_h_c = &ICR5H;
#endif

	/* Combine OCR5AL and OCR5AH */
#ifdef OCR5A
	extern mbl::uint16ptr_t const ocr_5_a_c = &OCR5A;
#endif
#ifdef OCR5AL
	extern mbl::uint8ptr_t const ocr_5_a_l_c = &OCR5AL;
#endif
#ifdef OCR5AH
	extern mbl::uint8ptr_t const ocr_5_a_h_c = &OCR5AH;
#endif

	/* Combine OCR5BL and OCR5BH */
#ifdef OCR5B
	extern mbl::uint16ptr_t const ocr_5_b_c = &OCR5B;
#endif
#ifdef OCR5BL
	extern mbl::uint8ptr_t const ocr_5_b_l_c = &OCR5BL;
#endif
#ifdef OCR5BH
	extern mbl::uint8ptr_t const ocr_5_b_h_c = &OCR5BH;
#endif
	/* Combine OCR5CL and OCR5CH */
#ifdef OCR5C
	extern mbl::uint16ptr_t const ocr_5_c_c = &OCR5C;
#endif
#ifdef OCR5CL
	extern mbl::uint8ptr_t const ocr_5_c_l_c = &OCR5CL;
#endif
#ifdef OCR5CH
	extern mbl::uint8ptr_t const ocr_5_c_h_c = &OCR5CH;
#endif
	/* Reserved [0x12E..0x12F] */
#ifdef UCSR3A
	extern mbl::uint8ptr_t const ucsr_3_a_c = &UCSR3A;
#endif
#ifdef UCSR3B
	extern mbl::uint8ptr_t const ucsr_3_b_c = &UCSR3B;
#endif
#ifdef UCSR3C
	extern mbl::uint8ptr_t const ucsr_3_c_c = &UCSR3C;
#endif   
	/* Reserved [0x133] */

	/* Combine UBRR3L and UBRR3H */
#ifdef UBRR3
	extern mbl::uint16ptr_t const ubrr_3_c = &UBRR3;
#endif
#ifdef UBRR3L
	extern mbl::uint8ptr_t const ubrr_3_l_c = &UBRR3L;
#endif
#ifdef UBRR3H
	extern mbl::uint8ptr_t const ubrr_3_h_c = &UBRR3H;
#endif
#ifdef UDR3
	extern mbl::uint8ptr_t const odr_3_c = &UDR3;
#endif 
} // end namespace mcreg

#endif // end if define ATMEGA_16
#endif // end if define ATMEGA_16_HPP