
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[reflexpr_MetaTyped
__namespace_meta_begin


template <>
struct __has_type<MetaTyped>
{
	typedef bool value_type;
	static constexpr const bool value = true;

	typedef __integral_constant<value_type, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

template <>
struct __get_category<MetaTyped>
{
	 typedef __MetaobjectCategory type;
};

template <>
struct __source_file<MetaTyped>
{
	
	typedef const char value_type[N+1];

	static constexpr const char value[N+1] = ... /*<
	Source file path of the declaration of  reflected by this MetaTyped.
	>*/;

	typedef __StringConstant type;

	operator const char* (void) const noexcept;
	const char* operator (void) const noexcept;
	
};

template <>
struct __source_line<MetaTyped>
{
	
	typedef unsigned value_type;
	static constexpr const unsigned value = /*<
	Source file line of the declaration of  reflected by this MetaTyped.
	>*/;

	typedef __integral_constant<value_type, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
	
};

template <>
struct __source_column<MetaTyped>
{
	
	typedef unsigned value_type;
	static constexpr const unsigned value = /*<
	Source file column of the declaration of  reflected by this MetaTyped.
	>*/;

	typedef __integral_constant<value_type, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
	
};

template <>
struct __get_type<MetaTyped>
{
	 typedef __MetaType type;
};


__namespace_meta_end
//]
