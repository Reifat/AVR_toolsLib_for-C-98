#ifndef REGISTER_INIT_HPP
#define REGISTER_INIT_HPP

#ifndef REGISTERSET_HPP
#include "metabit\register_set\registerset.hpp"
#endif
/*
Example,
Initialize bits of the register:
	registerSet<typeRegister> objRegister =
	rbi::Init<typeRegister,&pointerToRegister>(1)(1)(1)(0)(1)(1)(1)(0);
Example:
Setting bits of the register:
	objPORTB = rbi::Init<typeRegister>(1)(0)(1)(0)(1)(0)(0)(1);
*/
namespace mbl // namespace meta bit library
{
	namespace rbi // namespace register bit initialization
	{
		reg8_t* PNULL;
		
		template<typename _Ty, _Ty * *P>
		class GenerateListBits
		{
		public:
			GenerateListBits() :_ListBist((_Ty)0)
			{
				_SizeRegister = (sizeof(_Ty) * 8) - 1;
				_MyPos = _SizeRegister;
			}
			GenerateListBits& operator()(_Ty _Val)
			{
				_Val ? _ListBist |= ((_Ty)1 << _MyPos) : _ListBist &= ~((_Ty)1 << _MyPos);
				_MyPos--;
				return *this;
			}
			operator mbl::RegisterSet<_Ty>()
			{
				if (*P)
				{
					**P = _ListBist;
					return mbl::RegisterSet<_Ty>(*P);
				}
				else
					return mbl::RegisterSet<_Ty>(&_ListBist);
			}
		private:
			_Ty _ListBist;
			_Ty _MyPos;
			_Ty _SizeRegister;
		};

		template<typename _Ty, _Ty * *P>
		static GenerateListBits<_Ty, P> Init(_Ty _Val)
		{
			return GenerateListBits<_Ty, P>()(_Val);
		}
		template<typename _Ty>
		GenerateListBits<_Ty, &PNULL> Init(_Ty _Val)
		{
			return GenerateListBits<_Ty, &PNULL>()(_Val);
		}
	} // end namespace register bit initialization	
	
	using rbi::Init;
} // end namespace meta bit library
#endif