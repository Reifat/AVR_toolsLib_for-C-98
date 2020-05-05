avrdef.hpp
.Russian
Определения константных указателей 
на регистры микроконтроллеры AVR;
Все указатели размещаются в пространстве имен 
mcreg - microcontroller registers;
Имена всех указателей записаны в верхнем регистре и
совпадают с именами регистров микроконтроллера.
Имена указателей на регистр заканчиваются префиксом - "_ptr".

Пример использования к указателя на регистр:
	*mcreg::PORTA_ptr = 0x55; // Установка лог.1 в регистре через один разряд

.English
Definitions of constant pointers
on registers microcontrollers AVR;
All pointers are placed in the namespace 
mcreg - microcontroller registers;
The names of all pointers are written in uppercase and
match the names of the microcontroller registers.
The names of case pointers end with the prefix - "_ptr".

Example of using a pointer on register:
	*mcreg::PORTA_ptr = 0x55; // Set bool(1) in register via one bit