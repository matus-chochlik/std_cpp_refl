/*
 *  Copyright 2015 Matus Chochlik.
 */

//[reflexpr_metaobject

struct Metaobject { };

template <typename T>
struct __is_metaobject;

static_assert(is_metaobject<Metaobject>::value, "");

//]
//[reflexpr_metaobject_traits

__namespace_meta_begin

template <typename T>
struct __get_category;

template <typename T, typename __MetaobjectCategory>
struct __has_category;

template <typename T>
struct __has_name;

template <typename T>
struct __has_scope;

template <typename T>
struct __is_scope;

template <typename T>
struct __is_alias;

__namespace_meta_end
//]
//[reflexpr_metaobject_source_info
__namespace_meta_begin

template <typename T>
struct source_file
{
	static_assert(__is_metaobject_v<T>, "T must be a Metaobject"); /*<
	Only applicable to __Metaobject(s).
	>*/

	typedef const char value_type[N+1];

	static constexpr const char value[N+1] = ... /*<
	The path to the source file.
	>*/;

	typedef __StringConstant type;

	operator const char* (void) const noexcept; /*<
	Both return [^value] decayed to a pointer.
	>*/
	const char* operator (void) const noexcept;
};

template <typename T>
using source_file_t = typename source_file<T>::type;

template <typename T>
constexpr auto& source_file_v = source_file<T>::value;


template <typename T>
struct source_line
{
	static_assert(__is_metaobject_v<T>, "T must be a Metaobject");

	typedef unsigned value_type;

	static constexpr unsigned value = ... /*<
	The path to the source file line.
	>*/;

	typedef __integral_constant<value_type, value> type;

	operator unsigned  (void) const noexcept; /*<
	Both return [^value].
	>*/
	unsigned operator (void) const noexcept;
};

template <typename T>
using source_line_t = typename source_line<T>::type;

template <typename T>
constexpr unsigned source_line_v = source_line<T>::value;

template <typename T>
struct source_column
{
	static_assert(__is_metaobject_v<T>, "T must be a Metaobject");

	typedef unsigned value_type;

	static constexpr unsigned value = ... /*<
	The path to the source file column.
	>*/;

	typedef __integral_constant<value_type, value> type;

	operator unsigned  (void) const noexcept; /*<
	Both return [^value].
	>*/
	unsigned operator (void) const noexcept;
};

template <typename T>
using source_column_t = typename source_column<T>::type;

template <typename T>
constexpr unsigned source_column_v = source_column<T>::value;

__namespace_meta_end
//]

