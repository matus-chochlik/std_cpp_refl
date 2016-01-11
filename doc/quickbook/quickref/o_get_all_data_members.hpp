
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[meta_get_all_data_members
__namespace_meta_begin

template <typename T>
__requires __MetaClass<T>
struct get_all_data_members
{

	typedef __MetaobjectSequence type; /*<
	A sequence of Metaobjects reflecting all data members of a class reflected by a MetaClass.
	>*/
};

template <typename T>
using get_all_data_members_t = typename get_all_data_members<T>::type;

__namespace_meta_end
//]
