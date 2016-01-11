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
	ranksep=0.4
	fontName="Sans"
	maxiter=1000000

	node [penwidth=2]

	<!-- metaobjects -->
	node [style="rounded,filled",shape="box",fillcolor="#a0ffa0"]
<xsl:for-each select="metaobject">
	<xsl:value-of select="@name"/>[URL="concept-<xsl:value-of select="@name"/>.svg"<xsl:if test="@label">,label="<xsl:value-of select="@label"/>"</xsl:if>];
</xsl:for-each>

	<!-- generalizations -->
	edge [style="solid"]
	edge [arrowsize=1.5]
	edge [penwidth=2]
	edge [dir="both",arrowtail="onormal",arrowhead="none"]
<xsl:for-each select="*/generalization">
	<xsl:value-of select="@concept"/> -> <xsl:value-of select="../@name"/>
	<xsl:if test="@optional='true'">[style="dashed"]</xsl:if>;
</xsl:for-each>

	edge [style="invisible",dir="forward",arrowhead="none"]

<xsl:for-each select="metaobject">
	<xsl:variable name="this" select="@name"/>
	<xsl:for-each select="preceding-sibling::metaobject[1]">
	<xsl:value-of select="@name"/> -> <xsl:value-of select="$this"/>;
	</xsl:for-each>
</xsl:for-each>

}
</xsl:template>

</xsl:stylesheet>

