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
[/ Copyright 2015 Matus Chochlik.                             ]
<xsl:for-each select="metaobject[@name=$metaobject]">

[section:<xsl:value-of select="@name"/><xsl:text> </xsl:text><xsl:value-of select="@name"/>]
[import <xsl:value-of select="@name"/>.hpp]

[concept <xsl:value-of select="@name"/><xsl:text>] is </xsl:text>

<xsl:for-each select="generalization">
	<xsl:if test="position() != 1">
	<xsl:choose>
	<xsl:when test="position() != last()">, </xsl:when>
	<xsl:otherwise> and </xsl:otherwise>
	</xsl:choose>
	<xsl:if test="@optional='true'">possibly</xsl:if>
	</xsl:if>
	<xsl:text> a </xsl:text>
	<xsl:text>__</xsl:text><xsl:value-of select="@name"/>
</xsl:for-each>

<xsl:choose>
<xsl:when test="@is_a"><xsl:text> </xsl:text><xsl:value-of select="@is_a"/>.</xsl:when>
<xsl:when test="@reflects"> reflecting <xsl:value-of select="@reflects"/>.</xsl:when>
</xsl:choose>

[reflexpr_<xsl:value-of select="@name"/>]

[endsect]
</xsl:for-each>
</xsl:template>

</xsl:stylesheet>

