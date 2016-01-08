
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[meta_get_all_data_members
__namespace_meta_begin

template <typename MetaClass>
struct get_all_data_members
{

	static_assert(__is_class_v<__MetaClass>, "");

	typedef __MetaobjectSequence type; /*<
	A sequence of Metaobjects reflecting the all data members of a class reflected by a MetaClass.
	>*/


};


template <typename MetaClass>
using get_all_data_members_t =
	typename get_all_data_members<MetaClass>::type;

__namespace_meta_end
//]
