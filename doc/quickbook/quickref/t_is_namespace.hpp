
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[meta_is_namespace
__namespace_meta_begin


template <typename T>
struct is_namespace
{
	static_assert(__is_metaobject_v<T>, "");

	typedef bool value_type;
	static constexpr const bool value = ... /*<
	[^true] if [^X] is a [concept MetaNamespace]
	[^false] otherwise.
	>*/;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

template <typename T>
using is_namespace_t = typename is_namespace<T>::type;

template <typename T>
constexpr bool is_namespace_v = is_namespace<T>::value;



__namespace_meta_end
//]
