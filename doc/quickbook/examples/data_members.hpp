
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[example_data_members
#include __reflexpr_header
#include <iostream>

struct foo
{
private:
	int _i, _j;
public:
	static constexpr const bool b = true;
	float x, y, z;
private:
	static double d;
};

int main(void)
{
	using namespace std;

	typedef __reflexpr(foo) meta_foo;

	// (public) data members
	typedef __meta::__get_data_members_t<meta_foo> meta_data_mems;

	static_assert(__is_metaobject_v<meta_data_mems>, "");
	static_assert(meta::__is_sequence_v<meta_data_mems>, "");

	cout << meta::__get_size_v<meta_data_mems> << endl; /*<
	[^4]
	>*/

	// 0-th (public) data member
	typedef meta::__get_element_t<meta_data_mems, 0> meta_data_mem0;

	static_assert(is_metaobject_v<meta_data_mem0>, "");
	static_assert(meta::__is_variable_v<meta_data_mem0>, "");
	static_assert(meta::__has_type_v<meta_data_mem0>, "");

	cout << meta::__get_name_v<meta_data_mem0> << endl; /*<
	[^b]
	>*/

	// 2-nd (public) data member
	typedef meta::get_element_t<meta_data_mems, 2> meta_data_mem2;

	static_assert(is_metaobject_v<meta_data_mem2>, "");
	static_assert(meta::is_variable_v<meta_data_mem2>, "");
	static_assert(meta::has_type_v<meta_data_mem2>, "");

	cout << meta::get_name_v<meta_data_mem2> << endl; /*<
	[^y]
	>*/

	// all data members
	typedef meta::__get_all_data_members_t<meta_foo> meta_all_data_mems;

	static_assert(is_metaobject_v<meta_all_data_mems>, "");
	static_assert(meta::is_sequence_v<meta_all_data_mems>, "");

	cout << meta::get_size_v<meta_all_data_mems> << endl; /*<
	[^7]
	>*/

	// 0-th (overall) data member
	typedef meta::get_element_t<meta_all_data_mems, 0> meta_all_data_mem0;

	static_assert(is_metaobject_v<meta_all_data_mem0>, "");
	static_assert(meta::is_variable_v<meta_all_data_mem0>, "");
	static_assert(meta::has_type_v<meta_all_data_mem0>, "");

	cout << meta::get_name_v<meta_all_data_mem0> << endl; /*<
	[^_i]
	>*/

	// 3-rd (overall) data member
	typedef meta::get_element_t<meta_all_data_mems, 3> meta_all_data_mem3;

	static_assert(is_metaobject_v<meta_all_data_mem3>, "");
	static_assert(meta::is_variable_v<meta_all_data_mem3>, "");
	static_assert(meta::has_type_v<meta_all_data_mem3>, "");

	cout << meta::get_name_v<meta_all_data_mem3> << endl; /*<
	[^x]
	>*/

	return 0;
}
//]
