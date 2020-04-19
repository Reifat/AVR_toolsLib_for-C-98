#ifndef REFERENCE_WRAPPER_HPP
#define REFERENCE_WRAPPER_HPP
// reference_wrapper
// Упрощенная версия из boost

namespace mbl // namespace meta bit library
{
    namespace detail {
        typedef char& RefByte;
        typedef const volatile RefByte CV_ByteRef;

    }//end namespace detail

    template<class Ty>
    Ty* addressof(Ty& arg) {
        detail::CV_ByteRef cv_ref_on_byte = reinterpret_cast<detail::CV_ByteRef>(arg);
        detail::RefByte    ref_on_byte    = const_cast<char&>(cv_ref_on_byte);
        Ty*                addres         = reinterpret_cast<Ty*>(&ref_on_byte);
        return addres;
    }

    template<class T>
    class reference_wrapper {
    public:

        inline explicit reference_wrapper(T& t) : _t(addressof(t)) {}
        /**
        @return The stored reference.
        @remark Does not throw.
        */
        inline operator T& () const { return *_t; }
        /**
         @return The stored reference.
         @remark Does not throw.
        */
        inline T& get() const { return *_t; }
        /**
         @return A pointer to the object referenced by the stored
          reference.
         @remark Does not throw.
        */
        inline T* get_pointer() const { return _t; }

    private:
        T* _t;
    };

    // ref
    /**
    @return `reference_wrapper<T>(t)`
    @remark Does not throw.
    */
    template<class T>
    inline reference_wrapper<T> const ref(T& t)
    {
        return reference_wrapper<T>(t);
    }
    // cref
    /*
    @return `reference_wrapper<T const>(t)`
    @remark Does not throw.
    */
    template<class T>
    inline reference_wrapper<T const> const cref(T const& t)
    {
        return reference_wrapper<T const>(t);
    }

    // is_reference_wrapper

    /**
     @brief Determine if a type `T` is an instantiation of
         `reference_wrapper`.

         The value static constant will be true if the type `T` is a
         specialization of `reference_wrapper`.
        */
    template<typename T>
    struct is_reference_wrapper
    {
        static const bool value = false;
    };

    /**
     @cond
    */
    template<typename T>
    struct is_reference_wrapper< reference_wrapper<T> >
    {
        static const bool value = true;
    };

#if !defined(BOOST_NO_CV_SPECIALIZATIONS)

    template<typename T>
    struct is_reference_wrapper<reference_wrapper<T> const >
    {
        static const bool value = true;
    };

    template<typename T> struct is_reference_wrapper< reference_wrapper<T> volatile >
    {
        static const bool value = true;
    };

    template<typename T> struct is_reference_wrapper< reference_wrapper<T> const volatile >
    {
        static const bool value = true;
    };

#endif // !defined(BOOST_NO_CV_SPECIALIZATIONS)

    /**
    @endcond
    */

    // unwrap_reference
    /**
    @brief Find the type in a `reference_wrapper`.
     The `typedef` type is `T::type` if `T` is a
     `reference_wrapper`, `T` otherwise.
    */
    template<typename T> struct unwrap_reference
    {
        typedef T type;
    };

    /**
     @cond
    */
    template<typename T> struct unwrap_reference< reference_wrapper<T> >
    {
        typedef T type;
    };

#if !defined(BOOST_NO_CV_SPECIALIZATIONS)

    template<typename T>
    struct unwrap_reference< reference_wrapper<T> const >
    {
        typedef T type;
    };

    template<typename T>
    struct unwrap_reference< reference_wrapper<T> volatile >
    {
        typedef T type;
    };

    template<typename T>
    struct unwrap_reference< reference_wrapper<T> const volatile >
    {
        typedef T type;
    };

#endif // !defined(BOOST_NO_CV_SPECIALIZATIONS)

    /**
    @endcond
    */

    // unwrap_ref

    /**
    @return `unwrap_reference<T>::type&(t)`
    @remark Does not throw.
    */
    template<class T>
    inline typename unwrap_reference<T>::type& unwrap_ref(T& t)
    {
        return t;
    }

    // get_pointer
    template<class T>
    inline T* get_pointer(reference_wrapper<T> const& r)
    {
        return r.get_pointer();
    }

} // end namespace metabi
#endif