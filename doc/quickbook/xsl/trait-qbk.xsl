<?xml version="1.0" encoding="utf8"?>
<xsl:stylesheet
	xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0"
	xmlns:str="http://exslt.org/strings"
	xmlns:exsl="http://exslt.org/common"
	extension-element-prefixes="str exsl"
>
<xsl:param name="trait" value=""/>
<xsl:output method="text"/>

<xsl:template match="/concepts">
[/ Copyright 2015 Matus Chochlik.                             ]
<xsl:for-each select="trait[@name=$trait]">

[section:<xsl:value-of select="@name"/><xsl:text> </xsl:text><xsl:value-of select="@name"/>]
[import t_<xsl:value-of select="@name"/>.hpp]

The [^<xsl:value-of select="@name"/><xsl:text>] trait indicates that</xsl:text>
the tested metaobject is a [concept <xsl:value-of select="@indicates"/>].

[meta_<xsl:value-of select="@name"/>]

[endsect]
</xsl:for-each>
</xsl:template>

</xsl:stylesheet>

