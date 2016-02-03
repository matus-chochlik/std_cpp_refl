
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[meta_reflects_same
__namespace_meta_begin

template <typename T1, typename T2>
__requires __Object<T1> && __Object<T2>
struct reflects_same
{

	typedef bool value_type;
	static constexpr const bool value = ... /*<
	indicates if two metaobjects reflect the same base-level declaration.
	>*/;

	typedef integral_constant<bool, value> type;

	operator bool(void) const noexcept;
	bool operator(void) const noexcept;
};

template <typename T1, typename T2>
using reflects_same_t = typename reflects_same<T1, T2>::type;

template <typename T1, typename T2>
constexpr bool reflects_same_v = reflects_same<T1, T2>::value;

__namespace_meta_end
//]
