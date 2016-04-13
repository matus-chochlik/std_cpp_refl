
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[reflexpr_Function_def

template <typename T>
__concept bool Function =
	__Named<T> &&
	__Typed<T> &&
	__Linkable<T> &&
	__meta::__is_function_v<T>;

//]
//[reflexpr_Function_begin
__namespace_meta_begin
//]
//[reflexpr_Function_inherited_traits

template <>
struct __has_name<Function> /*<
Inherited from __Named.
>*/
{
	typedef bool value_type;
	static constexpr const bool value = true;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

template <>
struct __has_type<Function> /*<
Inherited from __Typed.
>*/
{
	typedef bool value_type;
	static constexpr const bool value = true;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

template <>
struct __has_scope<Function> /*<
Inherited from __Scoped.
>*/
{
	typedef bool value_type;
	static constexpr const bool value = true;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

template <>
struct __is_linkable<Function> /*<
Inherited from __Linkable.
>*/
{
	typedef bool value_type;
	static constexpr const bool value = true;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

//]
//[reflexpr_Function_traits

template <>
struct __is_function<Function>
{
	typedef bool value_type;
	static constexpr const bool value = true;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

//]
//[reflexpr_Function_inherited_operations

template <>
struct __reflects_same<Function, Function>
{
	
	typedef bool value_type;
	static constexpr const bool value = ... /*<
	indicates if two metaobjects reflect the same base-level declaration.
	>*/;

	typedef __integral_constant<bool, value> type;

	operator bool (void) const noexcept;
	bool operator(void) const noexcept;
	
};

template <>
struct __get_source_location<Function>
{
	
	typedef __SourceLocation value_type; /*<
	returns the source location info of the declaration of a function reflected by a Function.
	>*/
	
};

template <>
struct __get_name<Function>
{
	
	typedef const char value_type[N+1];

	static constexpr const char value[N+1] = ... /*<
	returns the basic name of the a function reflected by a Function.
	>*/;

	typedef __StringConstant type;

	operator const char*(void) const noexcept;
	const char* operator(void) const noexcept;
	
};

template <>
struct __get_type<Function>
{
	
	typedef __Type value_type; /*<
	returns the result reflecting the type of a function reflected by a Function.
	>*/
	
};

template <>
struct __get_scope<Function>
{
	
	typedef __Scope value_type; /*<
	returns the result reflecting the scope of a function reflected by a Function.
	>*/
	
};

template <>
struct __is_static<Function>
{
	
	typedef bool value_type;
	static constexpr const bool value = ... /*<
	returns whether the a function reflected by a Function was declared with the static specifier.
	>*/;

	typedef __integral_constant<bool, value> type;

	operator bool (void) const noexcept;
	bool operator(void) const noexcept;
	
};

//]
//[reflexpr_Function_operations

template <>
struct __get_pointer<Function>
{
	
	typedef __FunctionPointer value_type; /*<
	returns a pointer to the a function reflected by a Function.   If the function is a class member then the pointer is a class member function pointer,   otherwise it is a plain function pointer.
	>*/
	
};

template <>
struct __get_result_type<Function>
{
	
	typedef __Type value_type; /*<
	returns a result reflecting the return type of a Function.
	>*/
	
};

template <>
struct __get_parameters<Function>
{
	
	typedef __ObjectSequence value_type; /*<
	returns a result of elements reflecting the parameters of a Function.
	>*/
	
};

//]
//[reflexpr_Function_end
__namespace_meta_end
//]
