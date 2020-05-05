/*
 * ����� ����������� Reifat
 * GitHub Repository - https://github.com/Reifat
 * ��������� ��������� 04.05.2020.
*/
* * * * * * * * * remove_cv.hpp * * * * * * * * * * *
�������� conts/volatile �������������� � ����� ������.
�������� ���������� ���� ����� �� ���������� 
boost � ������� ���������� �����������.

�������� conts/volatile �������������� � ���������� ���� ������:
	Example:
		mbl::remove_cv< input_duta_type >::type;
�������� conts/volatile �������������� � ���������� ���� ������ ��� ��������:
	Example:
		mbl::remove_cv< input_duta_type , size_array >::type;


* * * * * * * * * * type_traits.hpp * * * * * * * * * * *
��������� ���������� ��� ������ � ������, � �������� ����� ������.

* * * * * * * * * �������� ������� � �������� * * * * * * * *

1. ��������, ����� ��� ���� ������ ���� ��������.
   ���� 2 ����� ������ ����������, "�����" ���������� false, � ��������� true
	Example:
		mbl::TestType<Ty_0, Ty_1>::result; 

2. �������� ��� ������.
   Ec�� � ���������� �������� ������� ��������� true, 
   �� "�����" ������ 1� ��������� ��� ������, � ��������� 2�.
	Example:
		mbl::IfThenElseType< bool_Condition , Ty_0, Ty_1>::Type;

3. �������������� ��� ������ �� ����� ���������� ���������.
   ����������� � ����������� �����������. ��� ������ ������������ � ������� �����.
   � ������� ���� ���������, ����� ��������� ��������� ��������� ������� ������� 
   ��������� ����� ������� ��.
	Example:
		mbl::ETVal< Ty, value >(); // coding

 * * * * * * * * * List data type * * * * * * 
��������� ������ ����� ������.
��� ��������� � � ������ ������������ � Tuple, �� ��� ������� � ��� ����,
������� ���� �������� � ��������� .hpp ����.

1. Nil - ������ ������. ���������� ����� ������

2. TList - ����������� ������ ����� ������.
	��������� �����:
	       Head - ������� ������ ������ �������
	       Tail - ������� ������ ��� ��������� ��������
	�������� ������ ����:
		typedef TList<Ty_0, TList<Ty_1, TList<Ty_2> > > ListType; // ������, �������� ���
									  // 3� ����� ������
* * * * * ������ ��� TList * * * * * * * * * * * * * * 
1. FrontType - ���������� 1�� �������� �� ������
	Example: 
		typedef FrontType<Tlist>::Type Front;

2. PushFrontType - ���������� �������� � ������ ������
	Example:
		typedef PushFrontType<List, newElement> NewTList;

3. PopFrontType - �������� 1�� �������� ������
	Example:
		typedef PopFrontType<List>::Type NewTList;

4. IsEmpty - ��������, ������ ������ ��� ���.
	     ����� ���������� bool ��������
	Example:
		IsEmpty<List>::Value; // return bool value

5. PushBack - ���������� �������� � ����� ������
	Example:
		typedef PushBack<List,newElement>::Type NewTList;

6. SizeTList - ������ ������ �����
	       ���������� enum value.
	Example:
		SizeTList<List>::Value; // return size

7. NthElement - �������� N ������� �� ������ �����
	Example:
		typedef NthElement<List,N>::Element Type;

8. NthTeil - ��������� N-�� ������ ������ �����
	Example:
		typedef NthTeil<List,N>::Element N_TailTList;

9. LargestTypeT - �������� ������ ����������� ���� � ������
	Example:
		typedef LargestTypeT<List>::Type MostType;

10. InsertSortedT - �������� ���������� ��������� ������ �����.
	Example:
		typedef InsertionSortT<List,KeySorted>::Type SortedTList;
		
    � �������� KeySorted ����� ������������ - mbl::Compare,
    ����� ������ ����� ������������� �� �����������.
    ���� ����� ���������� ���� ����������� ��������� KeySorted, ����� ��� ������ ����� ����. ���:
	template<typename Ty_0, typename Ty_1>
	struct Compare{
		//...
		// example static const bool Result = sizeof(Ty_0) < sizeof(Ty_1);
	}
    Ty_0 � Ty_1 - ������������ ���� ������ � TList.