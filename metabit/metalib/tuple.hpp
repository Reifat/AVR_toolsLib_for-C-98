#include "metabit\definitions_type\metalib.h"
#ifndef _TUPLE
#define _TUPLE
// Base class Tuple
template<typename TyHead, typename TyTail = Nil>
class Tpl
{
private:
    TyHead head_;
    TyTail tail_;
public:
    Tpl(TyHead head) : head_(head) {}
    Tpl(TyHead head, TyTail tail) : head_(head), tail_(tail) {}

    TyHead getHead() { return head_; }
    TyTail getTail() { return tail_; }
    typedef TyHead Head;
    typedef TyTail Tail;
};

template<typename _Ty, bool Empty = IsEmpty<typename PopFrontType<_Ty>::Type>::Valye>
class BildTyple
{
    typedef typename FrontType<_Ty>::Type CurrentFront;
    typedef typename PopFrontType<_Ty>::Type CurrentPopFront;
    typedef typename FrontType<CurrentPopFront>::Type NextFront;
    typedef typename Tpl<CurrentFront, CurrentPopFront>  PackedType;
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
    static Tpl<CurrentFront> Packing(CurrentFront* current_ptr)
    {
        return Tpl<CurrentFront>(*current_ptr);
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
        tuple_(BuildTail::Packing(&var)) {
    }
    template<typename T>
    T operator[](size_t pos)
    {

        return 0;
    }

    HeadType Front()
    {
        return tuple_.getHead();
    }
    TailType PopFront()
    {
        return tuple_.getTail();
    }
    template<typename Element>
    Tpl<Element, _Ty> PushFront(Element _Val)
    {
        return Tpl<Element, _Ty>(_Val, tuple_);
    }
private:

    _Ty     tuple_;
    //size_t  size_tuple;
};

#endif