/**
 *  @author Matus Chochlik
 *
 *  Copyright 2006-2012 Matus Chochlik. Distributed under the Boost
 *  Software License, Version 1.0. (See accompanying file
 *  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef STD_CPP_REFL_METAOBJECT_TRAITS_1205280839_HPP
#define STD_CPP_REFL_METAOBJECT_TRAITS_1205280839_HPP

#include <type_traits>

#include <bits/metaobject_categories.hpp>
#include <bits/metaobjects.hpp>
#include <bits/ct_string.hpp>

namespace std {

template <typename T>
struct is_metaobject : false_type 
{ };

template <typename T>
struct metaobject_traits;

template <typename P>
struct metaobject_traits<std::_mirrored<P>>
{
	typedef typename P::category category;
        typedef typename P::has_name has_name;
        typedef typename P::has_scope has_scope;
        typedef typename P::is_scope is_scope;
        typedef typename P::is_class_member is_class_member;
        typedef typename P::has_template has_template;
        typedef typename P::is_template is_template;
};

} // namespace std

#endif // include guard
