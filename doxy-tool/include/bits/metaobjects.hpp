/**
 *  @author Matus Chochlik
 *
 *  Copyright 2006-2012 Matus Chochlik. Distributed under the Boost
 *  Software License, Version 1.0. (See accompanying file
 *  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef STD_CPP_REFL_BITS_METAOBJECTS_1205280839_HPP
#define STD_CPP_REFL_BITS_METAOBJECTS_1205280839_HPP

namespace std {

template <typename Metaobject>
struct _mirrored : Metaobject
{ };

#define mirrored(X) ::std::_mirrored< ::std::_refl:: X ## _ >()

} // namespace std

#endif // include guard
