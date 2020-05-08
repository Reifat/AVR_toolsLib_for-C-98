### Сравнение производительности

Сравнивается производительность генерируемого кода компилятором, при использовании класса обертки для регистров и без него. Измеряется размер сгенерированного кода, а также число циклов при выполнении main программы.\
##### Список тестовых программ:
  1. [Запись/чтение регистра]
     1. [ASM код для W/R]
  2. [Логические операции]
     1. [ASM код LO]
  3. [Арифметические операции]
     1. [ASM код AO]
  4. [Смешанный тест]
     1. [ASM код]
  5. [Исходный код тестовых программ]
  
  ##### Все тесты проводилис в:
  GNU C v5.4 (Atmel studio 7) \
  Оптимизация - Optimize for size (-Os) \
  В каждой тестовой программе использовалась произвольная комбинация операций. Для оценки производительности по скорости выполнения кода   было взято максимальное число циклов на выполнение команды, чтобы оценить наихудший случай.
  
#### Итоговый результат
 ![Результаты]


[Запись/чтение регистра]:https://github.com/Reifat/MetaBitLibrary/tree/master/test/pictures/1.%20RECORD_WORD_TEST
[ASM код для W/R]:https://raw.githubusercontent.com/Reifat/MetaBitLibrary/master/test/pictures/1.%20RECORD_WORD_TEST/asm.bmp

[Логические операции]:https://github.com/Reifat/MetaBitLibrary/tree/master/test/pictures/2.%20LOGICAL_OPERATION_TEST
[ASM код LO]:https://raw.githubusercontent.com/Reifat/MetaBitLibrary/master/test/pictures/2.%20LOGICAL_OPERATION_TEST/asm.bmp

[Арифметические операции]:https://github.com/Reifat/MetaBitLibrary/tree/master/test/pictures/3.%20ARITHMETIC_OPERATIONS_TEST
[ASM код AO]:https://raw.githubusercontent.com/Reifat/MetaBitLibrary/master/test/pictures/3.%20ARITHMETIC_OPERATIONS_TEST/asm.bmp

[Смешанный тест]:https://github.com/Reifat/MetaBitLibrary/tree/master/test/pictures/4.%20COMPLEX_TEST
[ASM код]:https://github.com/Reifat/MetaBitLibrary/tree/master/test/asm_file

[Исходный код тестовых программ]:https://github.com/Reifat/MetaBitLibrary/blob/master/test/main.cpp

[Результаты]: https://github.com/Reifat/MetaBitLibrary/blob/master/test/pictures/Result_Test.PNG
