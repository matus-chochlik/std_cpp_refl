/**
 *  @author Matus Chochlik
 *
 *  Copyright 2006-2012 Matus Chochlik. Distributed under the Boost
 *  Software License, Version 1.0. (See accompanying file
 *  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#include <iostream>
#include <metaobject_traits.hpp>

typedef int fubar;

namespace foo {

struct bar
{
	int baz;
};

} // namespace foo

/*
namespace std {
namespace _refl {

struct _
{
        typedef global_scope_tag category;
        typedef true_type has_name;
        typedef true_type has_scope;
        typedef true_type is_scope;
        typedef false_type is_class_member;
        typedef false_type has_template;
        typedef false_type is_template;

        static std::_ct_string<> base_name(void)
        {
                return std::_ct_string<>();
        }

	static _mirrored<_> scope(void)
	{
		return _mirrored<_>();
	}
};

namespace foo { }

struct foo_
{
        typedef namespace_tag category;
        typedef true_type has_name;
        typedef true_type has_scope;
        typedef true_type is_scope;
        typedef false_type is_class_member;
        typedef false_type has_template;
        typedef false_type is_template;

        static std::_ct_string<'f', 'o', 'o'> base_name(void)
        {
                return std::_ct_string<'f', 'o', 'o'>();
        }

	static _mirrored<_> scope(void)
	{
		return _mirrored<_>();
	}
};

} // namespace _refl
} // namespace std


template <typename T, T v>
T bla(std::integral_constant<T, v>)
{
	return v;
}
*/

int main(void)
{
/*
	auto x = mirrored(foo).base_name();
	std::cout << x.c_str() << std::endl;
	std::cout << bla(x.size()) << std::endl;
	std::cout << bla(x.at(std::integral_constant<int, 0>())) << std::endl;
	std::cout << bla(x.at(std::integral_constant<int, 1>())) << std::endl;
	std::cout << bla(x.at(std::integral_constant<int, 2>())) << std::endl;
*/
	return 0;
}

