
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[meta_get_size
__namespace_meta_begin

template <typename T>
__requires __MetaobjectSequence<T>
struct get_size
{

	typedef size_t value_type;
	static constexpr const size_t value = ... /*<
	returns a number of elements in the sequence.
	>*/;

	typedef __StringConstant type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

template <typename T>
using get_size_t = typename get_size<T>::type;

template <typename T>
constexpr bool get_size_v = get_size<T>::value;

__namespace_meta_end
//]
