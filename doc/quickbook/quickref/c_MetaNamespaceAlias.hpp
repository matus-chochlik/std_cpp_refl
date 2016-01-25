
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[reflexpr_MetaNamespaceAlias_def

template <typename T>
__concept bool MetaNamespaceAlias =
	__MetaNamespace<T> &&
	__MetaAlias<T> &&
	__meta::__is_namespace_v<__get_aliased_t<T>>;

//]
//[reflexpr_MetaNamespaceAlias_begin
__namespace_meta_begin
//]
//[reflexpr_MetaNamespaceAlias_inherited_traits

template <>
struct __has_name<MetaNamespaceAlias> /*<
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
struct __has_scope<MetaNamespaceAlias> /*<
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
struct __is_scope<MetaNamespaceAlias> /*<
Inherited from __MetaScope.
>*/
{
	typedef bool value_type;
	static constexpr const bool value = true;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

template <>
struct __is_namespace<MetaNamespaceAlias> /*<
Inherited from __MetaNamespace.
>*/
{
	typedef bool value_type;
	static constexpr const bool value = true;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

template <>
struct __is_alias<MetaNamespaceAlias> /*<
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
//[reflexpr_MetaNamespaceAlias_traits

//]
//[reflexpr_MetaNamespaceAlias_inherited_operations

template <>
struct __get_source_file<MetaNamespaceAlias>
{
	
	typedef const char value_type[N+1];

	static constexpr const char value[N+1] = ... /*<
	returns the source file path of the declaration of a namespace alias reflected by a MetaNamespaceAlias.
	>*/;

	typedef __StringConstant type;

	operator const char*(void) const noexcept;
	const char* operator(void) const noexcept;
	
};

template <>
struct __get_source_line<MetaNamespaceAlias>
{
	
	typedef unsigned value_type;
	static constexpr const unsigned value = ... /*<
	returns the source file line of the declaration of a namespace alias reflected by a MetaNamespaceAlias.
	>*/;

	typedef __integral_constant<unsigned, value> type;

	operator unsigned(void) const noexcept;
	unsigned operator(void) const noexcept;
	
};

template <>
struct __get_source_column<MetaNamespaceAlias>
{
	
	typedef unsigned value_type;
	static constexpr const unsigned value = ... /*<
	returns the source file column of the declaration of a namespace alias reflected by a MetaNamespaceAlias.
	>*/;

	typedef __integral_constant<unsigned, value> type;

	operator unsigned(void) const noexcept;
	unsigned operator(void) const noexcept;
	
};

template <>
struct __get_name<MetaNamespaceAlias>
{
	
	typedef const char value_type[N+1];

	static constexpr const char value[N+1] = ... /*<
	returns the basic name of the a namespace alias reflected by a MetaNamespaceAlias.
	>*/;

	typedef __StringConstant type;

	operator const char*(void) const noexcept;
	const char* operator(void) const noexcept;
	
};

template <>
struct __get_scope<MetaNamespaceAlias>
{
	
	typedef __MetaScope value_type; /*<
	returns the MetaScope reflecting the scope of a namespace alias reflected by a MetaNamespaceAlias.
	>*/
	
};

template <>
struct __get_aliased<MetaNamespaceAlias>
{
	
	typedef __MetaNamed value_type; /*<
	returns the MetaNamed reflecting the original declaration of a namespace alias reflected by a MetaNamespaceAlias.
	>*/
	
};

//]
//[reflexpr_MetaNamespaceAlias_operations

//]
//[reflexpr_MetaNamespaceAlias_end
__namespace_meta_end
//]
