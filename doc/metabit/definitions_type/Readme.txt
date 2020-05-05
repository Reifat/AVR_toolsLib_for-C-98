Определения часто используемых типов данных в библиотеке
Definitions frequently used a data type in library
(Объявленные типы не гарантируют платформа независимость,
 напротив, все объявленные типы данных платформа зависиммые)
(Definitions data type not guaranteed independence platform, 
in contrast, all declared data types are platform-dependent)
(Диапазоны значений справедливы для 8 битной платформы AVR)
(Range value a number fair for 8 bit platform AVR)
1.**********************************************************************************************
Беззнаковый целочисленные указатели для регистров/
unsigned integral pointer for register:
	uint8ptr_t;   // (volatile unsigned char*) pointer on register, consistig of 8 bits
	uint16ptr_t;  // (volatile unsigned int*)  pointer on register, consisting of 16 bits
2.**********************************************************************************************
Беззнаковый целочисленный тип, для регитсров (часто требуется для передачи в аргументы шаблоны)
Unsigned integral a type, for a registers (often require for broadcasts in argumet template)
	reg8_t;  // (volatile unsigned char) the type for a register, consisting of 8 bits
	reg16_t; // (volatile unsigned int)  the type for a register, consisting of 16 bits
3.**********************************************************************************************
Простые, часто используемые типы данных/
Simple, frequently used a data type.
Unsigned integer data type:
	uint8_t;  // Unsigned integer consisting 8 bit  (range 0 to 255)
	uint16_t; // Unsigned integer consisting 16 bit (range 0 to 65535)
	uint32_t; // Unsigned integer consisting 32 bit (range 0 to 4294967295)
	uint64_t; // Unsigned integer consisting 64 bit (range 0 to 18446744073709551615)
Signed integral data type:
	int8_t;   // Signed integer consisting 8 bit   (range -128 to 127)
	int16_t;  // Signed integer consisting 16 bit  (range -32768 to 32767)
	int32_t;  // Signed integer consisting 32 bit  (range -2147483648 to 2147483647)
	int64_t;  // Signed integer consisting 64 bit  (range -9223372036854775808 to 9223372036854775807)
4.************************************************************************************************
Типы данных для записи размера
Data type for record a size
size_t;   // Default type for SIZE (Size range 0 to 255)
size8_t;  // Size a range 0 to 255
size16_t; // Size a range 0 to 65535
size32_t; // Size a range 0 to 4294967295
size64_t; // Size a range 0 to 18446744073709551615