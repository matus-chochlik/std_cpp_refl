
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
	Source file path of the declaration of a base-level program feature reflected by a Metaobject.
	>*/;

	typedef __StringConstant type;

	operator const char* (void) const noexcept;
	const char* operator (void) const noexcept;
	
};

template <>
struct __source_line<Metaobject>
{
	
	typedef unsigned value_type;
	static constexpr const unsigned value = ... /*<
	Source file line of the declaration of a base-level program feature reflected by a Metaobject.
	>*/;

	typedef __integral_constant<value_type, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
	
};

template <>
struct __source_column<Metaobject>
{
	
	typedef unsigned value_type;
	static constexpr const unsigned value = ... /*<
	Source file column of the declaration of a base-level program feature reflected by a Metaobject.
	>*/;

	typedef __integral_constant<value_type, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
	
};

//]
//[reflexpr_Metaobject_end
__namespace_meta_end
//]
