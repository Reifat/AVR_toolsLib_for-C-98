#include <avr/io.h>

#ifndef AVRPTRDEF_H
#define AVRPTRDEF_H

typedef volatile unsigned char* uint8ptr_t;
typedef volatile unsigned char  reg8_t;
typedef volatile unsigned int*  uint16ptr_t;
typedef volatile unsigned int   reg16_t;

namespace ptrdef
{
	/* Registers and associated bit numbers */
#ifdef PINA
	uint8ptr_t const pPINA = &PINA;
#endif
#ifdef DDRA
	uint8ptr_t const pDDRA = &DDRA;
#endif
#ifdef PORTA
	uint8ptr_t const pPORTA = &PORTA;
#endif
#ifdef PINB
	uint8ptr_t const pPINB = &PINB;
#endif
#ifdef DDRB
	uint8ptr_t const pDDRB = &DDRB;
#endif
#ifdef PORTB
	uint8ptr_t const pPORTB = &PORTB;
#endif
#ifdef PINC
	uint8ptr_t const pPINC = &PINC;
#endif
#ifdef DDRC
	uint8ptr_t const pDDRC = &DDRC;
#endif
#ifdef PORTC
	uint8ptr_t const pPORTC = &PORTC;
#endif
#ifdef PIND
	uint8ptr_t const pPIND = &PIND;
#endif
#ifdef DDRD
	uint8ptr_t const pDDRD = &DDRD;
#endif
#ifdef PORTD
	uint8ptr_t const pPORTD = &PORTD;
#endif
#ifdef PINE
	uint8ptr_t const pPINE = &PINE;
#endif
#ifdef DDRE
	uint8ptr_t const pDDRE = &DDRE;
#endif
#ifdef PORTE
	uint8ptr_t const pPORTE = &PORTE;
#endif
#ifdef PINF
	uint8ptr_t const pPINF = &PINF;
#endif
#ifdef DDRF
	uint8ptr_t const pDDRF = &DDRF;
#endif
#ifdef PORTF
	uint8ptr_t const pPORTF = &PORTF;
#endif
#ifdef PING
	uint8ptr_t const pPING = &PING;
#endif
#ifdef DDRG
	uint8ptr_t const pDDRG = &DDRG;
#endif
#ifdef PORTG
	uint8ptr_t const pPORTG = &PORTG;
#endif
#ifdef TIFR0
	uint8ptr_t const pTIFR0 = &TIFR0;
#endif
#ifdef TIFR1
	uint8ptr_t const pTIFR1 = &TIFR1;
#endif
#ifdef TIFR2
	uint8ptr_t const pTIFR2 = &TIFR2;
#endif
#ifdef TIFR3
	uint8ptr_t const pTIFR3 = &TIFR3;
#endif
#ifdef TIFR4
	uint8ptr_t const pTIFR4 = &TIFR4;
#endif
#ifdef TIFR5
	uint8ptr_t const pTIFR5 = &TIFR5;
#endif
#ifdef PCIFR
	uint8ptr_t const pPCIFR = &PCIFR;
#endif
#ifdef EIFR
	uint8ptr_t const pEIFR = &EIFR;
#endif
#ifdef EIMSK
	uint8ptr_t const pEIMSK = &EIMSK;
#endif
#ifdef GPIOR0
	uint8ptr_t const pGPIOR0 = &GPIOR0;
#endif
#ifdef EECR
	uint8ptr_t const pEECR = &EECR;
#endif
#ifdef EEDR
	uint8ptr_t const pEEDR = &EEDR;
#endif

	/* Combine EEARL and EEARH */
#ifdef EEAR
	uint16ptr_t const pEEAR = &EEAR;
#endif
#ifdef EEARL
	uint8ptr_t const pEEARL = &EEARL;
#endif
#ifdef EEARH
	uint8ptr_t const pEEARH = &EEARH;
#endif

