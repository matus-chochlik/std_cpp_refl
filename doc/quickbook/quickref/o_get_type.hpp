
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[meta_get_type
__namespace_meta_begin

template <typename T>
__requires __Typed<T>
struct get_type
{

	typedef __Type type; /*<
	returns the result reflecting the type of base-level declaration with a type reflected by a Typed.
	>*/
};

template <typename T>
using get_type_t = typename get_type<T>::type;

__namespace_meta_end
//]
