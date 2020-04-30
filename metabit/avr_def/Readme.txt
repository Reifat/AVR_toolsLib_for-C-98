avrdef.hpp
.Russian
Определения константных указателей 
на регистры микроконтроллеры AVR;
Все указатели размещаются в пространстве имен 
mcreg - microcontroller registers;
Для каждого регистра объявлено два указателя,
неконстантный и константный.
Имена всех указателей записаны в нижнем регистре и
совпадают с именами регистров микроконтроллера.
Константные регистры заканчиваются префиксом - "_c".

Пример использования к указателя на регистр:
	*mcreg::port_a = 0x55; // Установка лог.1 в регистре через один разряд

.English
Definitions of constant pointers
on registers microcontrollers AVR;
All pointers are placed in the namespace 
mcreg - microcontroller registers;
Two pointers are declared for each register,
non constant and constant.
The names of all pointers are written in lowercase and
match the names of the microcontroller registers.
Constant registers end with the prefix - "_c".

Example of using a pointer on register:
	*mcreg::port_a = 0x55; // Set bool(1) in register via one bit