	/* 6-char sequence denoting where to find the EEPROM registers in memory space.
	   Adresses denoted in hex syntax with uppercase letters. Used by the EEPROM
	   subroutines.
	   First two letters:  EECR address.
	   Second two letters: EEDR address.
	   Last two letters:   EEAR address.  */
#ifdef GTCCR
	uint8ptr_t const pGTCCR = &GTCCR;
#endif
#ifdef TCCR0A
	uint8ptr_t const pTCCR0A = &TCCR0A;
#endif
#ifdef TCCR0B
	uint8ptr_t const pTCCR0B = &TCCR0B;
#endif
#ifdef TCNT0
	uint8ptr_t const pTCNT0 = &TCNT0;
#endif
#ifdef OCR0A
	uint8ptr_t const pOCR0A = &OCR0A;
#endif
#ifdef OCR0B
	uint8ptr_t const pOCR0B = &OCR0B;
#endif

	/* Reserved [0x29] */
#ifdef GPIOR1
	uint8ptr_t const pGPIOR1 = &GPIOR1;
#endif
#ifdef GPIOR2
	uint8ptr_t const pGPIOR2 = &GPIOR2;
#endif
#ifdef SPCR
	uint8ptr_t const pSPCR = &SPCR;
#endif
#ifdef SPSR
	uint8ptr_t const pSPSR = &SPSR;
#endif
#ifdef SPDR
	uint8ptr_t const pSPDR = &SPDR;
#endif

	/* Reserved [0x2F] */
#ifdef ACSR
	uint8ptr_t const pACSR = &ACSR;
#endif
#ifdef MONDR
	uint8ptr_t const pMONDR = &MONDR;
#endif
#ifdef OCDR
	uint8ptr_t const pOCDR = &OCDR;
#endif

	/* Reserved [0x32] */
#ifdef SMCR
	uint8ptr_t const pSMCR = &SMCR;
#endif
#ifdef MCUSR
	uint8ptr_t const pMCUSR = &MCUSR;
#endif
#ifdef MCUCR
	uint8ptr_t const pMCUCR = &MCUCR;
#endif

	/* Reserved [0x36] */
#ifdef SPMCSR
	uint8ptr_t const pSPMCSR = &SPMCSR;
#endif

	/* Reserved [0x38..0x3A] */
#ifdef RAMPZ
	uint8ptr_t const pRAMPZ = &RAMPZ;
#endif
#ifdef EIND
	uint8ptr_t const pEIND = &EIND;
#endif

	/* SP [0x3D..0x3E] */
	/* SREG [0x3F] */
#ifdef WDTCSR
	uint8ptr_t const pWDTCSR = &WDTCSR;
#endif
#ifdef CLKPR
	uint8ptr_t const pCLKPR = &CLKPR;
#endif

	/* Reserved [0x62..0x63] */
#ifdef PRR0
	uint8ptr_t const pPRR0 = &PRR0;
#endif
#ifdef PRR1
	uint8ptr_t const pPRR1 = &PRR1;
#endif

#ifdef OSCCAL
	uint8ptr_t const pOSCCAL = &OSCCAL;
#endif

	/* Reserved [0x67] */
#ifdef PCICR
	uint8ptr_t const pPCICR = &PCICR;
#endif
#ifdef EICRA
	uint8ptr_t const pEICRA = &EICRA;
#endif
#ifdef EICRB
	uint8ptr_t const pEICRB = &EICRB;
#endif
#ifdef PCMSK0
	uint8ptr_t const pPCMSK0 = &PCMSK0;
#endif
#ifdef PCMSK1
	uint8ptr_t const pPCMSK1 = &PCMSK1;
#endif
#ifdef PCMSK2
	uint8ptr_t const pPCMSK2 = &PCMSK2;
#endif
#ifdef TIMSK0
	uint8ptr_t const pTIMSK0 = &TIMSK0;
#endif
#ifdef TIMSK1
	uint8ptr_t const pTIMSK1 = &TIMSK1;
#endif
#ifdef TIMSK2
	uint8ptr_t const pTIMSK2 = &TIMSK2;
#endif
#ifdef TIMSK3
	uint8ptr_t const pTIMSK3 = &TIMSK3;
#endif
#ifdef TIMSK4
	uint8ptr_t const pTIMSK4 = &TIMSK4;
#endif
#ifdef TIMSK5
	uint8ptr_t const pTIMSK5 = &TIMSK5;
#endif
#ifdef XMCRA
	uint8ptr_t const pXMCRA = &XMCRA;
#endif
#ifdef XMCRB
	uint8ptr_t const pXMCRB = &XMCRB;
#endif

