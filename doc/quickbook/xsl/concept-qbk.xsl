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
[import c_<xsl:value-of select="@name"/>.hpp]

[concept <xsl:value-of select="@name"/><xsl:text>] </xsl:text>

<xsl:choose>
<xsl:when test="@brief">
<xsl:value-of select="@brief"/>
</xsl:when>
<xsl:otherwise>
	<xsl:text>is </xsl:text>

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
</xsl:otherwise>
</xsl:choose>

[reflexpr_<xsl:value-of select="@name"/>_begin]
[heading Traits]
[reflexpr_<xsl:value-of select="@name"/>_inherited_traits]
[reflexpr_<xsl:value-of select="@name"/>_traits]
[heading Operations]
[reflexpr_<xsl:value-of select="@name"/>_inherited_operations]
[reflexpr_<xsl:value-of select="@name"/>_operations]
[reflexpr_<xsl:value-of select="@name"/>_end]

[endsect]
</xsl:for-each>
</xsl:template>

</xsl:stylesheet>

