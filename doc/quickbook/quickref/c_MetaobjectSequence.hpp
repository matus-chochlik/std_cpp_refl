
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[reflexpr_MetaobjectSequence_def

template <typename T>
__concept bool MetaobjectSequence =
	__Metaobject<T> &&
	__meta::__is_sequence_v<T>;

//]
//[reflexpr_MetaobjectSequence_begin
__namespace_meta_begin
//]
//[reflexpr_MetaobjectSequence_inherited_traits

//]
//[reflexpr_MetaobjectSequence_traits

template <>
struct __is_sequence<MetaobjectSequence>
{
	typedef bool value_type;
	static constexpr const bool value = true;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

//]
//[reflexpr_MetaobjectSequence_inherited_operations

template <>
struct __get_source_file<MetaobjectSequence>
{
	
	typedef const char value_type[N+1];

	static constexpr const char value[N+1] = ... /*<
	returns the source file path of the declaration of  reflected by a MetaobjectSequence.
	>*/;

	typedef __StringConstant type;

	operator const char*(void) const noexcept;
	const char* operator(void) const noexcept;
	
};

template <>
struct __get_source_line<MetaobjectSequence>
{
	
	typedef unsigned value_type;
	static constexpr const unsigned value = ... /*<
	returns the source file line of the declaration of  reflected by a MetaobjectSequence.
	>*/;

	typedef __integral_constant<unsigned, value> type;

	operator unsigned(void) const noexcept;
	unsigned operator(void) const noexcept;
	
};

template <>
struct __get_source_column<MetaobjectSequence>
{
	
	typedef unsigned value_type;
	static constexpr const unsigned value = ... /*<
	returns the source file column of the declaration of  reflected by a MetaobjectSequence.
	>*/;

	typedef __integral_constant<unsigned, value> type;

	operator unsigned(void) const noexcept;
	unsigned operator(void) const noexcept;
	
};

//]
//[reflexpr_MetaobjectSequence_operations

template <>
struct __get_size<MetaobjectSequence>
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
struct __get_element<MetaobjectSequence, Index>
{
	
	typedef __Metaobject value_type; /*<
	returns the i-th element in a MetaobjectSequence.
	>*/
	
};

//]
//[reflexpr_MetaobjectSequence_end
__namespace_meta_end
//]