	/* Reserved [0x76..0x77] */

	/* Combine ADCL and ADCH */
#ifdef ADC
	uint16ptr_t const pADC = &ADC;
#endif
#ifdef ADCW
	uint16ptr_t const pADCW = &ADCW;
#endif
#ifdef ADCL
	uint8ptr_t const pADCL = &ADCL;
#endif
#ifdef ADCH
	uint8ptr_t const pADCH = &ADCH;
#endif
#ifdef ADCSRA
	uint8ptr_t const pADCSRA = &ADCSRA;
#endif
#ifdef ADCSRB
	uint8ptr_t const pADCSRB = &ADCSRB;
#endif
#ifdef ADMUX
	uint8ptr_t const pADMUX = &ADMUX;
#endif
#ifdef DIDR2
	uint8ptr_t const pDIDR2 = &DIDR2;
#endif
#ifdef DIDR0
	uint8ptr_t const pDIDR0 = &DIDR0;
#endif
#ifdef DIDR1
	uint8ptr_t const pDIDR1 = &DIDR1;
#endif
#ifdef TCCR1A
	uint8ptr_t const pTCCR1A = &TCCR1A;
#endif
#ifdef TCCR1B
	uint8ptr_t const pTCCR1B = &TCCR1B;
#endif
#ifdef TCCR1C
	uint8ptr_t const pTCCR1C = &TCCR1C;
#endif

	/* Reserved [0x83] */

	/* Combine TCNT1L and TCNT1H */
#ifdef TCNT1
	uint16ptr_t const pTCNT1 = &TCNT1;
#endif
#ifdef TCNT1L
	uint8ptr_t const pTCNT1L = &TCNT1L;
#endif
#ifdef TCNT1H
	uint8ptr_t const pTCNT1H = &TCNT1H;
#endif

	/* Combine ICR1L and ICR1H */
#ifdef ICR1
	uint16ptr_t const pICR1 = &ICR1;
#endif
#ifdef ICR1L
	uint8ptr_t const pICR1L = &ICR1L;
#endif
#ifdef ICR1H
	uint8ptr_t const pICR1H = &ICR1H;
#endif

	/* Combine OCR1AL and OCR1AH */
#ifdef OCR1A
	uint16ptr_t const pOCR1A = &OCR1A;
#endif
#ifdef OCR1AL
	uint8ptr_t const pOCR1AL = &OCR1AL;
#endif
#ifdef OCR1AH
	uint8ptr_t const pOCR1AH = &OCR1AH;
#endif

	/* Combine OCR1BL and OCR1BH */
#ifdef OCR1B
	uint16ptr_t const pOCR1B = &OCR1B;
#endif
#ifdef OCR1BL
	uint8ptr_t const pOCR1BL = &OCR1BL;
#endif
#ifdef OCR1BH
	uint8ptr_t const pOCR1BH = &OCR1BH;
#endif

	/* Combine OCR1CL and OCR1CH */
#ifdef OCR1C
	uint16ptr_t const pOCR1C = &OCR1C;
#endif
#ifdef OCR1CL
	uint8ptr_t const pOCR1CL = &OCR1CL;
#endif
#ifdef OCR1CH
	uint8ptr_t const pOCR1CH = &OCR1CH;
#endif

	/* Reserved [0x8E..0x8F] */
#ifdef TCCR3A
	uint8ptr_t const pTCCR3A = &TCCR3A;
#endif
#ifdef TCCR3B
	uint8ptr_t const pTCCR3B = &TCCR3B;
#endif
#ifdef TCCR3C
	uint8ptr_t const pTCCR3C = &TCCR3C;
#endif

	/* Reserved [0x93] */

