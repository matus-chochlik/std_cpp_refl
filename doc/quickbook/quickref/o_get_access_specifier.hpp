
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[meta_get_access_specifier
__namespace_meta_begin

template <typename T>
__requires __ClassMember<T>
struct get_access_specifier
{

	typedef __Specifier type; /*<
	returns the result reflecting the access specifier of class member reflected by a ClassMember.
	>*/
};

template <typename T>
using get_access_specifier_t = typename get_access_specifier<T>::type;

__namespace_meta_end
//]
