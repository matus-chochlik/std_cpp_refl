
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[reflexpr_MetaSpecifier_def

template <typename T>
__concept bool MetaSpecifier =
	__Metaobject<T> &&
	__meta::__is_specifier_v<T>;

//]
//[reflexpr_MetaSpecifier_begin
__namespace_meta_begin
//]
//[reflexpr_MetaSpecifier_inherited_traits

//]
//[reflexpr_MetaSpecifier_traits

template <>
struct __is_specifier<MetaSpecifier>
{
	typedef bool value_type;
	static constexpr const bool value = true;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

//]
//[reflexpr_MetaSpecifier_inherited_operations

template <>
struct __source_file<MetaSpecifier>
{
	
	typedef const char value_type[N+1];

	static constexpr const char value[N+1] = ... /*<
	Source file path of the declaration of a specifier reflected by a MetaSpecifier.
	>*/;

	typedef __StringConstant type;

	operator const char* (void) const noexcept;
	const char* operator (void) const noexcept;
	
};

template <>
struct __source_line<MetaSpecifier>
{
	
	typedef unsigned value_type;
	static constexpr const unsigned value = ... /*<
	Source file line of the declaration of a specifier reflected by a MetaSpecifier.
	>*/;

	typedef __integral_constant<value_type, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
	
};

template <>
struct __source_column<MetaSpecifier>
{
	
	typedef unsigned value_type;
	static constexpr const unsigned value = ... /*<
	Source file column of the declaration of a specifier reflected by a MetaSpecifier.
	>*/;

	typedef __integral_constant<value_type, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
	
};

//]
//[reflexpr_MetaSpecifier_operations

template <>
struct __get_keyword<MetaSpecifier>
{
	
	typedef const char value_type[N+1];

	static constexpr const char value[N+1] = ... /*<
	The keyword of the specifier reflected by a MetaSpecifier.
	>*/;

	typedef __StringConstant type;

	operator const char* (void) const noexcept;
	const char* operator (void) const noexcept;
	
};

//]
//[reflexpr_MetaSpecifier_end
__namespace_meta_end
//]