	/* Combine TCNT3L and TCNT3H */
#ifdef TCNT3
	uint16ptr_t const pTCNT3 = &TCNT3;
#endif
#ifdef TCNT3L
	uint8ptr_t const pTCNT3L = &TCNT3L;
#endif
#ifdef TCNT3H
	uint8ptr_t const pTCNT3H = &TCNT3H;
#endif

	/* Combine ICR3L and ICR3H */
#ifdef ICR3
	uint16ptr_t const pICR3 = &ICR3;
#endif
#ifdef ICR3L
	uint8ptr_t const pICR3L = &ICR3L;
#endif
#ifdef ICR3H
	uint8ptr_t const pICR3H = &ICR3H;
#endif

	/* Combine OCR3AL and OCR3AH */
#ifdef OCR3A
	uint16ptr_t const pOCR3A = &OCR3A;
#endif
#ifdef OCR3AL
	uint8ptr_t const pOCR3AL = &OCR3AL;
#endif
#ifdef OCR3AH
	uint8ptr_t const pOCR3AH = &OCR3AH;
#endif

	/* Combine OCR3BL and OCR3BH */
#ifdef OCR3B
	uint16ptr_t const pOCR3B = &OCR3B;
#endif
#ifdef OCR3BL
	uint8ptr_t const pOCR3BL = &OCR3BL;
#endif
#ifdef OCR3BH
	uint8ptr_t const pOCR3BH = &OCR3BH;
#endif

	/* Combine OCR3CL and OCR3CH */
#ifdef OCR3C
	uint16ptr_t const pOCR3C = &OCR3C;
#endif
#ifdef OCR3CL
	uint8ptr_t const pOCR3CL = &OCR3CL;
#endif
#ifdef OCR3CH
	uint8ptr_t const pOCR3CH = &OCR3CH;
#endif

	/* Reserved [0x9E..0x9F] */
#ifdef TCCR4A
	uint8ptr_t const pTCCR4A = &TCCR4A;
#endif
#ifdef TCCR4B
	uint8ptr_t const pTCCR4B = &TCCR4B;
#endif
#ifdef TCCR4C
	uint8ptr_t const pTCCR4C = &TCCR4C;
#endif

	/* Reserved [0xA3] */

	/* Combine TCNT4L and TCNT4H */
#ifdef TCNT4
	uint16ptr_t const pTCNT4 = &TCNT4;
#endif
#ifdef TCNT4L
	uint8ptr_t const pTCNT4L = &TCNT4L;
#endif
#ifdef TCNT4H
	uint8ptr_t const pTCNT4H = &TCNT4H;
#endif

	/* Combine ICR4L and ICR4H */
#ifdef ICR4
	uint16ptr_t const pICR4 = &ICR4;
#endif
#ifdef ICR4L
	uint8ptr_t const pICR4L = &ICR4L;
#endif
#ifdef ICR4H
	uint8ptr_t const pICR4H = &ICR4H;
#endif

	/* Combine OCR4AL and OCR4AH */
#ifdef OCR4A
	uint16ptr_t const pOCR4A = &OCR4A;
#endif
#ifdef OCR4AL
	uint8ptr_t const pOCR4AL = &OCR4AL;
#endif
#ifdef OCR4AH
	uint8ptr_t const pOCR4AH = &OCR4AH;
#endif

	/* Combine OCR4BL and OCR4BH */
#ifdef OCR4B
	uint16ptr_t const pOCR4B = &OCR4B;
#endif
#ifdef OCR4BL
	uint8ptr_t const pOCR4BL = &OCR4BL;
#endif
#ifdef OCR4BH
	uint8ptr_t const pOCR4BH = &OCR4BH;
#endif

	/* Combine OCR4CL and OCR4CH */
#ifdef OCR4C
	uint16ptr_t const pOCR4C = &OCR4C;
#endif
#ifdef OCR4CL
	uint8ptr_t const pOCR4CL = &OCR4CL;
#endif
#ifdef OCR4CH
	uint8ptr_t const pOCR4CH = &OCR4CH;
#endif

