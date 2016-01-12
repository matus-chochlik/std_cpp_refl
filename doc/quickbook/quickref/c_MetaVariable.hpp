
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[reflexpr_MetaVariable_def

template <typename T>
__concept bool MetaVariable =
	__MetaNamed<T> &&
	__MetaTyped<T> &&
	__meta::__is_variable_v<T>;

//]
//[reflexpr_MetaVariable_begin
__namespace_meta_begin
//]
//[reflexpr_MetaVariable_inherited_traits

template <>
struct __has_name<MetaVariable> /*<
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
struct __has_type<MetaVariable> /*<
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
struct __has_scope<MetaVariable> /*<
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
//[reflexpr_MetaVariable_traits

template <>
struct __is_variable<MetaVariable>
{
	typedef bool value_type;
	static constexpr const bool value = true;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

//]
//[reflexpr_MetaVariable_inherited_operations

template <>
struct __source_file<MetaVariable>
{
	
	typedef const char value_type[N+1];

	static constexpr const char value[N+1] = ... /*<
	returns a source file path of the declaration of a variable reflected by a MetaVariable.
	>*/;

	typedef __StringConstant type;

	operator const char* (void) const noexcept;
	const char* operator (void) const noexcept;
	
};

template <>
struct __source_line<MetaVariable>
{
	
	typedef unsigned value_type;
	static constexpr const unsigned value = ... /*<
	returns a source file line of the declaration of a variable reflected by a MetaVariable.
	>*/;

	typedef __integral_constant<value_type, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
	
};

template <>
struct __source_column<MetaVariable>
{
	
	typedef unsigned value_type;
	static constexpr const unsigned value = ... /*<
	returns a source file column of the declaration of a variable reflected by a MetaVariable.
	>*/;

	typedef __integral_constant<value_type, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
	
};

template <>
struct __get_name<MetaVariable>
{
	
	typedef const char value_type[N+1];

	static constexpr const char value[N+1] = ... /*<
	returns the basic name of the a variable reflected by a MetaVariable.
	>*/;

	typedef __StringConstant type;

	operator const char* (void) const noexcept;
	const char* operator (void) const noexcept;
	
};

template <>
struct __get_type<MetaVariable>
{
	
	typedef __MetaType type; /*<
	returns the MetaType reflecting the type of a variable reflected by a MetaVariable.
	>*/
	
};

template <>
struct __get_scope<MetaVariable>
{
	
	typedef __MetaScope type; /*<
	returns the MetaScope reflecting the scope of a variable reflected by a MetaVariable.
	>*/
	
};

//]
//[reflexpr_MetaVariable_operations

template <>
struct __get_pointer<MetaVariable>
{
	
	typedef Pointer type;

	static const type value = ... /*<
	returns a pointer to the a variable reflected by a MetaVariable.   If the variable is a class member then the pointer is a class data member pointer,   otherwise it is a plain pointer to the variable.
	>*/;
	
};

//]
//[reflexpr_MetaVariable_end
__namespace_meta_end
//]
