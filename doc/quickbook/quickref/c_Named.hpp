
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[reflexpr_Named_def

template <typename T>
__concept bool Named =
	__Object<T> &&
	__meta::__has_name_v<T>;

//]
//[reflexpr_Named_begin
__namespace_meta_begin
//]
//[reflexpr_Named_inherited_traits

//]
//[reflexpr_Named_traits

template <>
struct __has_name<Named>
{
	typedef bool value_type;
	static constexpr const bool value = true;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

//]
//[reflexpr_Named_inherited_operations

template <>
struct __reflects_same<Named, Named>
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
struct __get_source_location<Named>
{
	
	typedef __SourceLocation value_type; /*<
	returns the source location info of the declaration of a named declaration reflected by a Named.
	>*/
	
};

//]
//[reflexpr_Named_operations

template <>
struct __get_name<Named>
{
	
	typedef const char value_type[N+1];

	static constexpr const char value[N+1] = ... /*<
	returns the basic name of the a named declaration reflected by a Named.
	>*/;

	typedef __StringConstant type;

	operator const char*(void) const noexcept;
	const char* operator(void) const noexcept;
	
};

//]
//[reflexpr_Named_end
__namespace_meta_end
//]
