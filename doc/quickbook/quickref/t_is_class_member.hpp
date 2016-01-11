
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[meta_is_class_member
__namespace_meta_begin


template <typename T>
__requires __Metaobject<T>
struct is_class_member
{
	typedef bool value_type;
	static constexpr const bool value = ... /*<
	[^true] if [^T] is a __MetaClassMember
	[^false] otherwise.
	>*/;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

template <typename T>
using is_class_member_t = typename is_class_member<T>::type;

template <typename T>
constexpr bool is_class_member_v = is_class_member<T>::value;


__namespace_meta_end
//]
