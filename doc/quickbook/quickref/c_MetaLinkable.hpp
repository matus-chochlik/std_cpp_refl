
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[reflexpr_MetaLinkable_def

template <typename T>
__concept bool MetaLinkable =
	__MetaNamed<T> &&
	__MetaScoped<T> &&
	__meta::__is_linkable_v<T>;

//]
//[reflexpr_MetaLinkable_begin
__namespace_meta_begin
//]
//[reflexpr_MetaLinkable_inherited_traits

template <>
struct __has_name<MetaLinkable> /*<
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
struct __has_scope<MetaLinkable> /*<
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
//[reflexpr_MetaLinkable_traits

template <>
struct __is_linkable<MetaLinkable>
{
	typedef bool value_type;
	static constexpr const bool value = true;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

//]
//[reflexpr_MetaLinkable_inherited_operations

template <>
struct __source_file<MetaLinkable>
{
	
	typedef const char value_type[N+1];

	static constexpr const char value[N+1] = ... /*<
	returns the source file path of the declaration of declaration with storage duration and/or linkage reflected by a MetaLinkable.
	>*/;

	typedef __StringConstant type;

	operator const char*(void) const noexcept;
	const char* operator(void) const noexcept;
	
};

template <>
struct __source_line<MetaLinkable>
{
	
	typedef unsigned value_type;
	static constexpr const unsigned value = ... /*<
	returns the source file line of the declaration of declaration with storage duration and/or linkage reflected by a MetaLinkable.
	>*/;

	typedef __integral_constant<unsigned, value> type;

	operator unsigned(void) const noexcept;
	unsigned operator(void) const noexcept;
	
};

template <>
struct __source_column<MetaLinkable>
{
	
	typedef unsigned value_type;
	static constexpr const unsigned value = ... /*<
	returns the source file column of the declaration of declaration with storage duration and/or linkage reflected by a MetaLinkable.
	>*/;

	typedef __integral_constant<unsigned, value> type;

	operator unsigned(void) const noexcept;
	unsigned operator(void) const noexcept;
	
};

template <>
struct __get_name<MetaLinkable>
{
	
	typedef const char value_type[N+1];

	static constexpr const char value[N+1] = ... /*<
	returns the basic name of the declaration with storage duration and/or linkage reflected by a MetaLinkable.
	>*/;

	typedef __StringConstant type;

	operator const char*(void) const noexcept;
	const char* operator(void) const noexcept;
	
};

template <>
struct __get_scope<MetaLinkable>
{
	
	typedef __MetaScope value_type; /*<
	returns the MetaScope reflecting the scope of declaration with storage duration and/or linkage reflected by a MetaLinkable.
	>*/
	
};

//]
//[reflexpr_MetaLinkable_operations

template <>
struct __is_static<MetaLinkable>
{
	
	typedef bool value_type;
	static constexpr const bool value = ... /*<
	returns whether the declaration with storage duration and/or linkage reflected by a MetaLinkable was declared with the static specifier.
	>*/;

	typedef __integral_constant<bool, value> type;

	operator bool (void) const noexcept;
	bool operator(void) const noexcept;
	
};

//]
//[reflexpr_MetaLinkable_end
__namespace_meta_end
//]
