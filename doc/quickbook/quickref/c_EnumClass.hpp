
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[reflexpr_EnumClass_def

template <typename T>
__concept bool EnumClass =
	__Enum<T> &&
	__Scope<T>;

//]
//[reflexpr_EnumClass_begin
__namespace_meta_begin
//]
//[reflexpr_EnumClass_inherited_traits

template <>
struct __has_name<EnumClass> /*<
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
struct __has_scope<EnumClass> /*<
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
struct __is_type<EnumClass> /*<
Inherited from __Type.
>*/
{
	typedef bool value_type;
	static constexpr const bool value = true;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

template <>
struct __is_enum<EnumClass> /*<
Inherited from __Enum.
>*/
{
	typedef bool value_type;
	static constexpr const bool value = true;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

template <>
struct __is_scope<EnumClass> /*<
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
//[reflexpr_EnumClass_traits

//]
//[reflexpr_EnumClass_inherited_operations

template <>
struct __reflects_same<EnumClass, EnumClass>
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
struct __get_source_location<EnumClass>
{
	
	typedef __SourceLocation value_type; /*<
	returns the source location info of the declaration of a strongly typed enumeration reflected by a EnumClass.
	>*/
	
};

template <>
struct __get_name<EnumClass>
{
	
	typedef const char value_type[N+1];

	static constexpr const char value[N+1] = ... /*<
	returns the basic name of the a strongly typed enumeration reflected by a EnumClass.
	>*/;

	typedef __StringConstant type;

	operator const char*(void) const noexcept;
	const char* operator(void) const noexcept;
	
};

template <>
struct __get_scope<EnumClass>
{
	
	typedef __Scope value_type; /*<
	returns the Scope reflecting the scope of a strongly typed enumeration reflected by a EnumClass.
	>*/
	
};

template <>
struct __get_reflected_type<EnumClass>
{
	
	typedef __OriginalType value_type; /*<
	returns the the base-level type reflected by a EnumClass.
	>*/
	
};

//]
//[reflexpr_EnumClass_operations

//]
//[reflexpr_EnumClass_end
__namespace_meta_end
//]
