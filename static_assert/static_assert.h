#ifdef _STDEX_NATIVE_CPP11_SUPPORT
#define STATIC_ASSERT(expression, message) static_assert((expression), #message)
#else // no C++11 support
#define CONCATENATE(arg1, arg2)   CONCATENATE1(arg1, arg2)
#define CONCATENATE1(arg1, arg2)  CONCATENATE2(arg1, arg2)
#define CONCATENATE2(arg1, arg2)  arg1##arg2

#define STATIC_ASSERT(expression, message)\
struct CONCATENATE(__static_assertion_at_line_, __LINE__)\
{\
	stdex::detail::StaticAssertion<static_cast<bool>((expression))> CONCATENATE(CONCATENATE(CONCATENATE(STATIC_ASSERTION_FAILED_AT_LINE_, __LINE__), _WITH__), message);\
};\
typedef stdex::detail::StaticAssertionTest<sizeof(CONCATENATE(__static_assertion_at_line_, __LINE__))> CONCATENATE(__static_assertion_test_at_line_, __LINE__)

#ifndef _STDEX_NATIVE_NULLPTR_SUPPORT
#define static_assert(expression, message) STATIC_ASSERT(expression, ERROR_MESSAGE_STRING)
#endif
#endif

namespace stdex
{
	namespace detail {

		template <bool>
		struct StaticAssertion;

		template <>
		struct StaticAssertion<true>
		{
		}; // StaticAssertion<true>

		template<int i>
		struct StaticAssertionTest
		{
		}; // StaticAssertionTest<int>
	}
}