
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[reflexpr_FunctionParameter_def

template <typename T>
__concept bool FunctionParameter =
	__Parameter<T> &&
	__meta::__is_function_v<__get_scope_t<T>>;

//]
//[reflexpr_FunctionParameter_begin
__namespace_meta_begin
//]
//[reflexpr_FunctionParameter_inherited_traits

template <>
struct __has_name<FunctionParameter> /*<
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
struct __has_type<FunctionParameter> /*<
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
struct __has_scope<FunctionParameter> /*<
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
struct __is_parameter<FunctionParameter> /*<
Inherited from __Parameter.
>*/
{
	typedef bool value_type;
	static constexpr const bool value = true;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

//]
//[reflexpr_FunctionParameter_traits

//]
//[reflexpr_FunctionParameter_inherited_operations

template <>
struct __reflects_same<FunctionParameter, FunctionParameter>
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
struct __get_source_location<FunctionParameter>
{
	
	typedef __SourceLocation value_type; /*<
	returns the source location info of the declaration of a function parameter reflected by a FunctionParameter.
	>*/
	
};

template <>
struct __get_name<FunctionParameter>
{
	
	typedef const char value_type[N+1];

	static constexpr const char value[N+1] = ... /*<
	returns the basic name of the a function parameter reflected by a FunctionParameter.
	>*/;

	typedef __StringConstant type;

	operator const char*(void) const noexcept;
	const char* operator(void) const noexcept;
	
};

template <>
struct __get_type<FunctionParameter>
{
	
	typedef __Type value_type; /*<
	returns the result reflecting the type of a function parameter reflected by a FunctionParameter.
	>*/
	
};

template <>
struct __get_scope<FunctionParameter>
{
	
	typedef __Scope value_type; /*<
	returns the result reflecting the scope of a function parameter reflected by a FunctionParameter.
	>*/
	
};

//]
//[reflexpr_FunctionParameter_operations

//]
//[reflexpr_FunctionParameter_end
__namespace_meta_end
//]
