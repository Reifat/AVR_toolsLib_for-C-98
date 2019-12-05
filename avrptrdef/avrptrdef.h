#include <avr/io.h>

#ifndef AVRPTRDEF_H
#define AVRPTRDEF_H

typedef volatile unsigned char* uint8ptr_t;
typedef volatile unsigned int* uint16ptr_t;

namespace ptrdef
{
	/* Registers and associated bit numbers */

	uint8ptr_t const pPINA = &PINA;

	uint8ptr_t const pDDRA = &DDRA;

	uint8ptr_t const pPORTA = &PORTA;

	uint8ptr_t const pPINB = &PINB;

	uint8ptr_t const pDDRB = &DDRB;

	uint8ptr_t const pPORTB = &PORTB;

	uint8ptr_t const pPINC = &PINC;

	uint8ptr_t const pDDRC = &DDRC;

	uint8ptr_t const pPORTC = &PORTC;

	uint8ptr_t const pPIND = &PIND;

	uint8ptr_t const pDDRD = &DDRD;

	uint8ptr_t const pPORTD = &PORTD;

	uint8ptr_t const pPINE = &PINE;

	uint8ptr_t const pDDRE = &DDRE;

	uint8ptr_t const pPORTE = &PORTE;

	uint8ptr_t const pPINF = &PINF;

	uint8ptr_t const pDDRF = &DDRF;

	uint8ptr_t const pPORTF = &PORTF;

	uint8ptr_t const pPING = &PING;

	uint8ptr_t const pDDRG = &DDRG;

	uint8ptr_t const pPORTG = &PORTG;

	uint8ptr_t const pTIFR0 = &TIFR0;

	uint8ptr_t const pTIFR1 = &TIFR1;

	uint8ptr_t const pTIFR2 = &TIFR2;

	uint8ptr_t const pTIFR3 = &TIFR3;

	uint8ptr_t const pTIFR4 = &TIFR4;

	uint8ptr_t const pTIFR5 = &TIFR5;

	uint8ptr_t const pPCIFR = &PCIFR;

	uint8ptr_t const pEIFR = &EIFR;

	uint8ptr_t const pEIMSK = &EIMSK;

	uint8ptr_t const pGPIOR0 = &GPIOR0;

	uint8ptr_t const pEECR = &EECR;

	uint8ptr_t const pEEDR = &EEDR;

	/* Combine EEARL and EEARH */
	uint16ptr_t const pEEAR = &EEAR;

	uint8ptr_t const pEEARL = &EEARL;
	uint8ptr_t const pEEARH = &EEARH;

	/* 6-char sequence denoting where to find the EEPROM registers in memory space.
	   Adresses denoted in hex syntax with uppercase letters. Used by the EEPROM
	   subroutines.
	   First two letters:  EECR address.
	   Second two letters: EEDR address.
	   Last two letters:   EEAR address.  */

	uint8ptr_t const pGTCCR = &GTCCR;

	uint8ptr_t const pTCCR0A = &TCCR0A;

	uint8ptr_t const pTCCR0B = &TCCR0B;

	uint8ptr_t const pTCNT0 = &TCNT0;

	uint8ptr_t const pOCR0A = &OCR0A;

	uint8ptr_t const pOCR0B = &OCR0B;

	/* Reserved [0x29] */

	uint8ptr_t const pGPIOR1 = &GPIOR1;

	uint8ptr_t const pGPIOR2 = &GPIOR2;

	uint8ptr_t const pSPCR = &SPCR;

	uint8ptr_t const pSPSR = &SPSR;

	uint8ptr_t const pSPDR = &SPDR;

	/* Reserved [0x2F] */

	uint8ptr_t const pACSR = &ACSR;

	uint8ptr_t const pMONDR = &MONDR;
	uint8ptr_t const pOCDR = &OCDR;

	/* Reserved [0x32] */

	uint8ptr_t const pSMCR = &SMCR;


	uint8ptr_t const pMCUSR = &MCUSR;

	uint8ptr_t const pMCUCR = &MCUCR;

	/* Reserved [0x36] */

	uint8ptr_t const pSPMCSR = &SPMCSR;

