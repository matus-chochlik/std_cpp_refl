/*
 *  Copyright 2015 Matus Chochlik.
 */

//[reflexpr_meta_scoped
__namespace_meta_begin

static_assert(__has_scope<MetaScoped>::value, "");

template <typename T>
struct get_scope
{
	static_assert(__has_scope<T>, "T must be a MetaScoped");

	typedef __MetaScope type;
};

template <typename T>
using get_scope_t = typename get_scope<T>::type;

__namespace_meta_end
//]

