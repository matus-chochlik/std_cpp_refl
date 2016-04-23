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
CONCEPTS-<xsl:value-of select="$revision"/> =<xsl:for-each select="metaobject[@since_revision &lt;= $revision]">
	<xsl:text> </xsl:text><xsl:value-of select="@name"/>
</xsl:for-each>

</xsl:template>

</xsl:stylesheet>

