#ifndef _REGISTERSET_HPP
#define _REGISTERSET_HPP

#ifndef	_DEFINITIONS_TYPE_HPP
#include "metabit\definitions_type\definitions_type.hpp"
#endif

#ifndef _METALIB_HPP
#include "metabit\metalib\metalib.hpp"
#endif

#ifndef _BITLIB_HPP
#include "metabit\bitlib\bitlib.hpp"
#endif

#if (_DEBUG | DEBUG | ONDBG) & !NO_DEBUG

template<typename T, size8_t _Pos>
struct CheckRenge
{
	static const bool Result = ((sizeof(T) * 8) > _Pos);
};

#define  CHECKTYPE(mess) const bool testType = SameType<_Ty, reg8_t  >::value   |	\
											   SameType<_Ty, reg16_t >::value   |	\
										       SameType<_Ty, uint8_t >::value   |	\
										       SameType<_Ty, uint16_t>::value   |	\
										       SameType<_Ty, uint32_t>::value   |	\
										       SameType<_Ty, uint64_t>::value   |	\
										       SameType<_Ty, int8_st  >::value  |	\
										       SameType<_Ty, int16_st >::value  |	\
										       SameType<_Ty, int32_st >::value  |	\
										       SameType<_Ty, int64_st >::value;		\
		STATIC_ASSERT( testType==true , INVALID_TYPES_ENTERED_VALID_TYPES_##mess)

#define CHECKRANGE(Ty, Pos) STATIC_ASSERT((CheckRenge<Ty,Pos>::Result), OUT_OF_RANGE_REGISTER)
#define D_AT(pos)	CellFunc<pos>(0)
#define D_LAS(pos)	CellFunc<pos>(1)
#define D_RAS(pos)	CellFunc<pos>(2)
#define D_FLIP(pos) CellFunc<pos>(3)
#define D_TEST(pos)	CellFunc<pos>()
#else
#define CHECKTYPE(mess)
#define CHECKRANGE(Ty, Pos)
#define D_AT(pos)	operator[](pos)
#define D_LAS(pos)	operator<<=(pos)
#define D_RAS(pos)	operator>>=(pos)
#define D_FLIP(pos) flip(pos)
#define D_TEST(pos)	test(pos)
#endif

template<typename _Ty>
class RegisterSet
{	
	public:

	RegisterSet(_Ty* const Register) : _Register(Register), _MyPos(0)
	{
		CHECKTYPE(ALL_signed_and_unsigned_integer_types);
	}
		
	// basic operators ************************************************************
	template<typename _inTy>
	RegisterSet& operator=(const _inTy _Val)
	{
		*_Register = _Val;
		return *this;
	}
	RegisterSet& operator=(const RegisterSet &_Right)
	{
		*_Register = _Right;
		return *this;
	}
	template<typename convertTy>
	operator convertTy()const
	{
		return *_Register;
	}
	operator _Ty&()const
	{
		return *_Register;
	}
	
	inline operator bool()const
	{
		return (*_Register & ((_Ty)1 << _MyPos));
	}
	RegisterSet& operator=(const bool &_Val)
	{
		BoolSetInPos(_Val);
		return *this;
	}
	RegisterSet& operator[](const size8_t& _Pos)
	{
		_MyPos = _Pos;
		return *this;
	}
	
	_Ty GetValue()
	{
		return *_Register;
	}
	// operators *******************************************************************
	RegisterSet& operator &=(const RegisterSet& _Right)
	{
		*_Register &= (_Ty)_Right;
		return *this;
	}
	RegisterSet& operator|=(const RegisterSet& _Right)
	{
		*_Register |= (_Ty)_Right;
		return *this;
	}
	RegisterSet& operator^=(const RegisterSet& _Right)
	{
		*_Register ^= (_Ty)_Right;
		return *this;
	}
	// metodth  ***********************************************************************
	
	RegisterSet& SetInRange(const size8_t &at, const size8_t &to, bool _val = true) // Установка или сброс с разряда a по b
	{
		*_Register = bitlib::SetInRange<_Ty>(*_Register, at, to,_val);
		return *this;
	}
	
	RegisterSet& SetInPos(const size8_t &_pos, const bool &_val = true)
	{
		_val ? (*_Register |= ((_Ty)1 << _pos)) : (*_Register &= ~((_Ty)1 << _pos));
		return *this;
	}
	RegisterSet& set(bool _Val = true) // Установка или сброс всех битов в регистре
	{
		if(_Val) *_Register = ~(_Ty)0;
		else     *_Register = (_Ty)0;
		return *this;
	}
	RegisterSet& reset() // Сброс всех битов
	{
		*_Register = (_Ty)0;
		return *this;
	}
	bool all()const // Проверяет, чтобы все биты были установлены в true
	{
		return (*_Register & ~(_Ty)0);
	}
	bool any()const // Проверяет, чтобы хотя бы один бит был установлен в true
	{
		return (*_Register != (_Ty)0);
	}
	bool none()const // Проверяет, чтобы никакой из битов не был установлен в true 
	{
		return !any();
	}
	size8_t size()const // Возвращает размер регистра
	{
		return bitlib::SizeTy<_Ty>::_Size;
	}	
	RegisterSet& flip() // Инвертирует все биты
	{
		*_Register = ~(*_Register);
		return *this;
	}
	size8_t count()const // Возвращает количество битов, которые установлены в true
	{
		return bitlib::Count<_Ty>(*_Register);;
	}
		
	
	//***** Методы для debug и для Release
#if (_DEBUG | DEBUG | ONDBG) & !NO_DEBUG
	public:
	template<size8_t _Pos>
	bool CellFunc()
	{
		return test<_Pos>();
	}

	template<size8_t _Pos>
	RegisterSet& CellFunc(size8_t num)
	{
		switch (num)
		{
			case 0:
			return at<_Pos>();
			break;
			case 1:
			return LAS<_Pos>();
			break;
			case 2:
			return RAS<_Pos>();
			break;
			case 3:
			return flip<_Pos>();
			break;
		}
	}
	private:
	template<size8_t _Pos>
	bool test()const // test if bit at _Pos is set
	{
		CHECKRANGE(_Ty, _Pos);
		return (*_Register &= (1 << _Pos));
	}
	template<size8_t _Pos>
	RegisterSet& at()
	{
		CHECKRANGE(_Ty, _Pos);
		_MyPos = _Pos;
		return *this;
	}
	template<size8_t _Pos>
	RegisterSet& LAS()//registerSet& operator<<=()
	{
		CHECKRANGE(_Ty, _Pos);
		*_Register <<= _Pos;
		return *this;
	}
	template<size8_t _Pos>
	RegisterSet& RAS() //registerSet& operator>>=()
	{
		CHECKRANGE(_Ty, _Pos);
		*_Register >>= _Pos;
		return *this;
	}
	template<size8_t _Pos>
	RegisterSet& flip()
	{
		CHECKRANGE(_Ty, _Pos);
		*_Register ^= (1 << _Pos);
		return *this;
	}	
#else
	public:
	RegisterSet& operator<<=(const size8_t& _Pos)
	{
		*_Register <<= _Pos;
		return *this;
	}
	RegisterSet& operator>>=(const size8_t& _Pos)
	{
		*_Register >>= _Pos;
		return *this;
	}
	RegisterSet& flip(const size8_t &_Pos)
	{
		*_Register ^= (1 << _Pos);
		return *this;
	}
	bool test(size8_t _Pos)const // test if bit at _Pos is set
	{
		return (*_Register &= (1 << _Pos));
	}	
	#endif
	
	private:
	RegisterSet& BoolSetInPos(const bool &_Val)
	{
		if (_Val)
		*_Register |= ((_Ty)1 << _MyPos);
		else
		*_Register &= ~((_Ty)1 << _MyPos);
		return *this;
	}
	//end - metoth*********************************************************************

	protected:	
		_Ty* const   _Register;
	private:
	size8_t _MyPos;
};

#endif