	/* Reserved [0x38..0x3A] */

	uint8ptr_t const pRAMPZ = &RAMPZ;

	uint8ptr_t const pEIND = &EIND;

	/* SP [0x3D..0x3E] */
	/* SREG [0x3F] */

	uint8ptr_t const pWDTCSR = &WDTCSR;

	uint8ptr_t const pCLKPR = &CLKPR;

	/* Reserved [0x62..0x63] */

	uint8ptr_t const pPRR0 = &PRR0;

	uint8ptr_t const pPRR1 = &PRR1;


	uint8ptr_t const pOSCCAL = &OSCCAL;

	/* Reserved [0x67] */

	uint8ptr_t const pPCICR = &PCICR;

	uint8ptr_t const pEICRA = &EICRA;

	uint8ptr_t const pEICRB = &EICRB;

	uint8ptr_t const pPCMSK0 = &PCMSK0;

	uint8ptr_t const pPCMSK1 = &PCMSK1;

	uint8ptr_t const pPCMSK2 = &PCMSK2;

	uint8ptr_t const pTIMSK0 = &TIMSK0;

	uint8ptr_t const pTIMSK1 = &TIMSK1;

	uint8ptr_t const pTIMSK2 = &TIMSK2;

	uint8ptr_t const pTIMSK3 = &TIMSK3;

	uint8ptr_t const pTIMSK4 = &TIMSK4;

	uint8ptr_t const pTIMSK5 = &TIMSK5;

	uint8ptr_t const pXMCRA = &XMCRA;

	uint8ptr_t const pXMCRB = &XMCRB;

	/* Reserved [0x76..0x77] */

	/* Combine ADCL and ADCH */
	uint16ptr_t const pADC = ADC;
	uint16ptr_t const pADCW = &ADCW;
	uint8ptr_t const pADCL = &ADCL;
	uint8ptr_t const pADCH = &ADCH;

	uint8ptr_t const pADCSRA = &ADCSRA;

	uint8ptr_t const pADCSRB = &ADCSRB;

	uint8ptr_t const pADMUX = &ADMUX;

	uint8ptr_t const pDIDR2 = &DIDR2;

	uint8ptr_t const pDIDR0 = &DIDR0;

	uint8ptr_t const pDIDR1 = &DIDR1;

	uint8ptr_t const pTCCR1A = &TCCR1A;

	uint8ptr_t const pTCCR1B = &TCCR1B;

	uint8ptr_t const pTCCR1C = &TCCR1C;

	/* Reserved [0x83] */

	/* Combine TCNT1L and TCNT1H */
	uint16ptr_t const pTCNT1 = &TCNT1;

	uint8ptr_t const pTCNT1L = &TCNT1L;
	uint8ptr_t const pTCNT1H = &TCNT1H;

	/* Combine ICR1L and ICR1H */
	uint16ptr_t const pICR1 = &ICR1;

	uint8ptr_t const pICR1L = &ICR1L;
	uint8ptr_t const pICR1H = &ICR1H;

	/* Combine OCR1AL and OCR1AH */
	uint16ptr_t const pOCR1A = &OCR1A;

	uint8ptr_t const pOCR1AL = &OCR1AL;
	uint8ptr_t const pOCR1AH = &OCR1AH;

	/* Combine OCR1BL and OCR1BH */
	uint16ptr_t const pOCR1B = &OCR1B;

	uint8ptr_t const pOCR1BL = &OCR1BL;
	uint8ptr_t const pOCR1BH = &OCR1BH;

	/* Combine OCR1CL and OCR1CH */
	uint16ptr_t const pOCR1C = &OCR1C;

	uint8ptr_t const pOCR1CL = &OCR1CL;
	uint8ptr_t const pOCR1CH = &OCR1CH;

	/* Reserved [0x8E..0x8F] */

	uint8ptr_t const pTCCR3A = &TCCR3A;

	uint8ptr_t const pTCCR3B = &TCCR3B;

	uint8ptr_t const pTCCR3C = &TCCR3C;

	/* Reserved [0x93] */

	/* Combine TCNT3L and TCNT3H */
	uint16ptr_t const pTCNT3 = &TCNT3;

