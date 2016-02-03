
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[meta_is_static
__namespace_meta_begin

template <typename T>
__requires __Linkable<T>
struct is_static
{

	typedef bool value_type;
	static constexpr const bool value = ... /*<
	returns whether the declaration with storage duration and/or linkage reflected by a Linkable was declared with the static specifier.
	>*/;

	typedef integral_constant<bool, value> type;

	operator bool(void) const noexcept;
	bool operator(void) const noexcept;
};

template <typename T>
using is_static_t = typename is_static<T>::type;

template <typename T>
constexpr bool is_static_v = is_static<T>::value;

__namespace_meta_end
//]
