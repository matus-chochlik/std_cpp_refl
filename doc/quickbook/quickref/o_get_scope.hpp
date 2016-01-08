
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[meta_get_scope
__namespace_meta_begin

template <typename MetaScoped>
struct get_scope
{

	static_assert(__has_scope_v<__MetaScoped>, "");

	typedef __MetaScope type; /*<
	The MetaScope reflecting the scope of a scoped declaration reflected by a MetaScoped.
	>*/


};


template <typename MetaScoped>
using get_scope_t =
	typename get_scope<MetaScoped>::type;

__namespace_meta_end
//]
