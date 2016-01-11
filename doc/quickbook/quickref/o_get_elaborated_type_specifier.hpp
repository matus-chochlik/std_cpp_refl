
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[meta_get_elaborated_type_specifier
__namespace_meta_begin

template <typename MetaClass>
struct get_elaborated_type_specifier
{

	static_assert(__is_class_v<__MetaClass>, "");

	typedef __MetaSpecifier type; /*<
	A MetaSpecifier reflecting the elaborated type specifier (class,struct,union,...) of a class reflected by a MetaClass.
	>*/


};


template <typename MetaClass>
using get_elaborated_type_specifier_t =
	typename get_elaborated_type_specifier<MetaClass>::type;

__namespace_meta_end
//]
