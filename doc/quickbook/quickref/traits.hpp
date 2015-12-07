/*
 *  Copyright 2015 Matus Chochlik.
 */

//[reflexpr_is_metaobject

template <typename T>
struct is_metaobject
{
	typedef bool value_type;
	static constexpr const bool value = ... /*<
	[^true] if [^T] is a __Metaobject, [^false] otherwise.
	>*/;

	typedef __integral_constant<value_type, value> type;

	operator value_type (void) const noexcept; /*< Both return [^value]. >*/
	value_type operator(void) const noexcept;
};

template <typename T>
using is_metaobject_t = typename is_metaobject<T>::type;

template <typename T>
constexpr bool is_metaobject_v = is_metaobject<T>::value;

//]

//[reflexpr_get_category
__namespace_meta_begin

template <typename T>
struct get_category
{
	static_assert(__is_metaobject_v<T>, "T must be a Metaobject"); /*<
	Only applicable to __Metaobject(s).
	>*/

	typedef __MetaobjectCategory type;
};

template <typename T>
using get_category_t = typename get_category<T>::type;
__namespace_meta_end
//]

//[reflexpr_has_category_1
__namespace_meta_begin

template <typename T, typename __MetaobjectCategory>
struct has_category
{
	static_assert(__is_metaobject_v<T>, "T must be a Metaobject"); /*<
	Only applicable to __Metaobject(s).
	>*/

	typedef bool value_type;
	static constexpr const bool value =
		__is_same_v<__get_category_t<T>, MetaobjectCategory>; /*<
		Possible implementation.
		>*/

	typedef __integral_constant<value_type, value> type;

	operator value_type (void) const noexcept; /*< Both return [^value]. >*/
	value_type operator(void) const noexcept;
}
//]
//[reflexpr_has_category_2

template <typename T>
struct has_category<T, __namespace_tag>
{
	static_assert(__is_metaobject_v<T>, "T must be a Metaobject");

	typedef bool value_type;
	static constexpr const bool value =
		__is_same_v<__get_category_t<T>, __global_scope_tag> ||
		__is_same_v<__get_category_t<T>, __namespace_tag>; /*<
		Possible implementation.
		>*/

	typedef __integral_constant<value_type, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};
//]
//[reflexpr_has_category_3

template <typename T>
struct has_category<T, __type_tag>
{
	static_assert(__is_metaobject_v<T>, "T must be a Metaobject");

	typedef bool value_type;
	static constexpr const bool value =
		__is_same_v<__get_category_t<T>, __class_tag> ||
		__is_same_v<__get_category_t<T>, __enum_tag> ||
		__is_same_v<__get_category_t<T>, __type_tag>; /*<
		Possible implementation.
		>*/

	typedef __integral_constant<value_type, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

//]
//[reflexpr_has_category_4

template <typename T, typename __MetaobjectCategory>
constexpr bool has_category_v = has_category<T, MetaobjectCategory>::value;

__namespace_meta_end
//]
//[reflexpr_is_namespace
__namespace_meta_begin

template <typename T>
using is_namespace = __has_category<T, __namespace_tag>;

template <typename T>
using is_namespace_t = typename is_namespace<T>::type;

template <typename T>
constexpr bool is_namespace_v = is_namespace<T>::value;

__namespace_meta_end
//]
//[reflexpr_is_global_scope
__namespace_meta_begin

template <typename T>
using is_global_scope = __has_category<T, __global_scope_tag>;

template <typename T>
using is_global_scope_t = typename is_global_scope<T>::type;

template <typename T>
constexpr bool is_global_scope_v = is_global_scope<T>::value;

__namespace_meta_end
//]
//[reflexpr_is_type
__namespace_meta_begin

template <typename T>
using is_type = __has_category<T, __type_tag>;

template <typename T>
using is_type_t = typename is_type<T>::type;

template <typename T>
constexpr bool is_type_v = is_type<T>::value;

__namespace_meta_end
//]
//[reflexpr_is_class
__namespace_meta_begin

template <typename T>
using is_class = __has_category<T, __class_tag>;

template <typename T>
using is_class_t = typename is_class<T>::type;

template <typename T>
constexpr bool is_class_v = is_class<T>::value;

__namespace_meta_end
//]
//[reflexpr_is_enum
__namespace_meta_begin

template <typename T>
using is_enum = __has_category<T, __enum_tag>;

template <typename T>
using is_enum_t = typename is_enum<T>::type;

template <typename T>
constexpr bool is_enum_v = is_enum<T>::value;

__namespace_meta_end
//]
//[reflexpr_is_enum_class
__namespace_meta_begin

template <typename T>
using is_enum_class = __has_category<T, __enum_class_tag>;

template <typename T>
using is_enum_class_t = typename is_enum_class<T>::type;

template <typename T>
constexpr bool is_enum_class_v = is_enum_class<T>::value;

__namespace_meta_end
//]

//[reflexpr_is_sequence
__namespace_meta_begin

template <typename T>
struct is_sequence
{
	static_assert(__is_metaobject_v<T>, "T must be a Metaobject"); /*<
	Only applicable to __Metaobject(s).
	>*/

