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
&lt;pre&gt;&lt;code&gt;
namespace std {

template &amp;lt;typename T&amp;gt; struct is_metaobject;

namespace meta {

// &lt;em&gt;metaobject traits&lt;/em&gt;
<xsl:for-each select="trait[@since_revision &lt;= $revision]">
<xsl:text>template &amp;lt;typename T&amp;gt; struct </xsl:text><xsl:value-of select="@name"/>;
</xsl:for-each>
// 
<xsl:for-each select="trait[@since_revision &lt;= $revision]">
<xsl:text>template &amp;lt;typename T&amp;gt;
  constexpr bool </xsl:text><xsl:value-of select="@name"/>_v = <xsl:value-of select="@name"/>::value;
</xsl:for-each>

} namespace meta
} namespace std
&lt;/code&gt;&lt;/pre&gt;
</xsl:template>

</xsl:stylesheet>

