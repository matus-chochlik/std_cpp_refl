
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[meta_is_linkable
__namespace_meta_begin


template <typename T>
__requires __Metaobject<T>
struct is_linkable
{
	typedef bool value_type;
	static constexpr const bool value = ... /*<
	[^true] if [^T] is a __MetaLinkable
	[^false] otherwise.
	>*/;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

template <typename T>
using is_linkable_t = typename is_linkable<T>::type;

template <typename T>
constexpr bool is_linkable_v = is_linkable<T>::value;


__namespace_meta_end
//]
