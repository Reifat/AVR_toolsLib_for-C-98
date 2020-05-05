Библиотека для работы над разрядами целочисленных типов данных
Library for working with bits of integer data types

В библиотеки используются вычисления на этапе компиляции и гибридные вычисления
The library uses compile-time calculations and hybrid calculations

Перечень функций и примеры их вызовов / 
List of functions and examples of their calls:

1.****************************************************************************
Вычислить количество разрядов в используемом типе данных
Calculate the number of bits in using the data type;
Example:
	mbl::SizeTy<Ty>::_Size; // return number of bits in using data type

2.*****************************************************************************
Проверка, разряд "n" установлен в лог.1
Check, bit number "n" set in true
Example:
	unsigned char a = 0x55; // initialization variable and set bits;
	mbl::IsBitSet(a,2);	// Check bit 2 on true;

3.*****************************************************************************
Абсолютное значение целочисленного числа x
Absolute value of the signed a number
Examples:
	int a = -0x0055; // initialization variable 0xffab;
	mbl::Mod(a);	 // return 0x0055;
4.*****************************************************************************
Подсчет количества бит установленных в лог.1;
Counting the quantity bits set in true
Example:
	char a = 0b10101010;		    // initialization variable;
	unsigned int count = mbl::Count(a); // return count = 4;
5.*****************************************************************************
Установить лог.1 во всех разрядах после первой лог. 1цы
Set bool(1) after first bool(1)
Example:
	unsigned char a = 0b00101000;  // initialization variable;
	unsigned char b = mbl::SetAfterTrue(a); // Result 0b00111111;
6.*****************************************************************************
Число ведущих нулевых бит
Number of leading Zero bits
Example:
	unsigned char a = 0b00101000; // initialization variable;
	unsigned char num_leading_zero = mbl::NumberLeadingZero(a); // return 2;
7.******************************************************************************
Беззнаковый целочисленный log2(x)
unsigned integerlog2(x)
Examples: 
	unsigned int x = 128;		   // initialization variable;
	unsigned int log2 = mbl::ilog2(x); // Return 7;
8.******************************************************************************
Проверка, чтобы только 1н бит установлен в лог.1;
Check, only single the bit set in true;
Example:
	unsigned char x = 0x55; // initialization variable;
	bool y = mbl::OnlySingleTrue(x); // Return false;
9.******************************************************************************
Подсчет количества завершающих нулевых бит
Counting trailing zeros bits
Example:
	unsigned char x = 0b10011000; // initialization variable;
	unsigned char y = mbl::CountTrailingZeros(x); // Return 3;
10.*****************************************************************************
Установка или сброс с разряда a по b
Set/reset in range with bit "a" to "b"
Example:
	unsigned char x = 0b10011000;   // initialization variable;
	x = mbl::SetInRange(x,2,5,true);// result 0b10111100;