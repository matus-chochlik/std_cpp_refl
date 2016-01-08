
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[example_typedefs
#include __reflexpr_header
#include <iostream>

namespace foo {

typedef int bar;
typedef bar baz;

} // namespace foo

int main(void)
{
	using namespace std;

	// reflected typedef foo::baz
	typedef __reflexpr(foo::baz) meta_foo_baz;

	static_assert(__is_metaobject_v<meta_foo_baz>, "");
	static_assert(__meta::__is_type_v<meta_foo_baz>, "");
	static_assert(meta::__is_alias_v<meta_foo_baz>, "");

	static_assert(is_same<
		meta::__get_reflected_type_t<meta_foo_baz>,
		foo::baz
	>::value, "");

	static_assert(meta::__has_name_v<meta_foo_baz>, "");
	cout << meta::__get_name_v<meta_foo_baz> << endl;

	// getting the reflected typedef foo::bar
	typedef meta::__get_typedef_type_t<meta_foo_baz> meta_foo_bar;

	static_assert(is_metaobject_v<meta_foo_bar>, "");
	static_assert(meta::is_type_v<meta_foo_bar>, "");
	static_assert(meta::is_alias_v<meta_foo_bar>, "");

	static_assert(is_same<
		meta::get_reflected_type_t<meta_foo_bar>,
		foo::bar
	>::value, "");

	static_assert(meta::has_name_v<meta_foo_bar>, "");
	cout << meta::get_name_v<meta_foo_bar> << endl;

	// getting the reflected type int
	typedef meta::get_aliased_t<meta_foo_bar> meta_int;

	static_assert(is_metaobject_v<meta_int>, "");
	static_assert(meta::is_type_v<meta_int>, "");
	static_assert(!meta::is_alias_v<meta_int>, "");

	static_assert(is_same<
		meta::get_reflected_type_t<meta_int>,
		int
	>::value, "");

	static_assert(meta::has_name_v<meta_int>, "");
	cout << meta::get_name_v<meta_int> << endl;

	return 0;
}
//]
