/*
 * Автор модификаций Reifat
 * GitHub Repository - https://github.com/Reifat
 * Последние изменения 30.04.2020.
*/
#ifndef REMOVE_CV_HPP
#define REMOVE_CV_HPP

namespace mbl // namespace meta bit library 
{

    // remove_cv.h - взят из библиотеки boost(внесена упрощающая модификация);
    //  (C) Copyright Dave Abrahams, Steve Cleary, Beman Dawes, Howard
    //  Hinnant & John Maddock 2000. 

    //  convert a type T to a non-cv-qualified type - remove_cv<T>
    template <class T> struct remove_cv { typedef T type; };
    template <class T> struct remove_cv<T const> { typedef T type; };
    template <class T> struct remove_cv<T volatile> { typedef T type; };
    template <class T> struct remove_cv<T const volatile> { typedef T type; };

#if !defined(METABIT_NO_ARRAY_TYPE_SPECIALIZATIONS)
    template <class T, size_t N> struct remove_cv<T const [N]> { typedef T type[N]; };
    template <class T, size_t N> struct remove_cv<T const volatile [N]> { typedef T type[N]; };
    template <class T, size_t N> struct remove_cv<T volatile [N]> { typedef T type[N]; };
    template <class T> struct remove_cv<T const []> { typedef T type[]; };
    template <class T> struct remove_cv<T const volatile []> { typedef T type[]; };
    template <class T> struct remove_cv<T volatile []> { typedef T type[]; };

#endif
}

#endif

