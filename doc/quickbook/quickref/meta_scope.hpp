/*
 *  Copyright 2015 Matus Chochlik.
 */

//[reflexpr_meta_scope
__namespace_meta_begin

static_assert(__is_scope<MetaScope>::value, "");

template <typename T>
struct get_members
{
	static_assert(__is_scope<T>, "T must be a MetaScope");

	typedef __MetaobjectSequence type;
};

template <typename T>
using get_members_t = typename get_members<T>::type;

__namespace_meta_end
//]

