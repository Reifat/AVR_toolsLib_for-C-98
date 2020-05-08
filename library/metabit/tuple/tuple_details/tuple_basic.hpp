#ifndef METABIT_TUPLE_BASIC_HPP
#define METABIT_TUPLE_BASIC_HPP

#include "metabit\type_traits\type_traits.hpp"
#include "metabit\type_traits\remove_cv.hpp"
#include "metabit\utility\ref.hpp"

#ifndef NO_TUPLE_MACRO
#define NO_TUPLE_MACRO 
#define TElement(N) metabit::ETVal<unsigned, N>{}
#define T_0     TElement(0)
#define T_1     TElement(1)
#define T_2     TElement(2)
#define T_3     TElement(3)
#define T_4     TElement(4)
#define T_5     TElement(5)
#define T_6     TElement(6)
#define T_7     TElement(7)
#define T_8     TElement(8)
#define T_9     TElement(9)
#define T_10    TElement(10)
#define T_11    TElement(11)
#define T_12    TElement(12)
#define T_13    TElement(13)
#define T_14    TElement(14)
#define T_15    TElement(15)
#endif

namespace mbl // namespace meta bit library
 {
	namespace Tuples {
		
		namespace detail{
			inline const Nil NilType() { return Nil(); }
		} // end namespace detail

		template<typename TyHead, typename TyTail = Nil>
		class Cons;
		
		namespace detail{
			template <class T> 
			struct access_traits {
				typedef const T& const_type;
				typedef		  T& non_const_type;
				typedef const typename mbl::remove_cv<T>::type& parameter_type;
			};
			
			template<unsigned char N>
			class TupleGetElement {
			public:
				template<typename Head, typename Tail>
				static typename access_traits<
					typename NthElement<Cons<Head, Tail>, N>::Element
				>::const_type
					Apply(const Cons<Head, Tail>& t) {
					return TupleGetElement<N - 1>::Apply(t.getTail());
				}
			};
			template<>
			class TupleGetElement<0> {
			public:
				template<typename Head, typename Tail>
				static typename access_traits<
					typename NthElement<Cons<Head, Tail>, 0>::Element
				>::const_type
					Apply(const Cons<Head, Tail>& t){return t.getHead();}
			};
		}// end namespace detail
		
		template<int N, class Head, class Tail>
		inline typename detail::access_traits<
			typename NthElement<Cons<Head, Tail>, N>::Element
		>::non_const_type
			Get(Cons<Head, Tail>& t)
		{
			typedef typename NthElement<Cons<Head, Tail>, N>::Element const_element;
			return const_cast<const_element&>(detail::TupleGetElement<N>::Apply(t));
		}
		template<int N, class Head, class Teil>
		inline typename detail::access_traits<
			typename NthElement<Cons<Head, Teil>, N>::Element
		>::const_type
			Get(const Cons<Head, Teil>& t)
		{
			return detail::TupleGetElement<N>::Apply(t);
		}

		// Basic representation of a tuple
		template<typename TyHead, typename TyTail>
		class Cons :public TList<TyHead, TyTail>
		{
			TyHead _head;
			TyTail _tail;
		public:
			TyHead& getHead() { return _head; }
			TyTail& getTail() { return _tail; }
			const TyHead& getHead()const { return _head; }
			const TyTail& getTail()const { return _tail; }
			// constructors Cons
			Cons() : _head(), _tail() {}
			Cons(const TyHead& head, const TyTail& tail) : _head(head), _tail(tail) {}

			template<class T0, class T1, class T2, class T3, class T4,
				class T5, class T6, class T7, class T8, class T9,
				class T10, class T11, class T12, class T13, class T14>
				Cons(T0& arg0, T1& arg1, T2& arg2, T3& arg3, T4& arg4,
					T5& arg5, T6& arg6, T7& arg7, T8& arg8, T9& arg9,
					T10& arg10, T11& arg11, T12& arg12, T13& arg13, T14& arg14) :
				_head(arg0), _tail(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10,
					arg11, arg12, arg13, arg14, detail::NilType()) {}

			template<class T1, class T2, class T3, class T4, class T5,
				class T6, class T7, class T8, class T9, class T10,
				class T11, class T12, class T13, class T14>
				Cons(const Nil&/*arg0*/, T1& arg1, T2& arg2, T3& arg3, T4& arg4,
					T5& arg5, T6& arg6, T7& arg7, T8& arg8, T9& arg9,
					T10& arg10, T11& arg11, T12& arg12, T13& arg13, T14& arg14) :
				_head(), _tail(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10,
					arg11, arg12, arg13, arg14, detail::NilType()) {}

			template<class Head, class Tail>
			Cons(const Cons<Head, Tail>& tuple) : 
				_head(tuple.getHead()), _tail(tuple.getTail()) {}

			// operators and metodth
			template<class TyHead2, class TyTeil2>
			Cons& operator=(const Cons<TyHead2, TyTeil2>& right) {
				_head = right.getHead(); _tail = right.getTail(); return *this;
			}
			Cons& operator=(const Cons& right) {
				_head = right.getHead(); _tail = right.getTail(); return *this;
			}

			template<unsigned char N>
			typename detail::access_traits<
				typename NthElement<Cons<TyHead, TyTail>, N>::Element
			>::non_const_type operator[](const ETVal<unsigned, N>&) {
				return Get<N>(*this);
			}
			template<unsigned char N>
			typename detail::access_traits<
				typename NthElement<Cons<TyHead, TyTail>, N>::Element
			>::const_type operator[](const ETVal<unsigned, N>&)const {
				return Get<N>(*this);
			}
			template<unsigned char N>
			typename detail::access_traits<
				typename NthElement<Cons<TyHead, TyTail>, N>::Element
			>::non_const_type
				get() {
				return Get<N>(*this);
			}
			template<unsigned char N>
			typename detail::access_traits<
				typename NthElement<Cons<TyHead, TyTail>, N>::Element
			>::const_type
				get()const {
				return Get<N>(*this);
			}
		};

		template<typename TyHead>
		class Cons<TyHead, Nil> :public TList<TyHead, Nil>
		{
			typedef Cons<TyHead, Nil> Self_Type;
			typedef Nil Tail_Type;

			TyHead _head;
		public:
			TyHead& getHead() { return _head; }
			Tail_Type& getTail() { return detail::NilType(); }
			const TyHead& getHead()const { return _head; }
			const Tail_Type& getTail()const { return detail::NilType(); }
			// Constructors
			Cons() : _head() {}
			Cons(const TyHead& arg0, const Nil & = detail::NilType()) : _head(arg0) {}
			template<class T0>
			Cons(T0& arg0, const Nil&, const Nil&, const Nil&, const Nil&, const Nil&,
				const Nil&, const Nil&, const Nil&, const Nil&, const Nil&,
				const Nil&, const Nil&, const Nil&, const Nil&)
				: _head(arg0) {}
			Cons(const Nil&, const Nil&, const Nil&, const Nil&,
				const Nil&, const Nil&, const Nil&, const Nil&,
				const Nil&, const Nil&)
				: _head() {}

			template <class Tail>
			Cons(const Cons<Tail, Nil>& tuple) : _head(tuple.getHead()) {}

			// operators and metodth
			template<class TyHead2>
			Cons& operator=(const Cons<TyHead2, Nil>& right) {
				_head = right.getHead(); return *this;
			}

			Cons& operator=(const Cons& right) {
				_head = right.getHead();  return *this;
			}

			template<unsigned char N>
			typename detail::access_traits<
				typename NthElement<Self_Type, N>::Element
			>::non_const_type
			 operator[](const ETVal<unsigned, N>&) {
				return Get<N>(*this);
			}
			template<unsigned char N>
			typename detail::access_traits<
				typename NthElement<Self_Type, N>::Element
			>::const_type
				operator[](const ETVal<unsigned, N>&)const {
				return Get<N>(*this);
			}
			template<unsigned char N>
			typename detail::access_traits<
				typename NthElement<Self_Type, N>::Element
			>::non_const_type
				get() {
				return Get<N>(*this);
			}
			template<unsigned char N>
			typename detail::access_traits<
				typename NthElement<Self_Type, N>::Element
			>::const_type
				get()const {
				return Get<N>(*this);
			}

		};
		
		namespace detail
		{
				template<class T0, class T1, class T2, class T3, class T4,
				class T5, class T6, class T7, class T8, class T9,
				class T10, class T11, class T12, class T13, class T14>
				struct Map_Tuple_To_Cons
				{
					typedef Cons<T0,
					typename Map_Tuple_To_Cons<T1, T2, T3, T4, T5,
					T6, T7, T8, T9, T10, T11, T12, T13, T14, Nil>::type
					> type;
				};

				// The empty tuple is a null_type
				template <>
				struct Map_Tuple_To_Cons<Nil, Nil, Nil, Nil, Nil, Nil, Nil,
				Nil, Nil, Nil, Nil, Nil, Nil, Nil, Nil>
				{
					typedef Nil type;
				};	
		} // end namespace detail

		// -- tuple ------------------------------------------------------
		template <class T0 = Nil, class T1 = Nil, class T2 = Nil, class T3 = Nil, class T4 = Nil, class T5 = Nil, class T6 = Nil, class T7 = Nil,
			class T8 = Nil, class T9 = Nil, class T10 = Nil, class T11 = Nil, class T12 = Nil, class T13 = Nil, class T14 = Nil>
			class Tuple : public detail::Map_Tuple_To_Cons<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14>::type
		{
			// 
			typedef typename detail::Map_Tuple_To_Cons<T0, T1, T2, T3, T4, T5, T6, T7,
				T8, T9, T10, T11, T12, T13, T14>::type Inherited;
			typedef typename Inherited::Head Head_Type;
			typedef typename Inherited::Tail Tail_Type;

		public:
			// constructors of Tuple
			Tuple() {}
			explicit Tuple(typename detail::access_traits<T0>::parameter_type arg0)
				: Inherited(arg0, detail::NilType(), detail::NilType(), detail::NilType(), detail::NilType(),
					detail::NilType(), detail::NilType(), detail::NilType(), detail::NilType(), detail::NilType(),
					detail::NilType(), detail::NilType(), detail::NilType(), detail::NilType(), detail::NilType()) {}

			explicit Tuple(
				typename detail::access_traits<T0>::parameter_type arg0,
				typename detail::access_traits<T1>::parameter_type arg1)
				: Inherited(arg0, arg1, detail::NilType(), detail::NilType(), detail::NilType(),
					detail::NilType(), detail::NilType(), detail::NilType(), detail::NilType(), detail::NilType(),
					detail::NilType(), detail::NilType(), detail::NilType(), detail::NilType(), detail::NilType()) {}

			explicit Tuple(
				typename detail::access_traits<T0>::parameter_type arg0,
				typename detail::access_traits<T1>::parameter_type arg1,
				typename detail::access_traits<T2>::parameter_type arg2)
				: Inherited(arg0, arg1, arg2, detail::NilType(), detail::NilType(),
					detail::NilType(), detail::NilType(), detail::NilType(), detail::NilType(), detail::NilType(),
					detail::NilType(), detail::NilType(), detail::NilType(), detail::NilType(), detail::NilType()) {}

			explicit Tuple(
				typename detail::access_traits<T0>::parameter_type arg0,
				typename detail::access_traits<T1>::parameter_type arg1,
				typename detail::access_traits<T2>::parameter_type arg2,
				typename detail::access_traits<T2>::parameter_type arg3)
				: Inherited(arg0, arg1, arg2, arg3, detail::NilType(),
					detail::NilType(), detail::NilType(), detail::NilType(), detail::NilType(), detail::NilType(),
					detail::NilType(), detail::NilType(), detail::NilType(), detail::NilType(), detail::NilType()) {}

			explicit Tuple(
				typename detail::access_traits<T0>::parameter_type arg0,
				typename detail::access_traits<T1>::parameter_type arg1,
				typename detail::access_traits<T2>::parameter_type arg2,
				typename detail::access_traits<T2>::parameter_type arg3,
				typename detail::access_traits<T2>::parameter_type arg4)
				: Inherited(arg0, arg1, arg2, arg3, arg4,
					detail::NilType(), detail::NilType(), detail::NilType(), detail::NilType(), detail::NilType(),
					detail::NilType(), detail::NilType(), detail::NilType(), detail::NilType(), detail::NilType()) {}


			explicit Tuple(
				typename detail::access_traits<T0>::parameter_type arg0,
				typename detail::access_traits<T1>::parameter_type arg1,
				typename detail::access_traits<T2>::parameter_type arg2,
				typename detail::access_traits<T2>::parameter_type arg3,
				typename detail::access_traits<T2>::parameter_type arg4,
				typename detail::access_traits<T2>::parameter_type arg5)
				: Inherited(arg0, arg1, arg2, arg3, arg4, arg5, detail::NilType(), detail::NilType(),
					detail::NilType(), detail::NilType(), detail::NilType(), detail::NilType(), 
					detail::NilType(), detail::NilType(), detail::NilType()) {}

			explicit Tuple(
				typename detail::access_traits<T0>::parameter_type arg0,
				typename detail::access_traits<T1>::parameter_type arg1,
				typename detail::access_traits<T2>::parameter_type arg2,
				typename detail::access_traits<T2>::parameter_type arg3,
				typename detail::access_traits<T2>::parameter_type arg4,
				typename detail::access_traits<T2>::parameter_type arg5,
				typename detail::access_traits<T2>::parameter_type arg6)
				: Inherited(arg0, arg1, arg2, arg3, arg4, arg5, arg6, detail::NilType(),
					detail::NilType(), detail::NilType(), detail::NilType(), detail::NilType(),
					detail::NilType(), detail::NilType(), detail::NilType()) {}

			explicit Tuple(
				typename detail::access_traits<T0>::parameter_type arg0,
				typename detail::access_traits<T1>::parameter_type arg1,
				typename detail::access_traits<T2>::parameter_type arg2,
				typename detail::access_traits<T2>::parameter_type arg3,
				typename detail::access_traits<T2>::parameter_type arg4,
				typename detail::access_traits<T2>::parameter_type arg5,
				typename detail::access_traits<T2>::parameter_type arg6,
				typename detail::access_traits<T2>::parameter_type arg7)
				: Inherited(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7,
					detail::NilType(), detail::NilType(), detail::NilType(), detail::NilType(),
					 detail::NilType(), detail::NilType(), detail::NilType()) {}

			explicit Tuple(
				typename detail::access_traits<T0>::parameter_type arg0,
				typename detail::access_traits<T1>::parameter_type arg1,
				typename detail::access_traits<T2>::parameter_type arg2,
				typename detail::access_traits<T2>::parameter_type arg3,
				typename detail::access_traits<T2>::parameter_type arg4,
				typename detail::access_traits<T2>::parameter_type arg5,
				typename detail::access_traits<T2>::parameter_type arg6,
				typename detail::access_traits<T2>::parameter_type arg7,
				typename detail::access_traits<T2>::parameter_type arg8)
				: Inherited(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7,
					arg8, detail::NilType(), detail::NilType(), detail::NilType(), 
					detail::NilType(), detail::NilType(), detail::NilType()) {}

			explicit Tuple(
				typename detail::access_traits<T0>::parameter_type arg0,
				typename detail::access_traits<T1>::parameter_type arg1,
				typename detail::access_traits<T2>::parameter_type arg2,
				typename detail::access_traits<T2>::parameter_type arg3,
				typename detail::access_traits<T2>::parameter_type arg4,
				typename detail::access_traits<T2>::parameter_type arg5,
				typename detail::access_traits<T2>::parameter_type arg6,
				typename detail::access_traits<T2>::parameter_type arg7,
				typename detail::access_traits<T2>::parameter_type arg8,
				typename detail::access_traits<T2>::parameter_type arg9)
				: Inherited(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7,
					arg8, arg9, detail::NilType(), detail::NilType(), detail::NilType(), 
					detail::NilType(), detail::NilType()) {}

			explicit Tuple(
				typename detail::access_traits<T0>::parameter_type arg0,
				typename detail::access_traits<T1>::parameter_type arg1,
				typename detail::access_traits<T2>::parameter_type arg2,
				typename detail::access_traits<T2>::parameter_type arg3,
				typename detail::access_traits<T2>::parameter_type arg4,
				typename detail::access_traits<T2>::parameter_type arg5,
				typename detail::access_traits<T2>::parameter_type arg6,
				typename detail::access_traits<T2>::parameter_type arg7,
				typename detail::access_traits<T2>::parameter_type arg8,
				typename detail::access_traits<T2>::parameter_type arg9,
				typename detail::access_traits<T2>::parameter_type arg10)
				: Inherited(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7,
					arg8, arg9, arg10, detail::NilType(), detail::NilType(),
					 detail::NilType(), detail::NilType()) {}

			explicit Tuple(
				typename detail::access_traits<T0>::parameter_type arg0,
				typename detail::access_traits<T1>::parameter_type arg1,
				typename detail::access_traits<T2>::parameter_type arg2,
				typename detail::access_traits<T2>::parameter_type arg3,
				typename detail::access_traits<T2>::parameter_type arg4,
				typename detail::access_traits<T2>::parameter_type arg5,
				typename detail::access_traits<T2>::parameter_type arg6,
				typename detail::access_traits<T2>::parameter_type arg7,
				typename detail::access_traits<T2>::parameter_type arg8,
				typename detail::access_traits<T2>::parameter_type arg9,
				typename detail::access_traits<T2>::parameter_type arg10,
				typename detail::access_traits<T2>::parameter_type arg11)
				: Inherited(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7,
					arg8, arg9, arg10, arg11, detail::NilType(), detail::NilType(), detail::NilType()) {}

			explicit Tuple(
				typename detail::access_traits<T0>::parameter_type arg0,
				typename detail::access_traits<T1>::parameter_type arg1,
				typename detail::access_traits<T2>::parameter_type arg2,
				typename detail::access_traits<T2>::parameter_type arg3,
				typename detail::access_traits<T2>::parameter_type arg4,
				typename detail::access_traits<T2>::parameter_type arg5,
				typename detail::access_traits<T2>::parameter_type arg6,
				typename detail::access_traits<T2>::parameter_type arg7,
				typename detail::access_traits<T2>::parameter_type arg8,
				typename detail::access_traits<T2>::parameter_type arg9,
				typename detail::access_traits<T2>::parameter_type arg10,
				typename detail::access_traits<T2>::parameter_type arg11,
				typename detail::access_traits<T2>::parameter_type arg12)
				: Inherited(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7,
					arg8, arg9, arg10, arg11, arg12, detail::NilType(), detail::NilType()) {}

			explicit Tuple(
				typename detail::access_traits<T0>::parameter_type arg0,
				typename detail::access_traits<T1>::parameter_type arg1,
				typename detail::access_traits<T2>::parameter_type arg2,
				typename detail::access_traits<T2>::parameter_type arg3,
				typename detail::access_traits<T2>::parameter_type arg4,
				typename detail::access_traits<T2>::parameter_type arg5,
				typename detail::access_traits<T2>::parameter_type arg6,
				typename detail::access_traits<T2>::parameter_type arg7,
				typename detail::access_traits<T2>::parameter_type arg8,
				typename detail::access_traits<T2>::parameter_type arg9,
				typename detail::access_traits<T2>::parameter_type arg10,
				typename detail::access_traits<T2>::parameter_type arg11,
				typename detail::access_traits<T2>::parameter_type arg12,
				typename detail::access_traits<T2>::parameter_type arg13)
				: Inherited(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7,
					arg8, arg9, arg10, arg11, arg12, arg13, detail::NilType()) {}

			explicit Tuple(
				typename detail::access_traits<T0>::parameter_type arg0,
				typename detail::access_traits<T1>::parameter_type arg1,
				typename detail::access_traits<T2>::parameter_type arg2,
				typename detail::access_traits<T2>::parameter_type arg3,
				typename detail::access_traits<T2>::parameter_type arg4,
				typename detail::access_traits<T2>::parameter_type arg5,
				typename detail::access_traits<T2>::parameter_type arg6,
				typename detail::access_traits<T2>::parameter_type arg7,
				typename detail::access_traits<T2>::parameter_type arg8,
				typename detail::access_traits<T2>::parameter_type arg9,
				typename detail::access_traits<T2>::parameter_type arg10,
				typename detail::access_traits<T2>::parameter_type arg11,
				typename detail::access_traits<T2>::parameter_type arg12,
				typename detail::access_traits<T2>::parameter_type arg13,
				typename detail::access_traits<T2>::parameter_type arg14)
				: Inherited(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7,
					arg8, arg9, arg10, arg11, arg12, arg13, arg14) {}

			template<class Head, class Teil>
			Tuple(const Cons<Head, Teil>& tuple) : Inherited(tuple) {}

			template<class Head, class Teil>
			Tuple& operator=(const Cons<Head, Teil>& tuple) {
				Inherited::operator=(tuple);
				return *this;
			}


		};
		// The empty tuple
		template <>
		class Tuple<Nil, Nil, Nil, Nil, Nil, Nil, Nil, Nil, Nil, Nil, Nil, Nil, Nil, Nil, Nil> :public Nil
		{
		public:
			typedef Nil Inherited;
		};

		// Фрагмент кода взят из библиотеки - boost (Автор Doug Gregor)
		// The code snippet is taken from the library - boost (by Doug Gregor)
		// Swallows any assignment  
		namespace detail {
			struct swallow_assign;
			typedef void (swallow_assign::* Ignore_Ty)();
			struct swallow_assign {
				swallow_assign(Ignore_Ty(*)(Ignore_Ty)) {}
				template<typename T>
				swallow_assign const& operator=(const T&) const {
					return *this;
				}
			};
		}
		inline detail::Ignore_Ty Ignore(detail::Ignore_Ty) { return 0; }
		
		namespace detail {
			template<class T>
			class Generate_Error;

			template<class T>
			struct Make_Tuple_Traits {
				typedef T type;
			};

			template<class T>
			struct Make_Tuple_Traits<T&> {
				typedef typename
				Generate_Error<T&>::
				do_not_use_with_reference_type error;
			};

			template<class T, int n>  struct Make_Tuple_Traits <T[n]> {
				typedef const T(&type)[n];
			};

			template<class T, int n>
			struct Make_Tuple_Traits<const T[n]> {
				typedef const T(&type)[n];
			};

			template<class T, int n>  struct Make_Tuple_Traits<volatile T[n]> {
				typedef const volatile T(&type)[n];
			};

			template<class T, int n>
			struct Make_Tuple_Traits<const volatile T[n]> {
				typedef const volatile T(&type)[n];
			};

			template<class T>
			struct Make_Tuple_Traits<mbl::reference_wrapper<T> > {
				typedef T& type;
			};

			template<class T>
			struct Make_Tuple_Traits<const mbl::reference_wrapper<T> > {
				typedef T& type;
			};

			template<>
			struct Make_Tuple_Traits<Ignore_Ty(Ignore_Ty)> {
				typedef swallow_assign type;
			};
			template <
				class T0 = Nil, class T1 = Nil, class T2 = Nil,
				class T3 = Nil, class T4 = Nil, class T5 = Nil,
				class T6 = Nil, class T7 = Nil, class T8 = Nil,
				class T9 = Nil, class T10 = Nil, class T11 = Nil,
				class T12 = Nil, class T13 = Nil, class T14 = Nil
				>
			struct Make_Tuple_Mapper {
			typedef	Tuple<
					typename Make_Tuple_Traits<T0>::type,
					typename Make_Tuple_Traits<T1>::type,
					typename Make_Tuple_Traits<T2>::type,
					typename Make_Tuple_Traits<T3>::type,
					typename Make_Tuple_Traits<T4>::type,
					typename Make_Tuple_Traits<T5>::type,
					typename Make_Tuple_Traits<T6>::type,
					typename Make_Tuple_Traits<T7>::type,
					typename Make_Tuple_Traits<T8>::type,
					typename Make_Tuple_Traits<T9>::type,
					typename Make_Tuple_Traits<T10>::type,
					typename Make_Tuple_Traits<T11>::type,
					typename Make_Tuple_Traits<T12>::type,
					typename Make_Tuple_Traits<T13>::type,
					typename Make_Tuple_Traits<T14>::type> type;
			};
		} // end namespace detail

		inline Tuple<> Make_Tuple() {
			return Tuple<>();
		}

		template<class T0>
		inline typename detail::Make_Tuple_Mapper<T0>::type
			Make_Tuple(const T0& t0) {
			typedef typename detail::Make_Tuple_Mapper<T0>::type t;
			return t(t0);
		}

		template<class T0, class T1>
		inline typename detail::Make_Tuple_Mapper<T0, T1>::type
			Make_Tuple(const T0& t0, const T1& t1) {
			typedef typename detail::Make_Tuple_Mapper<T0, T1>::type t;
			return t(t0, t1);
		}

		template<class T0, class T1, class T2>
		inline typename detail::Make_Tuple_Mapper<T0, T1, T2>::type
			Make_Tuple(const T0& t0, const T1& t1, const T2& t2) {
			typedef typename detail::Make_Tuple_Mapper<T0, T1, T2>::type t;
			return t(t0, t1, t2);
		}

		template<class T0, class T1, class T2, class T3>
		inline typename detail::Make_Tuple_Mapper<T0, T1, T2, T3>::type
			Make_Tuple(const T0& t0, const T1& t1, const T2& t2, const T3& t3) {
			typedef typename detail::Make_Tuple_Mapper<T0, T1, T2, T3>::type t;
			return t(t0, t1, t2, t3);
		}

		template<class T0, class T1, class T2, class T3, class T4>
		inline typename detail::Make_Tuple_Mapper<T0, T1, T2, T3, T4>::type
			Make_Tuple(const T0& t0, const T1& t1, const T2& t2, const T3& t3,
				const T4& t4) {
			typedef typename detail::Make_Tuple_Mapper<T0, T1, T2, T3, T4>::type t;
			return t(t0, t1, t2, t3, t4);
		}

		template<class T0, class T1, class T2, class T3, class T4, class T5>
		inline typename detail::Make_Tuple_Mapper<T0, T1, T2, T3, T4, T5>::type
			Make_Tuple(const T0& t0, const T1& t1, const T2& t2, const T3& t3,
				const T4& t4, const T5& t5) {
			typedef typename detail::Make_Tuple_Mapper<T0, T1, T2, T3, T4, T5>::type t;
			return t(t0, t1, t2, t3, t4, t5);
		}

		template<class T0, class T1, class T2, class T3, class T4, class T5, class T6>
		inline typename detail::Make_Tuple_Mapper<T0, T1, T2, T3, T4, T5, T6>::type
			Make_Tuple(const T0& t0, const T1& t1, const T2& t2, const T3& t3,
				const T4& t4, const T5& t5, const T6& t6) {
			typedef typename detail::Make_Tuple_Mapper
				<T0, T1, T2, T3, T4, T5, T6>::type t;
			return t(t0, t1, t2, t3, t4, t5, t6);
		}

		template<class T0, class T1, class T2, class T3, class T4, class T5, class T6,
			class T7>
			inline typename detail::Make_Tuple_Mapper<T0, T1, T2, T3, T4, T5, T6, T7>::type
			Make_Tuple(const T0& t0, const T1& t1, const T2& t2, const T3& t3,
				const T4& t4, const T5& t5, const T6& t6, const T7& t7) {
			typedef typename detail::Make_Tuple_Mapper
				<T0, T1, T2, T3, T4, T5, T6, T7>::type t;
			return t(t0, t1, t2, t3, t4, t5, t6, t7);
		}

		template<class T0, class T1, class T2, class T3, class T4, class T5, class T6,
			class T7, class T8>
			inline typename detail::Make_Tuple_Mapper
			<T0, T1, T2, T3, T4, T5, T6, T7, T8>::type
			Make_Tuple(const T0& t0, const T1& t1, const T2& t2, const T3& t3,
				const T4& t4, const T5& t5, const T6& t6, const T7& t7,
				const T8& t8) {
			typedef typename detail::Make_Tuple_Mapper
				<T0, T1, T2, T3, T4, T5, T6, T7, T8>::type t;
			return t(t0, t1, t2, t3, t4, t5, t6, t7, t8);
		}

		template<class T0, class T1, class T2, class T3, class T4, class T5, class T6,
			class T7, class T8, class T9>
			inline typename detail::Make_Tuple_Mapper
			<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9>::type
			Make_Tuple(const T0& t0, const T1& t1, const T2& t2, const T3& t3,
				const T4& t4, const T5& t5, const T6& t6, const T7& t7,
				const T8& t8, const T9& t9) {
			typedef typename detail::Make_Tuple_Mapper
				<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9>::type t;
			return t(t0, t1, t2, t3, t4, t5, t6, t7, t8, t9);
		}

		template<class T0, class T1, class T2, class T3, class T4, class T5, class T6,
			class T7, class T8, class T9, class T10>
			inline typename detail::Make_Tuple_Mapper
			<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10>::type
			Make_Tuple(const T0& t0, const T1& t1, const T2& t2, const T3& t3,
				const T4& t4, const T5& t5, const T6& t6, const T7& t7,
				const T8& t8, const T9& t9, const T10& t10) {
			typedef typename detail::Make_Tuple_Mapper
				<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10>::type t;
			return t(t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10);
		}

		template<class T0, class T1, class T2, class T3, class T4, class T5, class T6,
			class T7, class T8, class T9, class T10, class T11>
			inline typename detail::Make_Tuple_Mapper
			<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11>::type
			Make_Tuple(const T0& t0, const T1& t1, const T2& t2, const T3& t3,
				const T4& t4, const T5& t5, const T6& t6, const T7& t7,
				const T8& t8, const T9& t9, const T10& t10, const T11& t11) {
			typedef typename detail::Make_Tuple_Mapper
				<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11>::type t;
			return t(t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11);
		}

		template<class T0, class T1, class T2, class T3, class T4, class T5, class T6,
			class T7, class T8, class T9, class T10, class T11, class T12>
			inline typename detail::Make_Tuple_Mapper
			<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12>::type
			Make_Tuple(const T0& t0, const T1& t1, const T2& t2, const T3& t3,
				const T4& t4, const T5& t5, const T6& t6, const T7& t7,
				const T8& t8, const T9& t9, const T10& t10, const T11& t11, const T12& t12) {
			typedef typename detail::Make_Tuple_Mapper
				<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12>::type t;
			return t(t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12);
		}

		template<class T0, class T1, class T2, class T3, class T4, class T5, class T6,
			class T7, class T8, class T9, class T10, class T11, class T12, class T13>
			inline typename detail::Make_Tuple_Mapper
			<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13>::type
			Make_Tuple(const T0& t0, const T1& t1, const T2& t2, const T3& t3,
				const T4& t4, const T5& t5, const T6& t6, const T7& t7,
				const T8& t8, const T9& t9, const T10& t10, const T11& t11, const T12& t12, const T13& t13) {
			typedef typename detail::Make_Tuple_Mapper
				<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13>::type t;
			return t(t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13);
		}

		template<class T0, class T1, class T2, class T3, class T4, class T5, class T6,
			class T7, class T8, class T9, class T10, class T11, class T12, class T13, class T14>
			inline typename detail::Make_Tuple_Mapper
			<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14>::type
			Make_Tuple(const T0& t0, const T1& t1, const T2& t2, const T3& t3,
				const T4& t4, const T5& t5, const T6& t6, const T7& t7,
				const T8& t8, const T9& t9, const T10& t10, const T11& t11, const T12& t12, const T13& t13, const T14& t14) {
			typedef typename detail::Make_Tuple_Mapper
				<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14>::type t;
			return t(t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14);
		}
		namespace detail{
			template<class T>
			struct Tie_Traits {
				typedef T& type;
			};

			template<>
			struct Tie_Traits<Ignore_Ty(Ignore_Ty)> {
				typedef swallow_assign type;
			};

			template<>
			struct Tie_Traits<void> {
				typedef Nil type;
			};

			template <
			class T0 = void, class T1 = void, class T2 = void,
			class T3 = void, class T4 = void, class T5 = void,
			class T6 = void, class T7 = void, class T8 = void,
			class T9 = void, class T10 = void, class T11 = void,
			class T12 = void, class T13 = void, class T14 = void
			>
			struct Tie_Mapper {
				typedef	Tuple<typename Tie_Traits<T0>::type,
				typename Tie_Traits<T1>::type,
				typename Tie_Traits<T2>::type,
				typename Tie_Traits<T3>::type,
				typename Tie_Traits<T4>::type,
				typename Tie_Traits<T5>::type,
				typename Tie_Traits<T6>::type,
				typename Tie_Traits<T7>::type,
				typename Tie_Traits<T8>::type,
				typename Tie_Traits<T9>::type,
				typename Tie_Traits<T10>::type,
				typename Tie_Traits<T11>::type,
				typename Tie_Traits<T12>::type,
				typename Tie_Traits<T13>::type,
				typename Tie_Traits<T14>::type> type;
			};		
		} // end namespace detail
		
		// Tie function templates -------------------------------------------------

		template<class T0>
		inline typename detail::Tie_Mapper<T0>::type
			Tie(T0& t0) {
			typedef typename detail::Tie_Mapper<T0>::type t;
			return t(t0);
		}

		template<class T0, class T1>
		inline typename detail::Tie_Mapper<T0, T1>::type
			Tie(T0& t0, T1& t1) {
			typedef typename detail::Tie_Mapper<T0, T1>::type t;
			return t(t0, t1);
		}

		template<class T0, class T1, class T2>
		inline typename detail::Tie_Mapper<T0, T1, T2>::type
			Tie(T0& t0, T1& t1, T2& t2) {
			typedef typename detail::Tie_Mapper<T0, T1, T2>::type t;
			return t(t0, t1, t2);
		}


		template<class T0, class T1, class T2, class T3>
		inline typename detail::Tie_Mapper<T0, T1, T2, T3>::type
			Tie(T0& t0, T1& t1, T2& t2, T3& t3) {
			typedef typename detail::Tie_Mapper<T0, T1, T2, T3>::type t;
			return t(t0, t1, t2, t3);
		}

		template<class T0, class T1, class T2, class T3, class T4>
		inline typename detail::Tie_Mapper<T0, T1, T2, T3, T4>::type
			Tie(T0& t0, T1& t1, T2& t2, T3& t3,
				T4& t4) {
			typedef typename detail::Tie_Mapper<T0, T1, T2, T3, T4>::type t;
			return t(t0, t1, t2, t3, t4);
		}

		template<class T0, class T1, class T2, class T3, class T4, class T5>
		inline typename detail::Tie_Mapper<T0, T1, T2, T3, T4, T5>::type
			Tie(T0& t0, T1& t1, T2& t2, T3& t3,
				T4& t4, T5& t5) {
			typedef typename detail::Tie_Mapper<T0, T1, T2, T3, T4, T5>::type t;
			return t(t0, t1, t2, t3, t4, t5);
		}

		template<class T0, class T1, class T2, class T3, class T4, class T5, class T6>
		inline typename detail::Tie_Mapper<T0, T1, T2, T3, T4, T5, T6>::type
			Tie(T0& t0, T1& t1, T2& t2, T3& t3,
				T4& t4, T5& t5, T6& t6) {
			typedef typename detail::Tie_Mapper
				<T0, T1, T2, T3, T4, T5, T6>::type t;
			return t(t0, t1, t2, t3, t4, t5, t6);
		}

		template<class T0, class T1, class T2, class T3, class T4, class T5, class T6,
			class T7>
			inline typename detail::Tie_Mapper<T0, T1, T2, T3, T4, T5, T6, T7>::type
			Tie(T0& t0, T1& t1, T2& t2, T3& t3,
				T4& t4, T5& t5, T6& t6, T7& t7) {
			typedef typename detail::Tie_Mapper
				<T0, T1, T2, T3, T4, T5, T6, T7>::type t;
			return t(t0, t1, t2, t3, t4, t5, t6, t7);
		}

		template<class T0, class T1, class T2, class T3, class T4, class T5, class T6,
			class T7, class T8>
			inline typename detail::Tie_Mapper
			<T0, T1, T2, T3, T4, T5, T6, T7, T8>::type
			Tie(T0& t0, T1& t1, T2& t2, T3& t3,
				T4& t4, T5& t5, T6& t6, T7& t7,
				T8& t8) {
			typedef typename detail::Tie_Mapper
				<T0, T1, T2, T3, T4, T5, T6, T7, T8>::type t;
			return t(t0, t1, t2, t3, t4, t5, t6, t7, t8);
		}

		template<class T0, class T1, class T2, class T3, class T4, class T5, class T6,
			class T7, class T8, class T9>
			inline typename detail::Tie_Mapper
			<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9>::type
			Tie(T0& t0, T1& t1, T2& t2, T3& t3,
				T4& t4, T5& t5, T6& t6, T7& t7,
				T8& t8, T9& t9) {
			typedef typename detail::Tie_Mapper
				<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9>::type t;
			return t(t0, t1, t2, t3, t4, t5, t6, t7, t8, t9);
		}

		template<class T0, class T1, class T2, class T3, class T4, class T5, class T6,
			class T7, class T8, class T9, class T10>
			inline typename detail::Tie_Mapper
			<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10>::type
			Tie(T0& t0, T1& t1, T2& t2, T3& t3,
				T4& t4, T5& t5, T6& t6, T7& t7,
				T8& t8, T9& t9, T10& t10) {
			typedef typename detail::Tie_Mapper
				<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10>::type t;
			return t(t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10);
		}

		template<class T0, class T1, class T2, class T3, class T4, class T5, class T6,
			class T7, class T8, class T9, class T10, class T11>
			inline typename detail::Tie_Mapper
			<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11>::type
			Tie(T0& t0, T1& t1, T2& t2, T3& t3,
				T4& t4, T5& t5, T6& t6, T7& t7,
				T8& t8, T9& t9, T10& t10, T11& t11) {
			typedef typename detail::Tie_Mapper
				<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11>::type t;
			return t(t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11);
		}

		template<class T0, class T1, class T2, class T3, class T4, class T5, class T6,
			class T7, class T8, class T9, class T10, class T11, class T12>
			inline typename detail::Tie_Mapper
			<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12>::type
			Tie(T0& t0, T1& t1, T2& t2, T3& t3,
				T4& t4, T5& t5, T6& t6, T7& t7,
				T8& t8, T9& t9, T10& t10, T11& t11, T12& t12) {
			typedef typename detail::Tie_Mapper
				<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12>::type t;
			return t(t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12);
		}

		template<class T0, class T1, class T2, class T3, class T4, class T5, class T6,
			class T7, class T8, class T9, class T10, class T11, class T12, class T13>
			inline typename detail::Tie_Mapper
			<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13>::type
			Tie(T0& t0, T1& t1, T2& t2, T3& t3,
				T4& t4, T5& t5, T6& t6, T7& t7,
				T8& t8, T9& t9, T10& t10, T11& t11, T12& t12, T13& t13) {
			typedef typename detail::Tie_Mapper
				<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13>::type t;
			return t(t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13);
		}

		template<class T0, class T1, class T2, class T3, class T4, class T5, class T6,
			class T7, class T8, class T9, class T10, class T11, class T12, class T13, class T14>
			inline typename detail::Tie_Mapper
			<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14>::type
			Tie(T0& t0, T1& t1, T2& t2, T3& t3,
				T4& t4, T5& t5, T6& t6, T7& t7,
				T8& t8, T9& t9, T10& t10, T11& t11, T12& t12, T13& t13, T14& t14) {
			typedef typename detail::Tie_Mapper
				<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14>::type t;
			return t(t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14);
		}
	} // end namespace Tuple
} // end namespace meta bit library

#endif