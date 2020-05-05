/*
 * ����� Reifat
 * GitHub Repository - https://github.com/Reifat
 * ��������� ��������� 30.04.2020.
*/
#ifndef TYPE_TRAITS_HPP
#define TYPE_TRAITS_HPP
#include "metabit/definitions_type/definitions_type.hpp"
// Meta library

namespace mbl // namespace meta bit library 
{

	// Soft for test type and limiting
#define CANCATENATE_(arg0 , arg1) arg0 ## arg1
#define MESSAGE_ERROR(message, LineError) \
		(CANCATENATE_(ERROT_OF_STATIC_ASSERTION_##message##_ERROR_AT_LINE__, LineError))
#define STATIC_ASSERT(cond, message) typedef unsigned int MESSAGE_ERROR(message, __LINE__)[(cond) ? 1 : -1]


// Check Type
	template <class _Ty0, class _Ty1>
	struct TestType {
		static const bool result = true;
	};
	template <class _Ty0>
	struct TestType<_Ty0, _Ty0> {
		static const bool result = false;
	};
	// Conditional Type
	template <bool _Test, class _Ty0, class _Ty1>
	struct IfThenElseType { // Choose _Ty0 if _Test is true, and _Ty1 otherwise
		typedef _Ty0  Type;
	};
	template <class _Ty0, class _Ty1>
	struct IfThenElseType<false, _Ty0, _Ty1> {
		typedef _Ty1  Type;
	};

	// encoding a type, value;
	template<typename T, T _value>
	struct ETVal
	{
		static const T value = _value;
	};
	// List Type ***************************************************************
	class Nil {};
	template<typename HeadTy, typename TailTy = Nil>
	class TList
	{
	public:
		typedef HeadTy Head;
		typedef TailTy Tail;
	};

	//** ���������� 1�� �������� �� ������
	template<typename List>
	struct FrontType
	{
		typedef typename List::Head Type;
	};
	//** ���������� �������� � ������ ������
	template<typename List, typename Element>
	struct PushFrontType : public  TList<Element, List>
	{};
	//** �������� 1�� �������� ������
	template<typename List>
	struct PopFrontType
	{
		typedef typename List::Tail Type;
	};
	//** ��������, ������ ������ ��� ���
	template<typename List>
	class IsEmpty
	{
	public:
		static const bool Value = false;
	};
	template<>
	class IsEmpty<Nil>
	{
	public:
		static const bool Value = true;
	};

	// ���������� �������� � ����� ������
	template<typename List, typename NewElement, bool empty = IsEmpty<List>::Value>
	class PushBack;
	// ����������� ������
	template<typename List, typename NewElement>
	class PushBack<List, NewElement, false>
	{
	private:
		// ������������������ ������ �����
		typedef typename FrontType<List>::Type Head;
		typedef typename PopFrontType<List>::Type Teil;
		// ���������������� ������ ������ �����
		typedef typename PushBack<Teil, NewElement>::Type NewTail;
	public:
		typedef typename PushFrontType<NewTail, Head>::Type Type;
	};
	// ������� ������
	template<typename NewElement>
	class PushBack<Nil, NewElement, true>
	{
	public:
		typedef typename PushFrontType<Nil, NewElement>::Type Type;
	};

	// ������ ������ �����
	template<class TList, bool Empty = IsEmpty<TList>::Value>
	class SizeTList;
	template<class TList>
	class SizeTList<TList, false>
	{
		typedef typename PopFrontType<TList>::Type TeilTlist;
	public:
		enum { value = 1 + SizeTList<TeilTlist>::value };
	};
	template<class TList>
	class SizeTList<TList, true>
	{
	public:
		enum { value = 0 };
	};
	//***************************************************************************************************************
	// �������� ���������� �� ������ �����

	// ��������� N-� ������ ������ ����
	template<typename List, size_t N, typename defT = Nil, bool Empty = IsEmpty<List>::Value>
	class NthElement;

	template<typename List, size_t N, typename defT>
	class NthElement<List, N, defT, false>
	{
	private:
		typedef typename PopFrontType<List>::Type _PopFront;
	public:
		typedef typename NthElement<_PopFront, N - 1, defT>::Element Element;
	};
	template<typename List, typename defT>
	class NthElement<List, 0, defT, false>
	{
	public:
		typedef typename FrontType<List>::Type Element;
	};
	template<typename List, size_t N, typename defT>
	class NthElement<List, N, defT, true>
	{
	public:
		typedef defT Element;
	};
	// ��������� N-�� ������ ������ �����
	template<typename List, size_t N, typename defT = Nil, bool Empty = IsEmpty<List>::Value>
	class NthTeil;
	template<typename List, size_t N, typename defT>
	class NthTeil<List, N, defT, false>
	{
	private:
		typedef typename PopFrontType<List>::Type _PopFront;
	public:
		typedef typename NthTeil<_PopFront, N - 1, defT>::Element Element;
	};
	template<typename List, typename defT>
	class NthTeil<List, 0, defT, false>
	{
	public:
		typedef List Element;
	};
	template<typename List, size_t N, typename defT>
	class NthTeil<List, N, defT, true>
	{
	public:
		typedef defT Element;
	};
	//***************************************************************************************************************
	// �������� ������ ����������� ���� � ������
	template<typename List, bool Empty = IsEmpty<List>::Value>
	class LargestTypeT;
	template<typename List>
	class LargestTypeT<List, false>
	{
	private:
		typedef typename FrontType<List>::Type Contender;
		typedef typename PopFrontType<List>::Type _PopFront;
		typedef typename LargestTypeT<_PopFront>::Type Best;
	public:
		typedef typename IfThenElseType<(sizeof(Contender) >= sizeof(Best)), Contender, Best>::Type Type;
	};
	template<typename List>
	class LargestTypeT<List, true>
	{
	public:
		typedef char Type;
	};
	//***************************************************************************************************************
	// �������� ���������� ��������� ������ �����

	template<typename T, typename U> // �������� ������� ��������� ���������
	struct Compare
	{
		static const bool Result = sizeof(T) < sizeof(U);
	};
	// ���� ����������  //********************************************************************************************
	template<typename List, typename Element,
		template<typename T, typename U>class Compare,
		bool Empty = IsEmpty<List>::Value>
		class InsertSortedT;

	// ����������� ������ :
	template<typename List, typename Element,
		template<typename T, typename U>class Compare>
	class InsertSortedT<List, Element, Compare, false>
	{
		typedef typename FrontType<List>::Type _Front;
		typedef typename PopFrontType<List>::Type _PopFront;
		typedef typename InsertSortedT<_PopFront, Element, Compare>::Type RecursiveCall;
		static const bool _ValCompare = Compare<Element, _Front>::Result;
		// ��������� ������ ��������������� ������:
		typedef typename IfThenElseType<_ValCompare, List, RecursiveCall>::Type NewTail;
		// ��������� ������ ��������������� ������:
		typedef typename IfThenElseType<_ValCompare, Element, _Front>::Type NewHead;
	public:
		typedef typename PushFrontType<NewTail, NewHead>::Type Type;
	};
	// ������� ������ :
	template<typename List, typename Element,
		template<typename T, typename U>class Compare>
	class InsertSortedT<List, Element, Compare, true>
	{
	public:
		typedef typename PushFrontType<List, Element>::Type Type;
	};

	// ��������� ���������� //*****************************************************************************************
	template<typename List,
		template<typename T, typename U> class Compare,
		bool Empty = IsEmpty<List>::Value>
		class InsertionSortT;
	// ����������� ������ (������� ������� ������� 
	// � ��������������� ������):
	template<typename List,
		template<typename T, typename U> class Compare>
	class InsertionSortT<List, Compare, false>
	{
		typedef typename FrontType<List>::Type _Front;
		typedef typename PopFrontType<List>::Type _PopFront;
		typedef typename InsertionSortT<_PopFront, Compare>::Type RecursiveCall;
	public:
		typedef typename InsertSortedT<RecursiveCall, _Front, Compare>::Type Type;
	};
	// ������� ������ (������ ������ �������� ���������������):
	template<typename List,
		template<typename T, typename U> class Compare>
	class InsertionSortT<List, Compare, true>
	{
	public:
		typedef List Type;
	};
	//***************************************************************************************************************
}
#endif