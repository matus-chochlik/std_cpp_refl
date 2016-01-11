
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[reflexpr_MetaobjectSequence_def

template <typename T>
__concept bool MetaobjectSequence = __Metaobject<T> && __meta::__is_sequence_v<T>;

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
struct __source_file<MetaobjectSequence>
{
	
	typedef const char value_type[N+1];

	static constexpr const char value[N+1] = ... /*<
	Source file path of the declaration of  reflected by a MetaobjectSequence.
	>*/;

	typedef __StringConstant type;

	operator const char* (void) const noexcept;
	const char* operator (void) const noexcept;
	
};

template <>
struct __source_line<MetaobjectSequence>
{
	
	typedef unsigned value_type;
	static constexpr const unsigned value = ... /*<
	Source file line of the declaration of  reflected by a MetaobjectSequence.
	>*/;

	typedef __integral_constant<value_type, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
	
};

template <>
struct __source_column<MetaobjectSequence>
{
	
	typedef unsigned value_type;
	static constexpr const unsigned value = ... /*<
	Source file column of the declaration of  reflected by a MetaobjectSequence.
	>*/;

	typedef __integral_constant<value_type, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
	
};

//]
//[reflexpr_MetaobjectSequence_operations

template <>
struct __get_size<MetaobjectSequence>
{
	
	typedef size_t value_type;
	static constexpr const size_t value = ... /*<
	Number of elements in the sequence.
	>*/;

	typedef __integral_constant<value_type, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
	
};

template <size_t Index>
struct __get_element<MetaobjectSequence, Index>
{
	
	typedef __Metaobject type; /*<
	The i-th element in a MetaobjectSequence
	>*/
	
};

//]
//[reflexpr_MetaobjectSequence_end
__namespace_meta_end
//]
