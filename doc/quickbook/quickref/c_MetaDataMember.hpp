
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[reflexpr_MetaDataMember_def

template <typename T>
__concept bool MetaDataMember =
	__MetaVariable<T> &&
	__MetaClassMember<T>;

//]
//[reflexpr_MetaDataMember_begin
__namespace_meta_begin
//]
//[reflexpr_MetaDataMember_inherited_traits

template <>
struct __has_name<MetaDataMember> /*<
Inherited from __MetaNamed.
>*/
{
	typedef bool value_type;
	static constexpr const bool value = true;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

template <>
struct __has_type<MetaDataMember> /*<
Inherited from __MetaTyped.
>*/
{
	typedef bool value_type;
	static constexpr const bool value = true;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

template <>
struct __has_scope<MetaDataMember> /*<
Inherited from __MetaScoped.
>*/
{
	typedef bool value_type;
	static constexpr const bool value = true;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

template <>
struct __is_linkable<MetaDataMember> /*<
Inherited from __MetaLinkable.
>*/
{
	typedef bool value_type;
	static constexpr const bool value = true;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

template <>
struct __is_variable<MetaDataMember> /*<
Inherited from __MetaVariable.
>*/
{
	typedef bool value_type;
	static constexpr const bool value = true;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

template <>
struct __is_class_member<MetaDataMember> /*<
Inherited from __MetaClassMember.
>*/
{
	typedef bool value_type;
	static constexpr const bool value = true;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

//]
//[reflexpr_MetaDataMember_traits

//]
//[reflexpr_MetaDataMember_inherited_operations

template <>
struct __get_source_file<MetaDataMember>
{
	
	typedef const char value_type[N+1];

	static constexpr const char value[N+1] = ... /*<
	returns the source file path of the declaration of a class data member reflected by a MetaDataMember.
	>*/;

	typedef __StringConstant type;

	operator const char*(void) const noexcept;
	const char* operator(void) const noexcept;
	
};

template <>
struct __get_source_line<MetaDataMember>
{
	
	typedef unsigned value_type;
	static constexpr const unsigned value = ... /*<
	returns the source file line of the declaration of a class data member reflected by a MetaDataMember.
	>*/;

	typedef __integral_constant<unsigned, value> type;

	operator unsigned(void) const noexcept;
	unsigned operator(void) const noexcept;
	
};

template <>
struct __get_source_column<MetaDataMember>
{
	
	typedef unsigned value_type;
	static constexpr const unsigned value = ... /*<
	returns the source file column of the declaration of a class data member reflected by a MetaDataMember.
	>*/;

	typedef __integral_constant<unsigned, value> type;

	operator unsigned(void) const noexcept;
	unsigned operator(void) const noexcept;
	
};

template <>
struct __get_name<MetaDataMember>
{
	
	typedef const char value_type[N+1];

	static constexpr const char value[N+1] = ... /*<
	returns the basic name of the a class data member reflected by a MetaDataMember.
	>*/;

	typedef __StringConstant type;

	operator const char*(void) const noexcept;
	const char* operator(void) const noexcept;
	
};

template <>
struct __get_type<MetaDataMember>
{
	
	typedef __MetaType value_type; /*<
	returns the MetaType reflecting the type of a class data member reflected by a MetaDataMember.
	>*/
	
};

template <>
struct __get_scope<MetaDataMember>
{
	
	typedef __MetaScope value_type; /*<
	returns the MetaScope reflecting the scope of a class data member reflected by a MetaDataMember.
	>*/
	
};

template <>
struct __is_static<MetaDataMember>
{
	
	typedef bool value_type;
	static constexpr const bool value = ... /*<
	returns whether the a class data member reflected by a MetaDataMember was declared with the static specifier.
	>*/;

	typedef __integral_constant<bool, value> type;

	operator bool (void) const noexcept;
	bool operator(void) const noexcept;
	
};

template <>
struct __get_pointer<MetaDataMember>
{
	
	typedef Pointer value_type;

	static const value_type value = ... /*<
	returns a pointer to the a class data member reflected by a MetaDataMember.   If the variable is a class member then the pointer is a class data member pointer,   otherwise it is a plain pointer.
	>*/;
	
};

//]
//[reflexpr_MetaDataMember_operations

//]
//[reflexpr_MetaDataMember_end
__namespace_meta_end
//]
