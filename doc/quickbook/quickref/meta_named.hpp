/*
 *  Copyright 2015 Matus Chochlik.
 */

//[reflexpr_meta_named
__namespace_meta_begin

static_assert(__has_name<MetaNamed>::value, "");

template <typename T>
struct get_name
{
	static_assert(__has_name_v<T>, "T must be a MetaNamed"); /*<
	Only applicable to __Metaobject(s).
	>*/

	typedef const char value_type[N+1];

	static constexpr const char value[N+1] = ... /*<
	The basic unqualified name of the reflected object.
	>*/;

	typedef __StringConstant type;

	operator const char* (void) const noexcept; /*<
	Both return [^value] decayed to a pointer.
	>*/
	const char* operator (void) const noexcept;
};

template <typename T>
using get_name_t = typename get_name<T>::type;

template <typename T>
constexpr auto& get_name_v = get_name<T>::value;

__namespace_meta_end
//]

