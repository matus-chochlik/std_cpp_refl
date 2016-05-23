<?xml version="1.0" encoding="utf8"?>
<xsl:stylesheet
	xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0"
	xmlns:str="http://exslt.org/strings"
	xmlns:exsl="http://exslt.org/common"
	extension-element-prefixes="str exsl"
>
<xsl:param name="revision"/>
<xsl:output method="text"/>

<xsl:template match="/concepts">
&lt;pre&gt;&lt;code&gt;
namespace std {
namespace experimental
namespace meta {

// &lt;em&gt;metaobject concepts&lt;/em&gt;
<xsl:for-each select="/concepts/metaobject[@since_revision &lt;= $revision]">
<xsl:text>template &amp;lt;</xsl:text>
<xsl:choose>
<xsl:when test="@name='Object'">typename</xsl:when>
<xsl:otherwise>Object</xsl:otherwise>
</xsl:choose>
<xsl:text> T&amp;gt; concept bool </xsl:text><xsl:value-of select="@name"/>
<xsl:if test="generalization[not(@optional='true') and not(@concept='Object')]">
<xsl:text> = </xsl:text>
<xsl:for-each select="generalization[not(@optional='true') and not(@concept='Object')]">
	<xsl:if test="position() != 1"> &amp;amp;&amp;amp; </xsl:if>
	<xsl:value-of select="@concept"/><xsl:text>&amp;lt;T&amp;gt;</xsl:text>
</xsl:for-each>
<xsl:text> &amp;amp;&amp;amp; ... </xsl:text>
</xsl:if>;
</xsl:for-each>

// &lt;em&gt;metaobject traits&lt;/em&gt;
<xsl:for-each select="trait[@since_revision &lt;= $revision]">
<xsl:text>template &amp;lt;Object T&amp;gt; struct </xsl:text><xsl:value-of select="@name"/>;
</xsl:for-each>
// 
<xsl:for-each select="trait[@since_revision &lt;= $revision]">
<xsl:text>template &amp;lt;Object T&amp;gt;
  constexpr bool </xsl:text><xsl:value-of select="@name"/>_v = <xsl:value-of select="@name"/>&amp;lt;T&amp;gt;::value;
</xsl:for-each>

} // namespace meta
} // namespace experimental
} // namespace std
&lt;/code&gt;&lt;/pre&gt;
</xsl:template>

</xsl:stylesheet>

