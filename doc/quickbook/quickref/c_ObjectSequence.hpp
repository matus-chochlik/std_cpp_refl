
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[reflexpr_ObjectSequence_def

template <typename T>
__concept bool ObjectSequence =
	__Object<T> &&
	__meta::__is_sequence_v<T>;

//]
//[reflexpr_ObjectSequence_begin
__namespace_meta_begin
//]
//[reflexpr_ObjectSequence_inherited_traits

//]
//[reflexpr_ObjectSequence_traits

template <>
struct __is_sequence<ObjectSequence>
{
	typedef bool value_type;
	static constexpr const bool value = true;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

//]
//[reflexpr_ObjectSequence_inherited_operations

template <>
struct __reflects_same<ObjectSequence, ObjectSequence>
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
struct __get_source_location<ObjectSequence>
{
	
	typedef __SourceLocation value_type; /*<
	returns the source location info of the declaration of  reflected by a ObjectSequence.
	>*/
	
};

//]
//[reflexpr_ObjectSequence_operations

template <>
struct __get_size<ObjectSequence>
{
	
	typedef size_t value_type;
	static constexpr const size_t value = ... /*<
	returns a number of elements in the sequence.
	>*/;

	typedef __integral_constant<size_t, value> type;

	operator size_t(void) const noexcept;
	size_t operator(void) const noexcept;
	
};

template <size_t Index>
struct __get_element<ObjectSequence, Index>
{
	
	typedef __Object value_type; /*<
	returns the i-th element in a ObjectSequence.
	>*/
	
};

//]
//[reflexpr_ObjectSequence_end
__namespace_meta_end
//]
