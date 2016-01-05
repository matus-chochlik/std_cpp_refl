
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[meta_has_scope
__namespace_meta_begin


template <typename T>
struct has_scope
{
	static_assert(__is_metaobject_v<T>, "");

	typedef bool value_type;
	static constexpr const bool value = ... /*<
	[^true] if [^T] is a __MetaScoped
	[^false] otherwise.
	>*/;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

template <typename T>
using has_scope_t = typename has_scope<T>::type;

template <typename T>
constexpr bool has_scope_v = has_scope<T>::value;


__namespace_meta_end
//]
