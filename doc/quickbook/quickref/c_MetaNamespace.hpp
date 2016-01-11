
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[reflexpr_MetaNamespace_def

template <typename T>
__concept bool MetaNamespace =
	__MetaNamed<T> &&
	__MetaScope<T> &&
	__MetaScoped<T> &&
	__meta::__is_namespace_v<T>;

//]
//[reflexpr_MetaNamespace_begin
__namespace_meta_begin
//]
//[reflexpr_MetaNamespace_inherited_traits

template <>
struct __has_name<MetaNamespace> /*<
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
struct __has_scope<MetaNamespace> /*<
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
struct __is_scope<MetaNamespace> /*<
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
//[reflexpr_MetaNamespace_traits

template <>
struct __is_namespace<MetaNamespace>
{
	typedef bool value_type;
	static constexpr const bool value = true;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

//]
//[reflexpr_MetaNamespace_inherited_operations

template <>
struct __source_file<MetaNamespace>
{
	
	typedef const char value_type[N+1];

	static constexpr const char value[N+1] = ... /*<
	Source file path of the declaration of a namespace reflected by a MetaNamespace.
	>*/;

	typedef __StringConstant type;

	operator const char* (void) const noexcept;
	const char* operator (void) const noexcept;
	
};

template <>
struct __source_line<MetaNamespace>
{
	
	typedef unsigned value_type;
	static constexpr const unsigned value = ... /*<
	Source file line of the declaration of a namespace reflected by a MetaNamespace.
	>*/;

	typedef __integral_constant<value_type, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
	
};

template <>
struct __source_column<MetaNamespace>
{
	
	typedef unsigned value_type;
	static constexpr const unsigned value = ... /*<
	Source file column of the declaration of a namespace reflected by a MetaNamespace.
	>*/;

	typedef __integral_constant<value_type, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
	
};

template <>
struct __get_name<MetaNamespace>
{
	
	typedef const char value_type[N+1];

	static constexpr const char value[N+1] = ... /*<
	The basic name of the a namespace reflected by a MetaNamespace.
	>*/;

	typedef __StringConstant type;

	operator const char* (void) const noexcept;
	const char* operator (void) const noexcept;
	
};

template <>
struct __get_scope<MetaNamespace>
{
	
	typedef __MetaScope type; /*<
	The MetaScope reflecting the scope of a namespace reflected by a MetaNamespace.
	>*/
	
};

//]
//[reflexpr_MetaNamespace_operations

//]
//[reflexpr_MetaNamespace_end
__namespace_meta_end
//]
