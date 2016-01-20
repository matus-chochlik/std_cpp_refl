
/*
 *  Copyright 2015-2016 Matus Chochlik.
 */

//[example_data_members_2
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

template <typename ... T>
void eat(T ... ) { }

template <typename Metaobjects, std::size_t I>
int do_print_data_member(void)
{
	using namespace std;

	typedef __meta::__get_element_t<Metaobjects, I> metaobj;

	cout	<< I << ": "
		<< (meta::__is_public_v<metaobj>?"public":"non-public")
		<< " "
		<< (meta::__is_static_v<metaobj>?"static":"")
		<< " "
		<< meta::__get_name_v<meta::__get_type_t<metaobj>>
		<< " "
		<< meta::__get_name_v<metaobj>
		<< endl;

	return 0;
}

template <typename Metaobjects, std::size_t ... I>
void do_print_data_members(std::index_sequence<I...>)
{
	eat(do_print_data_member<Metaobjects, I>()...);
}

template <typename Metaobjects>
void do_print_data_members(void)
{
	using namespace std;

	do_print_data_members<Metaobjects>(
		make_index_sequence<
			meta::__get_size_v<Metaobjects>
		>()
	);
}

template <typename MetaClass>
void print_data_members(void)
{
	using namespace std;

	cout<< "Public data members of " << meta::__get_name_v<MetaClass> << endl;

	do_print_data_members<meta::__get_data_members_t<MetaClass>>();
}

template <typename MetaClass>
void print_all_data_members(void)
{
	using namespace std;

	cout << "All data members of " << meta::get_name_v<MetaClass> << endl;

	do_print_data_members<meta::__get_all_data_members_t<MetaClass>>();
}

int main(void)
{
	print_data_members<__reflexpr(foo)>();
	print_all_data_members<__reflexpr(foo)>();

	return 0;
}

//]
