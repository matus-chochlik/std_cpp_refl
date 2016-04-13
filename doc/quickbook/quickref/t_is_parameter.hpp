
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[meta_is_parameter
__namespace_meta_begin


template <typename T>
__requires __Metaobject<T>
struct is_parameter
{
	typedef bool value_type;
	static constexpr const bool value = ... /*<
	[^true] if [^T] is a __Parameter
	[^false] otherwise.
	>*/;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

template <typename T>
using is_parameter_t = typename is_parameter<T>::type;

template <typename T>
constexpr bool is_parameter_v = is_parameter<T>::value;


__namespace_meta_end
//]
