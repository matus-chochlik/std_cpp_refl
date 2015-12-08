/*
 *  Copyright 2015 Matus Chochlik.
 */

//[reflexpr_meta_class
__namespace_meta_begin

static_assert(__is_class<MetaClass>::value, "");

template <typename T>
struct get_data_members
{
	static_assert(__is_class<T>, "T must be a MetaClass");

	typedef __MetaobjectSequence type;
};

template <typename T>
using get_data_members_t = typename get_data_members<T>::type;

template <typename T>
struct get_all_data_members
{
	static_assert(__is_class<T>, "T must be a MetaClass");

	typedef __MetaobjectSequence type;
};

template <typename T>
using get_all_data_members_t = typename get_all_data_members<T>::type;

__namespace_meta_end
//]

