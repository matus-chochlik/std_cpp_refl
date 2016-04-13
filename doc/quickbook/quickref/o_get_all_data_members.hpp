
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[meta_get_all_data_members
__namespace_meta_begin

template <typename T>
__requires __Class<T>
struct get_all_data_members
{

	typedef __ObjectSequence type; /*<
	returns a result of elements reflecting all   (including the private and protected)   data members of a class reflected by a Class.
	>*/
};

template <typename T>
using get_all_data_members_t = typename get_all_data_members<T>::type;

__namespace_meta_end
//]
