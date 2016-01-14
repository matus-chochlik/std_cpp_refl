
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[reflexpr_MetaEnumClass_def

template <typename T>
__concept bool MetaEnumClass =
	__MetaEnum<T> &&
	__MetaScope<T>;

//]
//[reflexpr_MetaEnumClass_begin
__namespace_meta_begin
//]
//[reflexpr_MetaEnumClass_inherited_traits

template <>
struct __has_name<MetaEnumClass> /*<
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
struct __has_scope<MetaEnumClass> /*<
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
struct __is_type<MetaEnumClass> /*<
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
struct __is_enum<MetaEnumClass> /*<
Inherited from __MetaEnum.
>*/
{
	typedef bool value_type;
	static constexpr const bool value = true;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

template <>
struct __is_scope<MetaEnumClass> /*<
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
//[reflexpr_MetaEnumClass_traits

//]
//[reflexpr_MetaEnumClass_inherited_operations

template <>
struct __get_source_file<MetaEnumClass>
{
	
	typedef const char value_type[N+1];

	static constexpr const char value[N+1] = ... /*<
	returns the source file path of the declaration of a strongly typed enumeration reflected by a MetaEnumClass.
	>*/;

	typedef __StringConstant type;

	operator const char*(void) const noexcept;
	const char* operator(void) const noexcept;
	
};

template <>
struct __get_source_line<MetaEnumClass>
{
	
	typedef unsigned value_type;
	static constexpr const unsigned value = ... /*<
	returns the source file line of the declaration of a strongly typed enumeration reflected by a MetaEnumClass.
	>*/;

	typedef __integral_constant<unsigned, value> type;

	operator unsigned(void) const noexcept;
	unsigned operator(void) const noexcept;
	
};

template <>
struct __get_source_column<MetaEnumClass>
{
	
	typedef unsigned value_type;
	static constexpr const unsigned value = ... /*<
	returns the source file column of the declaration of a strongly typed enumeration reflected by a MetaEnumClass.
	>*/;

	typedef __integral_constant<unsigned, value> type;

	operator unsigned(void) const noexcept;
	unsigned operator(void) const noexcept;
	
};

template <>
struct __get_name<MetaEnumClass>
{
	
	typedef const char value_type[N+1];

	static constexpr const char value[N+1] = ... /*<
	returns the basic name of the a strongly typed enumeration reflected by a MetaEnumClass.
	>*/;

	typedef __StringConstant type;

	operator const char*(void) const noexcept;
	const char* operator(void) const noexcept;
	
};

template <>
struct __get_scope<MetaEnumClass>
{
	
	typedef __MetaScope value_type; /*<
	returns the MetaScope reflecting the scope of a strongly typed enumeration reflected by a MetaEnumClass.
	>*/
	
};

template <>
struct __get_reflected_type<MetaEnumClass>
{
	
	typedef __Type value_type; /*<
	returns the the base-level type reflected by a MetaEnumClass.
	>*/
	
};

//]
//[reflexpr_MetaEnumClass_operations

//]
//[reflexpr_MetaEnumClass_end
__namespace_meta_end
//]
