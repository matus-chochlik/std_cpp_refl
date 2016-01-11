
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[example_specifiers
#include __reflexpr_header
#include <iostream>

class some_class { };

struct some_struct { };

union some_union { };

enum some_enum { value };

enum class some_enum_class { value };

int main(void)
{
	using namespace std;

	typedef __meta::__get_elaborated_type_specifier_t<__reflexpr(some_class)>
		spec_class;
	typedef meta::get_elaborated_type_specifier_t<reflexpr(some_struct)>
		spec_struct;
	typedef meta::get_elaborated_type_specifier_t<reflexpr(some_union)>
		spec_union;
	typedef meta::get_elaborated_type_specifier_t<reflexpr(some_enum)>
		spec_enum;
	typedef meta::get_elaborated_type_specifier_t<reflexpr(some_enum_class)>
		spec_enum_class;

	cout << meta::__get_keyword_v<spec_class> << endl;
	cout << meta::get_keyword_v<spec_struct> << endl;
	cout << meta::get_keyword_v<spec_union> << endl;
	cout << meta::get_keyword_v<spec_enum> << endl;
	cout << meta::get_keyword_v<spec_enum_class> << endl;

	return 0;
}
//]
