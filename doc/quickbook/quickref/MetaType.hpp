
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[reflexpr_MetaType
__namespace_meta_begin


template <>
struct __has_name<MetaType> /*<
Inherited from __MetaNamed.
>*/
{
	typedef bool value_type;
	static constexpr const bool value = true;

	typedef __integral_constant<value_type, value> type;

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

	typedef __integral_constant<value_type, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

template <>
struct __is_type<MetaType>
{
	typedef bool value_type;
	static constexpr const bool value = true;

	typedef __integral_constant<value_type, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

template <>
struct __get_category<MetaType>
{
	 typedef __MetaobjectCategory type;
};

template <>
struct __source_file<MetaType>
{
	
	typedef const char value_type[N+1];

	static constexpr const char value[N+1] = ... /*<
	Source file path of the declaration of a type reflected by this MetaType.
	>*/;

	typedef __StringConstant type;

	operator const char* (void) const noexcept;
	const char* operator (void) const noexcept;
	
};

template <>
struct __source_line<MetaType>
{
	
	typedef unsigned value_type;
	static constexpr const unsigned value = /*<
	Source file line of the declaration of a type reflected by this MetaType.
	>*/;

	typedef __integral_constant<value_type, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
	
};

template <>
struct __source_column<MetaType>
{
	
	typedef unsigned value_type;
	static constexpr const unsigned value = /*<
	Source file column of the declaration of a type reflected by this MetaType.
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
	the basic name
	>*/;

	typedef __StringConstant type;

	operator const char* (void) const noexcept;
	const char* operator (void) const noexcept;
	
};

template <>
struct __get_scope<MetaType>
{
	 typedef __MetaScope type;
};

template <>
struct __get_reflected_type<MetaType>
{
	 typedef __Type type;
};


__namespace_meta_end
//]
