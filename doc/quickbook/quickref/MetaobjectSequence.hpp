
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[reflexpr_MetaobjectSequence
__namespace_meta_begin


template <>
struct __is_sequence<MetaobjectSequence>
{
	typedef bool value_type;
	static constexpr const bool value = true;

	typedef __integral_constant<value_type, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

template <>
struct __get_category<MetaobjectSequence>
{
	 typedef __MetaobjectCategory type;
};

template <>
struct __source_file<MetaobjectSequence>
{
	
	typedef const char value_type[N+1];

	static constexpr const char value[N+1] = ... /*<
	Source file path of the declaration of the .
	>*/;

	typedef __StringConstant type;

	operator const char* (void) const noexcept;
	const char* operator (void) const noexcept;
	
};

template <>
struct __source_line<MetaobjectSequence>
{
	
	typedef unsigned value_type;
	static constexpr const unsigned value = /*<
	Source file line of the declaration of the reflected .
	>*/;

	typedef __integral_constant<value_type, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
	
};

template <>
struct __source_column<MetaobjectSequence>
{
	
	typedef unsigned value_type;
	static constexpr const unsigned value = /*<
	Source file column of the declaration of the reflected .
	>*/;

	typedef __integral_constant<value_type, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
	
};

template <>
struct __get_size<MetaobjectSequence>
{
	
	typedef size_t value_type;
	static constexpr const size_t value = /*<
	Number of elements in the sequence.
	>*/;

	typedef __integral_constant<value_type, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
	
};

template <>
struct __get_element<MetaobjectSequence, __IntegralConstant>
{
	 typedef __Metaobject type;
};


__namespace_meta_end
//]