	/* Reserved [0xAE..0xAF] */
#ifdef TCCR2A
	uint8ptr_t const pTCCR2A = &TCCR2A;
#endif
#ifdef TCCR2A
	uint8ptr_t const pTCCR2A = &TCCR2A;
#endif
#ifdef TCNT2
	uint8ptr_t const pTCNT2 = &TCNT2;
#endif
#ifdef OCR2A
	uint8ptr_t const pOCR2A = &OCR2A;
#endif
#ifdef OCR2B
	uint8ptr_t const pOCR2B = &OCR2B;
#endif

	/* Reserved [0xB5] */
#ifdef ASSR
	uint8ptr_t const pASSR = &ASSR;
#endif

	/* Reserved [0xB7] */
#ifdef TWBR
	uint8ptr_t const pTWBR = &TWBR;
#endif
#ifdef TWSR
	uint8ptr_t const pTWSR = &TWSR;
#endif
#ifdef TWAR
	uint8ptr_t const pTWAR = &TWAR;
#endif
#ifdef TWDR
	uint8ptr_t const pTWDR = &TWDR;
#endif
#ifdef TWCR
	uint8ptr_t const pTWCR = &TWCR;
#endif
#ifdef TWAMR
	uint8ptr_t const pTWAMR = &TWAMR;
#endif

	/* Reserved [0xBE..0xBF] */
#ifdef UCSR0A
	uint8ptr_t const pUCSR0A = &UCSR0A;
#endif
#ifdef UCSR0B
	uint8ptr_t const pUCSR0B = &UCSR0B;
#endif
#ifdef UCSR0C
	uint8ptr_t const pUCSR0C = &UCSR0C;
#endif

	/* Reserved [0xC3] */

	/* Combine UBRR0L and UBRR0H */
#ifdef UBRR0
	uint16ptr_t const pUBRR0 = &UBRR0;
#endif
#ifdef UBRR0L
	uint8ptr_t const pUBRR0L = &UBRR0L;
#endif
#ifdef UBRR0H
	uint8ptr_t const pUBRR0H = &UBRR0H;
#endif
#ifdef UDR0
	uint8ptr_t const pUDR0 = &UDR0;
#endif

	/* Reserved [0xC7] */
#ifdef UCSR1A
	uint8ptr_t const pUCSR1A = &UCSR1A;
#endif
#ifdef UCSR1B
	uint8ptr_t const pUCSR1B = &UCSR1B;
#endif
#ifdef UCSR1C
	uint8ptr_t const pUCSR1C = &UCSR1C;
#endif

	/* Reserved [0xCB] */

	/* Combine UBRR1L and UBRR1H */
#ifdef UBRR1
	uint16ptr_t const pUBRR1 = &UBRR1;
#endif
#ifdef UBRR1L
	uint8ptr_t const pUBRR1L = &UBRR1L;
#endif
#ifdef UBRR1H
	uint8ptr_t const pUBRR1H = &UBRR1H;
#endif
#ifdef UDR1
	uint8ptr_t const pUDR1 = &UDR1;
#endif

	/* Reserved [0xCF] */
#ifdef UCSR2A
	uint8ptr_t const pUCSR2A = &UCSR2A;
#endif
#ifdef UCSR2B
	uint8ptr_t const pUCSR2B = &UCSR2B;
#endif
#ifdef UCSR2C
	uint8ptr_t const pUCSR2C = &UCSR2C;
#endif


	/* Reserved [0xD3] */

	/* Combine UBRR2L and UBRR2H */
#ifdef UBRR2
	uint16ptr_t const pUBRR2 = &UBRR2;
#endif
#ifdef UBRR2L
	uint8ptr_t const pUBRR2L = &UBRR2L;
#endif
#ifdef UBRR2H
	uint8ptr_t const pUBRR2H = &UBRR2H;
#endif
#ifdef UDR2
	uint8ptr_t const pUDR2 = &UDR2;
#endif

