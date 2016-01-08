
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[meta_get_name
__namespace_meta_begin

template <typename MetaNamed>
struct get_name
{

	static_assert(__has_name_v<__MetaNamed>, "");
	typedef const char value_type[N+1];

	static constexpr const char value[N+1] = ... /*<
	The basic name of the a named declaration reflected by a MetaNamed.
	>*/;

	typedef __StringConstant type;

	operator const char* (void) const noexcept;
	const char* operator (void) const noexcept;

};


template <typename MetaNamed>
using get_name_t =
	typename get_name<MetaNamed>::type;

template <typename MetaNamed>
constexpr bool get_name_v =
	get_name<MetaNamed>::value;

__namespace_meta_end
//]
