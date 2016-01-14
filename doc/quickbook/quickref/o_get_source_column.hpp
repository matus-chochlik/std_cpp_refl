
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[meta_get_source_column
__namespace_meta_begin

template <typename T>
__requires __Metaobject<T>
struct get_source_column
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
using get_source_column_t = typename get_source_column<T>::type;

template <typename T>
constexpr bool get_source_column_v = get_source_column<T>::value;

__namespace_meta_end
//]
