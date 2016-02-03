
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[reflexpr_Object_def

template <typename T>
__concept bool Object =
	;

//]
//[reflexpr_Object_begin
__namespace_meta_begin
//]
//[reflexpr_Object_inherited_traits

//]
//[reflexpr_Object_traits

//]
//[reflexpr_Object_inherited_operations

//]
//[reflexpr_Object_operations

template <>
struct __reflects_same<Object, Object>
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
struct __get_source_location<Object>
{
	
	typedef __SourceLocation value_type; /*<
	returns the source location info of the declaration of a base-level program declaration reflected by a Object.
	>*/
	
};

//]
//[reflexpr_Object_end
__namespace_meta_end
//]
