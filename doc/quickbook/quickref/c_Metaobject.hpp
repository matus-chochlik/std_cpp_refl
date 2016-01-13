
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[reflexpr_Metaobject_def

template <typename T>
__concept bool Metaobject =
	__is_metaobject_v<T>;

//]
//[reflexpr_Metaobject_begin
__namespace_meta_begin
//]
//[reflexpr_Metaobject_inherited_traits

//]
//[reflexpr_Metaobject_traits

//]
//[reflexpr_Metaobject_inherited_operations

//]
//[reflexpr_Metaobject_operations

template <>
struct __source_file<Metaobject>
{
	
	typedef const char value_type[N+1];

	static constexpr const char value[N+1] = ... /*<
	returns the source file path of the declaration of a base-level program feature reflected by a Metaobject.
	>*/;

	typedef __StringConstant type;

	operator const char*(void) const noexcept;
	const char* operator(void) const noexcept;
	
};

template <>
struct __source_line<Metaobject>
{
	
	typedef unsigned value_type;
	static constexpr const unsigned value = ... /*<
	returns the source file line of the declaration of a base-level program feature reflected by a Metaobject.
	>*/;

	typedef __integral_constant<unsigned, value> type;

	operator unsigned(void) const noexcept;
	unsigned operator(void) const noexcept;
	
};

template <>
struct __source_column<Metaobject>
{
	
	typedef unsigned value_type;
	static constexpr const unsigned value = ... /*<
	returns the source file column of the declaration of a base-level program feature reflected by a Metaobject.
	>*/;

	typedef __integral_constant<unsigned, value> type;

	operator unsigned(void) const noexcept;
	unsigned operator(void) const noexcept;
	
};

//]
//[reflexpr_Metaobject_end
__namespace_meta_end
//]
