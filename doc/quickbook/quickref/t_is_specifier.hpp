
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[meta_is_specifier
__namespace_meta_begin


template <typename T>
__requires __Metaobject<T>
struct is_specifier
{
	typedef bool value_type;
	static constexpr const bool value = ... /*<
	[^true] if [^T] is a __Specifier
	[^false] otherwise.
	>*/;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

template <typename T>
using is_specifier_t = typename is_specifier<T>::type;

template <typename T>
constexpr bool is_specifier_v = is_specifier<T>::value;


__namespace_meta_end
//]
