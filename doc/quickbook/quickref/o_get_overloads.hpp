
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[meta_get_overloads
__namespace_meta_begin

template <typename T>
__requires __OverloadedFunction<T>
struct get_overloads
{

	typedef __ObjectSequence type; /*<
	returns a result of the element reflecting the concrete overloads of a OverloadedFunction.
	>*/
};

template <typename T>
using get_overloads_t = typename get_overloads<T>::type;

__namespace_meta_end
//]
