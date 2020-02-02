// Meta library 
// C++98 style

#ifndef _METALIB_HPP
#define _METALIB_HPP

// include default definitions type
#ifndef _DEFINITIONS_TYPE_HPP
#include "metabit\definitions_type\definitions_type.h"
#endif

// Soft for test type and limiting
#define CANCATENATE_(arg0 , arg1) arg0 ## arg1
#define MESSAGE_ERROR(message, LineError) \
		(CANCATENATE_(ERROT_OF_STATIC_ASSERTION_##message##_ERROR_AT_LINE__, LineError))
#define STATIC_ASSERT(cond, message) typedef unsigned int MESSAGE_ERROR(message, __LINE__)[(cond) ? 1 : -1]

// Type checking
template<typename _Ty0, typename _Ty1>
struct SameType
{
	static const bool value = false;	// Types different
};
template<typename _Ty>
struct SameType<_Ty, _Ty>
{
	static const bool value = true;		// Type same
};


// Conditional Type
 template <bool _Test, class _Ty0, class _Ty1>
 struct IfThenElseType { // Choose _Ty1 if _Test is true, and _Ty2 otherwise
	typedef _Ty0  Type;
};
template <class _Ty0, class _Ty1>
struct IfThenElseType<false, _Ty0, _Ty1> {
	typedef _Ty1  Type;
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
//** Извлечение 1го элемента из списка
template<typename List>
struct FrontType
{
	typedef typename List::Head Type;
};
//** Добавление элемента в начало списка
template<typename List, typename Element>
struct PushFrontType
{
	typedef TList<Element, List> Type;
};
//** Удаление 1го элемента списка
template<typename List>
struct PopFrontType
{
	typedef typename List::Tail Type;
};
//** Проверка, пустой список или нет
template<typename List>
class IsEmpty
{
public:
	static const bool Valye = false;
};
template<>
class IsEmpty<Nil>
{
public:
	static const bool Valye = true;
};
//***************************************************************************************************************
// Алгоритм индексации по списку типов

template<typename List, size_t N, typename defT = Nil, bool Empty = IsEmpty<List>::Valye>
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

//***************************************************************************************************************
// Алгоритм поиска наибольшего типа в списке
template<typename List, bool Empty = IsEmpty<List>::Valye>
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
// Алгоритм сортировки вставками списка типов

template<typename T, typename U> // Условная функция сравнения элементов
struct Compare
{
	static const bool Result = sizeof(T) < sizeof(U);
};
// Ядро сортировки  //********************************************************************************************
template<typename List, typename Element,
		 template<typename T, typename U>class Compare,
		 bool Empty = IsEmpty<List>::Valye>
class InsertSortedT;

// Рекурсивный случай :
template<typename List, typename Element,
	template<typename T, typename U>class Compare>
class InsertSortedT<List, Element, Compare, false>
{
	typedef typename FrontType<List>::Type _Front;
	typedef typename PopFrontType<List>::Type _PopFront;
	typedef typename InsertSortedT<_PopFront, Element, Compare>::Type RecursiveCall;
	static const bool _ValCompare = Compare<Element, _Front>::Result;
	// Вычисляем хвоста результирующего списка:
	typedef typename IfThenElseType<_ValCompare, List, RecursiveCall>::Type NewTail;
	// Вычисляем головы результирующего списка:
	typedef typename IfThenElseType<_ValCompare, Element, _Front>::Type NewHead;
public:
	typedef typename PushFrontType<NewTail, NewHead>::Type Type;
};
// Базовый случай :
template<typename List, typename Element,
	template<typename T, typename U>class Compare>
class InsertSortedT<List, Element, Compare, true>
{
public:
	typedef typename PushFrontType<List, Element>::Type Type;
};

// Интерфейс сортировки //*****************************************************************************************
template<typename List,
	template<typename T, typename U> class Compare,
	bool Empty = IsEmpty<List>::Valye>
	class InsertionSortT;
// Рекурсивный случай (Вставка первого элемент 
// в отсортированный список):
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
// Базовый случай (пустой список является отсортированным):
template<typename List,
	template<typename T, typename U> class Compare>
class InsertionSortT<List, Compare, true>
{
public:
	typedef List Type;
};
//***************************************************************************************************************
#endif