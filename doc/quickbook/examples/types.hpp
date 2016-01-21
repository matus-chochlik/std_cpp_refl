
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[example_types
#include __reflexpr_header
#include <iostream>

int main(void)
{
	using namespace std;

	typedef __reflexpr(unsigned) meta_unsigned; /*<
	Reflected type [^unsigned].
	>*/

	static_assert(__is_metaobject_v<meta_unsigned>, "");
	static_assert(__meta::__is_type_v<meta_unsigned>, "");
	static_assert(!__meta::__is_alias_v<meta_unsigned>, "");

	static_assert(__is_same_v<
		meta::__get_reflected_type_t<meta_unsigned>,
		unsigned
	>, "");

	static_assert(meta::__has_name_v<meta_unsigned>, "");
	cout << meta::__get_name_v<meta_unsigned> << endl;

	typedef reflexpr(unsigned*) meta_ptr_unsigned;
	static_assert(meta::has_name_v<meta_ptr_unsigned>, "");
	cout << meta::get_name_v<meta_ptr_unsigned> << endl;

	return 0;
}
//]
