
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[reflexpr_Class_def

template <typename T>
__concept bool Class =
	__Type<T> &&
	__Scope<T> &&
	__meta::__is_class_v<T>;

//]
//[reflexpr_Class_begin
__namespace_meta_begin
//]
//[reflexpr_Class_inherited_traits

template <>
struct __has_name<Class> /*<
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
struct __has_scope<Class> /*<
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
struct __is_type<Class> /*<
Inherited from __Type.
>*/
{
	typedef bool value_type;
	static constexpr const bool value = true;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

template <>
struct __is_scope<Class> /*<
Inherited from __Scope.
>*/
{
	typedef bool value_type;
	static constexpr const bool value = true;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

//]
//[reflexpr_Class_traits

template <>
struct __is_class<Class>
{
	typedef bool value_type;
	static constexpr const bool value = true;

	typedef __integral_constant<bool, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

//]
//[reflexpr_Class_inherited_operations

template <>
struct __reflects_same<Class, Class>
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
struct __get_source_location<Class>
{
	
	typedef __SourceLocation value_type; /*<
	returns the source location info of the declaration of a class reflected by a Class.
	>*/
	
};

template <>
struct __get_name<Class>
{
	
	typedef const char value_type[N+1];

	static constexpr const char value[N+1] = ... /*<
	returns the basic name of the a class reflected by a Class.
	>*/;

	typedef __StringConstant type;

	operator const char*(void) const noexcept;
	const char* operator(void) const noexcept;
	
};

template <>
struct __get_scope<Class>
{
	
	typedef __Scope value_type; /*<
	returns the result reflecting the scope of a class reflected by a Class.
	>*/
	
};

template <>
struct __get_reflected_type<Class>
{
	
	typedef __OriginalType value_type; /*<
	returns the the base-level type reflected by a Class.
	>*/
	
};

//]
//[reflexpr_Class_operations

template <>
struct __get_elaborated_type_specifier<Class>
{
	
	typedef __Specifier value_type; /*<
	returns a result reflecting the elaborated type specifier (class,struct,union,...) of a class reflected by a Class.
	>*/
	
};

template <>
struct __get_data_members<Class>
{
	
	typedef __ObjectSequence value_type; /*<
	returns a result of metaobjects reflecting   the public data members of a class reflected by a Class.
	>*/
	
};

template <>
struct __get_all_data_members<Class>
{
	
	typedef __ObjectSequence value_type; /*<
	returns a result of metaobjects reflecting all    (including the private and protected)   data members of a class reflected by a Class.
	>*/
	
};

//]
//[reflexpr_Class_end
__namespace_meta_end
//]
