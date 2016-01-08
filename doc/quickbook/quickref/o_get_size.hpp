
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[meta_get_size
__namespace_meta_begin

template <typename MetaobjectSequence>
struct get_size
{

	static_assert(__is_sequence_v<__MetaobjectSequence>, "");
	typedef size_t value_type;
	static constexpr const size_t value = ... /*<
	Number of elements in the sequence.
	>*/;

	typedef __StringConstant type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;

};


template <typename MetaobjectSequence>
using get_size_t =
	typename get_size<MetaobjectSequence>::type;

template <typename MetaobjectSequence>
constexpr bool get_size_v =
	get_size<MetaobjectSequence>::value;

__namespace_meta_end
//]
