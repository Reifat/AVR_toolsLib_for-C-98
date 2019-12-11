#ifndef METALIB_H
#define METALIB_H
// Meta library 

// Conditional Type
 template <bool _Test, class _Ty0, class _Ty1>
 struct IfThenElseT { // Choose _Ty1 if _Test is true, and _Ty2 otherwise
	typedef _Ty0  Type;
};
template <class _Ty0, class _Ty1>
struct IfThenElseT<false, _Ty0, _Ty1> {
	typedef _Ty1  Type;
};

// List Type ***************************************************************
class Nil {};
template<typename HeadT, typename TailT = Nil>
class Cons
{
public:
	typedef HeadT Head;
	typedef TailT Tail;
};
//** ���������� 1�� �������� �� ������
template<typename List>
struct FrontT
{
	typedef typename List::Head Type;
};
//** ���������� �������� � ������ ������
template<typename List, typename Element>
struct PushFrontT
{
	typedef Cons<Element, List> Type;
};
//** �������� 1�� �������� ������
template<typename List>
struct PopFrontT
{
	typedef typename List::Tail Type;
};
//** ��������, ������ ������ ��� ���
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
// �������� ���������� �� ������ �����

template<typename List, std::size_t N, typename defT = Nil, bool Empty = IsEmpty<List>::Valye>
class NthElement;

template<typename List, std::size_t N, typename defT>
class NthElement<List, N, defT, false>
{
private:
	typedef typename PopFrontT<List>::Type _PopFront;
public:
	typedef typename NthElement<_PopFront, N - 1, defT>::Element Element;
};
template<typename List, typename defT>
class NthElement<List, 0, defT, false>
{
public:
	typedef typename FrontT<List>::Type Element;
};
template<typename List, std::size_t N, typename defT>
class NthElement<List, N, defT, true>
{
public:
	typedef defT Element;
};

//***************************************************************************************************************
// �������� ������ ����������� ���� � ������
template<typename List, bool Empty = IsEmpty<List>::Valye>
class LargestTypeT;
template<typename List>
class LargestTypeT<List, false>
{
private:
	typedef typename FrontT<List>::Type Contender;
	typedef typename PopFrontT<List>::Type _PopFront;
	typedef typename LargestTypeT<_PopFront>::Type Best;
public:
	typedef typename IfThenElseT<(sizeof(Contender) >= sizeof(Best)), Contender, Best>::Type Type;
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
		 bool Empty = IsEmpty<List>::Valye>
class InsertSortedT;

// ����������� ������ :
template<typename List, typename Element,
	template<typename T, typename U>class Compare>
class InsertSortedT<List, Element, Compare, false>
{
	typedef typename FrontT<List>::Type _Front;
	typedef typename PopFrontT<List>::Type _PopFront;
	typedef typename InsertSortedT<_PopFront, Element, Compare>::Type RecursiveCall;
	static const bool _ValCompare = Compare<Element, _Front>::Result;
	// ��������� ������ ��������������� ������:
	typedef typename IfThenElseT<_ValCompare, List, RecursiveCall>::Type NewTail;
	// ��������� ������ ��������������� ������:
	typedef typename IfThenElseT<_ValCompare, Element, _Front>::Type NewHead;
public:
	typedef typename PushFrontT<NewTail, NewHead>::Type Type;
};
// ������� ������ :
template<typename List, typename Element,
	template<typename T, typename U>class Compare>
class InsertSortedT<List, Element, Compare, true>
{
public:
	typedef typename PushFrontT<List, Element>::Type Type;
};

// ��������� ���������� //*****************************************************************************************
template<typename List,
	template<typename T, typename U> class Compare,
	bool Empty = IsEmpty<List>::Valye>
	class InsertionSortT;
// ����������� ������ (������� ������� ������� 
// � ��������������� ������):
template<typename List,
	template<typename T, typename U> class Compare>
class InsertionSortT<List, Compare, false>
{
	typedef typename FrontT<List>::Type _Front;
	typedef typename PopFrontT<List>::Type _PopFront;
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
#endif