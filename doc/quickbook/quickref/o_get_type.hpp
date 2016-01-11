
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[meta_get_type
__namespace_meta_begin

template <typename T>
__requires __MetaTyped<T>
struct get_type
{

	typedef __MetaType type; /*<
	The MetaType reflecting the type of base-level construct with a type reflected by a MetaTyped.
	>*/
};

template <typename T>
using get_type_t = typename get_type<T>::type;

__namespace_meta_end
//]
