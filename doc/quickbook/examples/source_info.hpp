
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

	typedef __reflexpr(foo) meta_foo; /*<
	Reflected [^struct foo].
	>*/

	static_assert(__is_metaobject_v<meta_foo>, "");

	cout << "name: " << __meta::__get_name_v<meta_foo> << endl;
	cout << "file: " << meta::__source_file_v<meta_foo> << endl;
	cout << "line: " << meta::__source_line_v<meta_foo> << endl;
	cout << "col: "<< meta::__source_column_v<meta_foo> << endl;

	return 0;
}
//]
