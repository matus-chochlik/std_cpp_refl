
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[reflexpr_MetaNamed_def

template <typename T>
__concept bool MetaNamed =
	__Metaobject<T> &&
	__meta::__has_name_v<T>;

//]
//[reflexpr_MetaNamed_begin
__namespace_meta_begin
//]
//[reflexpr_MetaNamed_inherited_traits

//]
//[reflexpr_MetaNamed_traits

template <>
struct __has_name<MetaNamed>
{
	typedef bool value_type;
	static constexpr const bool value = true;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

//]
//[reflexpr_MetaNamed_inherited_operations

template <>
struct __get_source_file<MetaNamed>
{
	
	typedef const char value_type[N+1];

	static constexpr const char value[N+1] = ... /*<
	returns the source file path of the declaration of a named declaration reflected by a MetaNamed.
	>*/;

	typedef __StringConstant type;

	operator const char*(void) const noexcept;
	const char* operator(void) const noexcept;
	
};

template <>
struct __get_source_line<MetaNamed>
{
	
	typedef unsigned value_type;
	static constexpr const unsigned value = ... /*<
	returns the source file line of the declaration of a named declaration reflected by a MetaNamed.
	>*/;

	typedef __integral_constant<unsigned, value> type;

	operator unsigned(void) const noexcept;
	unsigned operator(void) const noexcept;
	
};

template <>
struct __get_source_column<MetaNamed>
{
	
	typedef unsigned value_type;
	static constexpr const unsigned value = ... /*<
	returns the source file column of the declaration of a named declaration reflected by a MetaNamed.
	>*/;

	typedef __integral_constant<unsigned, value> type;

	operator unsigned(void) const noexcept;
	unsigned operator(void) const noexcept;
	
};

//]
//[reflexpr_MetaNamed_operations

template <>
struct __get_name<MetaNamed>
{
	
	typedef const char value_type[N+1];

	static constexpr const char value[N+1] = ... /*<
	returns the basic name of the a named declaration reflected by a MetaNamed.
	>*/;

	typedef __StringConstant type;

	operator const char*(void) const noexcept;
	const char* operator(void) const noexcept;
	
};

//]
//[reflexpr_MetaNamed_end
__namespace_meta_end
//]
