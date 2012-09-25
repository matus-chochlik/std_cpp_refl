/**
 *  @author Matus Chochlik
 *
 *  Copyright 2006-2012 Matus Chochlik. Distributed under the Boost
 *  Software License, Version 1.0. (See accompanying file
 *  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef STD_CPP_REFL_BITS_CT_STRING_1205280839_HPP
#define STD_CPP_REFL_BITS_CT_STRING_1205280839_HPP

#include <type_traits>

namespace std {

template <typename Position, char ... C>
struct _ct_string_at;

template <typename Position, char F, char ... C>
struct _ct_string_at<Position, F, C...>
 : _ct_string_at<
	integral_constant<
		int,
		Position::value - 1
	>,
	C...
> { };

template <char F, char ... C>
struct _ct_string_at<integral_constant<int, 0>, F, C...>
{
	typedef integral_constant<char, F> type;
};

template <char ... C>
struct _ct_string
{
	static const char* c_str(void)
	{
		static const char _result[] = {C..., '\0'};
		return _result;
	}

	static integral_constant<int, sizeof...(C)> size(void)
	{
		return integral_constant<int, sizeof...(C)>();
	}

	template <int I>
	static auto at(integral_constant<int, I>) ->
	typename _ct_string_at<integral_constant<int, I>, C...>::type
	{
		return typename _ct_string_at<
			integral_constant<int, I>,
			C...
		>::type();
	}
};

} // namespace std

#endif // include guard
