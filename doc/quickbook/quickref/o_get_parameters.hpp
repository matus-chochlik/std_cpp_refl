
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[meta_get_parameters
__namespace_meta_begin

template <typename T>
__requires __Function<T>
struct get_parameters
{

	typedef __ObjectSequence type; /*<
	returns a result of elements reflecting the parameters of a Function.
	>*/
};

template <typename T>
using get_parameters_t = typename get_parameters<T>::type;

__namespace_meta_end
//]
