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
	mbl::uint8ptr_t const PinA = &PINA;
#endif
#ifdef DDRA
	mbl::uint8ptr_t const DdrA = &DDRA;
#endif
#ifdef PORTA
	mbl::uint8ptr_t const PortA = &PORTA;
#endif
#ifdef PINB
	mbl::uint8ptr_t const PinB = &PINB;
#endif
#ifdef DDRB
	mbl::uint8ptr_t const DdrB = &DDRB;
#endif
#ifdef PORTB
	mbl::uint8ptr_t const PortB = &PORTB;
#endif
#ifdef PINC
	mbl::uint8ptr_t const PinC = &PINC;
#endif
#ifdef DDRC
	mbl::uint8ptr_t const DdrC = &DDRC;
#endif
#ifdef PORTC
	mbl::uint8ptr_t const PortC = &PORTC;
#endif
#ifdef PIND
	mbl::uint8ptr_t const PinD = &PIND;
#endif
#ifdef DDRD
	mbl::uint8ptr_t const DdrD = &DDRD;
#endif
#ifdef PORTD
	mbl::uint8ptr_t const PortD = &PORTD;
#endif
#ifdef PINE
	mbl::uint8ptr_t const PinE = &PINE;
#endif
#ifdef DDRE
	mbl::uint8ptr_t const DdrE = &DDRE;
#endif
#ifdef PORTE
	mbl::uint8ptr_t const PortE = &PORTE;
#endif
#ifdef PINF
	mbl::uint8ptr_t const PinF = &PINF;
#endif
#ifdef DDRF
	mbl::uint8ptr_t const DdrF = &DDRF;
#endif
#ifdef PORTF
	mbl::uint8ptr_t const PortF = &PORTF;
#endif
#ifdef PING
	mbl::uint8ptr_t const PinG = &PING;
#endif
#ifdef DDRG
	mbl::uint8ptr_t const DdrG = &DDRG;
#endif
#ifdef PORTG
	mbl::uint8ptr_t const PortG = &PORTG;
#endif
#ifdef TIFR
	mbl::uint8ptr_t const Tifr = &TIFR;
#endif
#ifdef TIFR0
	mbl::uint8ptr_t const Tifr0 = &TIFR0;
#endif
#ifdef TIFR1
	mbl::uint8ptr_t const Tifr1 = &TIFR1;
#endif
#ifdef TIFR2
	mbl::uint8ptr_t const Tifr2 = &TIFR2;
#endif
#ifdef TIFR3
	mbl::uint8ptr_t const Tifr3 = &TIFR3;
#endif
#ifdef TIFR4
	mbl::uint8ptr_t const Tifr4 = &TIFR4;
#endif
#ifdef TIFR5
	mbl::uint8ptr_t const Tifr5 = &TIFR5;
#endif
#ifdef PCIFR
	mbl::uint8ptr_t const Pcifr = &PCIFR;
#endif
#ifdef EIFR
	mbl::uint8ptr_t const Eifr = &EIFR;
#endif
#ifdef EIMSK
	mbl::uint8ptr_t const Eimsk = &EIMSK;
#endif
#ifdef GPIOR0
	mbl::uint8ptr_t const Gpior0 = &GPIOR0;
#endif
#ifdef EECR
	mbl::uint8ptr_t const Eecr = &EECR;
#endif
#ifdef EEDR
	mbl::uint8ptr_t const Eedr = &EEDR;
#endif

	/* Combine EEARL and EEARH */
#ifdef EEAR
	mbl::uint16ptr_t const Eear = &EEAR;
#endif
#ifdef EEARL
	mbl::uint8ptr_t const EearL = &EEARL;
#endif
#ifdef EEARH
	mbl::uint8ptr_t const EearH = &EEARH;
#endif

	/* 6-char sequence denoting where to find the EEPROM registers in memory space.
	   Adresses denoted in hex syntax with uppercase letters. Used by the EEPROM
	   subroutines.
	   First two letters:  EECR address.
	   Second two letters: EEDR address.
	   Last two letters:   EEAR address.  */
#ifdef GTCCR
	mbl::uint8ptr_t const Gtccr = &GTCCR;
#endif
#ifdef TCCR0
	mbl::uint8ptr_t const Tccr0 = &TCCR0;
#endif
#ifdef TCCR0A
	mbl::uint8ptr_t const Tccr0A = &TCCR0A;
