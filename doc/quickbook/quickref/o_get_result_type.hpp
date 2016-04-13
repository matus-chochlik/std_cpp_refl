
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[meta_get_result_type
__namespace_meta_begin

template <typename T>
__requires __Function<T>
struct get_result_type
{

	typedef __Type type; /*<
	returns a result reflecting the return type of a Function.
	>*/
};

template <typename T>
using get_result_type_t = typename get_result_type<T>::type;

__namespace_meta_end
//]
