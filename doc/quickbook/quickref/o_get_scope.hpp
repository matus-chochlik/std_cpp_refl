
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[meta_get_scope
__namespace_meta_begin

template <typename T>
__requires __MetaScoped<T>
struct get_scope
{

	typedef __MetaScope type; /*<
	returns the MetaScope reflecting the scope of a scoped declaration reflected by a MetaScoped.
	>*/
};

template <typename T>
using get_scope_t = typename get_scope<T>::type;

__namespace_meta_end
//]
