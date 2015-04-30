<?xml version="1.0" encoding="utf8"?>
<xsl:stylesheet
	xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0"
	xmlns:str="http://exslt.org/strings"
	xmlns:exsl="http://exslt.org/common"
	extension-element-prefixes="str exsl"
>
<xsl:output method="text"/>

<xsl:template match="/reflection">
digraph Reflection {
	mode="KK"
	ratio=0.7071
	sep=0.1
	overlap=false
	splines="curved"
	fontName="Courier"
	maxiter=1000000


	<xsl:for-each select="concept">
	<xsl:value-of select="@name"/> [label=&lt;
	&lt;TABLE BORDER="2" CELLBORDER="0" CELLSPACING="0" BGCOLOR="WHITE"&gt;
	&lt;TR&gt;&lt;TD&gt;&lt;B&gt;&lt;I&gt;<xsl:value-of select="@name"/>&lt;/I&gt;&lt;/B&gt;&lt;/TD&gt;&lt;/TR&gt;
	&lt;HR/&gt;
	&lt;TR&gt;&lt;TD&gt;&lt;/TD&gt;&lt;/TR&gt;
	&lt;HR/&gt;
	<xsl:for-each select="trait">
	&lt;TR&gt;&lt;TD ALIGN="LEFT"&gt;<xsl:value-of select="@name"/>&#9001;X&#9002;: &#8594; <xsl:value-of select="@result"/>&lt;/TD&gt;&lt;/TR&gt;
	</xsl:for-each>
	&lt;TR&gt;&lt;TD&gt;&lt;/TD&gt;&lt;/TR&gt;
	&lt;/TABLE&gt;
	&gt;,shape="none"]

	</xsl:for-each>

	<xsl:for-each select="concept">
	<xsl:for-each select="is_a">
	<xsl:value-of select="../@name"/> -&gt; <xsl:value-of select="@base"/> [penwidth="2",arrowhead="onormal"]
	</xsl:for-each>

	<xsl:for-each select="can_be">
	<xsl:value-of select="../@name"/> -&gt; <xsl:value-of select="@base"/> [penwidth="2",arrowhead="onormal",style="dashed",constraint=false]
	</xsl:for-each>

	<xsl:for-each select="either">
	<xsl:variable name="temp">_<xsl:value-of select="../@name"/>_base_<xsl:value-of select="position()"/></xsl:variable>
	<xsl:value-of select="$temp"/> [label="",penwidth="2",shape="point"]
	<xsl:value-of select="../@name"/> -&gt; <xsl:value-of select="$temp"/> [penwidth="2",arrowhead="none"]
	<xsl:for-each select="is_a">
	<xsl:value-of select="$temp"/> -&gt; <xsl:value-of select="@base"/> [penwidth="2",arrowhead="onormal"]
	</xsl:for-each>
	</xsl:for-each>

	</xsl:for-each>
}
</xsl:template>

</xsl:stylesheet>

