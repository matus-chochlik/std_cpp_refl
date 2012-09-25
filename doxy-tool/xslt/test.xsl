<xsl:stylesheet
	xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0"
	xmlns:crypto="http://exslt.org/crypto"
>
<xsl:output method="text"/>

<xsl:template name="nl">
<xsl:text>&#xA;</xsl:text>
</xsl:template>

<xsl:template match="*">
</xsl:template>

<xsl:template match="compounddef">
<xsl:value-of select="@kind"/>
<xsl:call-template name="nl"/>
</xsl:template>

<xsl:template match="/doxygen">
<xsl:variable name="fileid" select="crypto:md5(.)"/>
<xsl:text>
#ifndef __MIRRORED_</xsl:text><xsl:value-of select="$fileid"/><xsl:text>__
#define __MIRRORED_</xsl:text><xsl:value-of select="$fileid"/><xsl:text>__

#include &lt;bits/metaobject_traits.hpp&gt;

namespace std {
namespace _refl {
</xsl:text>
	<xsl:apply-templates select="compounddef"/>
<xsl:text>
struct __ {
        typedef ::std::global_scope_tag category;
        typedef ::std::true_type has_name;
        typedef ::std::true_type has_scope;
        typedef ::std::true_type is_scope;
        typedef ::std::false_type is_class_member;
        typedef ::std::false_type has_template;
        typedef ::std::false_type is_template;

        static ::std::_ct_string&lt;&gt; base_name(void)
        {
                return ::std::_ct_string&lt;&gt;();
        }

	static ::std::_mirrored&lt; ::std::_refl::__&gt; scope(void)
	{
		return ::std::_mirrored&lt; ::std::_refl::__&gt;();
	}

	static ::std::integral_constant&lt;int, </xsl:text>
		<xsl:value-of select="count(document('../xml/cpp_native.xml')/cpp/type)"/>
	<xsl:text>&gt; member_count(void)
	{
		return ::std::integral_constant&lt;int, </xsl:text>
			<xsl:value-of select="count(document('../xml/cpp_native.xml')/cpp/type)"/>
		<xsl:text>&gt;();
	}
</xsl:text>
<xsl:for-each select="document('../xml/cpp_native.xml')/cpp/type">
<xsl:text>
	static ::std::_mirrored&lt; ::std::_refl::</xsl:text>
		<xsl:value-of select="translate(@name, ' ', '_')"/>
	<xsl:text>_&gt;
	member(::std::integral_constant&lt;int, </xsl:text>
		<xsl:value-of select="position()-1"/>
	<xsl:text>&gt;)
	{
		return ::std::_refl::</xsl:text>
			<xsl:value-of select="translate(@name, ' ', '_')"/>
		<xsl:text>_&gt;();
	}
</xsl:text>
</xsl:for-each>
<xsl:text>
</xsl:text>
<xsl:text>
}; // struct _
} // namespace _refl
} // namespace std

#endif // include-guard
</xsl:text>
</xsl:template>

</xsl:stylesheet>
