/* Функция инициализации объектов класса RegisterSet
 * Автор Reifat
 * GitHub Repository - https://github.com/Reifat
 * Последние изменения 30.04.2020.
*/
#ifndef REGISTER_INIT_HPP
#define REGISTER_INIT_HPP

#ifndef REGISTERSET_HPP
#include "metabit\register_set\registerset.hpp"
#endif

#ifndef BITLIB_HPP
#include "metabit\bitlib\bitlib.hpp"
#endif

#define BitInit_static__  mbl::s_bi::BitInit
#define BitInit__		  mbl::ns_bi::BitInit


namespace mbl // namespace meta bit library
{
	
namespace detail{
	template<typename Ty, mbl::size_t size>
	inline Ty SetBit(int *ptr)	{
		Ty list_bit = 0;
		bool flag = (bool)*ptr;
		for(unsigned char n = (size-1); n != 0xFF; n--){
			list_bit |= (-flag & ((Ty)1 << n));
			ptr++;
			flag = (bool)*ptr;
		}
		return list_bit;
	}
} // end namespace detail

template<class Ty>
inline Ty BitInit(int arg,...) {
	return mbl::detail::SetBit<Ty,mbl::SizeTy<Ty>::_Size>(&arg);
}

namespace s_bi{
	
	using mbl::BitInit; // Initializing bits in a variable

	template<class Ty, Ty*const* ptr>
	inline typename mbl::RegisterSet<Ty>::static_ BitInit(int arg,...) {
		**ptr = mbl::detail::SetBit<Ty,mbl::SizeTy<Ty>::_Size>(&arg);
		return typename mbl::RegisterSet<Ty>::static_ (*ptr);
	}
}
namespace ns_bi{

	using mbl::BitInit; // Initializing bits in a variable
	
	template<class Ty, Ty*const* ptr>
	inline typename mbl::RegisterSet<Ty>::n_static_ BitInit(int arg,...) {
		**ptr = mbl::detail::SetBit<Ty,mbl::SizeTy<Ty>::_Size>(&arg);
		return typename mbl::RegisterSet<Ty>::n_static_(*ptr);
	}
}

} // end namespace meta bit library
#endif