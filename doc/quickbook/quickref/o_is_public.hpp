
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[meta_is_public
__namespace_meta_begin

template <typename T>
__requires __ClassMember<T>
struct is_public
{

	typedef bool value_type;
	static constexpr const bool value = ... /*<
	returns whether the class member reflected by a ClassMember was declared with public access.
	>*/;

	typedef integral_constant<bool, value> type;

	operator bool(void) const noexcept;
	bool operator(void) const noexcept;
};

template <typename T>
using is_public_t = typename is_public<T>::type;

template <typename T>
constexpr bool is_public_v = is_public<T>::value;

__namespace_meta_end
//]