	uint8ptr_t const pTCNT3L = &TCNT3L;
	uint8ptr_t const pTCNT3H = &TCNT3H;

	/* Combine ICR3L and ICR3H */
	uint16ptr_t const pICR3 = &ICR3;

	uint8ptr_t const pICR3L = &ICR3L;
	uint8ptr_t const pICR3H = &ICR3H;

	/* Combine OCR3AL and OCR3AH */
	uint16ptr_t const pOCR3A = &OCR3A;

	uint8ptr_t const pOCR3AL = &OCR3AL;
	uint8ptr_t const pOCR3AH = &OCR3AH;

	/* Combine OCR3BL and OCR3BH */
	uint16ptr_t const pOCR3B = &OCR3B;

	uint8ptr_t const pOCR3BL = &OCR3BL;
	uint8ptr_t const pOCR3BH = &OCR3BH;

	/* Combine OCR3CL and OCR3CH */
	uint16ptr_t const pOCR3C = &OCR3C;

	uint8ptr_t const pOCR3CL = &OCR3CL;
	uint8ptr_t const pOCR3CH = &OCR3CH;

	/* Reserved [0x9E..0x9F] */

	uint8ptr_t const pTCCR4A = &TCCR4A;

	uint8ptr_t const pTCCR4B = &TCCR4B;

	uint8ptr_t const pTCCR4C = &TCCR4C;

	/* Reserved [0xA3] */

	/* Combine TCNT4L and TCNT4H */
	uint16ptr_t const pTCNT4 = &TCNT4;

	uint8ptr_t const pTCNT4L = &TCNT4L;
	uint8ptr_t const pTCNT4H = &TCNT4H;

	/* Combine ICR4L and ICR4H */
	uint16ptr_t const pICR4 = &ICR4;

	uint8ptr_t const pICR4L = &ICR4L;
	uint8ptr_t const pICR4H = &ICR4H;

	/* Combine OCR4AL and OCR4AH */
	uint16ptr_t const pOCR4A = &OCR4A;

	uint8ptr_t const pOCR4AL = &OCR4AL;
	uint8ptr_t const pOCR4AH = &OCR4AH;

	/* Combine OCR4BL and OCR4BH */
	uint16ptr_t const pOCR4B = &OCR4B;

	uint8ptr_t const pOCR4BL = &OCR4BL;
	uint8ptr_t const pOCR4BH = &OCR4BH;

	/* Combine OCR4CL and OCR4CH */
	uint16ptr_t const pOCR4C = &OCR4C;

	uint8ptr_t const pOCR4CL = &OCR4CL;
	uint8ptr_t const pOCR4CH = &OCR4CH;

	/* Reserved [0xAE..0xAF] */

	uint8ptr_t const pTCCR2A = &TCCR2A;

	uint8ptr_t const pTCCR2A = &TCCR2A;

	uint8ptr_t const pTCNT2 = &TCNT2;

	uint8ptr_t const pOCR2A = &OCR2A;

	uint8ptr_t const pOCR2B = &OCR2B;

	/* Reserved [0xB5] */

	uint8ptr_t const pASSR = &ASSR;

	/* Reserved [0xB7] */

	uint8ptr_t const pTWBR = &TWBR;

	uint8ptr_t const pTWSR = &TWSR;

	uint8ptr_t const pTWAR = &TWAR;

	uint8ptr_t const pTWDR = &TWDR;

	uint8ptr_t const pTWCR = &TWCR;

	uint8ptr_t const pTWAMR = &TWAMR;

	/* Reserved [0xBE..0xBF] */

	uint8ptr_t const pUCSR0A = &UCSR0A;

	uint8ptr_t const pUCSR0B = &UCSR0B;

	uint8ptr_t const pUCSR0C = &UCSR0C;

	/* Reserved [0xC3] */

	/* Combine UBRR0L and UBRR0H */
	uint16ptr_t const pUBRR0 = &UBRR0;

	uint8ptr_t const pUBRR0L = &UBRR0L;
	uint8ptr_t const pUBRR0H = &UBRR0H;

	uint8ptr_t const pUDR0 = &UDR0;

