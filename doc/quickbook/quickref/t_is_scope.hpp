
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[meta_is_scope
__namespace_meta_begin


template <typename T>
__requires __Metaobject<T>
struct is_scope
{
	typedef bool value_type;
	static constexpr const bool value = ... /*<
	[^true] if [^T] is a __Scope
	[^false] otherwise.
	>*/;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

template <typename T>
using is_scope_t = typename is_scope<T>::type;

template <typename T>
constexpr bool is_scope_v = is_scope<T>::value;


__namespace_meta_end
//]
