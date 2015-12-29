
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[reflexpr_MetaClass
__namespace_meta_begin


template <>
struct __has_name<MetaClass> /*<
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
struct __has_scope<MetaClass> /*<
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
struct __is_type<MetaClass> /*<
Inherited from __MetaType.
>*/
{
	typedef bool value_type;
	static constexpr const bool value = true;

	typedef __integral_constant<value_type, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

template <>
struct __is_scope<MetaClass> /*<
Inherited from __MetaScope.
>*/
{
	typedef bool value_type;
	static constexpr const bool value = true;

	typedef __integral_constant<value_type, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

template <>
struct __is_class<MetaClass>
{
	typedef bool value_type;
	static constexpr const bool value = true;

	typedef __integral_constant<value_type, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

template <>
struct __get_category<MetaClass>
{
	 typedef __MetaobjectCategory type;
};

template <>
struct __source_file<MetaClass>
{
	
	typedef const char value_type[N+1];

	static constexpr const char value[N+1] = ... /*<
	Source file path of the declaration of a class reflected by this MetaClass.
	>*/;

	typedef __StringConstant type;

	operator const char* (void) const noexcept;
	const char* operator (void) const noexcept;
	
};

template <>
struct __source_line<MetaClass>
{
	
	typedef unsigned value_type;
	static constexpr const unsigned value = /*<
	Source file line of the declaration of a class reflected by this MetaClass.
	>*/;

	typedef __integral_constant<value_type, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
	
};

template <>
struct __source_column<MetaClass>
{
	
	typedef unsigned value_type;
	static constexpr const unsigned value = /*<
	Source file column of the declaration of a class reflected by this MetaClass.
	>*/;

	typedef __integral_constant<value_type, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
	
};

template <>
struct __get_name<MetaClass>
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
struct __get_scope<MetaClass>
{
	 typedef __MetaScope type;
};

template <>
struct __get_reflected_type<MetaClass>
{
	 typedef __Type type;
};

template <>
struct __get_data_members<MetaClass>
{
	 typedef __MetaobjectSequence type;
};


__namespace_meta_end
//]
