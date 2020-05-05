#ifndef TIMER_H_
#define TIMER_H_

#include "metabit/metabit.hpp"

class Timer :public mbl::RegisterSet<mbl::reg8_t>::n_static_
{
	mbl::reg8_t* _ocr;
	mbl::reg8_t* _tccr;
	mbl::reg8_t* _timsk;
	mbl::reg8_t* _tifr;
	
	typedef mbl::RegisterSet<mbl::reg8_t>::n_static_ Parent;
	public:
	Timer():Parent(mcreg::tcnt_0_c),
	_ocr(mcreg::ocr_0_c),
	_tccr(mcreg::tccr_0_c),
	_timsk(mcreg::timsk_c),
	_tifr(mcreg::tifr_c)  {
		*Parent::_register = 0;
		*_ocr   = 0;
		*_tccr  = 0;
		*_timsk = 0;
		*_tifr  = 0;
	}
	inline void SetNormal() const{
		*_tccr &= ~(1 << 6); // WGM00 reset
		*_tccr &= ~(1 << 3); // WGM01 reset
	}
	inline void SetPWM() const{
		*_tccr |=  (1 << 6); // WGM00 reset
		*_tccr &= ~(1 << 3); // WGM01 reset
	}
	inline void SetCTC() const{
		*_tccr &= ~(1 << 6); // WGM00 set
		*_tccr |=  (1 << 3); // WGM01 set
	}
	inline void SetFastPWM() const{
		*_tccr |=  (1 << 6); // WGM00 set
		*_tccr |=  (1 << 3); // WGM01 set
	}
	inline void TimerOff() const{ *_tccr &= 0xF8; }
	inline void Divider(mbl::size16_t num) const{
		switch (num) {
			case 1:
			*_tccr |= 0x01; // not divider
			break;
			case 8:
			*_tccr |= 0x02; // 8
			break;
			case 64:
			*_tccr |= 0x03; // 64
			break;
			case 256:
			*_tccr |= 0x04; // 256
			break;
			case 1024:
			*_tccr |= 0x05; // 1024
			break;
		}
	}
	inline void OCR_OffOut() const{ // Отключить вывод OCR
		*_tccr &= ~(1 << 4); // COM00 reset
		*_tccr &= ~(1 << 5); // COM01 reset
	}
	inline void OCR_FlipOut_If_Match() const{ // Изменить вывод OCR на противоположное в момент совпадения
		*_tccr |=  (1 << 4); // COM00 set
		*_tccr &= ~(1 << 5); // COM01 reset
	}
	inline void OCR_SetOut_If_Match() const{ // Установить вывод OCR в момент совпадения
		*_tccr &= ~(1 << 4); // COM00 reset
		*_tccr |=  (1 << 5); // COM01 set
	}
	inline void OCR_ResetOut_If_Match() const{ // Сбросить вывод OCR в момент совпадения
		*_tccr |= (1 << 4); // COM00 set
		*_tccr |= (1 << 5); // COM01 set
	}
	inline mbl::reg8_t& OCR_Get() const{return *_ocr; }
	inline mbl::reg8_t& OCR_Set(const mbl::size8_t& val) const{
		*_ocr = val;
		return *_ocr;
	}
	inline void OnInterruptOverflow() const {
		sei();
		*_timsk |=  (1 << 0);
	}
	inline void OffInterruptOverflow() const {
		 *_timsk &= ~(1 << 0);
	}
	inline void OnInterruptCoincidence() const {
		sei();
		*_timsk |=  (1 << 1);
	}
	inline void OffInterruptCoincidence() const {
		 *_timsk &= ~(1 << 1);
	}
};


#endif /* TIMER_H_ */