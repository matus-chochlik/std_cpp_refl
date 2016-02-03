
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[reflexpr_NamespaceAlias_def

template <typename T>
__concept bool NamespaceAlias =
	__Namespace<T> &&
	__Alias<T> &&
	__meta::__is_namespace_v<__get_aliased_t<T>>;

//]
//[reflexpr_NamespaceAlias_begin
__namespace_meta_begin
//]
//[reflexpr_NamespaceAlias_inherited_traits

template <>
struct __has_name<NamespaceAlias> /*<
Inherited from __Named.
>*/
{
	typedef bool value_type;
	static constexpr const bool value = true;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

template <>
struct __has_scope<NamespaceAlias> /*<
Inherited from __Scoped.
>*/
{
	typedef bool value_type;
	static constexpr const bool value = true;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

template <>
struct __is_scope<NamespaceAlias> /*<
Inherited from __Scope.
>*/
{
	typedef bool value_type;
	static constexpr const bool value = true;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

template <>
struct __is_namespace<NamespaceAlias> /*<
Inherited from __Namespace.
>*/
{
	typedef bool value_type;
	static constexpr const bool value = true;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

template <>
struct __is_alias<NamespaceAlias> /*<
Inherited from __Alias.
>*/
{
	typedef bool value_type;
	static constexpr const bool value = true;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

//]
//[reflexpr_NamespaceAlias_traits

//]
//[reflexpr_NamespaceAlias_inherited_operations

template <>
struct __reflects_same<NamespaceAlias, NamespaceAlias>
{
	
	typedef bool value_type;
	static constexpr const bool value = ... /*<
	indicates if two metaobjects reflect the same base-level declaration.
	>*/;

	typedef __integral_constant<bool, value> type;

	operator bool (void) const noexcept;
	bool operator(void) const noexcept;
	
};

template <>
struct __get_source_location<NamespaceAlias>
{
	
	typedef __SourceLocation value_type; /*<
	returns the source location info of the declaration of a namespace alias reflected by a NamespaceAlias.
	>*/
	
};

template <>
struct __get_name<NamespaceAlias>
{
	
	typedef const char value_type[N+1];

	static constexpr const char value[N+1] = ... /*<
	returns the basic name of the a namespace alias reflected by a NamespaceAlias.
	>*/;

	typedef __StringConstant type;

	operator const char*(void) const noexcept;
	const char* operator(void) const noexcept;
	
};

template <>
struct __get_scope<NamespaceAlias>
{
	
	typedef __Scope value_type; /*<
	returns the Scope reflecting the scope of a namespace alias reflected by a NamespaceAlias.
	>*/
	
};

template <>
struct __get_aliased<NamespaceAlias>
{
	
	typedef __Named value_type; /*<
	returns the Named reflecting the original declaration of a namespace alias reflected by a NamespaceAlias.
	>*/
	
};

//]
//[reflexpr_NamespaceAlias_operations

//]
//[reflexpr_NamespaceAlias_end
__namespace_meta_end
//]
