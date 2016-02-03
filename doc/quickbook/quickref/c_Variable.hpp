
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[reflexpr_Variable_def

template <typename T>
__concept bool Variable =
	__Named<T> &&
	__Typed<T> &&
	__Linkable<T> &&
	__meta::__is_variable_v<T>;

//]
//[reflexpr_Variable_begin
__namespace_meta_begin
//]
//[reflexpr_Variable_inherited_traits

template <>
struct __has_name<Variable> /*<
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
struct __has_type<Variable> /*<
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
struct __has_scope<Variable> /*<
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
struct __is_linkable<Variable> /*<
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
//[reflexpr_Variable_traits

template <>
struct __is_variable<Variable>
{
	typedef bool value_type;
	static constexpr const bool value = true;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

//]
//[reflexpr_Variable_inherited_operations

template <>
struct __reflects_same<Variable, Variable>
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
struct __get_source_location<Variable>
{
	
	typedef __SourceLocation value_type; /*<
	returns the source location info of the declaration of a variable reflected by a Variable.
	>*/
	
};

template <>
struct __get_name<Variable>
{
	
	typedef const char value_type[N+1];

	static constexpr const char value[N+1] = ... /*<
	returns the basic name of the a variable reflected by a Variable.
	>*/;

	typedef __StringConstant type;

	operator const char*(void) const noexcept;
	const char* operator(void) const noexcept;
	
};

template <>
struct __get_type<Variable>
{
	
	typedef __Type value_type; /*<
	returns the Type reflecting the type of a variable reflected by a Variable.
	>*/
	
};

template <>
struct __get_scope<Variable>
{
	
	typedef __Scope value_type; /*<
	returns the Scope reflecting the scope of a variable reflected by a Variable.
	>*/
	
};

template <>
struct __is_static<Variable>
{
	
	typedef bool value_type;
	static constexpr const bool value = ... /*<
	returns whether the a variable reflected by a Variable was declared with the static specifier.
	>*/;

	typedef __integral_constant<bool, value> type;

	operator bool (void) const noexcept;
	bool operator(void) const noexcept;
	
};

//]
//[reflexpr_Variable_operations

template <>
struct __get_pointer<Variable>
{
	
	typedef Pointer value_type;

	static const value_type value = ... /*<
	returns a pointer to the a variable reflected by a Variable.   If the variable is a class member then the pointer is a class data member pointer,   otherwise it is a plain pointer.
	>*/;
	
};

//]
//[reflexpr_Variable_end
__namespace_meta_end
//]
