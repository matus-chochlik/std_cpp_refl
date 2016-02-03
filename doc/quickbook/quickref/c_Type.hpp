
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[reflexpr_Type_def

template <typename T>
__concept bool Type =
	__Named<T> &&
	__Scoped<T> &&
	__meta::__is_type_v<T>;

//]
//[reflexpr_Type_begin
__namespace_meta_begin
//]
//[reflexpr_Type_inherited_traits

template <>
struct __has_name<Type> /*<
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
struct __has_scope<Type> /*<
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
//[reflexpr_Type_traits

template <>
struct __is_type<Type>
{
	typedef bool value_type;
	static constexpr const bool value = true;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

//]
//[reflexpr_Type_inherited_operations

template <>
struct __reflects_same<Type, Type>
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
struct __get_source_location<Type>
{
	
	typedef __SourceLocation value_type; /*<
	returns the source location info of the declaration of a type reflected by a Type.
	>*/
	
};

template <>
struct __get_name<Type>
{
	
	typedef const char value_type[N+1];

	static constexpr const char value[N+1] = ... /*<
	returns the basic name of the a type reflected by a Type.
	>*/;

	typedef __StringConstant type;

	operator const char*(void) const noexcept;
	const char* operator(void) const noexcept;
	
};

template <>
struct __get_scope<Type>
{
	
	typedef __Scope value_type; /*<
	returns the Scope reflecting the scope of a type reflected by a Type.
	>*/
	
};

//]
//[reflexpr_Type_operations

template <>
struct __get_reflected_type<Type>
{
	
	typedef __OriginalType value_type; /*<
	returns the the base-level type reflected by a Type.
	>*/
	
};

//]
//[reflexpr_Type_end
__namespace_meta_end
//]
