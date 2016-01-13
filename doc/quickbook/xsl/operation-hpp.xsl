<?xml version="1.0" encoding="utf8"?>
<xsl:stylesheet
	xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0"
	xmlns:str="http://exslt.org/strings"
	xmlns:exsl="http://exslt.org/common"
	extension-element-prefixes="str exsl"
>
<xsl:param name="operation"/>
<xsl:output method="text"/>

<xsl:template name="expand-variables">
<xsl:param name="text"/>
<xsl:param name="operand"/>
	<xsl:choose>
	<xsl:when test="contains($text, '$(')">
	<xsl:value-of select="substring-before($text, '$(')"/>

	<xsl:variable name="variable" select="substring-before(substring-after($text,'$('), ')')"/>
	<xsl:choose>
	<xsl:when test="$variable = 'operand'">
		<xsl:value-of select="$operand"/>
	</xsl:when>
	<xsl:when test="$variable = 'reflected'">
		<xsl:value-of select="/concepts/metaobject[@name=$operand]/@reflects"/>
	</xsl:when>
	<xsl:otherwise><xsl:value-of select="$variable"/></xsl:otherwise>
	</xsl:choose>

	<xsl:call-template name="expand-variables">
		<xsl:with-param name="text" select="substring-after(substring-after($text, '$('), ')')"/>
		<xsl:with-param name="operand" select="$operand"/>
	</xsl:call-template>

	</xsl:when>
	<xsl:otherwise><xsl:value-of select="$text"/></xsl:otherwise>
	</xsl:choose>
</xsl:template>

<xsl:template name="template-args-decl">
template &lt;<xsl:for-each select="argument">
<xsl:variable name="arg_type" select="@type"/>
	<xsl:if test="position() != 1">, </xsl:if>
	<xsl:choose>
	<xsl:when test="/concepts/metaobject[@name=$arg_type]">
	<xsl:text>typename T</xsl:text><xsl:if test="last()!=1"><xsl:value-of select="position()"/></xsl:if>
	</xsl:when>
	<xsl:otherwise>
	<xsl:value-of select="@type"/><xsl:text> </xsl:text><xsl:value-of select="@name"/>
	</xsl:otherwise>
	</xsl:choose>
</xsl:for-each>&gt;
</xsl:template>

<xsl:template name="template-args-list">
<xsl:text>&lt;</xsl:text><xsl:for-each select="argument">
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
</xsl:for-each><xsl:text>&gt;</xsl:text>
</xsl:template>

<xsl:template match="/concepts">
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[meta_<xsl:value-of select="$operation"/>
__namespace_meta_begin
<xsl:for-each select="operation[@name=$operation]">
<xsl:variable name="has_value" select="@result='IntegralConstant' or @result='StringConstant' or @result='Pointer'"/>

<xsl:call-template name="template-args-decl"/>
<xsl:text>__requires </xsl:text>
<xsl:for-each select="argument">
<xsl:variable name="arg_type" select="@type"/>
	<xsl:if test="/concepts/metaobject[@name=$arg_type]">
	<xsl:if test="position() != 1"> &amp;&amp; </xsl:if>
	<xsl:text>__</xsl:text>
	<xsl:value-of select="@type"/>&lt;T<xsl:if test="last()!=1"><xsl:value-of select="position()"/></xsl:if>
	<xsl:text>&gt;</xsl:text>
	</xsl:if>
</xsl:for-each>
<xsl:text>
struct </xsl:text><xsl:value-of select="@name"/>
{
<xsl:variable name="metaobject">
	<xsl:for-each select="argument">
	<xsl:variable name="arg_type" select="@type"/>
	<xsl:if test="/concepts/metaobject[@name=$arg_type]">
		<xsl:value-of select="$arg_type"/>
	</xsl:if>
	</xsl:for-each>
</xsl:variable>
<xsl:choose>
<xsl:when test="@result='IntegralConstant'">
	typedef <xsl:value-of select="@integer"/> value_type;
	static constexpr const <xsl:value-of select="@integer"/> value = ... /*&lt;
	<xsl:call-template name="expand-variables">
		<xsl:with-param name="text" select="@brief"/>
		<xsl:with-param name="operand" select="$metaobject"/>
	</xsl:call-template>
	&gt;*/;

	typedef __StringConstant type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
</xsl:when>
<xsl:when test="@result='StringConstant'">
	typedef const char value_type[N+1];

	static constexpr const char value[N+1] = ... /*&lt;
	<xsl:call-template name="expand-variables">
		<xsl:with-param name="text" select="@brief"/>
		<xsl:with-param name="operand" select="$metaobject"/>
	</xsl:call-template>
	&gt;*/;

	typedef __StringConstant type;

	operator const char* (void) const noexcept;
	const char* operator (void) const noexcept;
</xsl:when>
<xsl:when test="@result='Pointer'">
	typedef conditional_t&lt;
		__is_class_member_v&lt;T&gt; &amp;&amp; !__is_static_v&lt;T&gt;,
		__get_reflected_type_t&lt;__get_type_t&lt;T&gt;&gt;
		__get_reflected_type_t&lt;__get_scope_t&lt;T&gt;&gt;::*,
		__get_reflected_type_t&lt;__get_type_t&lt;T&gt;&gt;*
	&gt; type;

	static const type value = ... /*&lt;
	<xsl:call-template name="expand-variables">
		<xsl:with-param name="text" select="@brief"/>
		<xsl:with-param name="operand" select="$metaobject"/>
	</xsl:call-template>
	&gt;*/;
</xsl:when>
<xsl:otherwise>
	typedef __<xsl:value-of select="@result"/> type; /*&lt;
	<xsl:call-template name="expand-variables">
		<xsl:with-param name="text" select="@brief"/>
		<xsl:with-param name="operand" select="$metaobject"/>
	</xsl:call-template>
	&gt;*/
</xsl:otherwise>
</xsl:choose>
<xsl:text>};
</xsl:text>

<xsl:call-template name="template-args-decl"/>
<xsl:text>using </xsl:text><xsl:value-of select="@name"/>_t = typename <xsl:value-of select="@name"/>
	<xsl:call-template name="template-args-list"/>
	<xsl:text>::type;</xsl:text>


<xsl:if test="$has_value">
<xsl:text>
</xsl:text>
<xsl:call-template name="template-args-decl"/>
<xsl:text>constexpr bool </xsl:text><xsl:value-of select="@name"/>_v = <xsl:value-of select="@name"/>
	<xsl:call-template name="template-args-list"/>
	<xsl:text>::value;</xsl:text>
</xsl:if>

</xsl:for-each>

__namespace_meta_end
//]
</xsl:template>

</xsl:stylesheet>

