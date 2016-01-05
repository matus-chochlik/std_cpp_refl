
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[meta_is_global_scope
__namespace_meta_begin


template <typename T>
struct is_global_scope
{
	static_assert(__is_metaobject_v<T>, "");

	typedef bool value_type;
	static constexpr const bool value = ... /*<
	[^true] if [^X] is a [concept MetaGlobalScope]
	[^false] otherwise.
	>*/;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

template <typename T>
using is_global_scope_t = typename is_global_scope<T>::type;

template <typename T>
constexpr bool is_global_scope_v = is_global_scope<T>::value;



__namespace_meta_end
//]
