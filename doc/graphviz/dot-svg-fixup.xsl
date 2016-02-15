<?xml version="1.0" ?>
<xsl:stylesheet
	version="1.0"
	xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
    	xmlns:svg="http://www.w3.org/2000/svg" xmlns="http://www.w3.org/2000/svg"
>

<xsl:output
	method="xml"
	indent="yes"
	doctype-public="-//W3C//DTD SVG 1.0//EN"
	doctype-system="http://www.w3.org/TR/2001/REC-SVG-20010904/DTD/svg10.dtd"
/>

<xsl:template match="@*|node()">
	<xsl:copy>
		<xsl:apply-templates select="@*|node()"/>
	</xsl:copy>
</xsl:template>

<xsl:template name="drop-shadow">
	<xsl:param name="ofs"></xsl:param>
	<xsl:if test="$ofs&gt;0">
		<xsl:element name="g">
			<xsl:attribute name="transform">
				translate(<xsl:value-of select="$ofs"/>,<xsl:value-of select="$ofs"/>)
			</xsl:attribute>
			<xsl:for-each select="svg:polygon|svg:g/svg:a/svg:polygon">
				<xsl:element name="polygon">
					<xsl:attribute name="fill">gray</xsl:attribute>
					<xsl:attribute name="fill-opacity">0.2</xsl:attribute>
					<xsl:attribute name="points"><xsl:value-of select="@points"/></xsl:attribute>
				</xsl:element>
			</xsl:for-each>
			<xsl:for-each select="svg:path|svg:g/svg:a/svg:path">
				<xsl:element name="path">
					<xsl:attribute name="fill">gray</xsl:attribute>
					<xsl:attribute name="fill-opacity">0.2</xsl:attribute>
					<xsl:attribute name="d"><xsl:value-of select="@d"/></xsl:attribute>
				</xsl:element>
			</xsl:for-each>
		</xsl:element>
		<xsl:call-template name="drop-shadow">
			<xsl:with-param name="ofs" select="$ofs -2"/>
		</xsl:call-template>
	</xsl:if>
</xsl:template>

<xsl:template match="svg:g[@class='node']">
	<xsl:copy>
		<xsl:apply-templates select="@*"/>
		<xsl:call-template name="drop-shadow">
			<xsl:with-param name="ofs">7</xsl:with-param>
		</xsl:call-template>
		<xsl:apply-templates select="node()"/>
	</xsl:copy>
</xsl:template>

<xsl:template match="svg:g[@class='graph']">
	<xsl:copy>
		<xsl:apply-templates select="@*"/>
		<xsl:apply-templates select="svg:g[@class ='edge']"/>
		<xsl:apply-templates select="svg:g[@class!='edge']"/>
	</xsl:copy>
</xsl:template>

<xsl:template match="svg:svg">
	<svg xmlns="http://www.w3.org/2000/svg">
		<xsl:apply-templates select="@*"/>
		<xsl:apply-templates select="node()"/>
	</svg>
</xsl:template>

</xsl:stylesheet>
