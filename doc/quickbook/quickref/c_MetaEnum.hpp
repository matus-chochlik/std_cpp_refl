
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[reflexpr_MetaEnum_def

template <typename T>
__concept bool MetaEnum =
	__MetaType<T> &&
	__meta::__is_enum_v<T>;

//]
//[reflexpr_MetaEnum_begin
__namespace_meta_begin
//]
//[reflexpr_MetaEnum_inherited_traits

template <>
struct __has_name<MetaEnum> /*<
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
struct __has_scope<MetaEnum> /*<
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
struct __is_type<MetaEnum> /*<
Inherited from __MetaType.
>*/
{
	typedef bool value_type;
	static constexpr const bool value = true;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

template <>
struct __is_scope<MetaEnum> /*<
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
//[reflexpr_MetaEnum_traits

template <>
struct __is_enum<MetaEnum>
{
	typedef bool value_type;
	static constexpr const bool value = true;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

//]
//[reflexpr_MetaEnum_inherited_operations

template <>
struct __source_file<MetaEnum>
{
	
	typedef const char value_type[N+1];

	static constexpr const char value[N+1] = ... /*<
	returns a source file path of the declaration of an enumeration reflected by a MetaEnum.
	>*/;

	typedef __StringConstant type;

	operator const char* (void) const noexcept;
	const char* operator (void) const noexcept;
	
};

template <>
struct __source_line<MetaEnum>
{
	
	typedef unsigned value_type;
	static constexpr const unsigned value = ... /*<
	returns a source file line of the declaration of an enumeration reflected by a MetaEnum.
	>*/;

	typedef __integral_constant<value_type, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
	
};

template <>
struct __source_column<MetaEnum>
{
	
	typedef unsigned value_type;
	static constexpr const unsigned value = ... /*<
	returns a source file column of the declaration of an enumeration reflected by a MetaEnum.
	>*/;

	typedef __integral_constant<value_type, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
	
};

template <>
struct __get_name<MetaEnum>
{
	
	typedef const char value_type[N+1];

	static constexpr const char value[N+1] = ... /*<
	returns the basic name of the an enumeration reflected by a MetaEnum.
	>*/;

	typedef __StringConstant type;

	operator const char* (void) const noexcept;
	const char* operator (void) const noexcept;
	
};

template <>
struct __get_scope<MetaEnum>
{
	
	typedef __MetaScope type; /*<
	returns the MetaScope reflecting the scope of an enumeration reflected by a MetaEnum.
	>*/
	
};

template <>
struct __get_reflected_type<MetaEnum>
{
	
	typedef __Type type; /*<
	returns the the base-level type reflected by a MetaEnum.
	>*/
	
};

//]
//[reflexpr_MetaEnum_operations

//]
//[reflexpr_MetaEnum_end
__namespace_meta_end
//]
