
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[reflexpr_MetaScope_def

template <typename T>
__concept bool MetaScope =
	__MetaNamed<T> &&
	__meta::__is_scope_v<T>;

//]
//[reflexpr_MetaScope_begin
__namespace_meta_begin
//]
//[reflexpr_MetaScope_inherited_traits

template <>
struct __has_name<MetaScope> /*<
Inherited from __MetaNamed.
>*/
{
	typedef bool value_type;
	static constexpr const bool value = true;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

//]
//[reflexpr_MetaScope_traits

template <>
struct __is_scope<MetaScope>
{
	typedef bool value_type;
	static constexpr const bool value = true;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

//]
//[reflexpr_MetaScope_inherited_operations

template <>
struct __source_file<MetaScope>
{
	
	typedef const char value_type[N+1];

	static constexpr const char value[N+1] = ... /*<
	returns the source file path of the declaration of a scope reflected by a MetaScope.
	>*/;

	typedef __StringConstant type;

	operator const char*(void) const noexcept;
	const char* operator(void) const noexcept;
	
};

template <>
struct __source_line<MetaScope>
{
	
	typedef unsigned value_type;
	static constexpr const unsigned value = ... /*<
	returns the source file line of the declaration of a scope reflected by a MetaScope.
	>*/;

	typedef __integral_constant<unsigned, value> type;

	operator unsigned(void) const noexcept;
	unsigned operator(void) const noexcept;
	
};

template <>
struct __source_column<MetaScope>
{
	
	typedef unsigned value_type;
	static constexpr const unsigned value = ... /*<
	returns the source file column of the declaration of a scope reflected by a MetaScope.
	>*/;

	typedef __integral_constant<unsigned, value> type;

	operator unsigned(void) const noexcept;
	unsigned operator(void) const noexcept;
	
};

template <>
struct __get_name<MetaScope>
{
	
	typedef const char value_type[N+1];

	static constexpr const char value[N+1] = ... /*<
	returns the basic name of the a scope reflected by a MetaScope.
	>*/;

	typedef __StringConstant type;

	operator const char*(void) const noexcept;
	const char* operator(void) const noexcept;
	
};

//]
//[reflexpr_MetaScope_operations

//]
//[reflexpr_MetaScope_end
__namespace_meta_end
//]
