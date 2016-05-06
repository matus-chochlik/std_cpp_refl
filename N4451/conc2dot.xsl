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
	bgcolor="white"
	style="filled"
	ratio=1.4141
	sep=-0.1
	overlap=false
	splines="curved"
	fontName="Courier"
	maxiter=1000000


	<xsl:for-each select="concept">
	<xsl:value-of select="@name"/> [label=&lt;
	&lt;TABLE BORDER="2" CELLBORDER="0" CELLSPACING="0" CELLPADDING="4" BGCOLOR="WHITE"&gt;
	&lt;TR&gt;&lt;TD BGCOLOR="<xsl:choose><xsl:when test="@future='true'">WHEAT</xsl:when><xsl:otherwise>ORANGE</xsl:otherwise></xsl:choose>"&gt;&lt;B&gt;&lt;I&gt;<xsl:value-of select="@name"/>&lt;/I&gt;&lt;/B&gt;&lt;/TD&gt;&lt;/TR&gt;
	&lt;HR/&gt;

	<xsl:for-each select="returns">
	<xsl:choose>
	<xsl:when test="self">
	&lt;TR&gt;&lt;TD ALIGN="LEFT"&gt;type: <xsl:value-of select="../@name"/>&lt;/TD&gt;&lt;/TR&gt;
	</xsl:when>
	</xsl:choose>
	</xsl:for-each>

	<xsl:for-each select="data">
	&lt;TR&gt;&lt;TD ALIGN="LEFT"&gt;<xsl:value-of select="@name"/>: <xsl:value-of select="@type"/>&lt;/TD&gt;&lt;/TR&gt;
	</xsl:for-each>

	&lt;TR&gt;&lt;TD&gt;&lt;/TD&gt;&lt;/TR&gt;
	&lt;HR/&gt;

	<xsl:for-each select="trait">
	&lt;TR&gt;&lt;TD ALIGN="LEFT"&gt;<xsl:value-of select="@name"/>&#9001;X&#9002;: &#8594; <xsl:value-of select="@result"/>&lt;/TD&gt;&lt;/TR&gt;
	</xsl:for-each>

	<xsl:for-each select="mfunc|afunc">
	<xsl:variable name="res_typ" select="@result"/>
	<xsl:choose>
	<xsl:when test="/reflection/concept[@name=$res_typ]">
	&lt;TR&gt;&lt;TD PORT="<xsl:value-of select="@name"/>" ALIGN="LEFT"&gt;<xsl:value-of select="@name"/>&#9001;X&#9002;:&lt;/TD&gt;&lt;/TR&gt;
	</xsl:when>
	<xsl:otherwise>
	&lt;TR&gt;&lt;TD ALIGN="LEFT"&gt;<xsl:value-of select="@name"/>&#9001;X&#9002;: <xsl:value-of select="@result"/>&lt;/TD&gt;&lt;/TR&gt;
	</xsl:otherwise>
	</xsl:choose>
	</xsl:for-each>


	&lt;TR&gt;&lt;TD&gt;&lt;/TD&gt;&lt;/TR&gt;
	&lt;/TABLE&gt;
	&gt;,shape="none"]

	</xsl:for-each>

	<xsl:for-each select="concept">
	<xsl:for-each select="is_a">
	<xsl:variable name="pw"><xsl:choose><xsl:when test="@base='MetaNamedScoped'">1.5</xsl:when><xsl:otherwise>3</xsl:otherwise></xsl:choose></xsl:variable>
	<xsl:value-of select="../@name"/> -&gt; <xsl:value-of select="@base"/> [penwidth="<xsl:value-of select="$pw"/>",arrowhead="onormal"]
	</xsl:for-each>

	<xsl:for-each select="can_be">
	<xsl:variable name="pw"><xsl:choose><xsl:when test="@base='MetaNamedScoped'">1.5</xsl:when><xsl:otherwise>3</xsl:otherwise></xsl:choose></xsl:variable>
	<xsl:value-of select="../@name"/> -&gt; <xsl:value-of select="@base"/> [penwidth="<xsl:value-of select="$pw"/>",arrowhead="onormal",style="dashed",constraint=false]
	</xsl:for-each>

	<xsl:for-each select="either">
	<xsl:variable name="temp">_<xsl:value-of select="../@name"/>_base_<xsl:value-of select="position()"/></xsl:variable>
	<xsl:value-of select="$temp"/> [label="",penwidth="3",shape="point"]
	<xsl:value-of select="../@name"/> -&gt; <xsl:value-of select="$temp"/> [penwidth="3",arrowhead="none"]
	<xsl:for-each select="is_a">
	<xsl:value-of select="$temp"/> -&gt; <xsl:value-of select="@base"/> [penwidth="3",arrowhead="onormal"]
	</xsl:for-each>
	</xsl:for-each>

	<xsl:for-each select="mfunc">
	<xsl:variable name="res_typ" select="@result"/>
	<xsl:choose>
	<xsl:when test="/reflection/concept[@name=$res_typ]">
	<xsl:value-of select="../@name"/>:<xsl:value-of select="@name"/> -&gt; <xsl:value-of select="@result"/> [penwidth="0.7",style="dashed",constraint=false]
	</xsl:when>
	</xsl:choose>
	</xsl:for-each>

	<xsl:for-each select="afunc">
	<xsl:variable name="res_typ" select="@result"/>
	<xsl:choose>
	<xsl:when test="/reflection/concept[@name=$res_typ]">
	<xsl:value-of select="../@name"/>:<xsl:value-of select="@name"/> -&gt; <xsl:value-of select="@result"/> [penwidth="0.7",arrowhead="none",arrowtail="diamond",dir="both",style="dashed",constraint=false]
	</xsl:when>
	</xsl:choose>
	</xsl:for-each>

	</xsl:for-each>
}
</xsl:template>

</xsl:stylesheet>

