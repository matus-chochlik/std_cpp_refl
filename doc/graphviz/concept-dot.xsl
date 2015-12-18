<?xml version="1.0" encoding="utf8"?>
<xsl:stylesheet
	xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0"
	xmlns:str="http://exslt.org/strings"
	xmlns:exsl="http://exslt.org/common"
	extension-element-prefixes="str exsl"
>
<xsl:param name="metaobject" value="Metaobject"/>
<xsl:output method="text"/>

<xsl:template match="/concepts">
digraph <xsl:value-of select="$metaobject"/> {
	overlap=false
	rankdir=BT
	ranksep=0.4
	fontName="Sans"
	maxiter=1000000

	node [penwidth=2]

	Overview [style="filled",shape="note",fillcolor="WHEAT",URL="overview.svg"];

	<!-- generic types -->
	node [style="filled",shape="box",fillcolor="#a0a0a0"]
<xsl:for-each select="baseobject[@kind='type']">
	<xsl:variable name="obj_name" select="@name"/>

	<xsl:if test="
		/concepts/operation[@result=$obj_name and argument[@type=$metaobject]] or
		/concepts/operation[@result=$metaobject and argument[@type=$obj_name]]
	">
	<xsl:value-of select="@name"/>
	<xsl:if test="@label">[label="<xsl:value-of select="@label"/>"]</xsl:if>;
	</xsl:if>
</xsl:for-each>

	<!-- compile-time constant types -->
	node [style="filled",shape="box",fillcolor="#ffffa0"]
<xsl:for-each select="baseobject[@kind='const']">
	<xsl:variable name="obj_name" select="@name"/>

	<xsl:if test="
		/concepts/operation[@result=$obj_name and argument[@type=$metaobject]] or
		/concepts/operation[@result=$metaobject and argument[@type=$obj_name]]
	">
	<xsl:value-of select="@name"/>
	<xsl:if test="@label">[label="<xsl:value-of select="@label"/>"]</xsl:if>;
	</xsl:if>
</xsl:for-each>

	edge [style="solid"]
	edge [arrowsize=1.5]
	edge [penwidth=2]

	<!-- the metaobject -->
	node [style="rounded,filled",shape="box",fillcolor="#90cc90"]
<xsl:for-each select="metaobject[@name=$metaobject]">
	<xsl:value-of select="@name"/>[URL="hierarchy.svg"<xsl:if test="@label">,label="<xsl:value-of select="@label"/>"</xsl:if>];
</xsl:for-each>

	<!-- metaobject's generalizations -->
	node [style="rounded,filled",shape="box",fillcolor="#c0ffc0"]
	edge [dir="both",arrowtail="onormal",arrowhead="none"]
<xsl:for-each select="metaobject[@name=$metaobject]/generalization">
	<xsl:variable name="gen_name" select="@name"/>
	<xsl:variable name="optional" select="@optional='true'"/>
	<xsl:for-each select="/concepts/metaobject[@name=$gen_name]">
		<xsl:value-of select="@name"/>[URL="concept-<xsl:value-of select="@name"/>.svg"<xsl:if test="@label">,label="<xsl:value-of select="@label"/>"</xsl:if>];
		<xsl:value-of select="@name"/> -> <xsl:value-of select="$metaobject"/>
		<xsl:if test="$optional">[style="dashed"]</xsl:if>;
	</xsl:for-each>
</xsl:for-each>

<xsl:for-each select="metaobject[@name=$metaobject]/generalization">
	<xsl:variable name="gen_name" select="@name"/>
	<xsl:for-each select="/concepts/metaobject[@name=$gen_name]">
		<xsl:if test="preceding-sibling::metaobject[generalization/@name=$gen_name]">
		edge [style="invisible",dir="forward"]
		<xsl:value-of select="preceding-sibling::metaobject[generalization/@name=$gen_name][1]/@name"/> -> <xsl:value-of select="@name"/>;
		</xsl:if>
	</xsl:for-each>
</xsl:for-each>

	<!-- metaobject's specializations -->
<xsl:for-each select="metaobject[generalization[@name=$metaobject]]">
	<xsl:value-of select="@name"/>[URL="concept-<xsl:value-of select="@name"/>.svg"<xsl:if test="@label">,label="<xsl:value-of select="@label"/>"</xsl:if>];
	<xsl:variable name="optional" select="generalization[@name=$metaobject]/@optional='true'"/>
	<xsl:value-of select="$metaobject"/> -> <xsl:value-of select="@name"/>
	<xsl:if test="$optional">[style="dashed"]</xsl:if>;
</xsl:for-each>

<xsl:for-each select="metaobject[generalization[@name=$metaobject]]">
		<xsl:if test="preceding-sibling::metaobject[generalization/@name=$metaobject]">
		edge [style="invisible",dir="forward"]
		<xsl:value-of select="preceding-sibling::metaobject[generalization/@name=$metaobject][1]/@name"/> -> <xsl:value-of select="@name"/>;
		</xsl:if>
</xsl:for-each>

	<!-- related metaobjects -->
<xsl:for-each select="operation[@result=$metaobject]/argument">
	<xsl:variable name="arg_name" select="@type"/>
	<xsl:for-each select="/concepts/metaobject[@name=$arg_name]">
		<xsl:value-of select="@name"/>[URL="./concept-<xsl:value-of select="@name"/>.svg"<xsl:if test="@label">,label="<xsl:value-of select="@label"/>"</xsl:if>];
	</xsl:for-each>
</xsl:for-each>

<xsl:for-each select="operation/argument[@type=$metaobject]">
	<xsl:variable name="res_name" select="../@result"/>
	<xsl:for-each select="/concepts/metaobject[@name=$res_name]">
		<xsl:value-of select="@name"/>
		<xsl:if test="@label">[label="<xsl:value-of select="@label"/>"]</xsl:if>;
	</xsl:for-each>
</xsl:for-each>


	edge [style="dotted",dir="forward"]
	node [style="filled",shape="egg",fillcolor="#c0c0c0"]
	<!-- traits -->
<xsl:for-each select="trait[@indicates=$metaobject]">
	<xsl:value-of select="@name"/> [URL="trait-<xsl:value-of select="@name"/>.svg"];
	<xsl:value-of select="@name"/> -> <xsl:value-of select="$metaobject"/>;
</xsl:for-each>

	<!-- operations -->
<xsl:for-each select="operation[@result=$metaobject or argument[@type=$metaobject]]">
	<xsl:value-of select="@name"/> [URL="operation-<xsl:value-of select="@name"/>.svg"];
</xsl:for-each>

	edge [style="dashed",dir="forward"]
	edge [arrowhead="vee"]

<xsl:for-each select="operation[@result=$metaobject]">
	<xsl:value-of select="@name"/> -> <xsl:value-of select="@result"/>;
</xsl:for-each>

<xsl:for-each select="operation[argument[@type=$metaobject]]">
	<xsl:variable name="op_name" select="@name"/>
	<xsl:value-of select="$op_name"/> -> <xsl:value-of select="@result"/>;
</xsl:for-each>

	edge [arrowhead="none"]

<xsl:for-each select="operation[@result=$metaobject]">
	<xsl:for-each select="argument">
		<xsl:value-of select="@type"/> -> <xsl:value-of select="../@name"/>;
	</xsl:for-each>
</xsl:for-each>

<xsl:for-each select="operation/argument[@type=$metaobject]">
	<xsl:value-of select="@type"/> -> <xsl:value-of select="../@name"/>;
</xsl:for-each>

<xsl:for-each select="operation[argument[@type=$metaobject]]">
	<xsl:for-each select="argument[@type != $metaobject]">
		<xsl:value-of select="@type"/> -> <xsl:value-of select="../@name"/>;
	</xsl:for-each>
</xsl:for-each>

}
</xsl:template>

</xsl:stylesheet>

