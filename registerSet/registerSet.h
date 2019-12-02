template<typename _Ty>
class registerSet
{
public:
	registerSet(_Ty* Register) : _Register(Register)
	{
		_SizeRegister = sizeof(_Ty) * 8 - 1;
	}
	class reference
	{
		friend registerSet<_Ty>;
	public:
		~reference() { // TRANSITION, ABI
		}
		reference& operator=(bool _Val)
		{
			_PregisterSet->Set(_Mypos, _Val);
			return *this;
		}
		operator bool()const
		{
			return _PregisterSet->_Subscript(_Mypos);
		}

	private:
		reference() : _PregisterSet(0), _Mypos(0) {}
		reference(registerSet<_Ty>& _RegisterSet, _Ty& _Pos)
			: _PregisterSet(&_RegisterSet), _Mypos(_Pos) {
			// construct from registerSet reference and position
		}
		registerSet<_Ty>* _PregisterSet;
		_Ty _Mypos;
	};

	reference operator[](_Ty _Pos) 
	{ return (reference(*this, _Pos)); }

	registerSet& operator=(_Ty _Val)
	{
		*_Register = _Val;
		return *this;
	}
	registerSet& operator=(registerSet _Val)
	{
		*_Register = _Val;
		return *this;
	}
	operator _Ty()
	{
		return *_Register;
	}
	bool _Subscript(_Ty _Pos) const
	{
		return (*_Register & ((_Ty)1 << _Pos));
	}

	registerSet& Set(bool _Val = true)
	{
		_Val ? *_Register |= ~(_Ty)0 : *_Register &= (_Ty)0;
		return *this;
	}
private:
	registerSet& Set(_Ty _Pos, bool _Val = true)
	{
		if (_Val)
			*_Register |=  ((_Ty)1 << _Pos);
		else
			*_Register &= ~((_Ty)1 << _Pos);
		return *this;
	}

	_Ty *_Register;
	_Ty _SizeRegister;
};

namespace ars //auxiliary register set
{
	template<typename _Ty, _Ty *P = nullptr>
	class generateListBits
	{
	public:
		generateListBits() :_ListBist((_Ty)0)
		{
			_SizeRegister = (sizeof(_Ty) * 8) - 1;
			_MyPos = _SizeRegister;
		}
		~generateListBits(){}
		generateListBits& operator()(_Ty _Val)
		{
			_Val ? _ListBist |= ((_Ty)1 << _MyPos) : _ListBist &= ~((_Ty)1 << _MyPos);
			_MyPos--;
			return *this;
		}
		operator registerSet<_Ty>()
		{
			if (P)
			{
				*P = _ListBist;
				return registerSet<_Ty>(P);
			}
			else
				return registerSet<_Ty>(&_ListBist);
		}
	private:
		_Ty _ListBist;
		_Ty _MyPos;
		_Ty _SizeRegister;
	};

	template<typename _Ty, _Ty *P = nullptr>
	generateListBits<_Ty,P> SetVal(_Ty _Val)
	{
		return generateListBits<_Ty, P>()(_Val);
	}
}