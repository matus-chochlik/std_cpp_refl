
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[meta_get_reflected_type
__namespace_meta_begin

template <typename T>
__requires __Type<T>
struct get_reflected_type
{

	typedef __OriginalType type; /*<
	returns the the base-level type reflected by a Type.
	>*/
};

template <typename T>
using get_reflected_type_t = typename get_reflected_type<T>::type;

__namespace_meta_end
//]
