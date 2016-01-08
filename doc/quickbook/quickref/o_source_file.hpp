
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[meta_source_file
__namespace_meta_begin

template <typename Metaobject>
struct source_file
{
	static_assert(__is_metaobject_v<__Metaobject>, "");
	
	typedef const char value_type[N+1];

	static constexpr const char value[N+1] = ... /*<
	Source file path of the declaration of a base-level program feature reflected by a Metaobject.
	>*/;

	typedef __StringConstant type;

	operator const char* (void) const noexcept;
	const char* operator (void) const noexcept;

};


template <typename Metaobject>
using source_file_t =
	typename source_file<Metaobject>::type;

template <typename Metaobject>
constexpr bool source_file_v =
	source_file<Metaobject>::value;

__namespace_meta_end
//]
