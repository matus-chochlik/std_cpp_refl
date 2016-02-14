
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[reflexpr_ClassMember_def

template <typename T>
__concept bool ClassMember =
	__Scoped<T> &&
	__meta::__is_class_member_v<T> &&
	meta::__is_class_v<__get_scope_t<T>>;

//]
//[reflexpr_ClassMember_begin
__namespace_meta_begin
//]
//[reflexpr_ClassMember_inherited_traits

template <>
struct __has_scope<ClassMember> /*<
Inherited from __Scoped.
>*/
{
	typedef bool value_type;
	static constexpr const bool value = true;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

//]
//[reflexpr_ClassMember_traits

template <>
struct __is_class_member<ClassMember>
{
	typedef bool value_type;
	static constexpr const bool value = true;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

//]
//[reflexpr_ClassMember_inherited_operations

template <>
struct __reflects_same<ClassMember, ClassMember>
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
struct __get_source_location<ClassMember>
{
	
	typedef __SourceLocation value_type; /*<
	returns the source location info of the declaration of class member reflected by a ClassMember.
	>*/
	
};

template <>
struct __get_scope<ClassMember>
{
	
	typedef __Scope value_type; /*<
	returns the result reflecting the scope of class member reflected by a ClassMember.
	>*/
	
};

//]
//[reflexpr_ClassMember_operations

template <>
struct __is_public<ClassMember>
{
	
	typedef bool value_type;
	static constexpr const bool value = ... /*<
	returns whether the class member reflected by a ClassMember was declared with public access.
	>*/;

	typedef __integral_constant<bool, value> type;

	operator bool (void) const noexcept;
	bool operator(void) const noexcept;
	
};

template <>
struct __get_access_specifier<ClassMember>
{
	
	typedef __Specifier value_type; /*<
	returns the result reflecting the access specifier of class member reflected by a ClassMember.
	>*/
	
};

//]
//[reflexpr_ClassMember_end
__namespace_meta_end
//]
