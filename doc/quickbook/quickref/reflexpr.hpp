/*
 *  Copyright 2015 Matus Chochlik.
 */

//[reflexpr_usage

namespace foo { namespace bar { } }

namespace foobar = foo::bar;

typedef int baz;

typedef reflexpr()         __MetaGlobalScope;
typedef reflexpr(::)       __MetaGlobalScope; /*<
A metaobject reflecting the global scope.
>*/
typedef reflexpr(foo::bar) __MetaNamespace; /*<
A metaobject reflecting the foo::bar namespace.
>*/
typedef reflexpr(foobar)   __MetaNamespaceAlias; /*<
A metaobject reflecting the foobar namespace alias.
>*/
typedef reflexpr(int)      __MetaType; /*<
A metaobject reflecting the int type.
>*/
typedef reflexpr(baz)      __MetaTypeAlias; /*<
A metaobject reflecting the baz typedef.
>*/
//]

