/*
 *  Copyright 2015 Matus Chochlik.
 */

//[reflexpr_meta_type_alias
__namespace_meta_begin

static_assert(__is_type<MetaTypeAlias>::value, "");
static_assert(__is_alias<MetaTypeAlias>::value, "");

template <typename T>
struct get_typedef_type
{
	static_assert(__is_type<T>, "T must be a MetaType");
	static_assert(__is_alias<T>, "T must be a MetaAlias");

	typedef __MetaType type; /*<
	The metaobject reflecting the aliased type.
	>*/
};

template <typename T>
using get_typedef_type_t = typename get_typedef_type<T>::type;

__namespace_meta_end
//]

