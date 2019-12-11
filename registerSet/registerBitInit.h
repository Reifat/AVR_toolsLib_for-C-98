/*
Example:
Initialize bits of the register:
	initialize pointer for register - volatile unsigned char* p = &PORTB
	registerSet<typeRegister> objRegister =
	RBI::Init<typeRegister,&pointerToRegister>(1)(1)(1)(0)(1)(1)(1)(0);
Example:
Setting bits of the register:
	objPORTB = RBI::Init<typeRegister>(1)(0)(1)(0)(1)(0)(0)(1);
*/
namespace RBI // namespace RegisterBitInitialization
{
	reg8_t* PNULL;

	template<typename _Ty, _Ty* const* const P>
	class generateListBits
	{
	public:
		generateListBits() :_ListBist((_Ty)0)
		{
			_SizeRegister = (sizeof(_Ty) * 8) - 1;
			_MyPos = _SizeRegister;
		}
		~generateListBits() {}
		generateListBits& operator()(_Ty _Val)
		{
			_Val ? _ListBist |= ((_Ty)1 << _MyPos) : _ListBist &= ~((_Ty)1 << _MyPos);
			_MyPos--;
			return *this;
		}
		operator registerSet<_Ty>()
		{
			if (*P)
			{
				**P = _ListBist;
				return registerSet<_Ty>(*P);
			}
			else
				return registerSet<_Ty>(&_ListBist);
		}
	private:
		_Ty _ListBist;
		_Ty _MyPos;
		_Ty _SizeRegister;
	};

	template<typename _Ty, _Ty* const* const P>
	static generateListBits<_Ty, P> Init(_Ty _Val)
	{
		return generateListBits<_Ty, P>()(_Val);
	}
	template<typename _Ty>
	generateListBits<_Ty, &PNULL> Init(_Ty _Val)
	{
		return generateListBits<_Ty, &PNULL>()(_Val);
	}
}
/****************************************************************************************/