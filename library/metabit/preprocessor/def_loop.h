/* Заголовочный файл def_loop - определения постоянных, 
   для псевдопрепроцессорного цикла */
#ifndef DEF_LOOP
#define DEF_LOOP

#ifndef LOOP_MIN 
#define LOOP_MIN -1
#endif
#ifndef LOOP_MAX 
#define LOOP_MAX -1
#endif

#if 0 >= LOOP_MIN && 0 <= LOOP_MAX
LOOP_BODY(0)
#endif

#if 1 >= LOOP_MIN && 1 <= LOOP_MAX
LOOP_BODY(1)
#endif

#if 2 >= LOOP_MIN && 2 <= LOOP_MAX
LOOP_BODY(2)
#endif

#if 3 >= LOOP_MIN && 3 <= LOOP_MAX
LOOP_BODY(3)
#endif

#if 4 >= LOOP_MIN && 4 <= LOOP_MAX
LOOP_BODY(4)
#endif

#if 5 >= LOOP_MIN && 5 <= LOOP_MAX
LOOP_BODY(5)
#endif

#if 6 >= LOOP_MIN && 6 <= LOOP_MAX
LOOP_BODY(6)
#endif

#if 7 >= LOOP_MIN && 7 <= LOOP_MAX
LOOP_BODY(7)
#endif

#if 8 >= LOOP_MIN && 8 <= LOOP_MAX
LOOP_BODY(8)
#endif

#if 9 >= LOOP_MIN && 9<= LOOP_MAX
LOOP_BODY(9)
#endif

#if 10 >= LOOP_MIN && 10 <= LOOP_MAX
LOOP_BODY(10)
#endif

#endif