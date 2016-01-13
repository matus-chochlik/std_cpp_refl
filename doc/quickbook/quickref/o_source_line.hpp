
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[meta_source_line
__namespace_meta_begin

template <typename T>
__requires __Metaobject<T>
struct source_line
{

	typedef unsigned value_type;
	static constexpr const unsigned value = ... /*<
	returns the source file line of the declaration of a base-level program feature reflected by a Metaobject.
	>*/;

	typedef integral_constant<unsigned, value> type;

	operator value_type(void) const noexcept;
	value_type operator(void) const noexcept;
};

template <typename T>
using source_line_t = typename source_line<T>::type;

template <typename T>
constexpr bool source_line_v = source_line<T>::value;

__namespace_meta_end
//]
