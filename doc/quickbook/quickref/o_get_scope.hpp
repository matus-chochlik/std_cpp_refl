
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[meta_get_scope
__namespace_meta_begin

template <typename T>
__requires __Scoped<T>
struct get_scope
{

	typedef __Scope type; /*<
	returns the Scope reflecting the scope of a scoped declaration reflected by a Scoped.
	>*/
};

template <typename T>
using get_scope_t = typename get_scope<T>::type;

__namespace_meta_end
//]
