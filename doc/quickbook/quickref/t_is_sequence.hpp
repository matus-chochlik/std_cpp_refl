
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[meta_is_sequence
__namespace_meta_begin


template <typename T>
struct is_sequence
{
	static_assert(__is_metaobject_v<T>, "");

	typedef bool value_type;
	static constexpr const bool value = ... /*<
	[^true] if [^X] is a [concept MetaobjectSequence]
	[^false] otherwise.
	>*/;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

template <typename T>
using is_sequence_t = typename is_sequence<T>::type;

template <typename T>
constexpr bool is_sequence_v = is_sequence<T>::value;



__namespace_meta_end
//]
