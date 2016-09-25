<?xml version="1.0" encoding="utf8"?>
<xsl:stylesheet
	xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0"
	xmlns:str="http://exslt.org/strings"
	xmlns:exsl="http://exslt.org/common"
	extension-element-prefixes="str exsl"
>
<xsl:param name="revision"/>
<xsl:output method="text"/>

<xsl:template name="expand-variables">
<xsl:param name="text"/>
<xsl:param name="result"/>
<xsl:param name="element"/>
<xsl:param name="operand"/>
	<xsl:choose>
	<xsl:when test="contains($text, '$(')">
	<xsl:value-of select="substring-before($text, '$(')"/>

	<xsl:variable name="variable" select="substring-before(substring-after($text,'$('), ')')"/>
	<xsl:choose>
	<xsl:when test="$variable = 'result'">
		<xsl:text>&lt;code&gt;</xsl:text>meta::<xsl:text>&lt;em&gt;</xsl:text>
		<xsl:value-of select="$result"/>
		<xsl:text>&lt;/em&gt;</xsl:text>
		<xsl:text>&lt;/code&gt;</xsl:text>
	</xsl:when>
	<xsl:when test="$variable = 'elements'">
		<xsl:text>&lt;code&gt;</xsl:text>meta::<xsl:text>&lt;em&gt;</xsl:text>
		<xsl:value-of select="$element"/>
		<xsl:text>&lt;/em&gt;</xsl:text>
		<xsl:text>&lt;/code&gt;(s)</xsl:text>
	</xsl:when>
	<xsl:when test="$variable = 'operand'">
		<xsl:text>&lt;code&gt;</xsl:text>meta::<xsl:text>&lt;em&gt;</xsl:text>
		<xsl:value-of select="$operand"/>
		<xsl:text>&lt;/em&gt;</xsl:text>
		<xsl:text>&lt;/code&gt;</xsl:text>
	</xsl:when>
	<xsl:when test="$variable = 'reflected'">
		<xsl:value-of select="/concepts/metaobject[@name=$operand]/@reflects"/>
	</xsl:when>
	<xsl:otherwise><xsl:value-of select="$variable"/></xsl:otherwise>
	</xsl:choose>

	<xsl:call-template name="expand-variables">
		<xsl:with-param name="text" select="substring-after(substring-after($text, '$('), ')')"/>
		<xsl:with-param name="result" select="$result"/>
		<xsl:with-param name="element" select="$element"/>
		<xsl:with-param name="operand" select="$operand"/>
	</xsl:call-template>

	</xsl:when>
	<xsl:otherwise><xsl:value-of select="$text"/></xsl:otherwise>
	</xsl:choose>
</xsl:template>

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
	<xsl:value-of select="@type"/><xsl:text> </xsl:text><xsl:value-of select="@name"/>
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
<xsl:text>&lt;div&gt;</xsl:text>

<xsl:text>&lt;table&gt;</xsl:text>
<xsl:text>&lt;tr&gt;&lt;th&gt;Template&lt;/th&gt;
&lt;th&gt;Description&lt;/th&gt;
&lt;th&gt;Result&lt;/th&gt;&lt;/tr&gt;
</xsl:text>
<xsl:for-each select="/concepts/operation[@since_revision &lt;= $revision]">

<xsl:text>&lt;tr&gt;&lt;td&gt;</xsl:text>
<xsl:text>&lt;pre&gt;&lt;code&gt;</xsl:text>
<xsl:call-template name="template-args-decl"/>
struct <xsl:value-of select="@name"/>;
<xsl:text>&lt;/code&gt;&lt;/pre&gt;</xsl:text>
<xsl:text>&lt;/td&gt;&lt;td&gt;</xsl:text>
<xsl:call-template name="expand-variables">
	<xsl:with-param name="text" select="@brief"/>
	<xsl:with-param name="result" select="@result"/>
	<xsl:with-param name="element" select="@element"/>
	<xsl:with-param name="operand" select="argument[1]/@type"/>
</xsl:call-template>

<xsl:variable name="result" select="@result"/>
<xsl:variable name="element" select="@element"/>

<xsl:text>&lt;/td&gt;&lt;td&gt;</xsl:text>
<xsl:choose>
	<xsl:when test="/concepts/metaobject[@name=$result]">
		&lt;code&gt;meta::&lt;em&gt;<xsl:value-of select="$result"/>&lt;/em&gt;&lt;/code&gt;
		<xsl:if test="/concepts/metaobject[@name=$element]">
		<xsl:text>of &lt;code&gt;meta::&lt;em&gt;</xsl:text> 
		<xsl:value-of select="$element"/>
		<xsl:text>&lt;/em&gt;&lt;/code&gt;(s)</xsl:text>
		</xsl:if>
	</xsl:when>
	<xsl:when test="@result='BooleanConstant'">a boolean constant</xsl:when>
	<xsl:when test="@result='IntegralConstant'">
		a &lt;code&gt;<xsl:value-of select="@integer"/>&lt;/code&gt; integral constant
	</xsl:when>
	<xsl:when test="@result='StringConstant'">a string constant</xsl:when>
	<xsl:when test="@result='OriginalType'">the original type reflected by the argument</xsl:when>
	<xsl:when test="@result='BaseLevelType'">a type</xsl:when>
	<xsl:when test="@result='ConstantValue'">
		a constant value of an unspecified, integer or <code>enum</code> type
	</xsl:when>
	<xsl:when test="@result='Pointer'">a regular or class data member pointer</xsl:when>
	<xsl:when test="@result='SourceLocation'">
		a &lt;code&gt;std::source_location&lt;/code&gt; constant
	</xsl:when>
	<xsl:otherwise><xsl:value-of select="@result"/></xsl:otherwise>
</xsl:choose>
<xsl:text>&lt;/td&gt;&lt;/tr&gt;</xsl:text>

</xsl:for-each>
<xsl:text>&lt;/table&gt;</xsl:text>
<xsl:text>&lt;/div&gt;</xsl:text>
</xsl:template>

</xsl:stylesheet>

