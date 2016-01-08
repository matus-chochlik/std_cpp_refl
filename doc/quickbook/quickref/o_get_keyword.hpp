
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[meta_get_keyword
__namespace_meta_begin

template <typename MetaSpecifier>
struct get_keyword
{

	static_assert(__is_specifier_v<__MetaSpecifier>, "");
	typedef const char value_type[N+1];

	static constexpr const char value[N+1] = ... /*<
	The keyword of the specifier reflected by a MetaSpecifier.
	>*/;

	typedef __StringConstant type;

	operator const char* (void) const noexcept;
	const char* operator (void) const noexcept;

};


template <typename MetaSpecifier>
using get_keyword_t =
	typename get_keyword<MetaSpecifier>::type;

template <typename MetaSpecifier>
constexpr bool get_keyword_v =
	get_keyword<MetaSpecifier>::value;

__namespace_meta_end
//]