#endif
#ifdef TCCR0B
	mbl::uint8ptr_t const Tccr0B = &TCCR0B;
#endif
#ifdef TCNT0
	mbl::uint8ptr_t const Tcnt0 = &TCNT0;
#endif
#ifdef OCR0
	mbl::uint8ptr_t const Ocr0 = &OCR0;
#endif
#ifdef OCR0A
	mbl::uint8ptr_t const Ocr0A = &OCR0A;
#endif
#ifdef OCR0B
	mbl::uint8ptr_t const Ocr0B = &OCR0B;
#endif

	/* Reserved [0x29] */
#ifdef GPIOR1
	mbl::uint8ptr_t const Gpior1 = &GPIOR1;
#endif
#ifdef GPIOR2
	mbl::uint8ptr_t const Gpior2 = &GPIOR2;
#endif
#ifdef SPCR
	mbl::uint8ptr_t const Spcr = &SPCR;
#endif
#ifdef SPSR
	mbl::uint8ptr_t const Spsr = &SPSR;
#endif
#ifdef SPDR
	mbl::uint8ptr_t const Spdr = &SPDR;
#endif

	/* Reserved [0x2F] */
#ifdef ACSR
	mbl::uint8ptr_t const Acsr = &ACSR;
#endif
#ifdef MONDR
	mbl::uint8ptr_t const Mondr = &MONDR;
#endif
#ifdef OCDR
	mbl::uint8ptr_t const Ocdr = &OCDR;
#endif

	/* Reserved [0x32] */
#ifdef SMCR
	mbl::uint8ptr_t const Smcr = &SMCR;
#endif
#ifdef MCUSR
	mbl::uint8ptr_t const Mcusr = &MCUSR;
#endif
#ifdef MCUCR
	mbl::uint8ptr_t const Mcucr = &MCUCR;
#endif

	/* Reserved [0x36] */
#ifdef SPMCSR
	mbl::uint8ptr_t const Spmcsr = &SPMCSR;
#endif

	/* Reserved [0x38..0x3A] */
#ifdef RAMPZ
	mbl::uint8ptr_t const Rampz = &RAMPZ;
#endif
#ifdef EIND
	mbl::uint8ptr_t const Eind = &EIND;
#endif

	/* SP [0x3D..0x3E] */
	/* SREG [0x3F] */
#ifdef WDTCSR
	mbl::uint8ptr_t const Wdtcsr = &WDTCSR;
#endif
#ifdef CLKPR
	mbl::uint8ptr_t const Clkpr = &CLKPR;
#endif

	/* Reserved [0x62..0x63] */
#ifdef PRR0
	mbl::uint8ptr_t const Prr0 = &PRR0;
#endif
#ifdef PRR1
	mbl::uint8ptr_t const Prr1 = &PRR1;
#endif

#ifdef OSCCAL
	mbl::uint8ptr_t const Osccal = &OSCCAL;
#endif

	/* Reserved [0x67] */
#ifdef PCICR
	mbl::uint8ptr_t const Pcicr = &PCICR;
#endif
#ifdef EICRA
	mbl::uint8ptr_t const EicrA = &EICRA;
#endif
#ifdef EICRB
	mbl::uint8ptr_t const EicrB = &EICRB;
#endif
#ifdef PCMSK0
	mbl::uint8ptr_t const Pcmsk0 = &PCMSK0;
#endif
#ifdef PCMSK1
	mbl::uint8ptr_t const Pcmsk1 = &PCMSK1;
#endif
#ifdef PCMSK2
	mbl::uint8ptr_t const Pcmsk2 = &PCMSK2;
#endif
#ifdef TIMSK
	mbl::uint8ptr_t const Timsk = &TIMSK;
#endif
#ifdef TIMSK0
	mbl::uint8ptr_t const Timsk0 = &TIMSK0;
#endif
#ifdef TIMSK1
	mbl::uint8ptr_t const Timsk1 = &TIMSK1;
#endif
#ifdef TIMSK2
	mbl::uint8ptr_t const Timsk2 = &TIMSK2;
#endif
#ifdef TIMSK3
	mbl::uint8ptr_t const Timsk3 = &TIMSK3;
#endif
#ifdef TIMSK4
	mbl::uint8ptr_t const Timsk4 = &TIMSK4;
