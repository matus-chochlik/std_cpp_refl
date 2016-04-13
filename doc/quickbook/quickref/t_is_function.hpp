
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[meta_is_function
__namespace_meta_begin


template <typename T>
__requires __Metaobject<T>
struct is_function
{
	typedef bool value_type;
	static constexpr const bool value = ... /*<
	[^true] if [^T] is a __Function
	[^false] otherwise.
	>*/;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

template <typename T>
using is_function_t = typename is_function<T>::type;

template <typename T>
constexpr bool is_function_v = is_function<T>::value;


__namespace_meta_end
//]
