
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[meta_get_pointer
__namespace_meta_begin

template <typename T>
__requires __MetaVariable<T>
struct get_pointer
{

	typedef conditional_t<
		__is_class_member_v<T> && !__is_static_v<T>,
		__get_reflected_type_t<__get_type_t<T>>
		__get_reflected_type_t<__get_scope_t<T>>::*,
		__get_reflected_type_t<__get_type_t<T>>*
	> value_type;

	static const value_type value = ... /*<
	returns a pointer to the a variable reflected by a MetaVariable.   If the variable is a class member then the pointer is a class data member pointer,   otherwise it is a plain pointer.
	>*/;
};


template <typename T>
constexpr bool get_pointer_v = get_pointer<T>::value;

template <typename T>
const bool get_pointer_v = get_pointer<T>::value;

__namespace_meta_end
//]