	typedef bool value_type;
	static constexpr const bool value = ... /*<
	[^true] if [^T] is a __MetaobjectSequence , [^false] otherwise.
	>*/;

	typedef integral_constant<value_type, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

template <typename T>
using is_sequence_t = typename is_sequence<T>::type;

template <typename T>
constexpr bool is_sequence_v = is_sequence<T>::value;

__namespace_meta_end
//]

//[reflexpr_has_name
__namespace_meta_begin

template <typename T>
struct has_name
{
	static_assert(__is_metaobject_v<T>, "T must be a Metaobject"); /*<
	Only applicable to __Metaobject(s).
	>*/

	typedef bool value_type;
	static constexpr const bool value = ... /*<
	[^true] if [^T] is a __MetaNamed, [^false] otherwise.
	>*/;

	typedef integral_constant<value_type, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

template <typename T>
using has_name_t = typename has_name<T>::type;

template <typename T>
constexpr bool has_name_v = has_name<T>::value;

__namespace_meta_end
//]

//[reflexpr_has_scope
__namespace_meta_begin

template <typename T>
struct has_scope
{
	static_assert(__is_metaobject_v<T>, "T must be a Metaobject"); /*<
	Only applicable to __Metaobject(s).
	>*/

	typedef bool value_type;
	static constexpr const bool value = ... /*<
	[^true] if [^T] is a __MetaScoped, [^false] otherwise.
	>*/;

	typedef integral_constant<value_type, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

template <typename T>
using has_scope_t = typename has_scope<T>::type;

template <typename T>
constexpr bool has_scope_v = has_scope<T>::value;

__namespace_meta_end
//]

//[reflexpr_is_scope
__namespace_meta_begin

template <typename T>
struct is_scope
{
	static_assert(__is_metaobject_v<T>, "T must be a Metaobject"); /*<
	Only applicable to __Metaobject(s).
	>*/

	typedef bool value_type;
	static constexpr const bool value = ... /*<
	[^true] if [^T] is a __MetaScope, [^false] otherwise.
	>*/;

	typedef integral_constant<value_type, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

template <typename T>
using is_scope_t = typename is_scope<T>::type;

template <typename T>
constexpr bool is_scope_v = is_scope<T>::value;

__namespace_meta_end
//]

//[reflexpr_is_alias
__namespace_meta_begin

template <typename T>
struct is_alias
{
	static_assert(__is_metaobject_v<T>, "T must be a Metaobject"); /*<
	Only applicable to __Metaobject(s).
	>*/

	typedef bool value_type;
	static constexpr const bool value = ... /*<
	[^true] if [^T] is a __MetaAlias, [^false] otherwise.
	>*/;

	typedef integral_constant<value_type, value> type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

template <typename T>
using is_alias_t = typename is_alias<T>::type;

template <typename T>
constexpr bool is_alias_v = is_alias<T>::value;

__namespace_meta_end
//]

