/*
 *  Copyright 2015 Matus Chochlik.
 */

//[reflexpr_meta_global_scope
__namespace_meta_begin

static_assert(__is_global_scope<MetaGlobalScope>::value, "");
static_assert(__is_namespace<MetaGlobalScope>::value, "");

static_assert(!__has_scope<MetaGlobalScope>::value, "");

__namespace_meta_end
//]

