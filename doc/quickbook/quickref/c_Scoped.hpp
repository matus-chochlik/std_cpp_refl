
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[reflexpr_Scoped_def

template <typename T>
__concept bool Scoped =
	__Object<T> &&
	__meta::__has_scope_v<T>;

//]
//[reflexpr_Scoped_begin
__namespace_meta_begin
//]
//[reflexpr_Scoped_inherited_traits

//]
//[reflexpr_Scoped_traits

template <>
struct __has_scope<Scoped>
{
	typedef bool value_type;
	static constexpr const bool value = true;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

//]
//[reflexpr_Scoped_inherited_operations

template <>
struct __reflects_same<Scoped, Scoped>
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
struct __get_source_location<Scoped>
{
	
	typedef __SourceLocation value_type; /*<
	returns the source location info of the declaration of a scoped declaration reflected by a Scoped.
	>*/
	
};

//]
//[reflexpr_Scoped_operations

template <>
struct __get_scope<Scoped>
{
	
	typedef __Scope value_type; /*<
	returns the Scope reflecting the scope of a scoped declaration reflected by a Scoped.
	>*/
	
};

//]
//[reflexpr_Scoped_end
__namespace_meta_end
//]
