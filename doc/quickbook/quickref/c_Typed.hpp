
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[reflexpr_Typed_def

template <typename T>
__concept bool Typed =
	__Object<T> &&
	__meta::__has_type_v<T>;

//]
//[reflexpr_Typed_begin
__namespace_meta_begin
//]
//[reflexpr_Typed_inherited_traits

//]
//[reflexpr_Typed_traits

template <>
struct __has_type<Typed>
{
	typedef bool value_type;
	static constexpr const bool value = true;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

//]
//[reflexpr_Typed_inherited_operations

template <>
struct __reflects_same<Typed, Typed>
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
struct __get_source_location<Typed>
{
	
	typedef __SourceLocation value_type; /*<
	returns the source location info of the declaration of base-level declaration with a type reflected by a Typed.
	>*/
	
};

//]
//[reflexpr_Typed_operations

template <>
struct __get_type<Typed>
{
	
	typedef __Type value_type; /*<
	returns the Type reflecting the type of base-level declaration with a type reflected by a Typed.
	>*/
	
};

//]
//[reflexpr_Typed_end
__namespace_meta_end
//]
