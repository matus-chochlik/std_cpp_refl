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

