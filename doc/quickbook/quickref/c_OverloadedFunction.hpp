
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[reflexpr_OverloadedFunction_def

template <typename T>
__concept bool OverloadedFunction =
	__Named<T> &&
	__Scoped<T>;

//]
//[reflexpr_OverloadedFunction_begin
__namespace_meta_begin
//]
//[reflexpr_OverloadedFunction_inherited_traits

template <>
struct __has_name<OverloadedFunction> /*<
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
struct __has_scope<OverloadedFunction> /*<
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
//[reflexpr_OverloadedFunction_traits

//]
//[reflexpr_OverloadedFunction_inherited_operations

template <>
struct __reflects_same<OverloadedFunction, OverloadedFunction>
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
struct __get_source_location<OverloadedFunction>
{
	
	typedef __SourceLocation value_type; /*<
	returns the source location info of the declaration of a set of functions reflected by a OverloadedFunction.
	>*/
	
};

template <>
struct __get_name<OverloadedFunction>
{
	
	typedef const char value_type[N+1];

	static constexpr const char value[N+1] = ... /*<
	returns the basic name of the a set of functions reflected by a OverloadedFunction.
	>*/;

	typedef __StringConstant type;

	operator const char*(void) const noexcept;
	const char* operator(void) const noexcept;
	
};

template <>
struct __get_scope<OverloadedFunction>
{
	
	typedef __Scope value_type; /*<
	returns the result reflecting the scope of a set of functions reflected by a OverloadedFunction.
	>*/
	
};

//]
//[reflexpr_OverloadedFunction_operations

template <>
struct __get_overloads<OverloadedFunction>
{
	
	typedef __ObjectSequence value_type; /*<
	returns a result of the element reflecting the concrete overloads of a OverloadedFunction.
	>*/
	
};

//]
//[reflexpr_OverloadedFunction_end
__namespace_meta_end
//]
