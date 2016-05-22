<?xml version="1.0" encoding="utf8"?>
<xsl:stylesheet
	xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0"
	xmlns:str="http://exslt.org/strings"
	xmlns:exsl="http://exslt.org/common"
	extension-element-prefixes="str exsl"
>
<xsl:output method="xml"/>

<xsl:template match="*">
<xsl:choose>
	<xsl:when test="name(.)='object' and @class='htmlc'">
		<xsl:copy-of select="document(@data)"/>
	</xsl:when>
	<xsl:when test="name(.)='link' and @rel='stylesheet'">
		<xsl:variable
			name="href"
			select="concat(substring-before(@href,'.css'),'.htmlc')"
		/>
		<xsl:copy-of select="document($href)"/>
	</xsl:when>
	<xsl:otherwise>
	<xsl:copy>
		<xsl:copy-of select="@*"/>
		<xsl:apply-templates/>
	</xsl:copy>
	</xsl:otherwise>
</xsl:choose>
</xsl:template>

</xsl:stylesheet>

