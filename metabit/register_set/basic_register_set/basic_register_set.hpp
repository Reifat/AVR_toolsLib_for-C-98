/* Базовый класс для RegisterSet
 * Автор Reifat
 * GitHub Repository - https://github.com/Reifat
 * Последние изменения 30.04.2020.
*/

#ifndef BASIC_REGISTER_SET_HPP
#define BASIC_REGISTER_SET_HPP

#ifndef	_DEFINITIONS_TYPE_HPP
#include "metabit\definitions_type\definitions_type.hpp"
#endif

#ifndef _METALIB_HPP
#include "metabit\type_traits\type_traits.hpp"
#endif

#ifndef _BITLIB_HPP
#include "metabit\bitlib\bitlib.hpp"
#endif

namespace mbl { // namespace meta bit library
	namespace rs{ // namespace RegisterSet
			namespace detail{ // namespace detail for RegisterSet			
				template<typename _Ty>
				class ChangeBits  // basic class for RegisterSet
				{
					public:
					// Конструктор / Designer
					ChangeBits(_Ty* Register) : _register(Register) { }
					// basic operators * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
					// Операторы присвоения
					template<typename T>
					inline const ChangeBits& operator=(T val)const {
						*_register = (_Ty)val;
						return *this;
					}
					template<typename T>
					inline ChangeBits& operator=(T val) {
						return const_cast<ChangeBits&>(static_cast<const ChangeBits&>(*this).operator=(val));
					}
					inline const ChangeBits& operator=(const ChangeBits& val)const {
						*_register = val.GetValue();
						return *this;
					}
					inline		ChangeBits& operator=(const ChangeBits& val) {
						return const_cast<ChangeBits&>(static_cast<const ChangeBits&>(*this).operator=(val));
					}
					inline ChangeBits& operator=(_Ty* new_addres) {
						_register = new_addres;
						return *this;
					}
					// Логические операторы
					inline const ChangeBits& operator &=(const ChangeBits& right) const {
						*_register &= (_Ty)right;
						return *this;
					}
					inline		ChangeBits& operator &=(const ChangeBits& right) {
						return const_cast<ChangeBits&>(static_cast<const ChangeBits&>(*this).operator&=(right));
					}
					
					inline const ChangeBits& operator|=(const ChangeBits& right) const {
						*_register |= (_Ty)right;
						return *this;
					}
					inline		ChangeBits& operator|=(const ChangeBits& right) {
						return const_cast<ChangeBits&>(static_cast<const ChangeBits&>(*this).operator|=(right));
					}
					
					inline const ChangeBits& operator^=(const ChangeBits& right) const {
						*_register ^= (_Ty)right;
						return *this;
					}
					inline		ChangeBits& operator^=(const ChangeBits& right) {
						return const_cast<ChangeBits&>(static_cast<const ChangeBits&>(*this).operator^=(right));
					}
					
					inline const ChangeBits& operator<<=(const size8_t& pos)const {
						*_register <<= pos;
						return *this;
					}
					inline		ChangeBits& operator<<=(const size8_t& pos) {
						return const_cast<ChangeBits&>(static_cast<const ChangeBits&>(*this).operator<<=(pos));
					}
					inline const ChangeBits& operator>>=(const size8_t& pos)const {
						*_register >>= pos;
						return *this;
					}
					inline		 ChangeBits& operator>>=(const size8_t& pos) {
						return const_cast<ChangeBits&>(static_cast<const ChangeBits&>(*this).operator>>=(pos));
					}
					// Арифметические операторы
					inline const ChangeBits& operator++()const { 
						++(*_register); return *this;
						 }
					inline const ChangeBits& operator++(int)const { 
						(*_register)++; return *this;
						 }
					inline const ChangeBits& operator--()const {
						 --(*_register); return *this;
						  }
					inline const ChangeBits& operator--(int)const {
						 (*_register)--; return *this;
						  }
					inline ChangeBits& operator++() {
						return const_cast<ChangeBits&>(static_cast<const ChangeBits&>(*this).operator++());
					}
					inline ChangeBits& operator++(int) {
						return const_cast<ChangeBits&>(static_cast<const ChangeBits&>(*this).operator++(1));
					}
					inline  ChangeBits& operator--() {
						return const_cast<ChangeBits&>(static_cast<const ChangeBits&>(*this).operator--());
					}
					inline ChangeBits& operator--(int) {
						return const_cast<ChangeBits&>(static_cast<const ChangeBits&>(*this).operator--(1));
					}	
										  
