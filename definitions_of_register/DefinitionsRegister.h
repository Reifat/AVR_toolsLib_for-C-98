volatile uint8_t * const pb = &PORTB;
/* Registers and associated bit numbers */
volatile unsigned char* const pTWBR = &TWBR;

volatile unsigned char* const pTWSR = &TWSR;

volatile unsigned char* const pTWAR = &TWAR;

volatile unsigned char* const pTWDR = &TWDR;

/* Combine ADCL and ADCH */
volatile unsigned char* const pADC  = &ADC;
volatile unsigned char* const pADCW	= &ADCW;
volatile unsigned char* const pADCL = &ADCL;
volatile unsigned char* const pADCH = &ADCH;

volatile unsigned char* const pADCSRA = &ADCSRA;

volatile unsigned char* const pADMUX  = &ADMUX;

volatile unsigned char* const pACSR   = &ACSR;

volatile unsigned char* const pUBRRL  = &pUBRRL;

volatile unsigned char* const pUCSRB  = &UCSRB;

volatile unsigned char* const pUCSRA  = &UCSRA;

volatile unsigned char* const pUDR    = &UDR;

volatile unsigned char* const pSPCR   = &SPCR;

volatile unsigned char* const pSPSR   = &SPSR;

volatile unsigned char* const pSPDR   = &SPDR;

volatile unsigned char* const pPIND   = &PIND;

volatile unsigned char* const pDDRD   = &DDRD;

volatile unsigned char* const pPORTD  = &PORTD;

volatile unsigned char* const pPINC   = &PINC;

volatile unsigned char* const pDDRC   = &DDRC;

volatile unsigned char* const pPORTC  = &PORTC;
	
volatile unsigned char* const pPINB   = &PINB;

volatile unsigned char* const pDDRB   = &DDRB;

volatile unsigned char* const pPORTB  = &PORTB;

volatile unsigned char* const pPINA   = &PINA;

volatile unsigned char* const pDDRA   = &DDRA;

volatile unsigned char* const pPORTA  = &PORTA;

/* EEPROM Control Register */
volatile unsigned char* const pEECR	  = &EECR;

/* EEPROM Data Register */
volatile unsigned char* const pEEDR	  = &EEDR;

/* EEPROM Address Register */
volatile unsigned char* const pEEAR	  = &EEAR;
volatile unsigned char* const pEEARL  =	&EEARL;
volatile unsigned char* const pEEARH  =	&EEARH;

volatile unsigned char* const pUCSRC  = &UCSRC;

volatile unsigned char* const pUBRRH  = &UBRRH;

volatile unsigned char* const pWDTCR  = &WDTCR;

volatile unsigned char* const pASSR   = &ASSR;

volatile unsigned char* const pOCR2   = &OCR2;

volatile unsigned char* const pTCNT2  = &TCNT2;
	
volatile unsigned char* const pTCCR2  = &TCCR2;

/* Combine ICR1L and ICR1H */
volatile unsigned char* const pICR1   = &ICR1;

volatile unsigned char* const pICR1L  = &ICR1L;
volatile unsigned char* const pICR1H  = &ICR1H;

/* Combine OCR1BL and OCR1BH */
volatile unsigned char* const pOCR1B  = &OCR1B;

volatile unsigned char* const pOCR1BL = &OCR1BL;
volatile unsigned char* const pOCR1BH = &OCR1BH;

/* Combine OCR1AL and OCR1AH */
volatile unsigned char* const pOCR1A  = &OCR1A;

volatile unsigned char* const pOCR1AL = &OCR1AL;
volatile unsigned char* const pOCR1AH = &OCR1AH;

/* Combine TCNT1L and TCNT1H */
volatile unsigned char* const pTCNT1  = &TCNT1;

volatile unsigned char* const pTCNT1L = &TCNT1L;
volatile unsigned char* const pTCNT1H = &TCNT1H;

volatile unsigned char* const pTCCR1B = &TCCR1B;

volatile unsigned char* const pTCCR1A = &TCCR1A;

/* 
   The ADHSM bit has been removed from all documentation, 
   as being not needed at all since the comparator has proven 
   to be fast enough even without feeding it more power.
*/

volatile unsigned char* const pSFIOR  = &SFIOR;

volatile unsigned char* const pOSCCAL = &OSCCAL

volatile unsigned char* const pOCDR   = &OCDR;

volatile unsigned char* const pTCNT0  = &TCNT0;

volatile unsigned char* const pTCCR0  = &TCCR0;

volatile unsigned char* const pMCUCSR = &MCUCSR;

volatile unsigned char* const pMCUCR  = &MCUCR;

volatile unsigned char* const pTWCR   = &TWCR;

volatile unsigned char* const pSPMCR  = &SPMCR;

volatile unsigned char* const pTIFR   = &TIFR;

volatile unsigned char* const pTIMSK  = &TIMSK;

volatile unsigned char* const pGIFR   = &GIFR;


volatile unsigned char* const pGICR   = &GICR;

volatile unsigned char* const pOCR0   = &OCR0;