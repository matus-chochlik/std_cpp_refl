
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[meta_get_typedef_type
__namespace_meta_begin

template <typename T>
__requires __MetaTypeAlias<T>
struct get_typedef_type
{

	typedef __MetaType type; /*<
	The MetaType reflecting the original declaration of a type reflected by a MetaTypeAlias.
	>*/
};

template <typename T>
using get_typedef_type_t = typename get_typedef_type<T>::type;

__namespace_meta_end
//]
