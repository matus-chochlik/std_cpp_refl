
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[example_base_names_tpl
#include __reflexpr_header
#include <iostream>

template <typename T>
void print_base_name(void)
{
	using namespace std;

	typedef __reflexpr(T) meta_T;

	cout << __meta::__get_name_v<meta_T> << endl;
	cout << meta::__get_name_v<meta::__get_aliased_t<meta_T>> << endl;
}

int main(void)
{
	print_base_name<int>();
	print_base_name<double>();
	print_base_name<std::istream>();

	return 0;
}
//]