					template<typename T>
					inline const ChangeBits& operator+=(const T& right)const { 
						*_register += right; 
						return *this; 
						}
					template<typename T>
					inline const ChangeBits& operator-=(const T& right)const {
						*_register -= right;
						return *this;
					}
					template<typename T>
					inline const ChangeBits& operator*=(const T& right)const {
						*_register *= right;
						return *this;
					}
					template<typename T>
					inline const ChangeBits& operator/=(const T& right)const {
						*_register /= right;
						return *this;
					}
					template<typename T>
					inline const ChangeBits& operator%=(const T& right)const {
						*_register %= right;
						return *this;
					}
					template<typename T>
					inline ChangeBits& operator+=(const T& right) {
						return const_cast<ChangeBits&>(static_cast<const ChangeBits&>(*this).operator+=(right));
					}
					template<typename T>
					inline ChangeBits& operator-=(const T& right) {
						return const_cast<ChangeBits&>(static_cast<const ChangeBits&>(*this).operator-=(right));
					}
					template<typename T>
					inline ChangeBits& operator*=(const T& right) {
						return const_cast<ChangeBits&>(static_cast<const ChangeBits&>(*this).operator*=(right));
					}
					template<typename T>
					inline ChangeBits& operator/=(const T& right) {
						return const_cast<ChangeBits&>(static_cast<const ChangeBits&>(*this).operator/=(right));
					}
					template<typename T>
					inline ChangeBits& operator%=(const T& right) {
						return const_cast<ChangeBits&>(static_cast<const ChangeBits&>(*this).operator%=(right));
					}
					// metodth * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
					// Изменение адреса указателя
					inline ChangeBits& ChangeAddres(_Ty* new_addres) {
						_register = new_addres;
						return *this;
					}
					inline const _Ty GetValue()const {
						return *_register;
					}
					// Установка или сброс с разряда a по b
					inline const ChangeBits& SetInRange(const size8_t &at, const size8_t &to, bool val = true)const {
						*_register = SetInRange(*_register, at, to, val);
						return *this;
					}
					inline		ChangeBits& SetInRange(const size8_t &at, const size8_t &to, bool val = true){
						return const_cast<ChangeBits&>(static_cast<const ChangeBits&>(*this).SetInRange(at,to,val));
					}
					
					inline const ChangeBits& SetInPos(const size8_t &pos, const bool &val = true)const {
						*_register = (*_register & ~((_Ty)1 <<pos)) | (-val & ((_Ty)1 << pos));
						return *this;
					}
					inline		 ChangeBits& SetInPos(const size8_t &pos, const bool &val = true) {
						return const_cast<ChangeBits&>(static_cast<const ChangeBits&>(*this).SetInPos(pos,val));
					}
					// Установка или сброс всех битов в регистре
					inline const ChangeBits& Set(bool val = true)const {
						*_register = (_Ty)(-val);;
						return *this;
					}
					inline		 ChangeBits& Set(bool val = true) {
						return const_cast<ChangeBits&>(static_cast<const ChangeBits&>(*this).Set(val));
					}
					// Сброс всех битов
					inline const ChangeBits& Reset() const	{
						*_register = (_Ty)0;
						return *this;
					}
					inline ChangeBits& Reset() {
						return const_cast<ChangeBits&>(static_cast<const ChangeBits&>(*this).Reset());
					}
					// Проверяет, чтобы все биты были установлены в true
					inline const bool All()const {
						return (*_register & ~(_Ty)0);
					}
					// Проверяет, чтобы хотя бы один бит был установлен в true
					inline const bool Any()const 	{
						return (*_register != (_Ty)0);
					}
					// Проверяет, чтобы никакой из битов не был установлен в true
					inline const bool None()const {
						return !Any();
					}
					// Возвращает размер регистра
					inline const size8_t size()const {
						return SizeTy<_Ty>::_Size;
					}
					// Инвертирует все биты
					inline const ChangeBits& Flip()const {
						*_register = ~(*_register);
						return *this;
					}
					inline ChangeBits& Flip() {
						return const_cast<ChangeBits&>(static_cast<const ChangeBits&>(*this).Flip());
					}
					// Возвращает количество битов, которые установлены в true
					inline const size8_t count()const {
						return mbl::Count<_Ty>(*_register);
					}
					inline const ChangeBits& FlipBitInPosition(const size8_t &pos)const {
						*_register ^= (1 << pos);
						return *this;
					}
					inline		 ChangeBits& FlipBitInPosition(const size8_t &pos) {
						return const_cast<ChangeBits&>(static_cast<const ChangeBits&>(*this).FlipBitInPosition(pos));
					}
					// test if bit at _Pos is set
					inline const bool test(size8_t pos)const 	{
						return (*_register & (1 << pos));
					}
					protected:
					_Ty*	  _register;
				};
			} // end namespace detail
	} // end namespace RegisterSet
} // end namespace mbl

#endif /* ABSTRACT_REGISTERSET_H_ */