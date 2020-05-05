/* Определение указателей для микроконтроллеров AVR
 * Автор Reifat
 * GitHub Repository - https://github.com/Reifat
 * Последние изменения 04.05.2020.
*/
#ifndef AVRDEF_PTR_HPP
#define AVRDEF_PTR_HPP

#include <avr/io.h>

// include default definitions type
#include "metabit\definitions_type\definitions_type.hpp"

#ifdef ATMEGA_8
#include "avrdef_ptr\detail\mega8.hpp"
#endif

#ifdef ATMEGA_16
#include "avrdef_ptr\detail\mega16.hpp"
#endif

#ifdef ATTINY_2313
#include "avrdef_ptr\detail\tiny2313.hpp"
#endif

#endif // AVRDEF_PTR_HPP