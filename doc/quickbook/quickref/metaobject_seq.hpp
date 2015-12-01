/*
 *  Copyright 2015 Matus Chochlik.
 */

//[reflexpr_metaobject_sequence

struct MetaobjectSequence { };

__namespace_meta_begin

template <typename T>
struct get_size
{
	static_assert(__is_metaobject_v<T>, "T must be a Metaobject");

	typedef unsigned value_type;

	static constexpr size_t value = ... /*<
	The path to the source file column.
	>*/;

	typedef __integral_constant<value_type, value> type;

	operator size_t (void) const noexcept; /*<
	Both return [^value].
	>*/
	size_t operator (void) const noexcept;
};

template <typename T>
using get_size_t = typename get_size<T>::type;

template <typename T>
constexpr size_t get_size_v = get_size<T>::value;


template <typename T, size_t N>
struct get
{
	typedef __Metaobject type;
};

template <typename T, size_t N>
using get_t = typename get<T>::type;

__namespace_meta_end
//]
