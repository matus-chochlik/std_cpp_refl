<?xml version="1.0" encoding="utf8"?>
<xsl:stylesheet
	xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0"
	xmlns:str="http://exslt.org/strings"
	xmlns:exsl="http://exslt.org/common"
	extension-element-prefixes="str exsl"
>
<xsl:param name="metaobject"/>
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
		<xsl:text>\meta{</xsl:text>
		<xsl:value-of select="substring-after($operand,'Meta')"/>
		<xsl:text>}</xsl:text>
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

<xsl:template name="operations">
<xsl:param name="operation_mo"/>
<xsl:variable name="has_value" select="@result='IntegralConstant' or @result='StringConstant'"/>

<xsl:for-each select="/concepts/operation[argument[@type=$operation_mo]]">
\subsubsection{\texttt{<xsl:value-of select="str:replace(@name, '_','\_')"/>}}

<xsl:call-template name="expand-variables">
	<xsl:with-param name="text" select="@brief"/>
	<xsl:with-param name="operand" select="$metaobject"/>
</xsl:call-template>

\begin{minted}[tabsize=4]{cpp}
<xsl:call-template name="template-args-decl"/>
<xsl:text>requires </xsl:text>
<xsl:for-each select="argument">
<xsl:variable name="arg_type" select="@type"/>
	<xsl:if test="/concepts/metaobject[@name=$arg_type]">
	<xsl:if test="position() != 1"> &amp;&amp; </xsl:if>
	<xsl:value-of select="@type"/>&lt;T<xsl:if test="last()!=1"><xsl:value-of select="position()"/></xsl:if>
	<xsl:text>&gt;</xsl:text>
	</xsl:if>
</xsl:for-each>
struct <xsl:value-of select="@name"/>
<xsl:text>
{</xsl:text>
	<xsl:choose>
	<xsl:when test="@result='IntegralConstant'">
	typedef <xsl:value-of select="@integer"/> value_type;
	static constexpr const <xsl:value-of select="@integer"/> value;

	typedef integral_constant&lt;value_type, value&gt; type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;<xsl:text/>
	</xsl:when>

	<xsl:when test="@result='StringConstant'">
	typedef const char value_type[N+1];

	static constexpr const char value[N+1];

	typedef StringConstant type;

	operator const char* (void) const noexcept;
	const char* operator (void) const noexcept;<xsl:text/>
	</xsl:when>

	<xsl:otherwise>
	typedef <xsl:value-of select="@result"/><xsl:text> type;</xsl:text>
	</xsl:otherwise>
	</xsl:choose>
};

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

\end{minted}
</xsl:for-each>
</xsl:template>


<xsl:template match="/concepts">
<xsl:call-template name="operations">
<xsl:with-param name="operation_mo" select="$metaobject"/>
</xsl:call-template>
</xsl:template>

</xsl:stylesheet>