#endif
#ifdef TIMSK5
	mbl::uint8ptr_t const Timsk5 = &TIMSK5;
#endif
#ifdef XMCRA
	mbl::uint8ptr_t const XmcrA = &XMCRA;
#endif
#ifdef XMCRB
	mbl::uint8ptr_t const XmcrB = &XMCRB;
#endif

	/* Reserved [0x76..0x77] */

	/* Combine ADCL and ADCH */
#ifdef ADC
	mbl::uint16ptr_t const Adc = &ADC;
#endif
#ifdef ADCW
	mbl::uint16ptr_t const AdcW = &ADCW;
#endif
#ifdef ADCL
	mbl::uint8ptr_t const AdcL = &ADCL;
#endif
#ifdef ADCH
	mbl::uint8ptr_t const AdcH = &ADCH;
#endif
#ifdef ADCSRA
	mbl::uint8ptr_t const AdcsrA = &ADCSRA;
#endif
#ifdef ADCSRB
	mbl::uint8ptr_t const AdcsrB = &ADCSRB;
#endif
#ifdef ADMUX
	mbl::uint8ptr_t const Admux = &ADMUX;
#endif
#ifdef DIDR0
	mbl::uint8ptr_t const Didr0 = &DIDR0;
#endif
#ifdef DIDR1
	mbl::uint8ptr_t const Didr1 = &DIDR1;
#endif
#ifdef DIDR2
	mbl::uint8ptr_t const Didr2 = &DIDR2;
#endif
#ifdef TCCR1A
	mbl::uint8ptr_t const Tccr1A = &TCCR1A;
#endif
#ifdef TCCR1B
	mbl::uint8ptr_t const Tccr1B = &TCCR1B;
#endif
#ifdef TCCR1C
	mbl::uint8ptr_t const Tccr1C = &TCCR1C;
#endif

	/* Reserved [0x83] */

	/* Combine TCNT1L and TCNT1H */
#ifdef TCNT1
	mbl::uint16ptr_t const Tcnt1 = &TCNT1;
#endif
#ifdef TCNT1L
	mbl::uint8ptr_t const Tcnt1L = &TCNT1L;
#endif
#ifdef TCNT1H
	mbl::uint8ptr_t const Tcnt1H = &TCNT1H;
#endif

	/* Combine ICR1L and ICR1H */
#ifdef ICR1
	mbl::uint16ptr_t const Icr1 = &ICR1;
#endif
#ifdef ICR1L
	mbl::uint8ptr_t const Icr1L = &ICR1L;
#endif
#ifdef ICR1H
	mbl::uint8ptr_t const Icr1H = &ICR1H;
#endif

	/* Combine OCR1AL and OCR1AH */
#ifdef OCR1A
	mbl::uint16ptr_t const Ocr1A = &OCR1A;
#endif
#ifdef OCR1AL
	mbl::uint8ptr_t const Ocr1AL = &OCR1AL;
#endif
#ifdef OCR1AH
	mbl::uint8ptr_t const Ocr1AH = &OCR1AH;
#endif

	/* Combine OCR1BL and OCR1BH */
#ifdef OCR1B
	mbl::uint16ptr_t const Ocr1B = &OCR1B;
#endif
#ifdef OCR1BL
	mbl::uint8ptr_t const Ocr1BL = &OCR1BL;
#endif
#ifdef OCR1BH
	mbl::uint8ptr_t const Ocr1BH = &OCR1BH;
#endif

	/* Combine OCR1CL and OCR1CH */
#ifdef OCR1C
	mbl::uint16ptr_t const Ocr1C = &OCR1C;
#endif
#ifdef OCR1CL
	mbl::uint8ptr_t const Ocr1CL = &OCR1CL;
#endif
#ifdef OCR1CH
	mbl::uint8ptr_t const Ocr1CH = &OCR1CH;
#endif

	/* Reserved [0x8E..0x8F] */
#ifdef TCCR3A
	mbl::uint8ptr_t const Tccr3A = &TCCR3A;
#endif
#ifdef TCCR3B
	mbl::uint8ptr_t const Tccr3B = &TCCR3B;
#endif
#ifdef TCCR3C
	mbl::uint8ptr_t const Tccr3C = &TCCR3C;
#endif

	/* Reserved [0x93] */

	/* Combine TCNT3L and TCNT3H */
#ifdef TCNT3
	mbl::uint16ptr_t const Tcnt3 = &TCNT3;
