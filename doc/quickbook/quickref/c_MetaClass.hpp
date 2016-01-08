
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[reflexpr_MetaClass_begin
__namespace_meta_begin
//]
//[reflexpr_MetaClass_inherited_traits

template <>
struct __has_name<MetaClass> /*<
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
struct __has_scope<MetaClass> /*<
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
struct __is_type<MetaClass> /*<
Inherited from __MetaType.
>*/
{
	typedef bool value_type;
	static constexpr const bool value = true;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

template <>
struct __is_scope<MetaClass> /*<
Inherited from __MetaScope.
>*/
{
	typedef bool value_type;
	static constexpr const bool value = true;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

//]
//[reflexpr_MetaClass_traits

template <>
struct __is_class<MetaClass>
{
	typedef bool value_type;
	static constexpr const bool value = true;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

//]
//[reflexpr_MetaClass_inherited_operations

template <>
struct __source_file<MetaClass>
{
	
	typedef const char value_type[N+1];

	static constexpr const char value[N+1] = ... /*<
	Source file path of the declaration of a class reflected by a MetaClass.
	>*/;

	typedef __StringConstant type;

	operator const char* (void) const noexcept;
	const char* operator (void) const noexcept;
	
};

template <>
struct __source_line<MetaClass>
{
	
	typedef unsigned value_type;
	static constexpr const unsigned value = ... /*<
	Source file line of the declaration of a class reflected by a MetaClass.
	>*/;

	typedef __integral_constant<value_type, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
	
};

template <>
struct __source_column<MetaClass>
{
	
	typedef unsigned value_type;
	static constexpr const unsigned value = ... /*<
	Source file column of the declaration of a class reflected by a MetaClass.
	>*/;

	typedef __integral_constant<value_type, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
	
};

template <>
struct __get_name<MetaClass>
{
	
	typedef const char value_type[N+1];

	static constexpr const char value[N+1] = ... /*<
	The basic name of the a class reflected by a MetaClass.
	>*/;

	typedef __StringConstant type;

	operator const char* (void) const noexcept;
	const char* operator (void) const noexcept;
	
};

template <>
struct __get_scope<MetaClass>
{
	
	typedef __MetaScope type; /*<
	The MetaScope reflecting the scope of a class reflected by a MetaClass.
	>*/
	
};

template <>
struct __get_reflected_type<MetaClass>
{
	
	typedef __Type type; /*<
	The the base-level type reflected by a MetaClass.
	>*/
	
};

//]
//[reflexpr_MetaClass_operations

template <>
struct __get_data_members<MetaClass>
{
	
	typedef __MetaobjectSequence type; /*<
	A sequence of Metaobjects reflecting the public data members of a class reflected by a MetaClass.
	>*/
	
};

template <>
struct __get_all_data_members<MetaClass>
{
	
	typedef __MetaobjectSequence type; /*<
	A sequence of Metaobjects reflecting the all data members of a class reflected by a MetaClass.
	>*/
	
};

//]
//[reflexpr_MetaClass_end
__namespace_meta_end
//]
