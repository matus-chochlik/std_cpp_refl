
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[reflexpr_Enum_def

template <typename T>
__concept bool Enum =
	__Type<T> &&
	__meta::__is_enum_v<T>;

//]
//[reflexpr_Enum_begin
__namespace_meta_begin
//]
//[reflexpr_Enum_inherited_traits

template <>
struct __has_name<Enum> /*<
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
struct __has_scope<Enum> /*<
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
struct __is_type<Enum> /*<
Inherited from __Type.
>*/
{
	typedef bool value_type;
	static constexpr const bool value = true;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

//]
//[reflexpr_Enum_traits

template <>
struct __is_enum<Enum>
{
	typedef bool value_type;
	static constexpr const bool value = true;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

//]
//[reflexpr_Enum_inherited_operations

template <>
struct __reflects_same<Enum, Enum>
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
struct __get_source_location<Enum>
{
	
	typedef __SourceLocation value_type; /*<
	returns the source location info of the declaration of an enumeration reflected by a Enum.
	>*/
	
};

template <>
struct __get_name<Enum>
{
	
	typedef const char value_type[N+1];

	static constexpr const char value[N+1] = ... /*<
	returns the basic name of the an enumeration reflected by a Enum.
	>*/;

	typedef __StringConstant type;

	operator const char*(void) const noexcept;
	const char* operator(void) const noexcept;
	
};

template <>
struct __get_scope<Enum>
{
	
	typedef __Scope value_type; /*<
	returns the result reflecting the scope of an enumeration reflected by a Enum.
	>*/
	
};

template <>
struct __get_reflected_type<Enum>
{
	
	typedef __OriginalType value_type; /*<
	returns the the base-level type reflected by a Enum.
	>*/
	
};

//]
//[reflexpr_Enum_operations

//]
//[reflexpr_Enum_end
__namespace_meta_end
//]
