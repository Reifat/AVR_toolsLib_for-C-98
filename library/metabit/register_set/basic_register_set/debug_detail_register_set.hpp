/* Вспомогательные макросы/структуры для класса debug RegisterSet
 * Автор Reifat
 * GitHub Repository - https://github.com/Reifat
 * Последние изменения 30.04.2020.
*/

#ifndef DEBUG_DETAIL_REGISTER_SET_HPP
#define DEBUG_DETAIL_REGISTER_SET_HPP

// Macro for debug RegisterSet
// Macro for validating the entered data type
#define  CHECKTYPE(mess) const bool testType =  mbl::TestType<_Ty, mbl::reg8_t  >::result   |	\
												mbl::TestType<_Ty, mbl::reg16_t >::result   |	\
												mbl::TestType<_Ty, mbl::uint8_t >::result   |	\
												mbl::TestType<_Ty, mbl::uint16_t>::result   |	\
												mbl::TestType<_Ty, mbl::uint32_t>::result   |	\
												mbl::TestType<_Ty, mbl::uint64_t>::result   |	\
												mbl::TestType<_Ty, mbl::int8_t  >::result   |	\
												mbl::TestType<_Ty, mbl::int16_t >::result   |	\
												mbl::TestType<_Ty, mbl::int32_t >::result   |	\
												mbl::TestType<_Ty, mbl::int64_t >::result;		\
						STATIC_ASSERT( testType==true , INVALID_TYPES_ENTERED_VALID_TYPES_##mess)
// Macro for check tolerance range / Проверка на допустимый диапазон
#define CHECKRANGE(Ty,Pos) STATIC_ASSERT((detail::CheckRenge<Ty,Pos>::Result), OUT_OF_RANGE_REGISTER)
#define D_AT(pos)	Cell_Function(mbl::ETVal<mbl::size_t, pos>(),0)
#define D_LAS(pos)	Cell_Function(mbl::ETVal<mbl::size_t, pos>(),1)
#define D_RAS(pos)	Cell_Function(mbl::ETVal<mbl::size_t, pos>(),2)
#define D_FLIP(pos) Cell_Function(mbl::ETVal<mbl::size_t, pos>(),3)
#define D_TEST(pos)	Cell_Function(mbl::ETVal<mbl::size_t, pos>())

namespace mbl{
	namespace d_rs{
		namespace detail{
			// Проверка введенного диапазона
			template<typename T, mbl::size8_t _Pos>
			struct CheckRenge { // need for debug version RegisterSet
				static const bool Result = ((sizeof(T) * 8) > _Pos);
			};
			// Установка класса родителя
			template<typename Ty>
			struct Parent{
				typedef mbl::rs::s_rs::RegisterSet<Ty>    static_;
				typedef mbl::rs::ns_rs::RegisterSet<Ty> n_static_;
			};
		} // end namespace detail
	} // end namespace register_set
}// end namespace mbl


#endif /* DEBUG_DETAIL_REGISTER_SET_HPP */