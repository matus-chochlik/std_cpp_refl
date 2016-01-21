
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[example_typedefs_2
#include __reflexpr_header
#include <iostream>

struct foo { };
typedef foo bar;

int main(void)
{
	using namespace std;

	typedef __reflexpr(bar) meta_bar;

	static_assert(__is_metaobject_v<meta_bar>, "");
	static_assert(__meta::__is_type_v<meta_bar>, "");
	static_assert(meta::__is_class_v<meta_bar>, "");
	static_assert(meta::__is_alias_v<meta_bar>, "");

	static_assert(__is_same_v<
		meta::__get_reflected_type_t<meta_bar>,
		bar
	>, "");

	static_assert(meta::__has_name_v<meta_bar>, "");
	cout << meta::__get_name_v<meta_bar> << endl;

	typedef meta::__get_aliased_t<meta_bar> meta_foo;

	static_assert(is_metaobject_v<meta_foo>, "");
	static_assert(meta::is_type_v<meta_foo>, "");
	static_assert(meta::is_class_v<meta_foo>, "");
	static_assert(!meta::is_alias_v<meta_foo>, "");

	static_assert(is_same_v<
		meta::get_reflected_type_t<meta_foo>,
		foo
	>, "");

	static_assert(meta::has_name_v<meta_foo>, "");
	cout << meta::get_name_v<meta_foo> << endl;

	return 0;
}
//]
