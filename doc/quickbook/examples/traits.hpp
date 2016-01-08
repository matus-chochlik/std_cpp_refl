
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[example_traits
#include __reflexpr_header

namespace foo {

struct bar { };

} // namespace foo

typedef int baz;

int main(void)
{
	using namespace std;

	typedef __reflexpr(int) meta_int;
	typedef reflexpr(foo::bar) meta_foo_bar;
	typedef reflexpr(baz) meta_baz;
	typedef __meta::__get_scope_t<meta_int> meta_gs;
	typedef meta::__get_scope_t<meta_foo_bar> meta_foo;

	static_assert(!__is_metaobject_v<char>, "");
	static_assert(!is_metaobject_v<int>, "");
	static_assert(is_metaobject_v<meta_int>, "");
	static_assert(is_metaobject_v<meta_foo>, "");
	static_assert(is_metaobject_v<meta_foo_bar>, "");
	static_assert(is_metaobject_v<meta_baz>, "");

	static_assert(meta::__is_global_scope_v<meta_gs>, "");
	static_assert(meta::__is_namespace_v<meta_gs>, "");

	static_assert(meta::__is_namespace_v<meta_foo>, "");

	static_assert(meta::__is_type_v<meta_baz>, "");
	static_assert(meta::__is_alias_v<meta_baz>, "");

	static_assert(meta::__is_class_v<meta_foo_bar>, "");

	return 0;
}
//]
