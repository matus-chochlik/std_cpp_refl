
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[meta_get_typedef_type
__namespace_meta_begin

template <typename MetaTypeAlias>
struct get_typedef_type
{

	static_assert(__is_type_v<__MetaTypeAlias>, "");
	static_assert(__is_alias_v<__MetaTypeAlias>, "");

	typedef __MetaType type; /*<
	The MetaType reflecting the original declaration of a type reflected by a MetaTypeAlias.
	>*/


};


template <typename MetaTypeAlias>
using get_typedef_type_t =
	typename get_typedef_type<MetaTypeAlias>::type;

__namespace_meta_end
//]
