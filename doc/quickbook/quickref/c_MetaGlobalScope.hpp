
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[reflexpr_MetaGlobalScope_begin
__namespace_meta_begin
//]
//[reflexpr_MetaGlobalScope_inherited_traits

template <>
struct __has_name<MetaGlobalScope> /*<
Inherited from __MetaNamed.
>*/
{
	typedef bool value_type;
	static constexpr const bool value = true;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

template <>
struct __has_scope<MetaGlobalScope> /*<
Inherited from __MetaScoped.
>*/
{
	typedef bool value_type;
	static constexpr const bool value = true;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

template <>
struct __is_scope<MetaGlobalScope> /*<
Inherited from __MetaScope.
>*/
{
	typedef bool value_type;
	static constexpr const bool value = true;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

//]
//[reflexpr_MetaGlobalScope_traits

template <>
struct __is_global_scope<MetaGlobalScope>
{
	typedef bool value_type;
	static constexpr const bool value = true;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

//]
//[reflexpr_MetaGlobalScope_inherited_operations

template <>
struct __source_file<MetaGlobalScope>
{
	
	typedef const char value_type[N+1];

	static constexpr const char value[N+1] = ... /*<
	Source file path of the declaration of the global scope reflected by a MetaGlobalScope.
	>*/;

	typedef __StringConstant type;

	operator const char* (void) const noexcept;
	const char* operator (void) const noexcept;
	
};

template <>
struct __source_line<MetaGlobalScope>
{
	
	typedef unsigned value_type;
	static constexpr const unsigned value = ... /*<
	Source file line of the declaration of the global scope reflected by a MetaGlobalScope.
	>*/;

	typedef __integral_constant<value_type, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
	
};

template <>
struct __source_column<MetaGlobalScope>
{
	
	typedef unsigned value_type;
	static constexpr const unsigned value = ... /*<
	Source file column of the declaration of the global scope reflected by a MetaGlobalScope.
	>*/;

	typedef __integral_constant<value_type, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
	
};

template <>
struct __get_name<MetaGlobalScope>
{
	
	typedef const char value_type[N+1];

	static constexpr const char value[N+1] = ... /*<
	The basic name of the the global scope reflected by a MetaGlobalScope.
	>*/;

	typedef __StringConstant type;

	operator const char* (void) const noexcept;
	const char* operator (void) const noexcept;
	
};

template <>
struct __get_scope<MetaGlobalScope>
{
	
	typedef __MetaScope type; /*<
	The MetaScope reflecting the scope of the global scope reflected by a MetaGlobalScope.
	>*/
	
};

//]
//[reflexpr_MetaGlobalScope_operations

//]
//[reflexpr_MetaGlobalScope_end
__namespace_meta_end
//]
