
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[reflexpr_Linkable_def

template <typename T>
__concept bool Linkable =
	__Named<T> &&
	__Scoped<T> &&
	__meta::__is_linkable_v<T>;

//]
//[reflexpr_Linkable_begin
__namespace_meta_begin
//]
//[reflexpr_Linkable_inherited_traits

template <>
struct __has_name<Linkable> /*<
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
struct __has_scope<Linkable> /*<
Inherited from __Scoped.
>*/
{
	typedef bool value_type;
	static constexpr const bool value = true;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

//]
//[reflexpr_Linkable_traits

template <>
struct __is_linkable<Linkable>
{
	typedef bool value_type;
	static constexpr const bool value = true;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

//]
//[reflexpr_Linkable_inherited_operations

template <>
struct __reflects_same<Linkable, Linkable>
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
struct __get_source_location<Linkable>
{
	
	typedef __SourceLocation value_type; /*<
	returns the source location info of the declaration of declaration with storage duration and/or linkage reflected by a Linkable.
	>*/
	
};

template <>
struct __get_name<Linkable>
{
	
	typedef const char value_type[N+1];

	static constexpr const char value[N+1] = ... /*<
	returns the basic name of the declaration with storage duration and/or linkage reflected by a Linkable.
	>*/;

	typedef __StringConstant type;

	operator const char*(void) const noexcept;
	const char* operator(void) const noexcept;
	
};

template <>
struct __get_scope<Linkable>
{
	
	typedef __Scope value_type; /*<
	returns the Scope reflecting the scope of declaration with storage duration and/or linkage reflected by a Linkable.
	>*/
	
};

//]
//[reflexpr_Linkable_operations

template <>
struct __is_static<Linkable>
{
	
	typedef bool value_type;
	static constexpr const bool value = ... /*<
	returns whether the declaration with storage duration and/or linkage reflected by a Linkable was declared with the static specifier.
	>*/;

	typedef __integral_constant<bool, value> type;

	operator bool (void) const noexcept;
	bool operator(void) const noexcept;
	
};

//]
//[reflexpr_Linkable_end
__namespace_meta_end
//]
