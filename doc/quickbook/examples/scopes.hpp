
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[example_scopes
#include __reflexpr_header
#include <iostream>

namespace foo {

struct bar
{
	typedef int baz;
};

} // namespace foo

typedef long foobar;

int main(void)
{
	using namespace std;

	typedef __reflexpr(int) meta_int;
	typedef reflexpr(foo::bar) meta_foo_bar;
	typedef reflexpr(foo::bar::baz) meta_foo_bar_baz;
	typedef reflexpr(foobar) meta_foobar;

	static_assert(__meta::__has_scope_v<meta_int>, "");
	static_assert(meta::has_scope_v<meta_foo_bar>, "");
	static_assert(meta::has_scope_v<meta_foo_bar_baz>, "");
	static_assert(meta::has_scope_v<meta_foobar>, "");

	typedef meta::__get_scope_t<meta_int> meta_int_s;
	typedef meta::get_scope_t<meta_foo_bar> meta_foo_bar_s;
	typedef meta::get_scope_t<meta_foo_bar_baz> meta_foo_bar_baz_s;
	typedef meta::get_scope_t<meta_foobar> meta_foobar_s;

	static_assert(meta::__is_scope_v<meta_int_s>, "");
	static_assert(meta::is_scope_v<meta_foo_bar_s>, "");
	static_assert(meta::is_scope_v<meta_foo_bar_baz_s>, "");
	static_assert(meta::is_scope_v<meta_foobar_s>, "");

	static_assert(meta::__is_namespace_v<meta_int_s>, "");
	static_assert(meta::__is_global_scope_v<meta_int_s>, "");
	static_assert(meta::is_namespace_v<meta_foo_bar_s>, "");
	static_assert(!meta::is_global_scope_v<meta_foo_bar_s>, "");
	static_assert(meta::__is_type_v<meta_foo_bar_baz_s>, "");
	static_assert(meta::__is_class_v<meta_foo_bar_baz_s>, "");
	static_assert(!meta::is_namespace_v<meta_foo_bar_baz_s>, "");
	static_assert(meta::is_namespace_v<meta_foobar_s>, "");
	static_assert(meta::is_global_scope_v<meta_foobar_s>, "");
	static_assert(!meta::is_class_v<meta_foobar_s>, "");

	cout << meta::__get_name_v<meta_foo_bar_baz> << endl;
	cout << meta::get_name_v<meta_foo_bar_baz_s> << endl;
	cout << meta::get_name_v<meta_foo_bar_s> << endl;

	return 0;
}
//]
