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

	edge [arrowsize=1.5]

	<!-- generic types -->
	node [style="filled",shape="box",fillcolor="#a0a0a0"]
<xsl:for-each select="baseobject[@kind='type']">
	<xsl:variable name="obj_name" select="@name"/>

	<xsl:if test="/concepts/operation[@result=$obj_name] or /concepts/operation/argument[@type=$obj_name]">
	<xsl:value-of select="@name"/>
	<xsl:if test="@label">[label="<xsl:value-of select="@label"/>"]</xsl:if>;
	</xsl:if>
</xsl:for-each>

	<!-- compile-time constant types -->
	node [style="filled",shape="box",fillcolor="#ffffa0"]
<xsl:for-each select="baseobject[@kind='const']">
	<xsl:variable name="obj_name" select="@name"/>

	<xsl:if test="/concepts/operation[@result=$obj_name] or /concepts/operation/argument[@type=$obj_name]">
	<xsl:value-of select="@name"/>
	<xsl:if test="@label">[label="<xsl:value-of select="@label"/>"]</xsl:if>;
	</xsl:if>
</xsl:for-each>

	<!-- metaobjects -->
	node [style="rounded,filled",shape="box",fillcolor="#a0ffa0"]
<xsl:for-each select="metaobject">
	<xsl:value-of select="@name"/>
	<xsl:text>[URL="concept-</xsl:text><xsl:value-of select="@name"/><xsl:text>.svg"</xsl:text>
	<xsl:if test="@abstract='true'">,fillcolor="#a0a0ff"</xsl:if>
	<xsl:if test="@label">,label="<xsl:value-of select="@label"/>"</xsl:if>];
</xsl:for-each>

	<!-- operations -->
	node [style="filled",shape="egg",fillcolor="#c0c0c0"]
<xsl:for-each select="operation">
	<xsl:value-of select="@name"/>[URL="operation-<xsl:value-of select="@name"/>.svg"];
</xsl:for-each>

	<!-- generalizations -->
	edge [style="solid"]
	edge [penwidth=1.0,color="#c0c0c0"]
	edge [dir="both",fillcolor="white",arrowtail="normal",arrowhead="none"]
<xsl:for-each select="*/generalization">
	<xsl:value-of select="@concept"/> -> <xsl:value-of select="../@name"/>
	<xsl:if test="@optional='true'">[style="dashed"]</xsl:if>;
</xsl:for-each>

	<!-- Node -> operation -->
	edge [penwidth=3,color="black"]
	edge [style="dashed"]
	edge [dir="forward",arrowhead="none"]
<xsl:for-each select="operation/argument">
	<xsl:value-of select="@type"/> -> <xsl:value-of select="../@name"/>;
</xsl:for-each>

	<!-- operations -> Result -->
	edge [dir="forward",arrowhead="vee",fillcolor="black"]
<xsl:for-each select="operation">
	<xsl:value-of select="@name"/> -> <xsl:choose>
		<xsl:when test="@result">
			<xsl:value-of select="@result"/>
		</xsl:when>
		<xsl:otherwise>BooleanConstant</xsl:otherwise>
	</xsl:choose>;
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

