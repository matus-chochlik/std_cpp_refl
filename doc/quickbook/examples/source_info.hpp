
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[example_source_info
#include __reflexpr_header
#include <iostream>

struct foo { };

int main(void)
{
	using namespace std;

	typedef __reflexpr(int) meta_int; /*<
	Reflected built-in type [^int].
	>*/
	static_assert(__is_metaobject_v<meta_int>, "");

	cout << "name: '" << __meta::__get_name_v<meta_int> << "'" << endl;
	cout << "file: '" << meta::__get_source_file_v<meta_int> << "'" << endl;
	cout << "line: " << meta::__get_source_line_v<meta_int> << endl;
	cout << "col: "<< meta::__get_source_column_v<meta_int> << endl;

	typedef reflexpr(foo) meta_foo; /*<
	Reflected [^struct foo].
	>*/
	static_assert(is_metaobject_v<meta_foo>, "");

	cout << "name: '" << meta::get_name_v<meta_foo> << "'" << endl;
	cout << "file: '" << meta::get_source_file_v<meta_foo> << "'" << endl;
	cout << "line: " << meta::get_source_line_v<meta_foo> << endl;
	cout << "col: "<< meta::get_source_column_v<meta_foo> << endl;

	return 0;
}
//]
