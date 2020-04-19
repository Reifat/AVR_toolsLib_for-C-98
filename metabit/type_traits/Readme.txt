Metaprogramming library

Condition type: Choose T0 if _Test is true, and T1 otherwise
Examples using:
	typedef IfThenElse<bool_Value, T0, T1>::Type ResultType;

The list of types in the style of LISP to C++98.
Example of a special case, initialization of a list of types:

typedef Cons<long long,
	     Cons<char,
		  Cons<int,
		       Cons<long> > > > TypeList;

The generalized case, the initialization of the list of types:
typedef Cons<Type_0,
	     Cons<Type_1,
		  Cons<Type_2,
			Cons<Type_3,
			...........
			    ..........
				.........
		       		    Cons<Type_N,> > ... >  TypeList;
...........................................................................
Retrieving the first element from the list:

	typedef FrontT<TypeList>::Type FirstElement;

Adding an item to the beginning of the list:

	typedef PushFrontT<Element, TypeList>::Type ResultTypeList;

Remove the first item from the list:

	typedef PopFrontT<TypeList>::Type ResultTypeList;

Checking the list, empty or not (true - the ListType empty, false - the ListType not empty):

	bool TestTypeList = IsEmpty<TypeList>::Valye;

An algorithm retrieves an item by index number( N - number of element ):

	typedef NthElementT<TypeList, N>::Type Element;

Search algorithm for the largest type in the list:

	typedef LargestTypeT<TypeList>::Type LargestType;

The algorithm for the insertion sort, the list of types:
(Compare - the function for order the elements)
	Compare function examples:
		template<typename T0, typename T1>
		struct Compare
		{
	    	    static const bool Result = sizeof(T0) < sizeof(T1);
		};
Examples using sort:
	typedef InsertionSort<TypeList,Compare>::Type SortedTypeList;