#endif
#ifdef TCNT3L
	mbl::uint8ptr_t const Tcnt3L = &TCNT3L;
#endif
#ifdef TCNT3H
	mbl::uint8ptr_t const Tcnt3H = &TCNT3H;
#endif

	/* Combine ICR3L and ICR3H */
#ifdef ICR3
	mbl::uint16ptr_t const Icr3 = &ICR3;
#endif
#ifdef ICR3L
	mbl::uint8ptr_t const Icr3L = &ICR3L;
#endif
#ifdef ICR3H
	mbl::uint8ptr_t const Icr3H = &ICR3H;
#endif

	/* Combine OCR3AL and OCR3AH */
#ifdef OCR3A
	mbl::uint16ptr_t const Ocr3A = &OCR3A;
#endif
#ifdef OCR3AL
	mbl::uint8ptr_t const Ocr3AL = &OCR3AL;
#endif
#ifdef OCR3AH
	mbl::uint8ptr_t const Ocr3AH = &OCR3AH;
#endif

	/* Combine OCR3BL and OCR3BH */
#ifdef OCR3B
	mbl::uint16ptr_t const Ocr3B = &OCR3B;
#endif
#ifdef OCR3BL
	mbl::uint8ptr_t const Ocr3BL = &OCR3BL;
#endif
#ifdef OCR3BH
	mbl::uint8ptr_t const Ocr3BH = &OCR3BH;
#endif

	/* Combine OCR3CL and OCR3CH */
#ifdef OCR3C
	mbl::uint16ptr_t const Ocr3C = &OCR3C;
#endif
#ifdef OCR3CL
	mbl::uint8ptr_t const Ocr3CL = &OCR3CL;
#endif
#ifdef OCR3CH
	mbl::uint8ptr_t const Ocr3CH = &OCR3CH;
#endif

	/* Reserved [0x9E..0x9F] */
#ifdef TCCR4A
	mbl::uint8ptr_t const Tccr4A = &TCCR4A;
#endif
#ifdef TCCR4B
	mbl::uint8ptr_t const Tccr4B = &TCCR4B;
#endif
#ifdef TCCR4C
	mbl::uint8ptr_t const Tccr4C = &TCCR4C;
#endif

	/* Reserved [0xA3] */

	/* Combine TCNT4L and TCNT4H */
#ifdef TCNT4
	mbl::uint16ptr_t const Tcnt4 = &TCNT4;
#endif
#ifdef TCNT4L
	mbl::uint8ptr_t const Tcnt4L = &TCNT4L;
#endif
#ifdef TCNT4H
	mbl::uint8ptr_t const Tcnt4H = &TCNT4H;
#endif

	/* Combine ICR4L and ICR4H */
#ifdef ICR4
	mbl::uint16ptr_t const Icr4 = &ICR4;
#endif
#ifdef ICR4L
	mbl::uint8ptr_t const Icr4L = &ICR4L;
#endif
#ifdef ICR4H
	mbl::uint8ptr_t const Icr4H = &ICR4H;
#endif

	/* Combine OCR4AL and OCR4AH */
#ifdef OCR4A
	mbl::uint16ptr_t const Ocr4A = &OCR4A;
#endif
#ifdef OCR4AL
	mbl::uint8ptr_t const Ocr4AL = &OCR4AL;
#endif
#ifdef OCR4AH
	mbl::uint8ptr_t const Ocr4AH = &OCR4AH;
#endif

	/* Combine OCR4BL and OCR4BH */
#ifdef OCR4B
	mbl::uint16ptr_t const Ocr4B = &OCR4B;
#endif
#ifdef OCR4BL
	mbl::uint8ptr_t const Ocr4BL = &OCR4BL;
#endif
#ifdef OCR4BH
	mbl::uint8ptr_t const Ocr4BH = &OCR4BH;
#endif

	/* Combine OCR4CL and OCR4CH */
#ifdef OCR4C
	mbl::uint16ptr_t const Ocr4C = &OCR4C;
#endif
#ifdef OCR4CL
	mbl::uint8ptr_t const Ocr4CL = &OCR4CL;
#endif
#ifdef OCR4CH
	mbl::uint8ptr_t const Ocr4CH = &OCR4CH;
#endif

	/* Reserved [0xAE..0xAF] */
