
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[meta_get_pointer
__namespace_meta_begin

template <typename T>
__requires __Variable<T>
struct get_pointer
{

	typedef conditional_t<
		__is_class_member_v<T> && !__is_static_v<T>,
		__get_reflected_type_t<__get_type_t<T>>
		__get_reflected_type_t<__get_scope_t<T>>::*,
		__get_reflected_type_t<__get_type_t<T>>*
	> value_type;

	static const value_type value = ... /*<
	returns a pointer to the a variable reflected by a Variable.   If the variable is a class member then the pointer is a class data member pointer,   otherwise it is a plain pointer.
	>*/;
};


template <typename T>
constexpr bool get_pointer_v = get_pointer<T>::value;

template <typename T>
const bool get_pointer_v = get_pointer<T>::value;
template <typename T>
__requires __Function<T>
struct get_pointer
{

	typedef __FunctionPointer type; /*<
	returns a pointer to the a function reflected by a Function.   If the function is a class member then the pointer is a class member function pointer,   otherwise it is a plain function pointer.
	>*/
};

template <typename T>
using get_pointer_t = typename get_pointer<T>::type;

__namespace_meta_end
//]
