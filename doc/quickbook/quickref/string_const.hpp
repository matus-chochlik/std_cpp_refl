/*
 *  Copyright 2015 Matus Chochlik.
 */

//[reflexpr_string_constant

struct StringConstant
{
	typedef const char value_type[N+1];

	static constexpr const char value[N+1] = ... ;

	typedef StringConstant type;

	operator const char* (void) const noexcept; /*<
	Both return [^value] decayed to a pointer.
	>*/
	const char* operator (void) const noexcept;
};
//]

