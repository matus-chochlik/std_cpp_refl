
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[meta_get_keyword
__namespace_meta_begin

template <typename T>
__requires __MetaSpecifier<T>
struct get_keyword
{

	typedef const char value_type[N+1];

	static constexpr const char value[N+1] = ... /*<
	The keyword of the specifier reflected by a MetaSpecifier.
	>*/;

	typedef __StringConstant type;

	operator const char* (void) const noexcept;
	const char* operator (void) const noexcept;
};

template <typename T>
using get_keyword_t = typename get_keyword<T>::type;

template <typename T>
constexpr bool get_keyword_v = get_keyword<T>::value;

__namespace_meta_end
//]
