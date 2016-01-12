
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[reflexpr_MetaType_def

template <typename T>
__concept bool MetaType =
	__MetaNamed<T> &&
	__MetaScoped<T> &&
	__meta::__is_type_v<T>;

//]
//[reflexpr_MetaType_begin
__namespace_meta_begin
//]
//[reflexpr_MetaType_inherited_traits

template <>
struct __has_name<MetaType> /*<
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
struct __has_scope<MetaType> /*<
Inherited from __MetaScoped.
>*/
{
	typedef bool value_type;
	static constexpr const bool value = true;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

//]
//[reflexpr_MetaType_traits

template <>
struct __is_type<MetaType>
{
	typedef bool value_type;
	static constexpr const bool value = true;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

//]
//[reflexpr_MetaType_inherited_operations

template <>
struct __source_file<MetaType>
{
	
	typedef const char value_type[N+1];

	static constexpr const char value[N+1] = ... /*<
	returns a source file path of the declaration of a type reflected by a MetaType.
	>*/;

	typedef __StringConstant type;

	operator const char* (void) const noexcept;
	const char* operator (void) const noexcept;
	
};

template <>
struct __source_line<MetaType>
{
	
	typedef unsigned value_type;
	static constexpr const unsigned value = ... /*<
	returns a source file line of the declaration of a type reflected by a MetaType.
	>*/;

	typedef __integral_constant<value_type, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
	
};

template <>
struct __source_column<MetaType>
{
	
	typedef unsigned value_type;
	static constexpr const unsigned value = ... /*<
	returns a source file column of the declaration of a type reflected by a MetaType.
	>*/;

	typedef __integral_constant<value_type, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
	
};

template <>
struct __get_name<MetaType>
{
	
	typedef const char value_type[N+1];

	static constexpr const char value[N+1] = ... /*<
	returns the basic name of the a type reflected by a MetaType.
	>*/;

	typedef __StringConstant type;

	operator const char* (void) const noexcept;
	const char* operator (void) const noexcept;
	
};

template <>
struct __get_scope<MetaType>
{
	
	typedef __MetaScope type; /*<
	returns the MetaScope reflecting the scope of a type reflected by a MetaType.
	>*/
	
};

//]
//[reflexpr_MetaType_operations

template <>
struct __get_reflected_type<MetaType>
{
	
	typedef __Type type; /*<
	returns the the base-level type reflected by a MetaType.
	>*/
	
};

//]
//[reflexpr_MetaType_end
__namespace_meta_end
//]
