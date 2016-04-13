<?xml version="1.0" encoding="utf8"?>
<xsl:stylesheet
	xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0"
	xmlns:str="http://exslt.org/strings"
	xmlns:exsl="http://exslt.org/common"
	extension-element-prefixes="str exsl"
>
<xsl:param name="revision"/>
<xsl:output method="text"/>

<xsl:template match="/concepts">
OPERATIONS-<xsl:value-of select="$revision"/> =<xsl:for-each select="operation[@from_revision &lt;= $revision]">
	<xsl:text> </xsl:text>
	<xsl:choose>
		<xsl:when test="@uname"><xsl:value-of select="@uname"/></xsl:when>
		<xsl:otherwise><xsl:value-of select="@name"/></xsl:otherwise>
	</xsl:choose>
</xsl:for-each>

</xsl:template>

</xsl:stylesheet>

