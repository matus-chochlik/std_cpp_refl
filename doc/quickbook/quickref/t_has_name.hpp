
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[meta_has_name
__namespace_meta_begin


template <typename T>
struct has_name
{
	static_assert(__is_metaobject_v<T>, "");

	typedef bool value_type;
	static constexpr const bool value = ... /*<
	[^true] if [^X] is a [concept MetaNamed]
	[^false] otherwise.
	>*/;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

template <typename T>
using has_name_t = typename has_name<T>::type;

template <typename T>
constexpr bool has_name_v = has_name<T>::value;



__namespace_meta_end
//]
