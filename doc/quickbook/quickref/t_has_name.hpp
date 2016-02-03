
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[meta_has_name
__namespace_meta_begin


template <typename T>
__requires __Metaobject<T>
struct has_name
{
	typedef bool value_type;
	static constexpr const bool value = ... /*<
	[^true] if [^T] is a __Named
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
