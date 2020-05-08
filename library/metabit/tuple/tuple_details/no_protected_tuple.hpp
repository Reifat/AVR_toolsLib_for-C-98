#ifndef NO_PROTECTED_TUPLE_HPP
#define NO_PROTECTED_TUPLE_HPP

#include "metabit\metalib\metalib.hpp"

namespace mbl // namespace meta bit library
{
	template<typename TyHead, typename TyTail = Nil>
	class BasicTuple :public TList<TyHead, TyTail>
	{

	private:
		TyHead _head;
		TyTail _tail;
	public:
		BasicTuple() {}
		BasicTuple(const TyHead& head) : _head(head) {}

		BasicTuple(const TyHead& arg0, const TyTail& arg1) :
			_head(arg0), _tail(arg1) {}

		BasicTuple<TyHead, TyTail>& operator=(TyHead right)
		{
			_head = right;
			return *this;
		}
		operator TyHead()const
		{
			return head_;
		}
		TyHead& getHead() { return _head; }
		TyTail& getTail() { return _tail; }
		~BasicTuple() {}
	};

	template<unsigned char N>
	struct TupleGet
	{
		template<typename HeadTuple, typename TailTuple>
		static typename NthElement<BasicTuple<HeadTuple, TailTuple>, N>::Element
			Apply(BasicTuple<HeadTuple, TailTuple> tuple)
		{
			return TupleGet<N - 1>::Apply(tuple.getTail());
		}
	};
	template<>
	struct TupleGet<0>
	{
		template<typename HeadTuple, typename TailTuple>
		static typename NthElement<BasicTuple<HeadTuple, TailTuple>, 0>::Element
			Apply(BasicTuple<HeadTuple, TailTuple> tuple)
		{
			return tuple.getHead();
		}
	};
	template<unsigned char N>
	struct TGet
	{
		template<typename Head, typename Tail>
		static typename NthTeil<BasicTuple<Head, Tail>, N>::Element&
			Apply(BasicTuple<Head, Tail>& tuple)
		{
			return TGet<N - 1>::Apply(tuple.getTail());
		}
	};
	template<>
	struct TGet<0>
	{
		template<typename Head, typename Tail>
		static typename NthTeil<BasicTuple<Head, Tail>, 0>::Element&
			Apply(BasicTuple<Head, Tail>& tuple)
		{
			return tuple;
		}
	};
	template<typename _Ty, bool Empty = IsEmpty<typename PopFrontType<_Ty>::Type>::Value>
	class BildTyple
	{
		typedef typename FrontType<_Ty>::Type CurrentFront;
		typedef typename PopFrontType<_Ty>::Type CurrentPopFront;
		typedef typename FrontType<CurrentPopFront>::Type NextFront;
		typedef typename BasicTuple<CurrentFront, CurrentPopFront>  PackedType;
		typedef typename BildTyple<CurrentPopFront>      NextPackedType;
	public:
		static _Ty Packing(CurrentFront* current_ptr)
		{
			CurrentFront val = *current_ptr;
			NextFront* next_ptr = (NextFront*)(++current_ptr);
			return PackedType(val, NextPackedType::Packing(next_ptr));
		}
	};
	template<typename _Ty>
	struct BildTyple<_Ty, true>
	{
		typedef typename FrontType<_Ty>::Type CurrentFront;
	public:
		static BasicTuple<CurrentFront> Packing(CurrentFront* current_ptr)
		{
			return BasicTuple<CurrentFront>(*current_ptr);
		}
	};

	// interface Tuple
	template<typename _Ty>
	class Tuple
	{
		typedef typename _Ty::Head      HeadType;
		typedef typename BildTyple<_Ty> BuildTail;
		typedef typename _Ty::Tail      TailType;
	public:

		Tuple(HeadType var, ...) :
			_tuple(BuildTail::Packing(&var)) {
		}
		template<unsigned index>
		typename NthElement<_Ty, index>::Element get()
		{
			return TupleGet<index>::Apply(_tuple);
		}

		template<typename T, T index>
		typename NthTeil<_Ty, index>::Element operator[](ETVal<T, index>)
		{

			return TGet<index>::Apply(_tuple);
		}

		HeadType Front()
		{
			return _tuple.getHead();
		}
		TailType PopFront()
		{
			return _tuple.getTail();
		}
		template<typename Element>
		BasicTuple<Element, _Ty> PushFront(Element _Val)
		{
			return BasicTuple<Element, _Ty>(_Val, _tuple);
		}
	protected:

		_Ty     _tuple;
		size_t  _size_tuple;
	};

	// Индивидуальный кортеж
	template<typename _Ty>
	struct SpecialTuple
	{
		typedef Tuple<_Ty> Tuple;
	};
} // end namespace metabit

#endif