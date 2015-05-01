<?xml version="1.0" encoding="utf8"?>
<xsl:stylesheet
	xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0"
	xmlns:str="http://exslt.org/strings"
	xmlns:exsl="http://exslt.org/common"
	extension-element-prefixes="str exsl"
>
<xsl:output method="text"/>
<xsl:strip-space elements="*"/>

<xsl:template match="/reflection">
	<xsl:value-of select="'#direction: right'"/><xsl:value-of select="'&#xA;'"/>

	<!-- entities -->
	<xsl:for-each select="concept">
	<xsl:value-of select="'['"/><xsl:value-of select="@name"/>
	<xsl:value-of select="'|'"/>
	<xsl:value-of select="'&#xA;'"/>

	<!-- returns-->
	<xsl:for-each select="returns">
	<xsl:choose>
	<xsl:when test="self">
	<xsl:value-of select="'type: '"/><xsl:value-of select="../@name"/><xsl:value-of select="'&#xA;'"/>
	</xsl:when>
	</xsl:choose>
	</xsl:for-each>

	<!-- data -->
	<xsl:for-each select="data">
	<xsl:value-of select="@name"/>: <xsl:value-of select="@type"/><xsl:value-of select="'&#xA;'"/>
	</xsl:for-each>

	<xsl:value-of select="'|'"/>
	<xsl:value-of select="'&#xA;'"/>

	<!-- trait -->
	<xsl:for-each select="trait">
	<xsl:value-of select="@name"/>&#9001;X&#9002;: &#8594; <xsl:value-of select="@result"/><xsl:value-of select="'&#xA;'"/>
	</xsl:for-each>

	<xsl:for-each select="mfunc|afunc">
	<xsl:value-of select="@name"/>&#9001;X&#9002;: &#8594;<xsl:value-of select="@result"/>
	<xsl:if test="name()='afunc'">&#8230;</xsl:if>
	<xsl:value-of select="'&#xA;'"/>
	</xsl:for-each>

	<xsl:value-of select="']'"/><xsl:value-of select="'&#xA;'"/>


	<!-- relationships -->
	</xsl:for-each>
	<xsl:for-each select="concept">

	<xsl:for-each select="is_a">
	<xsl:value-of select="'['"/><xsl:value-of select="../@name"/>
	<xsl:value-of select="'] '"/>
	<xsl:value-of select="@base"/>
	<xsl:value-of select="' -:&gt; ['"/>
	<xsl:value-of select="@base"/><xsl:value-of select="']&#xA;'"/>
	</xsl:for-each>
	<xsl:for-each select="can_be">
	<xsl:value-of select="'['"/><xsl:value-of select="../@name"/>
	<xsl:value-of select="'] '"/>
	<xsl:value-of select="@base"/>
	<xsl:value-of select="' &#x002D;-:&gt; ['"/>
	<xsl:value-of select="@base"/><xsl:value-of select="']&#xA;'"/>
	</xsl:for-each>

<!--
	<xsl:for-each select="either">
	<xsl:variable name="temp">_<xsl:value-of select="../@name"/>_base_<xsl:value-of select="position()"/></xsl:variable>
	<xsl:value-of select="'['"/>&lt;start&gt;<xsl:value-of select="$temp"/><xsl:value-of select="']&#xA;'"/>
	<xsl:value-of select="'['"/><xsl:value-of select="../@name"/>] -&gt; [<xsl:value-of select="$temp"/><xsl:value-of select="']&#xA;'"/>
	<xsl:for-each select="is_a">
	<xsl:value-of select="'['"/><xsl:value-of select="$temp"/>] -:&gt; [<xsl:value-of select="@base"/><xsl:value-of select="']&#xA;'"/>
	</xsl:for-each>
	</xsl:for-each>

	<xsl:for-each select="mfunc">
	<xsl:variable name="res_typ" select="@result"/>
	<xsl:choose>
	<xsl:when test="/reflection/concept[@name=$res_typ]">
	<xsl:value-of select="'['"/><xsl:value-of select="../@name"/>
	<xsl:value-of select="'] '"/>
	<xsl:value-of select="@name"/>
	<xsl:value-of select="' -&gt; ['"/>
	<xsl:value-of select="@result"/>
	<xsl:value-of select="']&#xA;'"/>
	</xsl:when>
	</xsl:choose>
	</xsl:for-each>

	<xsl:for-each select="afunc">
	<xsl:variable name="res_typ" select="@result"/>
	<xsl:choose>
	<xsl:when test="/reflection/concept[@name=$res_typ]">
	<xsl:value-of select="'['"/><xsl:value-of select="../@name"/>
	<xsl:value-of select="'] '"/>
	<xsl:value-of select="@name"/>
	<xsl:value-of select="' o-&gt; ['"/>
	<xsl:value-of select="@result"/>
	<xsl:value-of select="']&#xA;'"/>
	</xsl:when>
	</xsl:choose>
	</xsl:for-each>
-->


	</xsl:for-each>
</xsl:template>

</xsl:stylesheet>

