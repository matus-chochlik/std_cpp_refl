<?xml version="1.0" encoding="utf8"?>
<xsl:stylesheet
	xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0"
	xmlns:str="http://exslt.org/strings"
	xmlns:exsl="http://exslt.org/common"
	extension-element-prefixes="str exsl"
>
<xsl:param name="metaobject" value="Metaobject"/>
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

<xsl:template name="list-generalizations">
	<xsl:param name="child"/>

	<xsl:text>(</xsl:text><xsl:value-of select="$child"/><xsl:text>)</xsl:text>

	<xsl:for-each select="/concepts/metaobject[@name=$child]/generalization">
		<xsl:text>(</xsl:text><xsl:value-of select="@concept"/><xsl:text>)</xsl:text>

		<xsl:call-template name="list-generalizations">
			<xsl:with-param name="child" select="@concept"/>
		</xsl:call-template>
	</xsl:for-each>
</xsl:template>

<xsl:template name="trait">
<xsl:param name="trait_mo"/>

<xsl:for-each select="/concepts/trait[@indicates=$trait_mo]">
template &lt;&gt;
struct __<xsl:value-of select="@name"/>&lt;<xsl:value-of select="$metaobject"/>&gt;<xsl:if test="$trait_mo != $metaobject"> /*&lt;
<xsl:choose>
<xsl:when test="@optional='true'">Optionally inherited if <xsl:value-of select="$metaobject"/> is also a __<xsl:value-of select="$trait_mo"/>.</xsl:when>
<xsl:otherwise>Inherited from __<xsl:value-of select="$trait_mo"/>.</xsl:otherwise>
</xsl:choose>
&gt;*/</xsl:if>
{
	typedef bool value_type;
	static constexpr const bool value = true;

	typedef __integral_constant&lt;bool, value&gt; type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};
</xsl:for-each>
</xsl:template>


<xsl:template name="operations">
<xsl:param name="operation_mo"/>

<xsl:for-each select="/concepts/operation[argument[@type=$operation_mo]]">
template &lt;<xsl:for-each select="argument">
<xsl:variable name="arg_type" select="@type"/>
	<xsl:if test="not(/concepts/metaobject[@name=$arg_type])">
	<xsl:value-of select="@type"/><xsl:text> </xsl:text><xsl:value-of select="@name"/>
	</xsl:if>
</xsl:for-each>&gt;
struct __<xsl:value-of select="@name"/>&lt;<xsl:for-each select="argument">
<xsl:variable name="arg_type" select="@type"/>
<xsl:if test="position() != 1">, </xsl:if>
<xsl:choose>
<xsl:when test="@type = $operation_mo"><xsl:value-of select="$metaobject"/></xsl:when>
<xsl:when test="not(/concepts/metaobject[@name=$arg_type])"><xsl:value-of select="@name"/></xsl:when>
<xsl:otherwise>__<xsl:value-of select="@type"/></xsl:otherwise>
</xsl:choose>
</xsl:for-each>&gt;
{
	<xsl:choose>
	<xsl:when test="@result='IntegralConstant'">
	typedef <xsl:value-of select="@integer"/> value_type;
	static constexpr const <xsl:value-of select="@integer"/> value = ... /*&lt;
	<xsl:call-template name="expand-variables">
		<xsl:with-param name="text" select="@brief"/>
		<xsl:with-param name="operand" select="$metaobject"/>
	</xsl:call-template>
	&gt;*/;

	typedef __integral_constant&lt;value_type, value&gt; type;

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

	<xsl:otherwise>
	typedef __<xsl:value-of select="@result"/> type; /*&lt;
	<xsl:call-template name="expand-variables">
		<xsl:with-param name="text" select="@brief"/>
		<xsl:with-param name="operand" select="$metaobject"/>
	</xsl:call-template>
	&gt;*/
	</xsl:otherwise>
	</xsl:choose>
};
</xsl:for-each>
</xsl:template>

<xsl:template name="inherited-traits">
	<xsl:param name="child"/>
	<xsl:param name="done"/>

	<xsl:for-each select="/concepts/metaobject[@name=$child]/generalization">

		<xsl:variable name="new_done">
		<xsl:value-of select="$done"/>
		<xsl:for-each select="preceding-sibling::generalization">
		<xsl:call-template name="list-generalizations">
			<xsl:with-param name="child" select="@concept"/>
		</xsl:call-template>
		</xsl:for-each>
		</xsl:variable>

		<xsl:if test="not(contains($new_done, concat('(',@concept,')')))">
		<xsl:call-template name="inherited-traits">
			<xsl:with-param name="child" select="@concept"/>
			<xsl:with-param name="done" select="$new_done"/>
		</xsl:call-template>

		<xsl:call-template name="trait">
		<xsl:with-param name="trait_mo" select="@concept"/>
		</xsl:call-template>
		</xsl:if>
	</xsl:for-each>
