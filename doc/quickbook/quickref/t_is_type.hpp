
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[meta_is_type
__namespace_meta_begin


template <typename T>
__requires __Metaobject<T>
struct is_type
{
	typedef bool value_type;
	static constexpr const bool value = ... /*<
	[^true] if [^T] is a __Type
	[^false] otherwise.
	>*/;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

template <typename T>
using is_type_t = typename is_type<T>::type;

template <typename T>
constexpr bool is_type_v = is_type<T>::value;


__namespace_meta_end
//]
