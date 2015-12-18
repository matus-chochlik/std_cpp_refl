<?xml version="1.0" encoding="utf8"?>
<xsl:stylesheet
	xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0"
	xmlns:str="http://exslt.org/strings"
	xmlns:exsl="http://exslt.org/common"
	extension-element-prefixes="str exsl"
>
<xsl:param name="trait"/>
<xsl:output method="text"/>

<xsl:template name="process-specializations">
	<xsl:param name="parent"/>

	<xsl:for-each select="/concepts/metaobject[generalization/@name=$parent]">
		<xsl:value-of select="@name"/>[URL="concept-<xsl:value-of select="@name"/>.svg"<xsl:if test="@label">,label="<xsl:value-of select="@label"/>"</xsl:if>];

		edge [style="solid",dir="both",arrowtail="onormal",arrowhead="none"]
		<xsl:value-of select="$parent"/> -> <xsl:value-of select="@name"/>
		<xsl:if test="generalization[@name=$parent]/@optional='true'"> [style="dashed"]</xsl:if>;
		<xsl:if test="preceding-sibling::metaobject[generalization/@name=$parent]">
		edge [style="invisible",dir="forward"]
		<xsl:value-of select="preceding-sibling::metaobject[generalization/@name=$parent][1]/@name"/> -> <xsl:value-of select="@name"/>;
		</xsl:if>

		<xsl:call-template name="process-specializations">
			<xsl:with-param name="parent" select="@name"/>
		</xsl:call-template>
	</xsl:for-each>
</xsl:template>

<xsl:template match="/concepts">
digraph <xsl:value-of select="$trait"/> {
	overlap=false
	rankdir=BT
	ranksep=0.4
	fontName="Sans"
	maxiter=1000000

	node [penwidth=2]

	node [style="filled",shape="egg",fillcolor="#c0c0c0"]
	<!-- the trait -->
<xsl:for-each select="trait[@name=$trait]">
	<xsl:value-of select="@name"/>[URL="traits.svg"];
</xsl:for-each>

<xsl:variable name="mo_name" select="trait[@name=$trait]/@indicates"/>

	edge [arrowsize=1.5]
	edge [penwidth=2]
	edge [style="dotted",arrowhead="none"]
	node [style="rounded,filled",shape="box",fillcolor="#90cc90"]
	<!-- the metaobject -->
<xsl:for-each select="metaobject[@name=$mo_name]">
	<xsl:value-of select="@name"/>[URL="concept-<xsl:value-of select="@name"/>.svg"<xsl:if test="@label">,label="<xsl:value-of select="@label"/>"</xsl:if>];
	<xsl:value-of select="$trait"/> -> <xsl:value-of select="@name"/>;
</xsl:for-each>

	<!-- metaobject's specializations -->
	node [style="rounded,filled",shape="box",fillcolor="#c0ffc0"]

	<xsl:call-template name="process-specializations">
		<xsl:with-param name="parent" select="$mo_name"/>
	</xsl:call-template>
}
</xsl:template>

</xsl:stylesheet>

