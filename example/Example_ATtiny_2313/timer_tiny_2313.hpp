#ifndef TIMER_H_
#define TIMER_H_
// Simple timer TC0 for ATtiny2313

#define  AVR_ATTINY
#include "metabit/metabit.hpp"

class Timer :public mbl::RegisterSet<mbl::reg8_t>::n_static_
{
	mbl::reg8_t* _ocr_a;
	mbl::reg8_t* _ocr_b;
	mbl::reg8_t* _tccr_a;
	mbl::reg8_t* _tccr_b;
	mbl::reg8_t* _timsk;
	mbl::reg8_t* _tifr;
	
	typedef mbl::RegisterSet<mbl::reg8_t>::n_static_ Parent;
	public:
	Timer():Parent(mcreg::TCNT0_c),
	_ocr_a(mcreg::OCR0A_c),
	_ocr_b(mcreg::OCR0B_c),
	_tccr_a(mcreg::TCCR0A_c),
	_tccr_b(mcreg::TCCR0B_c),
	_timsk(mcreg::TIMSK_c),
	_tifr(mcreg::TIFR_c)  {
		*Parent::_register  = 0;
		*_ocr_a   = 0;
		*_ocr_b   = 0;
		*_tccr_a  = 0;
		*_tccr_b  = 0;
		*_timsk   = 0;
		*_tifr    = 0;
	}
	inline void SetNormal() const{
		*_tccr_a &= ~(1 << 0); // WGM00 reset
		*_tccr_a &= ~(1 << 1); // WGM01 reset
		*_tccr_b &= ~(1 << 3); // WGM02 reset
	}
	inline void SetPWM() const{
		*_tccr_a |=  (1 << 0); // WGM00 set
		*_tccr_a &= ~(1 << 1); // WGM01 reset
		*_tccr_b &= ~(1 << 3); // WGM02 reset
	}
	inline void SetCTC() const{
		*_tccr_a &= ~(1 << 0); // WGM00 reset
		*_tccr_a |=  (1 << 1); // WGM01 set
		*_tccr_b &= ~(1 << 3); // WGM02 reset
	}
	inline void SetFastPWM() const{
		*_tccr_a |=  (1 << 0); // WGM00 reset
		*_tccr_a |=  (1 << 1); // WGM01 reset
		*_tccr_b &= ~(1 << 3); // WGM02 reset
	}
	inline void TimerOff() const{ *_tccr_b |= 0x08; }
	inline void Divider(mbl::size16_t num) const{
		switch (num){
			case 1:
			*_tccr_b |= 0x01; // not divider
			break;
			case 8:
			*_tccr_b |= 0x02; // 8
			break;
			case 64:
			*_tccr_b |= 0x03; // 64
			break;
			case 256:
			*_tccr_b |= 0x04; // 256
			break;
			case 1024:
			*_tccr_b |= 0x05; // 1024
			break;
		}
	}
	inline void OCR_OffOut() const{ // Отключить вывод OCR0A
		*_tccr_a &= ~(1 << 6); // COM00A0 reset
		*_tccr_a &= ~(1 << 7); // COM00A1 reset
	}
	inline void OCR_FlipOut_If_Match() const{ // Изменить вывод OCR0A на противоположное в момент совпадения
		*_tccr_a |=  (1 << 6); // COM00A0 set
		*_tccr_a &= ~(1 << 7); // COM00A1 reset
	}
	inline void OCR_SetOut_If_Match() const{ // Установить вывод OCR0A в момент совпадения
		*_tccr_a &= ~(1 << 6); // COM00A0 reset
		*_tccr_a |=  (1 << 7); // COM00A1 set
	}
	inline void OCR_ResetOut_If_Match() const{ // Сбросить вывод OCR0A в момент совпадения
		*_tccr_a |= (1 << 6); // COM00A0 set
		*_tccr_a |= (1 << 6); // COM00A1 set
	}
	inline mbl::reg8_t& OCR_Get() const{return *_ocr_a; }
	inline mbl::reg8_t& OCR_Set(const mbl::size8_t& val) const{
		*_ocr_a = val;
		return *_ocr_a;
	}
	inline void OnInterruptOverflow() const {
		sei();
		*_timsk |=  (1 << 1);
	}
	inline void OffInterruptOverflow() const   {
		*_timsk &= ~(1 << 1);
	}
	inline void OnInterruptCoincidence() const {
		sei();
		*_timsk |=  (1 << 0);
	}
	inline void OffInterruptCoincidence() const{
		*_timsk &= ~(1 << 0);
	}
};




#endif /* TIMER_H_ */