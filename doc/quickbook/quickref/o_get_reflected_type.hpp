
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[meta_get_reflected_type
__namespace_meta_begin

template <typename MetaType>
struct get_reflected_type
{

	static_assert(__is_type_v<__MetaType>, "");

	typedef __Type type; /*<
	The the base-level type reflected by a MetaType.
	>*/


};


template <typename MetaType>
using get_reflected_type_t =
	typename get_reflected_type<MetaType>::type;

__namespace_meta_end
//]
