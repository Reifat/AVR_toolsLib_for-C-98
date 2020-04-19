avrdef.hpp
.Russian
Определения константных указателей 
на регистры микроконтроллеры AVR;
Все указатели размещаются в пространстве имен 
mcreg - microcontroller registers;

Пример использования к указателя на регистр:
	*mcreg::PortA = 0x55; // Установка лог.1 в регистре через один разряд

.English
Definitions of constant pointers
on registers microcontrollers AVR;
All pointers are placed in the namespace 
mcreg - microcontroller registers;

Example of using a pointer on register:
	*mcreg::PortA = 0x55; // Set bool(1) in register via one bit