</xsl:template>

<xsl:template name="inherited-operations">
	<xsl:param name="child"/>
	<xsl:param name="done"/>


	<xsl:for-each select="/concepts/metaobject[@name=$child]/generalization">

		<xsl:variable name="new_done">
		<xsl:value-of select="$done"/>
		<xsl:for-each select="preceding-sibling::generalization">
		<xsl:call-template name="list-generalizations">
			<xsl:with-param name="child" select="@concept"/>
		</xsl:call-template>
		</xsl:for-each>
		</xsl:variable>

		<xsl:if test="not(contains($new_done, concat('(',@concept,')')))">
		<xsl:call-template name="inherited-operations">
			<xsl:with-param name="child" select="@concept"/>
			<xsl:with-param name="done" select="$new_done"/>
		</xsl:call-template>

		<xsl:call-template name="operations">
		<xsl:with-param name="operation_mo" select="@concept"/>
		</xsl:call-template>
		</xsl:if>
	</xsl:for-each>
</xsl:template>

<xsl:template match="/concepts">
/*
 *  Copyright 2015 Matus Chochlik.
 */

//[reflexpr_<xsl:value-of select="$metaobject"/>_def
<xsl:for-each select="/concepts/metaobject[@name=$metaobject]">
template &lt;typename T&gt;
__concept bool <xsl:value-of select="@name"/><xsl:text> = </xsl:text>
<xsl:for-each select="generalization[not(@optional='true')]">
	<xsl:if test="position() != 1"> &amp;&amp; </xsl:if>
	<xsl:text>__</xsl:text><xsl:value-of select="@concept"/><xsl:text>&lt;T&gt;</xsl:text>
</xsl:for-each>
<xsl:variable name="has_gens" select="generalization[not(@optional='true')]"/>
<xsl:for-each select="/concepts/trait[@indicates=$metaobject]">
	<xsl:if test="position() != 1 or $has_gens"> &amp;&amp; </xsl:if>
	<xsl:if test="@scope">__<xsl:value-of select="@scope"/>::</xsl:if>
	<xsl:text>__</xsl:text><xsl:value-of select="@name"/><xsl:text>_v&lt;T&gt;</xsl:text>
</xsl:for-each>
<xsl:variable name="has_trts" select="/concepts/trait[@indicates=$metaobject]"/>
<xsl:for-each select="constraint">
	<xsl:if test="position() != 1 or $has_gens or $has_trts"> &amp;&amp; </xsl:if>
	<xsl:if test="not($has_trts)">__</xsl:if><xsl:text>meta::</xsl:text>
	<xsl:if test="@operation and @trait">
		<xsl:text>__</xsl:text><xsl:value-of select="@trait"/><xsl:text>_v&lt;</xsl:text>
		<xsl:text>__</xsl:text><xsl:value-of select="@operation"/><xsl:text>_t&lt;T&gt;&gt;</xsl:text>
	</xsl:if>
</xsl:for-each>
<xsl:if test="@name='Metaobject'">__is_metaobject_v&lt;T&gt;</xsl:if>;
</xsl:for-each>
//]
//[reflexpr_<xsl:value-of select="$metaobject"/>_begin
__namespace_meta_begin
//]
//[reflexpr_<xsl:value-of select="$metaobject"/>_inherited_traits
<xsl:call-template name="inherited-traits">
<xsl:with-param name="child" select="$metaobject"/>
</xsl:call-template>
//]
//[reflexpr_<xsl:value-of select="$metaobject"/>_traits
<xsl:call-template name="trait">
<xsl:with-param name="trait_mo" select="$metaobject"/>
</xsl:call-template>
//]
//[reflexpr_<xsl:value-of select="$metaobject"/>_inherited_operations
<xsl:call-template name="inherited-operations">
<xsl:with-param name="child" select="$metaobject"/>
</xsl:call-template>
//]
//[reflexpr_<xsl:value-of select="$metaobject"/>_operations
<xsl:call-template name="operations">
<xsl:with-param name="operation_mo" select="$metaobject"/>
</xsl:call-template>
//]
//[reflexpr_<xsl:value-of select="$metaobject"/>_end
__namespace_meta_end
//]
</xsl:template>

</xsl:stylesheet>

