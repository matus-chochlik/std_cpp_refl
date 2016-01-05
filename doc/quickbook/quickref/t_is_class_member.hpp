
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[meta_is_class_member
__namespace_meta_begin


template <typename T>
struct is_class_member
{
	static_assert(__is_metaobject_v<T>, "");

	typedef bool value_type;
	static constexpr const bool value = ... /*<
	[^true] if [^X] is a [concept MetaClassMember]
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
