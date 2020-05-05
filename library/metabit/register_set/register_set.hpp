/* Класс RegisterSet - обертка для регистров, которая упращает работу с его разрядами.
 * Автор Reifat
 * GitHub Repository - https://github.com/Reifat
 * Последние изменения 30.04.2020.
*/
#ifndef REGISTERSET_HPP
#define REGISTERSET_HPP

#ifndef BASIC_REGISTER_SET_HPP
#include "metabit\register_set\basic_register_set\basic_register_set.hpp"
#endif

#ifndef NO_STATIC_REGISTER_SET_H_
#include "metabit\register_set\basic_register_set\no_static_register_set.hpp"
#endif

#ifndef STATIC_REGISTER_SET_HPP
#include "metabit\register_set\basic_register_set\static_register_set.hpp"
#endif

#ifndef DEBUG_DETAIL_REGISTER_SET_HPP
#include "metabit\register_set\basic_register_set\debug_detail_register_set.hpp"
#endif

#ifndef DEBUG_REGISTER_SET_HPP
#include "metabit\register_set\basic_register_set\debug_register_set.hpp"
#endif

#define RegisterSet_static__     rs::s_rs:: RegisterSet
#define RegisterSet_not_static__ rs::ns_rs::RegisterSet

namespace mbl{
	
	template<typename T>
	struct RegisterSet{
		typedef mbl::rs::ns_rs::RegisterSet<T>	n_static_;
		typedef mbl::rs::s_rs::RegisterSet<T>     static_;
	};
	template<typename T>
	struct d_RegisterSet{
		typedef mbl::d_rs::RegisterSet<T,true>		   n_static_;
		typedef mbl::d_rs::RegisterSet<T,false,false>    static_;
	};
}

#endif