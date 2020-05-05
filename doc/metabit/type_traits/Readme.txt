/*
 * Автор модификаций Reifat
 * GitHub Repository - https://github.com/Reifat
 * Последние изменения 04.05.2020.
*/
* * * * * * * * * remove_cv.hpp * * * * * * * * * * *
Удаление conts/volatile квалификаторов у типов данных.
Основная реализация была взята из библиотеки 
boost и внесена упрощающая модификация.

Удаление conts/volatile квалификаторов у некоторого типа данных:
	Example:
		mbl::remove_cv< input_duta_type >::type;
Удаление conts/volatile квалификаторов у некоторого типа данных для массивов:
	Example:
		mbl::remove_cv< input_duta_type , size_array >::type;


* * * * * * * * * * type_traits.hpp * * * * * * * * * * *
Небольшая библиотека для работы с типами, и списками типов данных.

* * * * * * * * * Описание методов и структур * * * * * * * *

1. Проверка, чтобы два типа данных были различны.
   Если 2 типпа данных одинаковые, "метод" возвращает false, в противном true
	Example:
		mbl::TestType<Ty_0, Ty_1>::result; 

2. Условный тип данных.
   Ecли в результате проверки условия результат true, 
   то "метод" вернет 1й введенный тип данных, в противном 2й.
	Example:
		mbl::IfThenElseType< bool_Condition , Ty_0, Ty_1>::Type;

3. Закодированный тип данных со своим уникальным значением.
   Применяется в константных вычислениях. Как пример используется в списках типов.
   С помощью этой структуры, можно заполнять параметры шаблонных методов простой 
   передачей этого объекта им.
	Example:
		mbl::ETVal< Ty, value >(); // coding

 * * * * * * * * * List data type * * * * * * 
Структура список типов данных.
Эта структура и её методы используется в Tuple, но она полезна и без него,
поэтому была вынесена в отдельный .hpp файл.

1. Nil - Пустой список. Отображает конец списка

2. TList - Рекурсивный список типов данных.
	Структура имеет:
	       Head - который хранит первый элемент
	       Tail - который хоанит все остальные элементы
	Создание списка типа:
		typedef TList<Ty_0, TList<Ty_1, TList<Ty_2> > > ListType; // Пример, создание для
									  // 3х типов данных
* * * * * Методы для TList * * * * * * * * * * * * * * 
1. FrontType - Извлечение 1го элемента из списка
	Example: 
		typedef FrontType<Tlist>::Type Front;

2. PushFrontType - Добавление элемента в начало списка
	Example:
		typedef PushFrontType<List, newElement> NewTList;

3. PopFrontType - Удаление 1го элемента списка
	Example:
		typedef PopFrontType<List>::Type NewTList;

4. IsEmpty - Проверка, пустой список или нет.
	     Метод возвращает bool значение
	Example:
		IsEmpty<List>::Value; // return bool value

5. PushBack - Добавление элемента в конец списка
	Example:
		typedef PushBack<List,newElement>::Type NewTList;

6. SizeTList - Размер списка типов
	       Возвращает enum value.
	Example:
		SizeTList<List>::Value; // return size

7. NthElement - Получить N элемент из списка типов
	Example:
		typedef NthElement<List,N>::Element Type;

8. NthTeil - Получение N-го хвоста списка типов
	Example:
		typedef NthTeil<List,N>::Element N_TailTList;

9. LargestTypeT - Алгоритм поиска наибольшего типа в списке
	Example:
		typedef LargestTypeT<List>::Type MostType;

10. InsertSortedT - Алгоритм сортировки вставками списка типов.
	Example:
		typedef InsertionSortT<List,KeySorted>::Type SortedTList;
		
    В качестве KeySorted можно использовать - mbl::Compare,
    тогда список типов отсортируется по возрастанию.
    Либо можно определить свою собственную структуру KeySorted, тогда она должна иметь след. вид:
	template<typename Ty_0, typename Ty_1>
	struct Compare{
		//...
		// example static const bool Result = sizeof(Ty_0) < sizeof(Ty_1);
	}
    Ty_0 и Ty_1 - сравниваемые типы данных в TList.