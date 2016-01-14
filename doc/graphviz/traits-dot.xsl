<?xml version="1.0" encoding="utf8"?>
<xsl:stylesheet
	xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0"
	xmlns:str="http://exslt.org/strings"
	xmlns:exsl="http://exslt.org/common"
	extension-element-prefixes="str exsl"
>
<xsl:output method="text"/>

<xsl:template match="/concepts">
digraph Traits {
	rankdir=LR
	concentrate=true
	overlap=false
	sep=1.2
	ranksep=0.8
	clusterrank="local"
	fontName="Courier"
	maxiter=1000000

	node [penwidth=2]
	edge [penwidth=3]

<xsl:for-each select="metaobject">
	<xsl:variable name="mo_name" select="@name"/>
	<xsl:variable name="mo_pos" select="position()"/>
	subgraph cluster_<xsl:value-of select="@name"/> {
	penwidth=0
	node [style="rounded,filled",shape="box",fillcolor="#a0ffa0"]
	<xsl:value-of select="@name"/>
	<xsl:text>[URL="concept-</xsl:text><xsl:value-of select="@name"/><xsl:text>.svg"</xsl:text>
	<xsl:if test="@abstract='true'">,fillcolor="#a0a0ff"</xsl:if>
	<xsl:if test="@label">,label="<xsl:value-of select="@label"/>"</xsl:if>];

	node [style="filled",shape="egg",fillcolor="#c0c0c0"]
	edge [style="dashed",dir="forward",arrowhead="none"]
	<xsl:for-each select="/concepts/trait[@indicates=$mo_name]">
	<xsl:value-of select="@name"/>[URL="trait-<xsl:value-of select="@name"/>.svg"];
	<xsl:choose>
		<xsl:when test="($mo_pos mod 4) = 0">
			<xsl:value-of select="@name"/> -> <xsl:value-of select="@indicates"/>
		</xsl:when>
		<xsl:otherwise>
			<xsl:value-of select="@indicates"/> -> <xsl:value-of select="@name"/>
		</xsl:otherwise>
	</xsl:choose> [constraint="<xsl:value-of select="($mo_pos mod 2) = 0"/>"]
	</xsl:for-each>

	}
</xsl:for-each>

	edge [constraint="true"]
	edge [penwidth=0.3]
	edge [arrowsize=1.5]
	edge [style="solid",dir="both",fillcolor="white",arrowhead="none",arrowtail="normal"]

<xsl:for-each select="*/generalization">
	<xsl:value-of select="@concept"/> -> <xsl:value-of select="../@name"/>
	<xsl:if test="@optional='true'">[style="dashed"]</xsl:if>;
</xsl:for-each>

	edge [style="invisible",dir="forward",arrowhead="none"]

<xsl:for-each select="operation/argument">
	<xsl:variable name="arg" select="@type"/>
	<xsl:variable name="res" select="../@result"/>
	<xsl:if test="/concepts/metaobject[@name=$arg] and /concepts/metaobject[@name=$res]">
	<xsl:value-of select="$arg"/> -> <xsl:value-of select="$res"/>;
	</xsl:if>

</xsl:for-each>

<xsl:for-each select="metaobject">
	<xsl:variable name="this" select="@name"/>
	<xsl:for-each select="preceding-sibling::metaobject[1]">
	<xsl:value-of select="@name"/> -> <xsl:value-of select="$this"/>;
	</xsl:for-each>
</xsl:for-each>

}
</xsl:template>

</xsl:stylesheet>

