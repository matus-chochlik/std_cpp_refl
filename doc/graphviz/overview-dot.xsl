<?xml version="1.0" encoding="utf8"?>
<xsl:stylesheet
	xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0"
	xmlns:str="http://exslt.org/strings"
	xmlns:exsl="http://exslt.org/common"
	extension-element-prefixes="str exsl"
>
<xsl:output method="text"/>

<xsl:template match="/concepts"><xsl:text>
digraph Reflection {
	overlap=false
	rankdir=BT
	ranksep=0.5
	fontName="Courier"
	maxiter=1000000

	<!-- generic types -->
	node [penwidth=1.8,style="filled",shape="box",fillcolor="#a0a0a0"]
</xsl:text>
<xsl:for-each select="baseobject[@kind='type']">
<xsl:text>	</xsl:text><xsl:value-of select="@name"/>
	<xsl:if test="@label">[label="<xsl:value-of select="@label"/>"]</xsl:if>
	<xsl:text>
</xsl:text>
</xsl:for-each>
<xsl:text>

	<!-- compile-time constant types -->
	node [penwidth=1.8,style="filled",shape="box",fillcolor="#ffffa0"]
</xsl:text>
<xsl:for-each select="baseobject[@kind='const']">
<xsl:text>	</xsl:text><xsl:value-of select="@name"/>
	<xsl:if test="@label">[label="<xsl:value-of select="@label"/>"]</xsl:if>
	<xsl:text>
</xsl:text>
</xsl:for-each>
<xsl:text>

	<!-- metaobjects -->
	node [penwidth=2,style="rounded,filled",shape="box",fillcolor="#a0ffa0"]
</xsl:text>
<xsl:for-each select="metaobject">
<xsl:text>	</xsl:text><xsl:value-of select="@name"/>
	<xsl:if test="@label">[label="<xsl:value-of select="@label"/>"]</xsl:if>
	<xsl:text>
</xsl:text>
</xsl:for-each>
<xsl:text>

	<!-- operations / traits -->
	node [penwidth=1,style="filled",shape="egg",fillcolor="#c0c0c0"]
</xsl:text>
<xsl:for-each select="trait|operation">
<xsl:text>	</xsl:text><xsl:value-of select="@name"/><xsl:text>
</xsl:text>
</xsl:for-each>
<xsl:text>

	<!-- generalizations -->
	edge [penwidth=2,dir="both",arrowsize=1.5,arrowtail="onormal",arrowhead="none"]
</xsl:text>
<xsl:for-each select="*/generalization">
<xsl:text>	</xsl:text><xsl:value-of select="@name"/><xsl:text> -> </xsl:text>
	<xsl:value-of select="../@name"/><xsl:text>
</xsl:text>
</xsl:for-each>
<xsl:text>

	<!-- Metaobject -> trait -->
	edge [penwidth=1,arrowhead="none",arrowtail="none",style="solid"]
</xsl:text>
<xsl:for-each select="trait">
<xsl:text>	Metaobject -> </xsl:text>
	<xsl:value-of select="@name"/><xsl:text>
</xsl:text>
</xsl:for-each>
<xsl:text>

	<!-- Node -> operation -->
</xsl:text>
<xsl:for-each select="operation/argument">
<xsl:text>	</xsl:text><xsl:value-of select="@type"/><xsl:text> -> </xsl:text>
	<xsl:value-of select="../@name"/><xsl:text>
</xsl:text>
</xsl:for-each>
<xsl:text>

	<!-- traits -> Result -->
	edge [penwidth=1,arrowhead="vee",style="dashed"]
</xsl:text>
<xsl:for-each select="trait|operation">
<xsl:text>	</xsl:text><xsl:value-of select="@name"/><xsl:text> -> </xsl:text>
	<xsl:choose>
		<xsl:when test="@result">
			<xsl:value-of select="@result"/>
		</xsl:when>
		<xsl:otherwise>BooleanConstant</xsl:otherwise>
	</xsl:choose><xsl:text>
</xsl:text>
</xsl:for-each>
<xsl:text>

	<!-- trait -> indicates -->
	edge [penwidth=1,arrowhead="none",style="dotted"]
</xsl:text>
<xsl:for-each select="trait[@indicates]">
<xsl:text>	</xsl:text><xsl:value-of select="@name"/><xsl:text> -> </xsl:text>
	<xsl:value-of select="@indicates"/><xsl:text>
</xsl:text>
</xsl:for-each>
<xsl:text>

	<!-- trait ordering -->
	edge [style="invisible"]
</xsl:text>
<xsl:for-each select="*/generalization">
	<xsl:variable name="base" select="@name"/>
	<xsl:variable name="derived" select="../@name"/>
	<xsl:if test="/concepts/trait[@indicates=$base] and /concepts/trait[@indicates=$derived]">
<xsl:text>	</xsl:text><xsl:value-of select="/concepts/trait[@indicates=$derived]/@name"/><xsl:text> -> </xsl:text>
	<xsl:value-of select="/concepts/trait[@indicates=$base]/@name"/><xsl:text>
</xsl:text>
	</xsl:if>
</xsl:for-each>
<xsl:text>
}
</xsl:text>
</xsl:template>

</xsl:stylesheet>

