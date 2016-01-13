
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[meta_get_name
__namespace_meta_begin

template <typename T>
__requires __MetaNamed<T>
struct get_name
{

	typedef const char value_type[N+1];

	static constexpr const char value[N+1] = ... /*<
	returns the basic name of the a named declaration reflected by a MetaNamed.
	>*/;

	typedef __StringConstant type;

	operator const char*(void) const noexcept;
	const char* operator(void) const noexcept;
};

template <typename T>
using get_name_t = typename get_name<T>::type;

template <typename T>
constexpr bool get_name_v = get_name<T>::value;

__namespace_meta_end
//]
