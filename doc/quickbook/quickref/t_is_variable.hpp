
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[meta_is_variable
__namespace_meta_begin


template <typename T>
__requires __Metaobject<T>
struct is_variable
{
	typedef bool value_type;
	static constexpr const bool value = ... /*<
	[^true] if [^T] is a __MetaVariable
	[^false] otherwise.
	>*/;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

template <typename T>
using is_variable_t = typename is_variable<T>::type;

template <typename T>
constexpr bool is_variable_v = is_variable<T>::value;


__namespace_meta_end
//]
