
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[reflexpr_MetaClassMember_def

template <typename T>
__concept bool MetaClassMember =
	__MetaScoped<T> &&
	__meta::__is_class_member_v<T> &&
	meta::__is_class_v<__get_scope_t<T>>;

//]
//[reflexpr_MetaClassMember_begin
__namespace_meta_begin
//]
//[reflexpr_MetaClassMember_inherited_traits

template <>
struct __has_scope<MetaClassMember> /*<
Inherited from __MetaScoped.
>*/
{
	typedef bool value_type;
	static constexpr const bool value = true;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

//]
//[reflexpr_MetaClassMember_traits

template <>
struct __is_class_member<MetaClassMember>
{
	typedef bool value_type;
	static constexpr const bool value = true;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

//]
//[reflexpr_MetaClassMember_inherited_operations

template <>
struct __get_source_file<MetaClassMember>
{
	
	typedef const char value_type[N+1];

	static constexpr const char value[N+1] = ... /*<
	returns the source file path of the declaration of class member reflected by a MetaClassMember.
	>*/;

	typedef __StringConstant type;

	operator const char*(void) const noexcept;
	const char* operator(void) const noexcept;
	
};

template <>
struct __get_source_line<MetaClassMember>
{
	
	typedef unsigned value_type;
	static constexpr const unsigned value = ... /*<
	returns the source file line of the declaration of class member reflected by a MetaClassMember.
	>*/;

	typedef __integral_constant<unsigned, value> type;

	operator unsigned(void) const noexcept;
	unsigned operator(void) const noexcept;
	
};

template <>
struct __get_source_column<MetaClassMember>
{
	
	typedef unsigned value_type;
	static constexpr const unsigned value = ... /*<
	returns the source file column of the declaration of class member reflected by a MetaClassMember.
	>*/;

	typedef __integral_constant<unsigned, value> type;

	operator unsigned(void) const noexcept;
	unsigned operator(void) const noexcept;
	
};

template <>
struct __get_scope<MetaClassMember>
{
	
	typedef __MetaScope value_type; /*<
	returns the MetaScope reflecting the scope of class member reflected by a MetaClassMember.
	>*/
	
};

//]
//[reflexpr_MetaClassMember_operations

template <>
struct __is_public<MetaClassMember>
{
	
	typedef bool value_type;
	static constexpr const bool value = ... /*<
	returns whether the class member reflected by a MetaClassMember was declared with public access.
	>*/;

	typedef __integral_constant<bool, value> type;

	operator bool (void) const noexcept;
	bool operator(void) const noexcept;
	
};

//]
//[reflexpr_MetaClassMember_end
__namespace_meta_end
//]
