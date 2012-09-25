/**
 *  @author Matus Chochlik
 *
 *  Copyright 2006-2012 Matus Chochlik. Distributed under the Boost
 *  Software License, Version 1.0. (See accompanying file
 *  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef STD_CPP_REFL_BITS_METAOBJECT_CATEGORIES_1205280839_HPP
#define STD_CPP_REFL_BITS_METAOBJECT_CATEGORIES_1205280839_HPP

namespace std {

struct specifier_tag { };
struct namespace_tag { };
struct global_scope_tag { };
struct type_tag { };
struct typedef_tag { };
struct class_tag { };
struct function_tag { };
struct constructor_tag { };
struct operator_tag { };
struct overloaded_function_tag { };
struct enum_tag { };
struct inheritance_tag { };
struct constant_tag { };
struct variable_tag { };
struct parameter_tag { };

} // namespace std

#endif // include guard
