
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[example_global_scope
#include __reflexpr_header

int main(void)
{
	using namespace std;

	typedef __reflexpr(::) meta_gs; /*<
	Reflected global scope.
	>*/

	static_assert(__is_metaobject_v<meta_gs>, "");

	static_assert(__meta::__is_global_scope_v<meta_gs>, "");
	static_assert(meta::__is_namespace_v<meta_gs>, "");
	static_assert(!meta::__is_type_v<meta_gs>, "");
	static_assert(!meta::__is_alias_v<meta_gs>, "");

	static_assert(meta::__has_name_v<meta_gs>, "");
	static_assert(!meta::__has_scope_v<meta_gs>, "");

	return 0;
}
//]
