
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[meta_get_element
__namespace_meta_begin

template <typename T1, size_t Index>
__requires __ObjectSequence<T1>
struct get_element
{

	typedef __Object type; /*<
	returns the i-th result in a ObjectSequence.
	>*/
};

template <typename T1, size_t Index>
using get_element_t = typename get_element<T1, Index>::type;

__namespace_meta_end
//]
