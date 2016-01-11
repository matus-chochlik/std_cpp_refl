
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[meta_get_aliased
__namespace_meta_begin

template <typename T>
__requires __MetaAlias<T>
struct get_aliased
{

	typedef __MetaNamed type; /*<
	The MetaNamed reflecting the original declaration of a type or namespace alias reflected by a MetaAlias.
	>*/
};

template <typename T>
using get_aliased_t = typename get_aliased<T>::type;

__namespace_meta_end
//]
