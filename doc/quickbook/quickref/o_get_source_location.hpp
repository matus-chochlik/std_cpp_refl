
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[meta_get_source_location
__namespace_meta_begin

template <typename T>
__requires __Object<T>
struct get_source_location
{

	typedef __SourceLocation type; /*<
	returns the source location info of the declaration of a base-level program declaration reflected by a Object.
	>*/
};

template <typename T>
using get_source_location_t = typename get_source_location<T>::type;

__namespace_meta_end
//]
