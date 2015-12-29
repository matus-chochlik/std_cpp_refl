
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[reflexpr_MetaTypeAlias
__namespace_meta_begin


template <>
struct __has_name<MetaTypeAlias> /*<
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
struct __has_scope<MetaTypeAlias> /*<
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
struct __is_type<MetaTypeAlias> /*<
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
struct __is_alias<MetaTypeAlias> /*<
Inherited from __MetaAlias.
>*/
{
	typedef bool value_type;
	static constexpr const bool value = true;

	typedef __integral_constant<value_type, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

template <>
struct __get_category<MetaTypeAlias>
{
	 typedef __MetaobjectCategory type;
};

template <>
struct __source_file<MetaTypeAlias>
{
	
	typedef const char value_type[N+1];

	static constexpr const char value[N+1] = ... /*<
	Source file path of the declaration of a type alias or typedef reflected by this MetaTypeAlias.
	>*/;

	typedef __StringConstant type;

	operator const char* (void) const noexcept;
	const char* operator (void) const noexcept;
	
};

template <>
struct __source_line<MetaTypeAlias>
{
	
	typedef unsigned value_type;
	static constexpr const unsigned value = /*<
	Source file line of the declaration of a type alias or typedef reflected by this MetaTypeAlias.
	>*/;

	typedef __integral_constant<value_type, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
	
};

template <>
struct __source_column<MetaTypeAlias>
{
	
	typedef unsigned value_type;
	static constexpr const unsigned value = /*<
	Source file column of the declaration of a type alias or typedef reflected by this MetaTypeAlias.
	>*/;

	typedef __integral_constant<value_type, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
	
};

template <>
struct __get_name<MetaTypeAlias>
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
struct __get_scope<MetaTypeAlias>
{
	 typedef __MetaScope type;
};

template <>
struct __get_reflected_type<MetaTypeAlias>
{
	 typedef __Type type;
};

template <>
struct __get_aliased<MetaTypeAlias>
{
	 typedef __MetaNamed type;
};

template <>
struct __get_typedef_type<MetaTypeAlias>
{
	 typedef __MetaType type;
};


__namespace_meta_end
//]
