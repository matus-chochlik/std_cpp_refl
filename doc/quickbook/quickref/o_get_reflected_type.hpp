
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[meta_get_reflected_type
__namespace_meta_begin

template <typename T>
__requires __MetaType<T>
struct get_reflected_type
{

	typedef __Type type; /*<
	returns the the base-level type reflected by a MetaType.
	>*/
};

template <typename T>
using get_reflected_type_t = typename get_reflected_type<T>::type;

__namespace_meta_end
//]
