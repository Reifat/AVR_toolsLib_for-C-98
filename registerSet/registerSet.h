template<typename _Ty>
class registerSet
{
public:
	registerSet(_Ty* const Register) : _Register(Register), _MyPos(0)
	{
		_SizeRegister = sizeof(_Ty) * 8 - 1;
	}

	void operator=(const bool& _Val)
	{
		if (_Val)
			*_Register |= ((_Ty)1 << _MyPos);
		else
			*_Register &= ~((_Ty)1 << _MyPos);
	}
	registerSet& operator=(const registerSet& _Val)
	{
		*_Register = _Val;
		return *this;
	}
	operator _Ty& ()const
	{
		return *_Register;
	}

	inline operator bool()const
	{
		return (*_Register & ((_Ty)1 << _MyPos));
	}
	registerSet& operator[](const unsigned int& _Pos)
	{
		_MyPos = _Pos;
		return *this;
	}
	void Set(const unsigned int& _Pos, const bool& _Val)
	{
		if (_Val)
			*_Register |= ((_Ty)1 << _MyPos);
		else
			*_Register &= ~((_Ty)1 << _MyPos);
	}
private:
	_Ty* const   _Register;
	unsigned int _SizeRegister;
	unsigned int _MyPos;
};