	/* Reserved [0xC7] */

	uint8ptr_t const pUCSR1A = &UCSR1A;

	uint8ptr_t const pUCSR1B = &UCSR1B;

	uint8ptr_t const pUCSR1C = &UCSR1C;

	/* Reserved [0xCB] */

	/* Combine UBRR1L and UBRR1H */
	uint16ptr_t const pUBRR1 = &UBRR1;

	uint8ptr_t const pUBRR1L = &UBRR1L;
	uint8ptr_t const pUBRR1H = &UBRR1H;

	uint8ptr_t const pUDR1 = &UDR1;

	/* Reserved [0xCF] */

	uint8ptr_t const pUCSR2A = &UCSR2A;

	uint8ptr_t const pUCSR2B = &UCSR2B;

	uint8ptr_t const pUCSR2C = &UCSR2C;


	/* Reserved [0xD3] */

	/* Combine UBRR2L and UBRR2H */
	uint16ptr_t const pUBRR2 = &UBRR2;

	uint8ptr_t const pUBRR2L = &UBRR2L;
	uint8ptr_t const pUBRR2H = &UBRR2H;

	uint8ptr_t const pUDR2 = &UDR2;

	/* Reserved [0xD7..0xFF] */

	uint8ptr_t const pPINH = &PINH;

	uint8ptr_t const pDDRH = &DDRH;

	uint8ptr_t const pPORTH = &PORTH;

	uint8ptr_t const pPINJ = &PINJ;

	uint8ptr_t const pDDRJ = &DDRJ;

	uint8ptr_t const pPORTJ = &PORTJ;

	uint8ptr_t const pPINK = &PINK;

	uint8ptr_t const pDDRK = &DDRK;

	uint8ptr_t const pPORTK = &PORTK;

	uint8ptr_t const pPINL = &PINL;

	uint8ptr_t const pDDRL = &DDRL;

	uint8ptr_t const pPORTL = &PORTL;


	/* Reserved [0x10C..0x11F] */

	uint8ptr_t const pTCCR5A = &TCCR5A;

	uint8ptr_t const pTCCR5B = &TCCR5B;


	uint8ptr_t const pTCCR5C = &TCCR5C;

	/* Reserved [0x123] */

	/* Combine TCNT5L and TCNT5H */
	uint16ptr_t const pTCNT5 = &TCNT5;

	uint8ptr_t const pTCNT5L = &TCNT5L;
	uint8ptr_t const pTCNT5H = &TCNT5H;

	/* Combine ICR5L and ICR5H */
	uint16ptr_t const pICR5 = &ICR5;

	uint8ptr_t const pICR5L = &ICR5L;
	uint8ptr_t const pICR5H = &ICR5H;

	/* Combine OCR5AL and OCR5AH */
	uint16ptr_t const pOCR5A = &OCR5A;

	uint8ptr_t const pOCR5AL = &OCR5AL;
	uint8ptr_t const pOCR5AH = &OCR5AH;

	/* Combine OCR5BL and OCR5BH */
	uint16ptr_t const pOCR5B = &OCR5B;

	uint8ptr_t const pOCR5BL = &OCR5BL;
	uint8ptr_t const pOCR5BH = &OCR5BH;

	/* Combine OCR5CL and OCR5CH */
	uint16ptr_t const pOCR5C = &OCR5C;

	uint8ptr_t const pOCR5CL = &OCR5CL;
	uint8ptr_t const pOCR5CH = &OCR5CH;

	/* Reserved [0x12E..0x12F] */

	uint8ptr_t const pUCSR3A = &UCSR3A;

	uint8ptr_t const pUCSR3B = &UCSR3B;

	uint8ptr_t const pUCSR3C = &UCSR3C;


	/* Reserved [0x133] */

	/* Combine UBRR3L and UBRR3H */
	uint16ptr_t const pUBRR3 = &UBRR3;

	uint8ptr_t const pUBRR3L = &UBRR3L;
	uint8ptr_t const pUBRR3H = &UBRR3H;

	uint8ptr_t const pUDR3 = &UDR3;
}

#endif AVRPTRDEF_H