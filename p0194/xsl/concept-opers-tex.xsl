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
<xsl:param name="result"/>
<xsl:param name="operand"/>
	<xsl:choose>
	<xsl:when test="contains($text, '$(')">
	<xsl:value-of select="substring-before($text, '$(')"/>

	<xsl:variable name="variable" select="substring-before(substring-after($text,'$('), ')')"/>
	<xsl:choose>
	<xsl:when test="$variable = 'result'">
		<xsl:text>\meta{</xsl:text>
		<xsl:value-of select="$result"/>
		<xsl:text>}</xsl:text>
	</xsl:when>
	<xsl:when test="$variable = 'operand'">
		<xsl:text>\meta{</xsl:text>
		<xsl:value-of select="$operand"/>
		<xsl:text>}</xsl:text>
	</xsl:when>
	<xsl:when test="$variable = 'reflected'">
		<xsl:value-of select="/concepts/metaobject[@name=$operand]/@reflects"/>
	</xsl:when>
	<xsl:otherwise><xsl:value-of select="$variable"/></xsl:otherwise>
	</xsl:choose>

	<xsl:call-template name="expand-variables">
		<xsl:with-param name="text" select="substring-after(substring-after($text, '$('), ')')"/>
		<xsl:with-param name="result" select="$result"/>
		<xsl:with-param name="operand" select="$operand"/>
	</xsl:call-template>

	</xsl:when>
	<xsl:otherwise><xsl:value-of select="$text"/></xsl:otherwise>
	</xsl:choose>
</xsl:template>

<xsl:template name="template-args-decl">
<xsl:text>template &lt;</xsl:text><xsl:for-each select="argument">
<xsl:variable name="arg_type" select="@type"/>
	<xsl:if test="position() != 1">, </xsl:if>
	<xsl:choose>
	<xsl:when test="/concepts/metaobject[@name=$arg_type]">
	<xsl:value-of select="$arg_type"/>
	<xsl:text> T</xsl:text><xsl:if test="last()!=1"><xsl:value-of select="position()"/></xsl:if>
	</xsl:when>
	<xsl:otherwise>
	<xsl:value-of select="@type"/><xsl:text> </xsl:text><xsl:value-of select="@name"/>
	</xsl:otherwise>
	</xsl:choose>
</xsl:for-each><xsl:text>&gt;</xsl:text>
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

<xsl:for-each select="/concepts/operation[argument[@type=$operation_mo]]">
<xsl:variable name="result" select="@result"/>

\subsubsection{\texttt{<xsl:value-of select="str:replace(@name, '_','\_')"/>}}

<xsl:call-template name="expand-variables">
	<xsl:with-param name="text" select="@brief"/>
	<xsl:with-param name="result" select="@result"/>
	<xsl:with-param name="operand" select="$metaobject"/>
</xsl:call-template>

\begin{minted}{cpp}
namespace meta {
\end{minted}
\begin{minted}[xleftmargin=1em,tabsize=4]{cpp}
<xsl:call-template name="template-args-decl"/>
struct <xsl:value-of select="@name"/>
	<xsl:choose>
	<xsl:when test="@result='BooleanConstant'">
	<xsl:text> : integral_constant&lt;bool, ...&gt; { };</xsl:text>
	</xsl:when>

	<xsl:when test="@result='IntegralConstant'">
	<xsl:text> : integral_constant&lt;</xsl:text>
	<xsl:value-of select="@integer"/>
	<xsl:text>, ...&gt; { };</xsl:text>
	</xsl:when>

	<xsl:when test="@result='StringConstant'">
	<xsl:text> : StringConstant { };</xsl:text>
	</xsl:when>

	<xsl:when test="@result='SourceLocation'">
	<xsl:text> : source_location { };</xsl:text>
	</xsl:when>

	<xsl:when test="@result='Pointer'">
{
	typedef conditional_t&lt;
		is_class_member_v&lt;T&gt; &amp;&amp; !is_static_v&lt;T&gt;,
		get_reflected_type_t&lt;get_type_t&lt;T&gt;&gt;
		get_reflected_type_t&lt;get_scope_t&lt;T&gt;&gt;::*,
		get_reflected_type_t&lt;get_type_t&lt;T&gt;&gt;*
	&gt; value_type;

	static const value_type value;<xsl:text/>
};
	</xsl:when>

	<xsl:otherwise>
{
	typedef /* generated by the compiler */ type;
};
	</xsl:otherwise>
	</xsl:choose>

<xsl:text>
</xsl:text>

<xsl:if test="/concepts/metaobject[@name=$result]">
<xsl:call-template name="template-args-decl"/>
<xsl:text>
using </xsl:text><xsl:value-of select="@name"/>_t = typename <xsl:value-of select="@name"/>
	<xsl:call-template name="template-args-list"/>
	<xsl:text>::type;</xsl:text>
<xsl:text>
</xsl:text>
</xsl:if>

<xsl:if test="@result!='Pointer' and @result!='SourceLocation' and not(/concepts/metaobject[@name=$result])">
<xsl:call-template name="template-args-decl"/>
<xsl:text>
constexpr auto </xsl:text><xsl:value-of select="@name"/>_v = <xsl:value-of select="@name"/>
	<xsl:call-template name="template-args-list"/>
	<xsl:text>::value;</xsl:text>
</xsl:if>


<xsl:if test="@result='Pointer'">
<xsl:call-template name="template-args-decl"/>
<xsl:text>
const auto </xsl:text><xsl:value-of select="@name"/>_v = <xsl:value-of select="@name"/>
	<xsl:call-template name="template-args-list"/>
	<xsl:text>::value;</xsl:text>
</xsl:if>
<xsl:text>
\end{minted}
\begin{minted}{cpp}
} // namespace meta
\end{minted}

</xsl:text>
<xsl:if test="/concepts/metaobject[@name=$result]">
Note that \texttt{<xsl:value-of select="str:replace(@name,'_','\_')"/>&lt;...&gt;::type}
must conform to the \meta{<xsl:value-of select="@result"/>} concept.
</xsl:if>

</xsl:for-each>
</xsl:template>


<xsl:template match="/concepts">
<xsl:call-template name="operations">
<xsl:with-param name="operation_mo" select="$metaobject"/>
</xsl:call-template>
</xsl:template>

</xsl:stylesheet>

