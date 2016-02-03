
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[meta_get_aliased
__namespace_meta_begin

template <typename T>
__requires __Alias<T>
struct get_aliased
{

	typedef __Named type; /*<
	returns the Named reflecting the original declaration of a type or namespace alias reflected by a Alias.
	>*/
};

template <typename T>
using get_aliased_t = typename get_aliased<T>::type;

__namespace_meta_end
//]
