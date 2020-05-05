/*  Расширенная версия boost tuple
 * Автор Reifat
 * GitHub Repository - https://github.com/Reifat
 * Последние изменения 30.04.2020.

Типичный Tuple аналогичный реализации boost::tuple.
Tuple реализован аналогично boost::tuple, расширен 
до 15 элементов.
Определены две вспомогательные функции:
mbl::Make_Tuple(obj_1,obj_2,...obj_15);
mbl::Tie(obj_1,obj_2,...obj_15);

Более подробно о Tuple можно узнать:
https://www.boost.org/doc/libs/1_38_0/libs/tuple/doc/tuple_users_guide.html

В реализации отсутствуют операции сравнения Tuple объектов.