<?xml version="1.0" encoding="utf8"?>
<xsl:stylesheet
	xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0"
	xmlns:str="http://exslt.org/strings"
	xmlns:exsl="http://exslt.org/common"
	extension-element-prefixes="str exsl"
>
<xsl:param name="metaobject" value="Object"/>
<xsl:output method="text"/>

<xsl:template match="/concepts">
\subsubsection{Definition}

\begin{minted}{cpp}
namespace meta {
\end{minted}
\begin{minted}[xleftmargin=1em,tabsize=4,breakafter=&amp;]{cpp}
<xsl:for-each select="/concepts/metaobject[@name=$metaobject]">
template &lt;typename T&gt;
concept bool <xsl:value-of select="@name"/><xsl:text> = </xsl:text>
<xsl:for-each select="generalization[not(@optional='true')]">
	<xsl:if test="position() != 1"> &amp;&amp; </xsl:if>
	<xsl:value-of select="@concept"/><xsl:text>&lt;T&gt;</xsl:text>
</xsl:for-each>
<xsl:variable name="has_gens" select="generalization[not(@optional='true')]"/>
<xsl:for-each select="/concepts/trait[@indicates=$metaobject]">
	<xsl:if test="position() != 1 or $has_gens"> &amp;&amp; </xsl:if>
	<xsl:value-of select="@name"/><xsl:text>_v&lt;T&gt;</xsl:text>
</xsl:for-each>
<xsl:variable name="has_trts" select="/concepts/trait[@indicates=$metaobject]"/>
<xsl:for-each select="constraint">
	<xsl:if test="position() != 1 or $has_gens or $has_trts"> &amp;&amp; </xsl:if>
	<xsl:if test="@operation and @trait">
		<xsl:value-of select="@trait"/><xsl:text>_v&lt;</xsl:text>
		<xsl:value-of select="@operation"/><xsl:text>_t&lt;T&gt;&gt;</xsl:text>
	</xsl:if>
</xsl:for-each>
<xsl:if test="@name='Object'">is_metaobject_v&lt;T&gt;</xsl:if>;
</xsl:for-each>
\end{minted}
\begin{minted}{cpp}
} // namespace meta
\end{minted}
</xsl:template>

</xsl:stylesheet>

