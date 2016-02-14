
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[reflexpr_Specifier_def

template <typename T>
__concept bool Specifier =
	__Named<T> &&
	__meta::__is_specifier_v<T>;

//]
//[reflexpr_Specifier_begin
__namespace_meta_begin
//]
//[reflexpr_Specifier_inherited_traits

template <>
struct __has_name<Specifier> /*<
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
//[reflexpr_Specifier_traits

template <>
struct __is_specifier<Specifier>
{
	typedef bool value_type;
	static constexpr const bool value = true;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

//]
//[reflexpr_Specifier_inherited_operations

template <>
struct __reflects_same<Specifier, Specifier>
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
struct __get_source_location<Specifier>
{
	
	typedef __SourceLocation value_type; /*<
	returns the source location info of the declaration of a specifier reflected by a Specifier.
	>*/
	
};

template <>
struct __get_name<Specifier>
{
	
	typedef const char value_type[N+1];

	static constexpr const char value[N+1] = ... /*<
	returns the basic name of the a specifier reflected by a Specifier.
	>*/;

	typedef __StringConstant type;

	operator const char*(void) const noexcept;
	const char* operator(void) const noexcept;
	
};

//]
//[reflexpr_Specifier_operations

//]
//[reflexpr_Specifier_end
__namespace_meta_end
//]
