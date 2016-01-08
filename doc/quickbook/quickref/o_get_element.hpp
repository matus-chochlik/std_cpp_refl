
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[meta_get_element
__namespace_meta_begin

template <typename MetaobjectSequence, size_t Index>
struct get_element
{

	static_assert(__is_sequence_v<__MetaobjectSequence>, "");

	typedef __Metaobject type; /*<
	The i-th element in a MetaobjectSequence
	>*/


};


template <typename MetaobjectSequence, size_t Index>
using get_element_t =
	typename get_element<MetaobjectSequence, Index>::type;

__namespace_meta_end
//]
