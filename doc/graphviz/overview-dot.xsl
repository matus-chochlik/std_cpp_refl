<?xml version="1.0" encoding="utf8"?>
<xsl:stylesheet
	xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0"
	xmlns:str="http://exslt.org/strings"
	xmlns:exsl="http://exslt.org/common"
	extension-element-prefixes="str exsl"
>
<xsl:output method="text"/>

<xsl:template match="/concepts">
digraph Reflection {
	overlap=false
	rankdir=BT
	ranksep=0.5
	fontName="Courier"
	maxiter=1000000

	<!-- generic types -->
	node [penwidth=1.8,style="filled",shape="box",fillcolor="#a0a0a0"]
<xsl:for-each select="baseobject[@kind='type']">

	<xsl:value-of select="@name"/>
	<xsl:if test="@label">[label="<xsl:value-of select="@label"/>"]</xsl:if>;
</xsl:for-each>

	<!-- compile-time constant types -->
	node [penwidth=1.8,style="filled",shape="box",fillcolor="#ffffa0"]
<xsl:for-each select="baseobject[@kind='const']">
	<xsl:value-of select="@name"/>
	<xsl:if test="@label">[label="<xsl:value-of select="@label"/>"]</xsl:if>;
</xsl:for-each>

	<!-- metaobjects -->
	node [penwidth=2,style="rounded,filled",shape="box",fillcolor="#a0ffa0"]
<xsl:for-each select="metaobject">
	<xsl:value-of select="@name"/>
	<xsl:if test="@label">[label="<xsl:value-of select="@label"/>"]</xsl:if>;
</xsl:for-each>

	<!-- operations / traits -->
	node [penwidth=1,style="filled",shape="egg",fillcolor="#c0c0c0"]
<xsl:for-each select="trait|operation">
	<xsl:value-of select="@name"/>;
</xsl:for-each>

	<!-- generalizations -->
	edge [penwidth=2,dir="both",arrowsize=1.5,arrowtail="onormal",arrowhead="none"]
<xsl:for-each select="*/generalization">
	<xsl:value-of select="@name"/> -> <xsl:value-of select="../@name"/>;
</xsl:for-each>

	<!-- Metaobject -> trait -->
	edge [penwidth=1,arrowhead="none",arrowtail="none",style="solid"]
<xsl:for-each select="trait">
	Metaobject -> <xsl:value-of select="@name"/>;
</xsl:for-each>

	<!-- Node -> operation -->
<xsl:for-each select="operation/argument">
	<xsl:value-of select="@type"/> -> <xsl:value-of select="../@name"/>;
</xsl:for-each>

	<!-- traits -> Result -->
	edge [penwidth=1,arrowhead="vee",style="dashed"]
<xsl:for-each select="trait|operation">
	<xsl:value-of select="@name"/> -> <xsl:choose>
		<xsl:when test="@result">
			<xsl:value-of select="@result"/>
		</xsl:when>
		<xsl:otherwise>BooleanConstant</xsl:otherwise>
	</xsl:choose>;
</xsl:for-each>

	<!-- trait -> indicates -->
	edge [penwidth=1,arrowhead="none",style="dotted"]
<xsl:for-each select="trait[@indicates]">
	<xsl:value-of select="@name"/> -> <xsl:value-of select="@indicates"/>;
</xsl:for-each>

	<!-- trait ordering -->
	edge [style="invisible"]
<xsl:for-each select="*/generalization">
	<xsl:variable name="base" select="@name"/>
	<xsl:variable name="derived" select="../@name"/>
	<xsl:if test="/concepts/trait[@indicates=$base] and /concepts/trait[@indicates=$derived]">
	<xsl:value-of select="/concepts/trait[@indicates=$derived]/@name"/> -> <xsl:value-of select="/concepts/trait[@indicates=$base]/@name"/>;
	</xsl:if>
</xsl:for-each>
}
</xsl:template>

</xsl:stylesheet>