	/* Reserved [0xD7..0xFF] */
#ifdef PINH
	uint8ptr_t const pPINH = &PINH;
#endif
#ifdef DDRH
	uint8ptr_t const pDDRH = &DDRH;
#endif
#ifdef PORTH
	uint8ptr_t const pPORTH = &PORTH;
#endif
#ifdef PINJ
	uint8ptr_t const pPINJ = &PINJ;
#endif
#ifdef DDRJ
	uint8ptr_t const pDDRJ = &DDRJ;
#endif
#ifdef PORTJ
	uint8ptr_t const pPORTJ = &PORTJ;
#endif
#ifdef PINK
	uint8ptr_t const pPINK = &PINK;
#endif
#ifdef DDRK
	uint8ptr_t const pDDRK = &DDRK;
#endif
#ifdef PORTK
	uint8ptr_t const pPORTK = &PORTK;
#endif
#ifdef PINL
	uint8ptr_t const pPINL = &PINL;
#endif
#ifdef DDRL
	uint8ptr_t const pDDRL = &DDRL;
#endif
#ifdef PORTL
	uint8ptr_t const pPORTL = &PORTL;
#endif
	/* Reserved [0x10C..0x11F] */
#ifdef TCCR5A
	uint8ptr_t const pTCCR5A = &TCCR5A;
#endif
#ifdef TCCR5B
	uint8ptr_t const pTCCR5B = &TCCR5B;
#endif
#ifdef TCCR5C
	uint8ptr_t const pTCCR5C = &TCCR5C;
#endif
	/* Reserved [0x123] */

	/* Combine TCNT5L and TCNT5H */
#ifdef TCNT5
	uint16ptr_t const pTCNT5 = &TCNT5;
#endif
#ifdef TCNT5L
	uint8ptr_t const pTCNT5L = &TCNT5L;
#endif
#ifdef TCNT5H
	uint8ptr_t const pTCNT5H = &TCNT5H;
#endif
	/* Combine ICR5L and ICR5H */
#ifdef ICR5
	uint16ptr_t const pICR5 = &ICR5;
#endif
#ifdef ICR5L
	uint8ptr_t const pICR5L = &ICR5L;
#endif
#ifdef ICR5H
	uint8ptr_t const pICR5H = &ICR5H;
#endif

	/* Combine OCR5AL and OCR5AH */
#ifdef OCR5A
	uint16ptr_t const pOCR5A = &OCR5A;
#endif
#ifdef OCR5AL
	uint8ptr_t const pOCR5AL = &OCR5AL;
#endif
#ifdef OCR5AH
	uint8ptr_t const pOCR5AH = &OCR5AH;
#endif

	/* Combine OCR5BL and OCR5BH */
#ifdef OCR5B
	uint16ptr_t const pOCR5B = &OCR5B;
#endif
#ifdef OCR5BL
	uint8ptr_t const pOCR5BL = &OCR5BL;
#endif
#ifdef OCR5BH
	uint8ptr_t const pOCR5BH = &OCR5BH;
#endif
	/* Combine OCR5CL and OCR5CH */
#ifdef OCR5C
	uint16ptr_t const pOCR5C = &OCR5C;
#endif
#ifdef OCR5CL
	uint8ptr_t const pOCR5CL = &OCR5CL;
#endif
#ifdef OCR5CH
	uint8ptr_t const pOCR5CH = &OCR5CH;
#endif
	/* Reserved [0x12E..0x12F] */
#ifdef UCSR3A
	uint8ptr_t const pUCSR3A = &UCSR3A;
#endif
#ifdef UCSR3B
	uint8ptr_t const pUCSR3B = &UCSR3B;
#endif
#ifdef UCSR3C
	uint8ptr_t const pUCSR3C = &UCSR3C;
#endif   
	/* Reserved [0x133] */

	/* Combine UBRR3L and UBRR3H */
#ifdef UBRR3
	uint16ptr_t const pUBRR3 = &UBRR3;
#endif
#ifdef UBRR3L
	uint8ptr_t const pUBRR3L = &UBRR3L;
#endif
#ifdef UBRR3H
	uint8ptr_t const pUBRR3H = &UBRR3H;
#endif
#ifdef UDR3
	uint8ptr_t const pUDR3 = &UDR3;
#endif
}

#endif AVRPTRDEF_H