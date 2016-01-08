<?xml version="1.0" encoding="utf8"?>
<xsl:stylesheet
	xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0"
	xmlns:str="http://exslt.org/strings"
	xmlns:exsl="http://exslt.org/common"
	extension-element-prefixes="str exsl"
>
<xsl:output method="text"/>

<xsl:template match="/concepts">
[/ Copyright 2015 Matus Chochlik.                             ]
<xsl:for-each select="operation">
[include o_<xsl:value-of select="@name"/>.qbk]
</xsl:for-each>

</xsl:template>

</xsl:stylesheet>

