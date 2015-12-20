<?xml version="1.0" encoding="utf8"?>
<xsl:stylesheet
	xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0"
	xmlns:str="http://exslt.org/strings"
	xmlns:exsl="http://exslt.org/common"
	extension-element-prefixes="str exsl"
>
<xsl:param name="operation"/>
<xsl:output method="text"/>

<xsl:template name="list-specializations">
	<xsl:param name="parent"/>

	<xsl:for-each select="/concepts/metaobject[generalization/@name=$parent]">
		<xsl:text>(</xsl:text>
		<xsl:value-of select="@name"/>
		<xsl:text>)</xsl:text>

		<xsl:call-template name="list-specializations">
			<xsl:with-param name="parent" select="@name"/>
		</xsl:call-template>
	</xsl:for-each>
</xsl:template>

<xsl:template name="process-specializations">
	<xsl:param name="parent"/>
	<xsl:param name="done"/>

	<xsl:for-each select="/concepts/metaobject[generalization/@name=$parent]">
		<xsl:value-of select="@name"/>[URL="concept-<xsl:value-of select="@name"/>.svg"<xsl:if test="@label">,label="<xsl:value-of select="@label"/>"</xsl:if>];

		<xsl:if test="not(contains($done, concat('(',@name,')')))">
		edge [style="solid",dir="both",arrowtail="onormal",arrowhead="none"]
		<xsl:value-of select="$parent"/> -> <xsl:value-of select="@name"/>
		<xsl:if test="generalization[@name=$parent]/@optional='true'"> [style="dashed"]</xsl:if>;
		<xsl:if test="preceding-sibling::metaobject[generalization/@name=$parent]">
		edge [style="invisible",dir="forward"]
		<xsl:value-of select="preceding-sibling::metaobject[generalization/@name=$parent][1]/@name"/> -> <xsl:value-of select="@name"/>;
		</xsl:if>

		<xsl:call-template name="process-specializations">
			<xsl:with-param name="parent" select="@name"/>
			<xsl:with-param name="done">
				<xsl:value-of select="$done"/>
				<xsl:for-each select="preceding-sibling::metaobject[generalization/@name=$parent]">
				<xsl:call-template name="list-specializations">
					<xsl:with-param name="parent" select="@name"/>
				</xsl:call-template>
				</xsl:for-each>
			</xsl:with-param>
		</xsl:call-template>
		</xsl:if>
	</xsl:for-each>
</xsl:template>

<xsl:template match="/concepts">
digraph <xsl:value-of select="$operation"/> {
	overlap=false
	rankdir=BT
	ranksep=0.4
	fontName="Sans"
	maxiter=1000000

	node [penwidth=2]

	node [style="filled",shape="egg",fillcolor="#c0c0c0"]
	<!-- the trait -->
<xsl:for-each select="operation[@name=$operation]">
	<xsl:value-of select="@name"/>[URL="operations.svg"];
</xsl:for-each>

	edge [arrowsize=1.5]
	edge [penwidth=2]
	edge [style="dotted"]

<xsl:for-each select="operation[@name=$operation]">
	<xsl:variable name="obj_name" select="@result"/>

	node [penwidth=1.8,style="filled",shape="box",fillcolor="#a0a0a0"]
	<xsl:for-each select="/concepts/baseobject[@name=$obj_name]">
		<xsl:value-of select="@name"/>[URL="concept-<xsl:value-of select="@name"/>.svg"<xsl:if test="@label">,label="<xsl:value-of select="@label"/>"</xsl:if>];
		edge [dir="both",arrowhead="none",arrowtail="vee"]
		<xsl:value-of select="@name"/> -> <xsl:value-of select="$operation"/>;
	</xsl:for-each>

	node [style="rounded,filled",shape="box",fillcolor="#c0ffc0"]
	<xsl:for-each select="/concepts/metaobject[@name=$obj_name]">
		<xsl:value-of select="@name"/>[URL="concept-<xsl:value-of select="@name"/>.svg"<xsl:if test="@label">,label="<xsl:value-of select="@label"/>"</xsl:if>];
		edge [dir="both",arrowhead="none",arrowtail="vee"]
		<xsl:value-of select="@name"/> -> <xsl:value-of select="$operation"/>;
	</xsl:for-each>
</xsl:for-each>

	edge [dir="forward",arrowhead="none"]

<xsl:for-each select="operation[@name=$operation]/argument">
	<xsl:variable name="mo_name" select="@type"/>

	<!-- the metaobject -->
	<xsl:for-each select="/concepts/metaobject[@name=$mo_name]">
		<xsl:value-of select="@name"/>[URL="concept-<xsl:value-of select="@name"/>.svg"<xsl:if test="@label">,label="<xsl:value-of select="@label"/>"</xsl:if>];
		<xsl:value-of select="$operation"/> -> <xsl:value-of select="@name"/>;

		<!-- metaobject's specializations -->
		<xsl:call-template name="process-specializations">
			<xsl:with-param name="parent" select="$mo_name"/>
		</xsl:call-template>
	</xsl:for-each>
</xsl:for-each>
}
</xsl:template>

</xsl:stylesheet>

