
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[meta_source_line
__namespace_meta_begin

template <typename Metaobject>
struct source_line
{
	static_assert(__is_metaobject_v<__Metaobject>, "");
	
	typedef unsigned value_type;
	static constexpr const unsigned value = ... /*<
	Source file line of the declaration of a base-level program feature reflected by a Metaobject.
	>*/;

	typedef __StringConstant type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;

};


template <typename Metaobject>
using source_line_t =
	typename source_line<Metaobject>::type;

template <typename Metaobject>
constexpr bool source_line_v =
	source_line<Metaobject>::value;

__namespace_meta_end
//]
