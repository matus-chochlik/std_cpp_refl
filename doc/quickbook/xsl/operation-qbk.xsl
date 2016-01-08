<?xml version="1.0" encoding="utf8"?>
<xsl:stylesheet
	xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0"
	xmlns:str="http://exslt.org/strings"
	xmlns:exsl="http://exslt.org/common"
	extension-element-prefixes="str exsl"
>
<xsl:param name="operation" value=""/>
<xsl:output method="text"/>

<xsl:template match="/concepts">
[/ Copyright 2015 Matus Chochlik.                             ]
<xsl:for-each select="operation[@name=$operation]">

[section:<xsl:value-of select="@name"/><xsl:text> </xsl:text><xsl:value-of select="@name"/>]
[import o_<xsl:value-of select="@name"/>.hpp]

[meta_<xsl:value-of select="@name"/>]

[endsect]
</xsl:for-each>
</xsl:template>

</xsl:stylesheet>

