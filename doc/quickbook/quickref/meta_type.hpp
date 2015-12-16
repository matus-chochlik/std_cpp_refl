/*
 *  Copyright 2015 Matus Chochlik.
 */

//[reflexpr_meta_type
__namespace_meta_begin

static_assert(__is_type<MetaType>::value, "");

template <typename T>
struct get_reflected_type
{
	static_assert(__is_type<T>, "T must be a MetaType");

	typedef __unspecified type; /*<
	The original, base-level type reflected by the MetaType
	>*/
};

template <typename T>
using get_reflected_type_t = typename get_reflected_type<T>::type;

__namespace_meta_end
//]