#ifdef TCCR2A
	mbl::uint8ptr_t const Tccr2A = &TCCR2A;
#endif
#ifdef TCNT2
	mbl::uint8ptr_t const Tcnt2 = &TCNT2;
#endif
#ifdef OCR2A
	mbl::uint8ptr_t const Ocr2A = &OCR2A;
#endif
#ifdef OCR2B
	mbl::uint8ptr_t const Ocr2B = &OCR2B;
#endif

	/* Reserved [0xB5] */
#ifdef ASSR
	mbl::uint8ptr_t const Assr = &ASSR;
#endif

	/* Reserved [0xB7] */
#ifdef TWBR
	mbl::uint8ptr_t const TwBr = &TWBR;
#endif
#ifdef TWSR
	mbl::uint8ptr_t const TwSr = &TWSR;
#endif
#ifdef TWAR
	mbl::uint8ptr_t const TwAr = &TWAR;
#endif
#ifdef TWDR
	mbl::uint8ptr_t const TwDr = &TWDR;
#endif
#ifdef TWCR
	mbl::uint8ptr_t const TwCr = &TWCR;
#endif
#ifdef TWAMR
	mbl::uint8ptr_t const TwaMr = &TWAMR;
#endif

	/* Reserved [0xBE..0xBF] */
#ifdef UCSR0A
	mbl::uint8ptr_t const Ucsr0A = &UCSR0A;
#endif
#ifdef UCSR0B
	mbl::uint8ptr_t const Ucsr0B = &UCSR0B;
#endif
#ifdef UCSR0C
	mbl::uint8ptr_t const Ucsr0C = &UCSR0C;
#endif

	/* Reserved [0xC3] */

	/* Combine UBRR0L and UBRR0H */
#ifdef UBRR0
	mbl::uint16ptr_t const Ubrr0 = &UBRR0;
#endif
#ifdef UBRR0L
	mbl::uint8ptr_t const Ubrr0L = &UBRR0L;
#endif
#ifdef UBRR0H
	mbl::uint8ptr_t const Ubrr0H = &UBRR0H;
#endif
#ifdef UDR0
	mbl::uint8ptr_t const Udr0 = &UDR0;
#endif

	/* Reserved [0xC7] */
#ifdef UCSR1A
	mbl::uint8ptr_t const Ucsr1A = &UCSR1A;
#endif
#ifdef UCSR1B
	mbl::uint8ptr_t const Ucsr1B = &UCSR1B;
#endif
#ifdef UCSR1C
	mbl::uint8ptr_t const Ucsr1C = &UCSR1C;
#endif

	/* Reserved [0xCB] */

	/* Combine UBRR1L and UBRR1H */
#ifdef UBRR1
	mbl::uint16ptr_t const Ubrr1 = &UBRR1;
#endif
#ifdef UBRR1L
	mbl::uint8ptr_t const Ubrr1L = &UBRR1L;
#endif
#ifdef UBRR1H
	mbl::uint8ptr_t const Ubrr1H = &UBRR1H;
#endif
#ifdef UDR1
	mbl::uint8ptr_t const Udr1 = &UDR1;
#endif

	/* Reserved [0xCF] */
#ifdef UCSR2A
	mbl::uint8ptr_t const Ucsr2A = &UCSR2A;
#endif
#ifdef UCSR2B
	mbl::uint8ptr_t const Ucsr2B = &UCSR2B;
#endif
#ifdef UCSR2C
	mbl::uint8ptr_t const Ucsr2C = &UCSR2C;
#endif


	/* Reserved [0xD3] */

	/* Combine UBRR2L and UBRR2H */
#ifdef UBRR2
	mbl::uint16ptr_t const Ubrr2 = &UBRR2;
#endif
#ifdef UBRR2L
	mbl::uint8ptr_t const Ubrr2L = &UBRR2L;
#endif
#ifdef UBRR2H
	mbl::uint8ptr_t const Ubrr2H = &UBRR2H;
#endif
#ifdef UDR2
	mbl::uint8ptr_t const Udr2 = &UDR2;
#endif

	/* Reserved [0xD7..0xFF] */
#ifdef PINH
	mbl::uint8ptr_t const PinH = &PINH;
#endif
#ifdef DDRH
	mbl::uint8ptr_t const DdrH = &DDRH;
#endif
#ifdef PORTH
	mbl::uint8ptr_t const PortH = &PORTH;
