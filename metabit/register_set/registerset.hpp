#ifndef REGISTERSET_HPP
#define REGISTERSET_HPP

#ifndef	_DEFINITIONS_TYPE_HPP
#include "metabit\definitions_type\definitions_type.hpp"
#endif

#ifndef _METALIB_HPP
#include "metabit\type_traits\type_traits.hpp"
#endif

#ifndef _BITLIB_HPP
#include "metabit\bitlib\bitlib.hpp"
#endif

#if (_DEBUG | DEBUG | ONDBG) & !NO_DEBUG

namespace mbl // namespace meta bit library
{

namespace detail{
	template<typename T, size8_t _Pos>
	struct CheckRenge
	{
		static const bool Result = ((sizeof(T) * 8) > _Pos);
	};
}
}
#define  CHECKTYPE(mess) const bool testType = TestType<_Ty, reg8_t  >::value   |	\
											   TestType<_Ty, reg16_t >::value   |	\
										       TestType<_Ty, uint8_t >::value   |	\
										       TestType<_Ty, uint16_t>::value   |	\
										       TestType<_Ty, uint32_t>::value   |	\
										       TestType<_Ty, uint64_t>::value   |	\
										       TestType<_Ty, int8_st  >::value  |	\
										       TestType<_Ty, int16_st >::value  |	\
										       TestType<_Ty, int32_st >::value  |	\
										       TestType<_Ty, int64_st >::value;		\
		STATIC_ASSERT( testType==true , INVALID_TYPES_ENTERED_VALID_TYPES_##mess)

#define CHECKRANGE(Ty,Pos) STATIC_ASSERT((detail::CheckRenge<Ty,Pos>::Result), OUT_OF_RANGE_REGISTER)

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

namespace mbl { // namespace meta bit library
	
template<typename _Ty>
class RegisterSet
{	
	public:
	RegisterSet() {}
	RegisterSet(_Ty* const Register) : _register(Register), _my_pos(0)
	{
		CHECKTYPE(ALL_signed_and_unsigned_integer_types);
	}
	// basic operators ************************************************************
	template<typename _InTy>
	RegisterSet& operator=(const _InTy val)
	{
		if(_my_pos == -1)
			*_register = val;
		else
		{
			BoolSetInPos((bool)val);
			_my_pos = -1;	
		}
		return *this;
	}
	RegisterSet& operator=(const RegisterSet &obj)
	{
		*_register = obj;
		return *this;
	}
	template<typename ConvertTy>
	operator ConvertTy()const
	{
		return *_register;
	}
	inline operator bool()
	{
		bool return_val = (*_register & ((_Ty)1 << _my_pos));
		_my_pos = -1;
		return return_val;
	}

	RegisterSet& operator[](const size8_t& pos)
	{
		_my_pos = pos;
		return *this;
	}
	_Ty GetValue()
	{
		return *_register;
	}
	// operators *******************************************************************
	RegisterSet& operator &=(const RegisterSet& right)
	{
		*_register &= (_Ty)right;
		return *this;
	}
	RegisterSet& operator|=(const RegisterSet& right)
	{
		*_register |= (_Ty)right;
		return *this;
	}
	RegisterSet& operator^=(const RegisterSet& right)
	{
		*_register ^= (_Ty)right;
		return *this;
	}
	// metodth  ***********************************************************************
	RegisterSet& SetInRange(const size8_t &at, const size8_t &to, bool val = true) // Установка или сброс с разряда a по b
	{
		*_register = SetInRange(*_register, at, to, val);
		return *this;
	}
	RegisterSet& SetInPos(const size8_t &pos, const bool &val = true)
	{
		val ? (*_register |= ((_Ty)1 << pos)) : (*_register &= ~((_Ty)1 << pos));
		return *this;
	}
	RegisterSet& set(bool val = true) // Установка или сброс всех битов в регистре
	{
		if(val)  *_register = ~(_Ty)0;
		else     *_register =  (_Ty)0;
		return *this;
	}
	RegisterSet& reset() // Сброс всех битов
	{
		*_register = (_Ty)0;
		return *this;
	}
	bool all()const // Проверяет, чтобы все биты были установлены в true
	{
		return (*_register & ~(_Ty)0);
	}
	bool any()const // Проверяет, чтобы хотя бы один бит был установлен в true
	{
		return (*_register != (_Ty)0);
	}
	bool none()const // Проверяет, чтобы никакой из битов не был установлен в true 
	{
		return !any();
	}
	size8_t size()const // Возвращает размер регистра
	{
		return SizeTy<_Ty>::_Size;
	}	
	RegisterSet& flip() // Инвертирует все биты
	{
		*_register = ~(*_register);
		return *this;
	}
	size8_t count()const // Возвращает количество битов, которые установлены в true
	{
		return Count<_Ty>(*_register);;
	}
	//***** Методы для debug и для Release
#if (_DEBUG | DEBUG | ONDBG) & !NO_DEBUG
	public:
	template<size8_t pos>
	bool CellFunc()
	{
		return test<pos>();
	}

	template<size8_t pos>
	RegisterSet& CellFunc(size8_t num)
	{
		switch (num)
		{
			case 0:
			return at<pos>();
			break;
			case 1:
			return LAS<pos>();
			break;
			case 2:
			return RAS<pos>();
			break;
			case 3:
			return flip<pos>();
			break;
		}
	}
	private:
	template<size8_t pos>
	bool test()const // test if bit at _Pos is set
	{
		CHECKRANGE(_Ty, pos);
		return (*_register &= (1 << pos));
	}
	template<size8_t pos>
	RegisterSet& at()
	{
		CHECKRANGE(_Ty,pos);
		_my_pos = pos;
		return *this;
	}
	template<size8_t pos>
	RegisterSet& LAS()//registerSet& operator<<=()
	{
		CHECKRANGE(_Ty,pos);
		*_register <<= pos;
		return *this;
	}
	template<size8_t pos>
	RegisterSet& RAS() //registerSet& operator>>=()
	{
		CHECKRANGE(_Ty,pos);
		*_register >>= pos;
		return *this;
	}
	template<size8_t pos>
	RegisterSet& flip()
	{
		CHECKRANGE(_Ty,pos);
		*_register ^= (1 << pos);
		return *this;
	}	
#else
	public:
	RegisterSet& operator<<=(const size8_t& pos)
	{
		*_register <<= pos;
		return *this;
	}
	RegisterSet& operator>>=(const size8_t& pos)
	{
		*_register >>= pos;
		return *this;
	}
	RegisterSet& flip(const size8_t &pos)
	{
		*_register ^= (1 << pos);
		return *this;
	}
	bool test(size8_t pos)const // test if bit at _Pos is set
	{
		return (*_register &= (1 << pos));
	}	
	#endif
	
	private:
	RegisterSet& BoolSetInPos(const bool &val)
	{
		if (val)
		*_register |= ((_Ty)1 << _my_pos);
		else
		*_register &= ~((_Ty)1 << _my_pos);
		return *this;
	}
	//end - metoth*********************************************************************

	private:	
		_Ty* const   _register;
		size8_t _my_pos;
};
} // end namespace mbl
#endif