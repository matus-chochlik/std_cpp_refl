
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[meta_get_aliased
__namespace_meta_begin

template <typename MetaAlias>
struct get_aliased
{

	static_assert(__is_alias_v<__MetaAlias>, "");

	typedef __MetaNamed type; /*<
	The MetaNamed reflecting the original declaration of a type or namespace alias reflected by a MetaAlias.
	>*/


};


template <typename MetaAlias>
using get_aliased_t =
	typename get_aliased<MetaAlias>::type;

__namespace_meta_end
//]
