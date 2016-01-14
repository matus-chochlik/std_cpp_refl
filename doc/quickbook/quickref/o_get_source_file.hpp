
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[meta_get_source_file
__namespace_meta_begin

template <typename T>
__requires __Metaobject<T>
struct get_source_file
{

	typedef const char value_type[N+1];

	static constexpr const char value[N+1] = ... /*<
	returns the source file path of the declaration of a base-level program feature reflected by a Metaobject.
	>*/;

	typedef __StringConstant type;

	operator const char*(void) const noexcept;
	const char* operator(void) const noexcept;
};

template <typename T>
using get_source_file_t = typename get_source_file<T>::type;

template <typename T>
constexpr bool get_source_file_v = get_source_file<T>::value;

__namespace_meta_end
//]
