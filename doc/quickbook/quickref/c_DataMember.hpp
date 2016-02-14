
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[reflexpr_DataMember_def

template <typename T>
__concept bool DataMember =
	__Variable<T> &&
	__ClassMember<T>;

//]
//[reflexpr_DataMember_begin
__namespace_meta_begin
//]
//[reflexpr_DataMember_inherited_traits

template <>
struct __has_name<DataMember> /*<
Inherited from __Named.
>*/
{
	typedef bool value_type;
	static constexpr const bool value = true;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

template <>
struct __has_type<DataMember> /*<
Inherited from __Typed.
>*/
{
	typedef bool value_type;
	static constexpr const bool value = true;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

template <>
struct __has_scope<DataMember> /*<
Inherited from __Scoped.
>*/
{
	typedef bool value_type;
	static constexpr const bool value = true;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

template <>
struct __is_linkable<DataMember> /*<
Inherited from __Linkable.
>*/
{
	typedef bool value_type;
	static constexpr const bool value = true;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

template <>
struct __is_variable<DataMember> /*<
Inherited from __Variable.
>*/
{
	typedef bool value_type;
	static constexpr const bool value = true;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

template <>
struct __is_class_member<DataMember> /*<
Inherited from __ClassMember.
>*/
{
	typedef bool value_type;
	static constexpr const bool value = true;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

//]
//[reflexpr_DataMember_traits

//]
//[reflexpr_DataMember_inherited_operations

template <>
struct __reflects_same<DataMember, DataMember>
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
struct __get_source_location<DataMember>
{
	
	typedef __SourceLocation value_type; /*<
	returns the source location info of the declaration of a class data member reflected by a DataMember.
	>*/
	
};

template <>
struct __get_name<DataMember>
{
	
	typedef const char value_type[N+1];

	static constexpr const char value[N+1] = ... /*<
	returns the basic name of the a class data member reflected by a DataMember.
	>*/;

	typedef __StringConstant type;

	operator const char*(void) const noexcept;
	const char* operator(void) const noexcept;
	
};

template <>
struct __get_type<DataMember>
{
	
	typedef __Type value_type; /*<
	returns the result reflecting the type of a class data member reflected by a DataMember.
	>*/
	
};

template <>
struct __get_scope<DataMember>
{
	
	typedef __Scope value_type; /*<
	returns the result reflecting the scope of a class data member reflected by a DataMember.
	>*/
	
};

template <>
struct __is_static<DataMember>
{
	
	typedef bool value_type;
	static constexpr const bool value = ... /*<
	returns whether the a class data member reflected by a DataMember was declared with the static specifier.
	>*/;

	typedef __integral_constant<bool, value> type;

	operator bool (void) const noexcept;
	bool operator(void) const noexcept;
	
};

template <>
struct __get_pointer<DataMember>
{
	
	typedef Pointer value_type;

	static const value_type value = ... /*<
	returns a pointer to the a class data member reflected by a DataMember.   If the variable is a class member then the pointer is a class data member pointer,   otherwise it is a plain pointer.
	>*/;
	
};

template <>
struct __is_public<DataMember>
{
	
	typedef bool value_type;
	static constexpr const bool value = ... /*<
	returns whether the a class data member reflected by a DataMember was declared with public access.
	>*/;

	typedef __integral_constant<bool, value> type;

	operator bool (void) const noexcept;
	bool operator(void) const noexcept;
	
};

template <>
struct __get_access_specifier<DataMember>
{
	
	typedef __Specifier value_type; /*<
	returns the result reflecting the access specifier of a class data member reflected by a DataMember.
	>*/
	
};

//]
//[reflexpr_DataMember_operations

//]
//[reflexpr_DataMember_end
__namespace_meta_end
//]
