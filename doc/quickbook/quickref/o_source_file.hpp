
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[meta_source_file
__namespace_meta_begin

template <typename T>
__requires __Metaobject<T>
struct source_file
{

	typedef const char value_type[N+1];

	static constexpr const char value[N+1] = ... /*<
	Source file path of the declaration of a base-level program feature reflected by a Metaobject.
	>*/;

	typedef __StringConstant type;

	operator const char* (void) const noexcept;
	const char* operator (void) const noexcept;
};

template <typename T>
using source_file_t = typename source_file<T>::type;

template <typename T>
constexpr bool source_file_v = source_file<T>::value;

__namespace_meta_end
//]
