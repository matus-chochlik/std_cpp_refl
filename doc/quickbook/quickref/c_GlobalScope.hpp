
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[reflexpr_GlobalScope_def

template <typename T>
__concept bool GlobalScope =
	__Scope<T> &&
	__meta::__is_global_scope_v<T>;

//]
//[reflexpr_GlobalScope_begin
__namespace_meta_begin
//]
//[reflexpr_GlobalScope_inherited_traits

template <>
struct __has_name<GlobalScope> /*<
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
struct __has_scope<GlobalScope> /*<
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
struct __is_scope<GlobalScope> /*<
Inherited from __Scope.
>*/
{
	typedef bool value_type;
	static constexpr const bool value = true;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

//]
//[reflexpr_GlobalScope_traits

template <>
struct __is_global_scope<GlobalScope>
{
	typedef bool value_type;
	static constexpr const bool value = true;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

//]
//[reflexpr_GlobalScope_inherited_operations

template <>
struct __reflects_same<GlobalScope, GlobalScope>
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
struct __get_source_location<GlobalScope>
{
	
	typedef __SourceLocation value_type; /*<
	returns the source location info of the declaration of the global scope reflected by a GlobalScope.
	>*/
	
};

template <>
struct __get_name<GlobalScope>
{
	
	typedef const char value_type[N+1];

	static constexpr const char value[N+1] = ... /*<
	returns the basic name of the the global scope reflected by a GlobalScope.
	>*/;

	typedef __StringConstant type;

	operator const char*(void) const noexcept;
	const char* operator(void) const noexcept;
	
};

template <>
struct __get_scope<GlobalScope>
{
	
	typedef __Scope value_type; /*<
	returns the Scope reflecting the scope of the global scope reflected by a GlobalScope.
	>*/
	
};

//]
//[reflexpr_GlobalScope_operations

//]
//[reflexpr_GlobalScope_end
__namespace_meta_end
//]
