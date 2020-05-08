/* Библиотека для работы с разрядами
 * Автор Reifat
 * GitHub Repository - https://github.com/Reifat
 * Последние изменения 30.04.2020.
*/
#ifndef BITLIB_HPP
#define BITLIB_HPP

#ifndef	_DEFINITIONS_TYPE_HPP
#include "metabit\definitions_type\definitions_type.hpp"
#endif
namespace mbl // namespace meta bit library
{

	// Get size register / return number of bits in register;
	template<typename T>
	struct SizeTy
	{
		static const size8_t _Size = sizeof(T) * 8;
	};
	
	// Проверка, чтобы был установлен разряд n в лог.1;
	template<typename T>
	inline bool IsBitSet(T val, size8_t n) 
	{
		return (val & (1 << n)) != 0;
	}
	
	// Обнулить бит с номером n;
	template<typename T>
	bool BitOff(T val, size8_t n)
	{
		return val & ~(1 << n);
	}
	
	// Absolute value of the number
	template<typename T>
	inline T Mod(T x) 
	{
		return (x ^ (x >> SizeTy<T>::_Size - 1)) - (x >> SizeTy<T>::_Size - 1);
	}
	
	// Подсчет количества бит установленных в лог.1;
	namespace detail {
		template<typename T, size8_t N = SizeTy<T>::_Size>
		struct Count_8
		{
			inline static const uint8_t Result(T _Val)
			{
				uint8_t SinglesBit = _Val;
				SinglesBit -= (SinglesBit >> 1) & 0x55;
				SinglesBit = ((SinglesBit >> 2) & 0x33) + (SinglesBit & 0x33);
				SinglesBit = ((SinglesBit >> 4) + SinglesBit) & 0x0F;
				return (SinglesBit + Count_8<T, (N - 8)>::Result(_Val >> 8));
			}
		};
		template<typename T>
		struct Count_8<T, 0>
		{
			inline static const uint8_t Result(T _Val)
			{
				return 0;
			}
		};
	}
	// Возвращает количество битов, которые установлены в true;
	template<typename _Ty>
	size8_t Count(_Ty x)
	{
		return detail::Count_8<_Ty>::Result(x);
	}
	
	// Установить лог.1 во всех разрядах после первой лог. 1цы
	namespace detail
	{
		template<typename T, size8_t N = 1, bool over_size = true>
		struct _SetAfterTrue
		{
			inline static const T Result(T x)
			{
				T y = x | (x >> N);
				return _SetAfterTrue<T,(N << 1),(N < (SizeTy<T>::_Size >> 1)) >::Result(y);
			}
		};
		template<typename T, size8_t N>
		struct _SetAfterTrue<T, N, false>
		{
			inline static const T Result(T x)
			{
				return x;
			}
		};
	}
	template<typename T>
	inline T SetAfterTrue(T x)
	{
		return detail::_SetAfterTrue<T>::Result(x);
	}
	// Число ведущих нулей
	template<typename T>
	size8_t NumberLeadingZero(T x)
	{
		T val = detail::_SetAfterTrue<T>::Result(x);
		size8_t number = Count<T>(~val);
		return number;
	}
	
	// Целочисленный log2 по основанию 2
	template<typename T>
	T ilog2(T x)
	{
		T val = detail::_SetAfterTrue<T>::Result(x);
		size8_t val_log2 = Count<T>(val) - 1;
		return val_log2;
	}

	// Проверка, чтобы только 1н бит установлен в лог.1;
	template<typename T>
	bool OnlySingleTrue(T x)
	{
		return (Count<T>(x) == 1);
	}
	
	// Подсчет количества завершающих нулевых бит
	template<typename T>
	T CountTrailingZeros(T x)
	{
		T y = ~x & (x-1);
		return Count<T>(y);
	}
	
	// Установка или сброс с разряда a по b
	template<typename T>
	T SetInRange(const T &x,const size8_t &at,const size8_t &to, bool _val = true)
	{
		size8_t a = ~(T)0 << (to + 1);
		size8_t b = ~(~(T)0 << at);
		return _val ? ~(a | b) | x : (a | b) & x;
	}	
} // end namespace meta bit library

#endif