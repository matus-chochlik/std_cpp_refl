
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[meta_get_type
__namespace_meta_begin

template <typename MetaTyped>
struct get_type
{

	static_assert(__has_type_v<__MetaTyped>, "");

	typedef __MetaType type; /*<
	The MetaType reflecting the type of base-level construct with a type reflected by a MetaTyped.
	>*/


};


template <typename MetaTyped>
using get_type_t =
	typename get_type<MetaTyped>::type;

__namespace_meta_end
//]
