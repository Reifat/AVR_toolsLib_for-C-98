/* Класс RegisterSet с статическими свойствами
 * Автор Reifat
 * GitHub Repository - https://github.com/Reifat
 * Последние изменения 30.04.2020.
*/
#ifndef STATIC_REGISTER_SET_HPP
#define STATIC_REGISTER_SET_HPP

#ifndef BASIC_REGISTER_SET_HPP
#include "metabit\register_set\basic_register_set\basic_register_set.hpp"
#endif

namespace mbl{
	namespace rs{
		namespace s_rs {
			template<typename _Ty>
			class RegisterSet : public detail::ChangeBits<_Ty>
			{
				typedef detail::ChangeBits<_Ty> Parent;
				public:
					// Конструктор / Designer 
					RegisterSet(_Ty* ptr): Parent(ptr) { }
						
					// Операторы присвоения * * * * * * * * * * * * * * * * * * * *
					inline const RegisterSet& operator=(const bool &val)const {
						if (_my_pos == 0xFF) {
							*Parent::_register = (_Ty)(-val);
							return *this;
						}
						else {
							return SetBits((bool)val);
						}
					}
					inline RegisterSet& operator=(const bool &val){
						return const_cast<RegisterSet&>(static_cast<const RegisterSet&>(*this).operator=(val));
					}
					inline const RegisterSet& operator=(const int &val)const {
						if (_my_pos == 0xFF) {
							*Parent::_register = val;
							return *this;
						}
						else {
							return SetBits((bool)val);
						}
					}
					inline RegisterSet& operator=(const int &val){
						return const_cast<RegisterSet&>(static_cast<const RegisterSet&>(*this).operator=(val));
					}
					template<typename T>
					inline RegisterSet& operator=(T arg){
						Parent::operator=(arg);
						return *this;
					}
					template<typename T>
					inline const RegisterSet& operator=(T arg)const{
						static_cast<const RegisterSet&>(*this).operator=(arg);
						return *this;
					}
					// Операторы преобразования объекта * * * * * * * * * * * * * * 
					template<typename ConvertTy>
					inline operator const ConvertTy()const {
						if (_my_pos == 0xFF){
							return *Parent::_register;
						}
						else {
							ConvertTy temp_value = (((ConvertTy)1 << _my_pos) & 
							(*Parent::_register));
							_my_pos = 0xFF;
							return temp_value;
						}
					}
					template<typename ConvertTy>
					inline operator ConvertTy(){
						return static_cast<const RegisterSet&>(*this).operator const ConvertTy();
					}
					inline operator const bool() const
					{
						if (_my_pos != 0xFF)	{
							bool return_val = 
							(*Parent::_register & ((_Ty)1 << _my_pos));
							_my_pos = 0xFF;
							return return_val;
						}
						else
						return (bool)*Parent::_register;
					}
					inline operator bool(){
						return static_cast<const RegisterSet&>(*this).operator const bool();
					}
					inline const RegisterSet& operator[](const size8_t& pos)const {
						_my_pos = pos;
						return *this;
					}	
					inline RegisterSet& operator[](const size8_t& pos) {
						return const_cast<RegisterSet&>(static_cast<const RegisterSet&>(*this).operator[](pos));
					}									
				protected:
				inline const RegisterSet& SetBits(const bool& val)const {
					*Parent::_register = (*Parent::_register &
					~((_Ty)1 << _my_pos)) |			    // |  alternative code set the bit
					(-val & ((_Ty)1 << _my_pos));	    // |  if (val)
					_my_pos = 0xFF;					    // |  *_register |= ((_Ty)1 << _my_pos);
													    // |  else
														// |  *_register &= ~((_Ty)1 << _my_pos);
					return *this;
				}
				inline RegisterSet& SetBits(const bool& val) {
					return const_cast<RegisterSet&>(static_cast<const RegisterSet&>(*this).SetBits(val));
				}
				static char _my_pos;
			};
			template<typename _Ty>
			char RegisterSet<_Ty>::_my_pos = 0xFF;	
		} // end namespace static register_set
	}// end namespace register_set
} // namespace mbl

#endif /* STATIC_REGISTER_SET_H_ */