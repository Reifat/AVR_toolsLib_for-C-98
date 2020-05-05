/* Класс RegisterSet без статических свойств
 * Автор Reifat
 * GitHub Repository - https://github.com/Reifat
 * Последние изменения 30.04.2020.
*/
#ifndef NO_STATIC_REGISTER_SET_H_
#define NO_STATIC_REGISTER_SET_H_

#ifndef BASIC_REGISTER_SET_HPP
#include "metabit\register_set\basic_register_set\basic_register_set.hpp"
#endif

namespace mbl{
	namespace rs{
		namespace ns_rs{
			template<typename _Ty>
			class RegisterSet : public detail::ChangeBits<_Ty>
			{
				typedef detail::ChangeBits<_Ty> Parent;
				public:
				// Конструктор / Designer 
				RegisterSet(_Ty* ptr): Parent(ptr), _my_pos(0xFF) { }
				// Операторы присвоения * * * * * * * * * * * * * * * * * * * *
				inline const RegisterSet& operator=(const bool &val)const {
					*Parent::_register =  (_Ty)(-val);
					return *this;
				}
				inline RegisterSet& operator=(const bool &val) {
					if (_my_pos == 0xFF) {
						*Parent::_register =  (_Ty)(-val);
						return *this;
					}
					else {
						return SetBits((bool)val);
					}
				}
				inline RegisterSet& operator=(const int &val) {
					if (_my_pos == 0xFF) {
						*Parent::_register = val;
						return *this;
					}
					else {
						return SetBits((bool)val);
					}
				}
				template<typename T>
				inline const RegisterSet& operator=(T arg)const{
					Parent::operator=(arg);
					return *this;
				}
				template<typename T>
				inline RegisterSet& operator=(T arg){
					static_cast<const RegisterSet&>(*this).operator=(arg);
					return *this;
				}
				// Операторы преобразования объекта к типу * * * * * * * * * * * * * * 
				template<typename ConvertTy>
				inline operator ConvertTy()const {
					return *Parent::_register;
				}
				template<typename ConvertTy>
				inline operator const ConvertTy(){
					if (_my_pos == 0xFF){
						return *Parent::_register;
					}
					else {
						ConvertTy temp_value = (ConvertTy)((1 << _my_pos) &
						(*Parent::_register));
						_my_pos = 0xFF;
						return temp_value;
					}
				}
				inline operator const bool()const	{
					return (bool)*Parent::_register;
				}
				inline operator bool()	{
					if (_my_pos != 0xFF)	{
						bool return_val = (*Parent::_register & ((_Ty)1 << _my_pos));
						_my_pos = 0xFF;
						return return_val;
					}
					else
					return (bool)*Parent::_register;
				}
				// Оператор выделения бита в позиции 'pos'
				inline RegisterSet& operator[](const size8_t& pos) {
					_my_pos = pos;
					return *this;
				}
				protected:
				inline RegisterSet& SetBits(const bool& val) {
					*Parent::_register = (*Parent::_register &
					~((_Ty)1 << _my_pos)) |				 // |  alternative code set the bit
					(-val & ((_Ty)1 << _my_pos));		 // |  if (val)
					_my_pos = 0xFF;						 // |  *_register |= ((_Ty)1 << _my_pos);
														 // |  else
														 // |  *_register &= ~((_Ty)1 << _my_pos);
					return *this;
				}
				mbl::size_t  _my_pos;
			};
		} // end namespace no static register_set
	}// end namespace register_set	
}

#endif /* NO_STATIC_REGISTERSET_H_ */