
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[meta_source_column
__namespace_meta_begin

template <typename T>
__requires __Metaobject<T>
struct source_column
{

	typedef unsigned value_type;
	static constexpr const unsigned value = ... /*<
	returns the source file column of the declaration of a base-level program feature reflected by a Metaobject.
	>*/;

	typedef integral_constant<unsigned, value> type;

	operator value_type(void) const noexcept;
	value_type operator(void) const noexcept;
};

template <typename T>
using source_column_t = typename source_column<T>::type;

template <typename T>
constexpr bool source_column_v = source_column<T>::value;

__namespace_meta_end
//]
