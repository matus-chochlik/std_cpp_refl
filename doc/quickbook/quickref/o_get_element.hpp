
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[meta_get_element
__namespace_meta_begin

template <typename T1, size_t Index>
__requires __MetaobjectSequence<T1>
struct get_element
{

	typedef __Metaobject type; /*<
	The i-th element in a MetaobjectSequence
	>*/
};

template <typename T1, size_t Index>
using get_element_t = typename get_element<T1, Index>::type;

__namespace_meta_end
//]
