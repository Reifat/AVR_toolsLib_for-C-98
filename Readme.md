### Meta Bit Library (mbl)
Библиотека предназначена для написания кросплатформенных программ под микроконтроллеры (МК).\
mbl содержит класс обертку для регистров МК, интерфейс которого позволяет манипулировать разрядами, а также ряд методов для взаимодействия с регистром. Разработка с применением объектов класса обертки позволяет абстрагироваться от конкретной аппаратной платформы МК, что предоставляет более простое сопровождение и поддержку проекта. Перенесение кода праграммы сводится к конфигурированию используемых объектов в программе. В общем случаии, класс обертки вообще позволяет написать программу сначала для ПК, а затем при переносе на МК изменяется конфигурация.

###### Содержание библиотеки:
1. [Класс RegisterSet]
    1. [Функция инициализации разрядов BitInit]
2. [Библиотека функций для работы с разрядами BitLib]
3. [Кортэж типов Tuple]
4. [Библиотека для поддержки работы с типами данных Type_Traits]
    1. [Удалиние cv-квалификаторов]
5. [Класс обертка Reference_Wrapper]
6. [Заголовочеый файл с импользуемыми типами данных]
7. [nullptr]
8. [Препроцессорный псевдо "цикл"]
9. [Заголовочные файлы с указателями на регистры МК AVR]
10. [Сравнительные тесты]
11. [Пример]

###### Совместимость
 - GNU C v5.4 (Atmel studio 7)
 - MS C/C++ Compiler (VS 2019)

[Класс RegisterSet]:https://github.com/Reifat/MetaBit_Lib_in_style_Cpp98/tree/master/doc/metabit/register_set
[Функция инициализации разрядов BitInit]:https://github.com/Reifat/MetaBit_Lib_in_style_Cpp98/tree/master/doc/metabit/register_set
[Библиотека функций для работы с разрядами BitLib]:https://github.com/Reifat/MetaBit_Lib_in_style_Cpp98/tree/master/doc/metabit/bitlib
[Кортэж типов Tuple]:https://github.com/Reifat/MetaBit_Lib_in_style_Cpp98/tree/master/doc/metabit/tuple
[Библиотека для поддержки работы с типами данных Type_Traits]:https://github.com/Reifat/MetaBit_Lib_in_style_Cpp98/tree/master/doc/metabit/type_traits
[Удалиние cv-квалификаторов]:https://github.com/Reifat/MetaBit_Lib_in_style_Cpp98/tree/master/doc/metabit/type_traits
[Класс обертка Reference_Wrapper]:https://github.com/Reifat/MetaBit_Lib_in_style_Cpp98/tree/master/doc/metabit/utility
[Заголовочеый файл с импользуемыми типами данных]:https://github.com/Reifat/MetaBit_Lib_in_style_Cpp98/tree/master/doc/metabit/definitions_type
[nullptr]:https://github.com/Reifat/MetaBit_Lib_in_style_Cpp98/tree/master/doc/metabit/nullptr
[Препроцессорный псевдо "цикл"]:https://github.com/Reifat/MetaBit_Lib_in_style_Cpp98/tree/master/doc/metabit/preprocessor
[Заголовочные файлы с указателями на регистры МК AVR]:https://github.com/Reifat/MetaBit_Lib_in_style_Cpp98/tree/master/doc/avrdef_ptr
[Сравнительные тесты]:https://github.com/Reifat/MetaBitLibrary/tree/master/test
[Пример]:https://github.com/Reifat/MetaBit_Lib_in_style_Cpp98/tree/master/example











