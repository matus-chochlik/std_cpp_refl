
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[reflexpr_Alias_def

template <typename T>
__concept bool Alias =
	__Named<T> &&
	__meta::__is_alias_v<T>;

//]
//[reflexpr_Alias_begin
__namespace_meta_begin
//]
//[reflexpr_Alias_inherited_traits

template <>
struct __has_name<Alias> /*<
Inherited from __Named.
>*/
{
	typedef bool value_type;
	static constexpr const bool value = true;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

//]
//[reflexpr_Alias_traits

template <>
struct __is_alias<Alias>
{
	typedef bool value_type;
	static constexpr const bool value = true;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

//]
//[reflexpr_Alias_inherited_operations

template <>
struct __reflects_same<Alias, Alias>
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
struct __get_source_location<Alias>
{
	
	typedef __SourceLocation value_type; /*<
	returns the source location info of the declaration of a type or namespace alias reflected by a Alias.
	>*/
	
};

template <>
struct __get_name<Alias>
{
	
	typedef const char value_type[N+1];

	static constexpr const char value[N+1] = ... /*<
	returns the basic name of the a type or namespace alias reflected by a Alias.
	>*/;

	typedef __StringConstant type;

	operator const char*(void) const noexcept;
	const char* operator(void) const noexcept;
	
};

//]
//[reflexpr_Alias_operations

template <>
struct __get_aliased<Alias>
{
	
	typedef __Named value_type; /*<
	returns the Named reflecting the original declaration of a type or namespace alias reflected by a Alias.
	>*/
	
};

//]
//[reflexpr_Alias_end
__namespace_meta_end
//]
