/*
 *  Copyright 2015 Matus Chochlik.
 */

//[reflexpr_meta_variable
__namespace_meta_begin

static_assert(__is_variable<MetaVariable>::value, "");

template <typename T>
struct get_type
{
	static_assert(__is_variable<T>, "T must be a MetaVariable");

	typedef __MetaType type; /*<
	The metaobject reflecting the type of the reflected variable
	>*/
};

template <typename T>
using get_type_t = typename get_type<T>::type;

__namespace_meta_end
//]

