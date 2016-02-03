
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[reflexpr_TypeAlias_def

template <typename T>
__concept bool TypeAlias =
	__Type<T> &&
	__Alias<T> &&
	__meta::__is_type_v<__get_aliased_t<T>>;

//]
//[reflexpr_TypeAlias_begin
__namespace_meta_begin
//]
//[reflexpr_TypeAlias_inherited_traits

template <>
struct __has_name<TypeAlias> /*<
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
struct __has_scope<TypeAlias> /*<
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
struct __is_type<TypeAlias> /*<
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
struct __is_alias<TypeAlias> /*<
Inherited from __Alias.
>*/
{
	typedef bool value_type;
	static constexpr const bool value = true;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

//]
//[reflexpr_TypeAlias_traits

//]
//[reflexpr_TypeAlias_inherited_operations

template <>
struct __reflects_same<TypeAlias, TypeAlias>
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
struct __get_source_location<TypeAlias>
{
	
	typedef __SourceLocation value_type; /*<
	returns the source location info of the declaration of a type alias or typedef reflected by a TypeAlias.
	>*/
	
};

template <>
struct __get_name<TypeAlias>
{
	
	typedef const char value_type[N+1];

	static constexpr const char value[N+1] = ... /*<
	returns the basic name of the a type alias or typedef reflected by a TypeAlias.
	>*/;

	typedef __StringConstant type;

	operator const char*(void) const noexcept;
	const char* operator(void) const noexcept;
	
};

template <>
struct __get_scope<TypeAlias>
{
	
	typedef __Scope value_type; /*<
	returns the Scope reflecting the scope of a type alias or typedef reflected by a TypeAlias.
	>*/
	
};

template <>
struct __get_reflected_type<TypeAlias>
{
	
	typedef __OriginalType value_type; /*<
	returns the the base-level type reflected by a TypeAlias.
	>*/
	
};

template <>
struct __get_aliased<TypeAlias>
{
	
	typedef __Named value_type; /*<
	returns the Named reflecting the original declaration of a type alias or typedef reflected by a TypeAlias.
	>*/
	
};

//]
//[reflexpr_TypeAlias_operations

//]
//[reflexpr_TypeAlias_end
__namespace_meta_end
//]
