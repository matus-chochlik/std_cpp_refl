
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[meta_is_alias
__namespace_meta_begin


template <typename T>
__requires __Metaobject<T>
struct is_alias
{
	typedef bool value_type;
	static constexpr const bool value = ... /*<
	[^true] if [^T] is a __MetaAlias
	[^false] otherwise.
	>*/;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

template <typename T>
using is_alias_t = typename is_alias<T>::type;

template <typename T>
constexpr bool is_alias_v = is_alias<T>::value;


__namespace_meta_end
//]
