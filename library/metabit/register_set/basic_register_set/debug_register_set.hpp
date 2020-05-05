/* Класса debug RegisterSet
 * Автор Reifat
 * GitHub Repository - https://github.com/Reifat
 * Последние изменения 30.04.2020.
*/

#ifndef DEBUG_REGISTER_SET_HPP
#define DEBUG_REGISTER_SET_HPP

#ifndef STATIC_REGISTER_SET_HPP
#include "metabit/register_set/basic_register_set/static_register_set.hpp"
#endif
#ifndef NO_STATIC_REGISTER_SET_H_
#include "metabit\register_set\basic_register_set\no_static_register_set.hpp"
#endif

#ifndef TYPE_TRAITS_HPP
#include "metabit\type_traits\type_traits.hpp"
#endif

#ifndef DEBUG_DETAIL_REGISTER_SET_HPP
#include "debug_detail_register_set.hpp"
#endif

namespace mbl{
	namespace d_rs{
					
		template<typename _Ty,								// ad class for debug_RegisterSet
		bool flag_0 = true,									// 
		bool flag_1 = true>									// flag_0 - choosing a specialty
		class RegisterSet: public							//
		mbl::IfThenElseType<flag_1,							// flag_1 - selecting the parent class
		typename detail::Parent<_Ty>::n_static_ ,			//
		typename detail::Parent<_Ty>::  static_ >::Type {}; //
		
		// general class for Debug RegisterSet
		template<typename _Ty,bool flag>
		class RegisterSet<_Ty,true,flag>: public
		mbl::IfThenElseType<flag, // Condition inherited a type
		typename detail::Parent<_Ty>::n_static_ ,
		typename detail::Parent<_Ty>::  static_ >::Type
		{
			// The inherited type
			typedef typename mbl::IfThenElseType<flag ,
					typename detail::Parent<_Ty>::n_static_ ,
					typename detail::Parent<_Ty>::  static_ >::Type Parent;
			public:
			// Конструктор // Constructor
			RegisterSet(_Ty* ptr):Parent(ptr){
				CHECKTYPE(ALL_signed_and_unsigned_integer_types);
			 }
			
			template<typename T>
			RegisterSet& operator=(T arg){
				Parent::operator=(arg);
				return *this;
			}
			template<typename T>
			const RegisterSet& operator=(T arg)const{
				Parent::operator=(arg);
				return *this;
			}
			
			// Interface for accessing private methods * * * * * * * * * * 
		    template<mbl::size_t pos>
		    bool Cell_Function(const ETVal<mbl::size_t, pos>& obj)const{
				 return test(obj);
			}
		    
			// for const object RegisterSet
			template<mbl::size_t pos>
		    const RegisterSet& Cell_Function(const ETVal<mbl::size_t, pos>& obj, const mbl::size_t& num_func)const {
			    switch (num_func) {
				    case 1:
				    return LAS(ETVal<mbl::size_t, pos>());
				    break;
				    case 2:
				    return RAS(ETVal<mbl::size_t, pos>());
				    break;
				    case 3:
				    return FlipBitInPosition(obj);
				    break;
				    default:
				    return *this;
			    }
		    }
			// for not const object RegisterSet
		    template<mbl::size_t pos>
		    RegisterSet& Cell_Function(const ETVal<mbl::size_t, pos>& obj, const mbl::size_t& num_func) {
			    switch (num_func) {
				    case 0:
				    return operator[](ETVal<mbl::size_t, pos>());
				    break;
				    default: {
					    static_cast<const RegisterSet&>(*this).Cell_Function(obj, num_func);
					    return *this;
				    }
			    }
		    }
			// * * * * * * * * * * * * 			
			private:
			template<size8_t pos>
			RegisterSet& operator[](ETVal<mbl::size_t, pos>) { // Select bit at position
				CHECKRANGE(_Ty, pos); // check range
				Parent::_my_pos = pos;
				return *this;
			}		
			template<size8_t pos>
			bool test(ETVal<mbl::size_t, pos>)const { // test if bit at _Pos is set
				CHECKRANGE(_Ty, pos); // check range
				return (*(Parent::_register) & (1 << pos));
			}
			template<size8_t pos>
			const RegisterSet& LAS(ETVal<mbl::size_t, pos>)const {//registerSet& operator<<=()
				CHECKRANGE(_Ty, pos); // check range
				*(Parent::_register) <<= pos;
				return *this;
			}
			template<size8_t pos>
			const RegisterSet& RAS(ETVal<mbl::size_t, pos>)const { //registerSet& operator>>=()
				CHECKRANGE(_Ty, pos); // check range
				*(Parent::_register) >>= pos;
				return *this;
			}
			template<size8_t pos>
			const RegisterSet& FlipBitInPosition(ETVal<mbl::size_t, pos>)const {
				CHECKRANGE(_Ty, pos); // check range
				*(Parent::_register) ^= ((_Ty)1 << pos);
				return *this;
			}
		};
		
		// Specialization for static class RegisterSet
		template<typename _Ty,bool flag>
		class RegisterSet<_Ty,false,flag> : public
		RegisterSet<_Ty,true,flag> // inherited from  general debug RegisterSet
		{
			typedef RegisterSet<_Ty,true,flag> parent; // The inherited type
			
			public:
				RegisterSet(_Ty* ptr): RegisterSet<_Ty,true,flag>(ptr) {}
					
				template<typename T>
				const RegisterSet& operator=(T arg)const{
					parent::operator=(arg);
					return *this;
				}
				template<typename T>
				RegisterSet& operator=(T arg){
				     parent::operator=(arg);
					 return *this;
				}
				// Interface for accessing private methods * * * * * * * * * * 
			    template<mbl::size_t pos>
			    bool Cell_Function(const ETVal<mbl::size_t, pos>& obj)const{
				    return parent::Cell_Function(obj);
			    }
				// for const object RegisterSet
			    template<mbl::size_t pos>
			    const RegisterSet& Cell_Function(const ETVal<mbl::size_t, pos>& obj, const mbl::size_t& num_func)const {
				    switch (num_func) {
					    case 0:
					    return operator[](obj);
					    break;
					    default: {
							parent::Cell_Function(obj, num_func);
						    return *this;
					    }
				    }
			    }
				// for not const object RegisterSet
			    template<mbl::size_t pos>
			    RegisterSet& Cell_Function(const ETVal<mbl::size_t, pos>& obj, const mbl::size_t& num_func) {
				    static_cast<const RegisterSet&>(*this).Cell_Function(obj, num_func);
				    return *this;
			    }
				// * * * * * * * * * * * * * * * * * * *
			private:
				// Redefinition operator Select bit at position
				template<size8_t pos>
				const RegisterSet& operator[](ETVal<mbl::size_t, pos>)const {
					parent::_my_pos = pos;
					return *this;
				}				
		};
		
	} // end namespace debug static register_set
}//end namespace mbl;

#endif /* DEBUG_STATIC_REGISTER_SET_H_ */