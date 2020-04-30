В этом разделе размещаются и будут добавляться препроцессорные макросы.
In this section are placed and will be added to preprocessor macros.

Препроцессорный псевдоцикл
Preprocessor pseudocycle
Simple example:
	#define LOOP_MIN 0;
	#define LOOP_MAX 10;
	#define LOOP_BODY(n) \
		int a##n = n;
	#include def_loop.hpp