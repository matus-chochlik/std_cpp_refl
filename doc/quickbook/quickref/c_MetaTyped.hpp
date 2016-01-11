
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[reflexpr_MetaTyped_def

template <typename T>
__concept bool MetaTyped =
	__Metaobject<T> &&
	__meta::__has_type_v<T>;

//]
//[reflexpr_MetaTyped_begin
__namespace_meta_begin
//]
//[reflexpr_MetaTyped_inherited_traits

//]
//[reflexpr_MetaTyped_traits

template <>
struct __has_type<MetaTyped>
{
	typedef bool value_type;
	static constexpr const bool value = true;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

//]
//[reflexpr_MetaTyped_inherited_operations

template <>
struct __source_file<MetaTyped>
{
	
	typedef const char value_type[N+1];

	static constexpr const char value[N+1] = ... /*<
	Source file path of the declaration of base-level construct with a type reflected by a MetaTyped.
	>*/;

	typedef __StringConstant type;

	operator const char* (void) const noexcept;
	const char* operator (void) const noexcept;
	
};

template <>
struct __source_line<MetaTyped>
{
	
	typedef unsigned value_type;
	static constexpr const unsigned value = ... /*<
	Source file line of the declaration of base-level construct with a type reflected by a MetaTyped.
	>*/;

	typedef __integral_constant<value_type, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
	
};

template <>
struct __source_column<MetaTyped>
{
	
	typedef unsigned value_type;
	static constexpr const unsigned value = ... /*<
	Source file column of the declaration of base-level construct with a type reflected by a MetaTyped.
	>*/;

	typedef __integral_constant<value_type, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
	
};

//]
//[reflexpr_MetaTyped_operations

template <>
struct __get_type<MetaTyped>
{
	
	typedef __MetaType type; /*<
	The MetaType reflecting the type of base-level construct with a type reflected by a MetaTyped.
	>*/
	
};

//]
//[reflexpr_MetaTyped_end
__namespace_meta_end
//]
