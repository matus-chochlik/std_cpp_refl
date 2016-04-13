
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[reflexpr_Parameter_def

template <typename T>
__concept bool Parameter =
	__Named<T> &&
	__Typed<T> &&
	__Scoped<T> &&
	__meta::__is_parameter_v<T>;

//]
//[reflexpr_Parameter_begin
__namespace_meta_begin
//]
//[reflexpr_Parameter_inherited_traits

template <>
struct __has_name<Parameter> /*<
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
struct __has_type<Parameter> /*<
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
struct __has_scope<Parameter> /*<
Inherited from __Scoped.
>*/
{
	typedef bool value_type;
	static constexpr const bool value = true;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

//]
//[reflexpr_Parameter_traits

template <>
struct __is_parameter<Parameter>
{
	typedef bool value_type;
	static constexpr const bool value = true;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

//]
//[reflexpr_Parameter_inherited_operations

template <>
struct __reflects_same<Parameter, Parameter>
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
struct __get_source_location<Parameter>
{
	
	typedef __SourceLocation value_type; /*<
	returns the source location info of the declaration of a function parameter reflected by a Parameter.
	>*/
	
};

template <>
struct __get_name<Parameter>
{
	
	typedef const char value_type[N+1];

	static constexpr const char value[N+1] = ... /*<
	returns the basic name of the a function parameter reflected by a Parameter.
	>*/;

	typedef __StringConstant type;

	operator const char*(void) const noexcept;
	const char* operator(void) const noexcept;
	
};

template <>
struct __get_type<Parameter>
{
	
	typedef __Type value_type; /*<
	returns the result reflecting the type of a function parameter reflected by a Parameter.
	>*/
	
};

template <>
struct __get_scope<Parameter>
{
	
	typedef __Scope value_type; /*<
	returns the result reflecting the scope of a function parameter reflected by a Parameter.
	>*/
	
};

//]
//[reflexpr_Parameter_operations

//]
//[reflexpr_Parameter_end
__namespace_meta_end
//]
