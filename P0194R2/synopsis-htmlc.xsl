<?xml version="1.0" encoding="utf8"?>
<xsl:stylesheet
	xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0"
	xmlns:str="http://exslt.org/strings"
	xmlns:exsl="http://exslt.org/common"
	extension-element-prefixes="str exsl"
>
<xsl:param name="revision"/>
<xsl:output method="text"/>

<xsl:template name="template-args-decl">
<xsl:text>template &amp;lt;</xsl:text><xsl:for-each select="argument">
<xsl:variable name="arg_type" select="@type"/>
	<xsl:if test="position() != 1">, </xsl:if>
	<xsl:choose>
	<xsl:when test="/concepts/metaobject[@name=$arg_type]">
	<xsl:value-of select="$arg_type"/>
	<xsl:text> T</xsl:text><xsl:if test="last()!=1"><xsl:value-of select="position()"/></xsl:if>
	</xsl:when>
	<xsl:when test="$arg_type='VarTypeTemplate'">
	<xsl:text>template &amp;lt;class...&amp;gt; class </xsl:text>
	<xsl:value-of select="@name"/>
	</xsl:when>
	<xsl:otherwise>
	<xsl:value-of select="@type"/><xsl:text> </xsl:text>
	<xsl:value-of select="@name"/>
	</xsl:otherwise>
	</xsl:choose>
</xsl:for-each><xsl:text>&amp;gt;</xsl:text>
</xsl:template>

<xsl:template name="template-args-list">
<xsl:text>&amp;lt;</xsl:text><xsl:for-each select="argument">
<xsl:variable name="arg_type" select="@type"/>
	<xsl:if test="position() != 1">, </xsl:if>
	<xsl:choose>
	<xsl:when test="/concepts/metaobject[@name=$arg_type]">
	<xsl:text>T</xsl:text><xsl:if test="last()!=1"><xsl:value-of select="position()"/></xsl:if>
	</xsl:when>
	<xsl:otherwise>
	<xsl:value-of select="@name"/>
	</xsl:otherwise>
	</xsl:choose>
</xsl:for-each><xsl:text>&amp;gt;</xsl:text>
</xsl:template>

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
<xsl:text> T&amp;gt; concept bool </xsl:text><xsl:value-of select="@name"/>;
</xsl:for-each>

// &lt;em&gt;metaobject operations&lt;/em&gt;
<xsl:for-each select="/concepts/metaobject[@since_revision &lt;= $revision]">
<xsl:variable name="metaobject" select="@name"/>
<xsl:for-each select="/concepts/operation[argument[@type=$metaobject] and @since_revision &lt;= $revision]">
<xsl:call-template name="template-args-decl"/> struct <xsl:value-of select="@name"/>;
</xsl:for-each>
</xsl:for-each>

// 
<xsl:for-each select="/concepts/metaobject[@since_revision &lt;= $revision]">
<xsl:variable name="metaobject" select="@name"/>

<xsl:for-each select="/concepts/operation[argument[@type=$metaobject] and @since_revision &lt;= $revision]">
<xsl:variable name="result" select="@result"/>

<xsl:if test="/concepts/metaobject[@name=$result]">
<xsl:call-template name="template-args-decl"/>
  using <xsl:value-of select="@name"/>_m = typename <xsl:value-of select="@name"/>
<xsl:call-template name="template-args-list"/>::type;
</xsl:if>

<xsl:if test="@result = 'OriginalType'">
<xsl:call-template name="template-args-decl"/>
  using <xsl:value-of select="@name"/>_t = typename <xsl:value-of select="@name"/>
<xsl:call-template name="template-args-list"/>::type;
</xsl:if>

<xsl:if test="@result!='Pointer' and @result!='SourceLocation' and @result!='OriginalType' and not(/concepts/metaobject[@name=$result])">
<xsl:call-template name="template-args-decl"/>
  constexpr auto <xsl:value-of select="@name"/>_v = <xsl:value-of select="@name"/>
<xsl:call-template name="template-args-list"/>::value;
</xsl:if>

<xsl:if test="@result='Pointer'">
<xsl:call-template name="template-args-decl"/>
  const auto <xsl:value-of select="@name"/>_v = <xsl:value-of select="@name"/>
<xsl:call-template name="template-args-list"/>::value;
</xsl:if>

</xsl:for-each>
</xsl:for-each>

} // namespace meta
} // namespace experimental
} // namespace std
&lt;/code&gt;&lt;/pre&gt;
</xsl:template>

</xsl:stylesheet>