#endif
#ifdef PINJ
	mbl::uint8ptr_t const PinJ = &PINJ;
#endif
#ifdef DDRJ
	mbl::uint8ptr_t const DdrJ = &DDRJ;
#endif
#ifdef PORTJ
	mbl::uint8ptr_t const PortJ = &PORTJ;
#endif
#ifdef PINK
	mbl::uint8ptr_t const PinK = &PINK;
#endif
#ifdef DDRK
	mbl::uint8ptr_t const DdrK = &DDRK;
#endif
#ifdef PORTK
	mbl::uint8ptr_t const PortK = &PORTK;
#endif
#ifdef PINL
	mbl::uint8ptr_t const PinL = &PINL;
#endif
#ifdef DDRL
	mbl::uint8ptr_t const DdrL = &DDRL;
#endif
#ifdef PORTL
	mbl::uint8ptr_t const PortL = &PORTL;
#endif
	/* Reserved [0x10C..0x11F] */
#ifdef TCCR5A
	mbl::uint8ptr_t const Tccr5A = &TCCR5A;
#endif
#ifdef TCCR5B
	mbl::uint8ptr_t const Tccr5B = &TCCR5B;
#endif
#ifdef TCCR5C
	mbl::uint8ptr_t const Tccr5C = &TCCR5C;
#endif
	/* Reserved [0x123] */

	/* Combine TCNT5L and TCNT5H */
#ifdef TCNT5
	mbl::uint16ptr_t const Tcnt5 = &TCNT5;
#endif
#ifdef TCNT5L
	mbl::uint8ptr_t const Tcnt5L = &TCNT5L;
#endif
#ifdef TCNT5H
	mbl::uint8ptr_t const Tcnt5H = &TCNT5H;
#endif
	/* Combine ICR5L and ICR5H */
#ifdef ICR5
	mbl::uint16ptr_t const Icr5 = &ICR5;
#endif
#ifdef ICR5L
	mbl::uint8ptr_t const Icr5L = &ICR5L;
#endif
#ifdef ICR5H
	mbl::uint8ptr_t const Icr5H = &ICR5H;
#endif

	/* Combine OCR5AL and OCR5AH */
#ifdef OCR5A
	mbl::uint16ptr_t const Ocr5A = &OCR5A;
#endif
#ifdef OCR5AL
	mbl::uint8ptr_t const Ocr5AL = &OCR5AL;
#endif
#ifdef OCR5AH
	mbl::uint8ptr_t const Ocr5AH = &OCR5AH;
#endif

	/* Combine OCR5BL and OCR5BH */
#ifdef OCR5B
	mbl::uint16ptr_t const Ocr5B = &OCR5B;
#endif
#ifdef OCR5BL
	mbl::uint8ptr_t const Ocr5BL = &OCR5BL;
#endif
#ifdef OCR5BH
	mbl::uint8ptr_t const Ocr5BH = &OCR5BH;
#endif
	/* Combine OCR5CL and OCR5CH */
#ifdef OCR5C
	mbl::uint16ptr_t const Ocr5C = &OCR5C;
#endif
#ifdef OCR5CL
	mbl::uint8ptr_t const Ocr5CL = &OCR5CL;
#endif
#ifdef OCR5CH
	mbl::uint8ptr_t const Ocr5CH = &OCR5CH;
#endif
	/* Reserved [0x12E..0x12F] */
#ifdef UCSR3A
	mbl::uint8ptr_t const Ucsr3A = &UCSR3A;
#endif
#ifdef UCSR3B
	mbl::uint8ptr_t const Ucsr3B = &UCSR3B;
#endif
#ifdef UCSR3C
	mbl::uint8ptr_t const Ucsr3C = &UCSR3C;
#endif   
	/* Reserved [0x133] */

	/* Combine UBRR3L and UBRR3H */
#ifdef UBRR3
	mbl::uint16ptr_t const Ubrr3 = &UBRR3;
#endif
#ifdef UBRR3L
	mbl::uint8ptr_t const Ubrr3L = &UBRR3L;
#endif
#ifdef UBRR3H
	mbl::uint8ptr_t const Ubrr3H = &UBRR3H;
#endif
#ifdef UDR3
	mbl::uint8ptr_t const Odr3 = &UDR3;
#endif
} // end namespace microcontroller registers;

#endif /*_AVRDEF_HPP*/