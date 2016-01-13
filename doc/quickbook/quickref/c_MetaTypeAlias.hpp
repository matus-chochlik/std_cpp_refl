
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[reflexpr_MetaTypeAlias_def

template <typename T>
__concept bool MetaTypeAlias =
	__MetaType<T> &&
	__MetaAlias<T> &&
	__meta::__is_type_v<__get_aliased_t<T>>;

//]
//[reflexpr_MetaTypeAlias_begin
__namespace_meta_begin
//]
//[reflexpr_MetaTypeAlias_inherited_traits

template <>
struct __has_name<MetaTypeAlias> /*<
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
struct __has_scope<MetaTypeAlias> /*<
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
struct __is_type<MetaTypeAlias> /*<
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
struct __is_alias<MetaTypeAlias> /*<
Inherited from __MetaAlias.
>*/
{
	typedef bool value_type;
	static constexpr const bool value = true;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

//]
//[reflexpr_MetaTypeAlias_traits

//]
//[reflexpr_MetaTypeAlias_inherited_operations

template <>
struct __source_file<MetaTypeAlias>
{
	
	typedef const char value_type[N+1];

	static constexpr const char value[N+1] = ... /*<
	returns the source file path of the declaration of a type alias or typedef reflected by a MetaTypeAlias.
	>*/;

	typedef __StringConstant type;

	operator const char*(void) const noexcept;
	const char* operator(void) const noexcept;
	
};

template <>
struct __source_line<MetaTypeAlias>
{
	
	typedef unsigned value_type;
	static constexpr const unsigned value = ... /*<
	returns the source file line of the declaration of a type alias or typedef reflected by a MetaTypeAlias.
	>*/;

	typedef __integral_constant<unsigned, value> type;

	operator unsigned(void) const noexcept;
	unsigned operator(void) const noexcept;
	
};

template <>
struct __source_column<MetaTypeAlias>
{
	
	typedef unsigned value_type;
	static constexpr const unsigned value = ... /*<
	returns the source file column of the declaration of a type alias or typedef reflected by a MetaTypeAlias.
	>*/;

	typedef __integral_constant<unsigned, value> type;

	operator unsigned(void) const noexcept;
	unsigned operator(void) const noexcept;
	
};

template <>
struct __get_name<MetaTypeAlias>
{
	
	typedef const char value_type[N+1];

	static constexpr const char value[N+1] = ... /*<
	returns the basic name of the a type alias or typedef reflected by a MetaTypeAlias.
	>*/;

	typedef __StringConstant type;

	operator const char*(void) const noexcept;
	const char* operator(void) const noexcept;
	
};

template <>
struct __get_scope<MetaTypeAlias>
{
	
	typedef __MetaScope value_type; /*<
	returns the MetaScope reflecting the scope of a type alias or typedef reflected by a MetaTypeAlias.
	>*/
	
};

template <>
struct __get_reflected_type<MetaTypeAlias>
{
	
	typedef __Type value_type; /*<
	returns the the base-level type reflected by a MetaTypeAlias.
	>*/
	
};

template <>
struct __get_aliased<MetaTypeAlias>
{
	
	typedef __MetaNamed value_type; /*<
	returns the MetaNamed reflecting the original declaration of a type alias or typedef reflected by a MetaTypeAlias.
	>*/
	
};

//]
//[reflexpr_MetaTypeAlias_operations

//]
//[reflexpr_MetaTypeAlias_end
__namespace_meta_end
//]
