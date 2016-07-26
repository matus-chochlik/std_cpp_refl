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
<xsl:text>&lt;div&gt;</xsl:text>
<xsl:text>&lt;table&gt;
</xsl:text>
<xsl:text>&lt;tr&gt;&lt;th&gt;Template&lt;/th&gt;&lt;th&gt;Condition&lt;/th&gt;&lt;/tr&gt;
</xsl:text>

<xsl:for-each select="/concepts/trait[@since_revision &lt;= $revision]">

<xsl:text>&lt;tr&gt;</xsl:text>
<xsl:text>&lt;td&gt;&lt;code&gt;</xsl:text>
<xsl:text>template &amp;lt;Object T&amp;gt;&lt;br/&gt;
struct </xsl:text><xsl:value-of select="@name"/>;
<xsl:text>&lt;/code&gt;&lt;/td&gt;</xsl:text>
<xsl:text>&lt;td&gt;</xsl:text>
<xsl:text>&lt;code&gt;T&lt;/code&gt; is a model of &lt;code&gt;meta::</xsl:text>
<xsl:value-of select="@indicates"/><xsl:text>&lt;/code&gt;.</xsl:text>
<xsl:text>&lt;/td&gt;</xsl:text>
<xsl:text>&lt;/tr&gt;
</xsl:text>

</xsl:for-each>
<xsl:text>&lt;/table&gt;</xsl:text>
<xsl:text>&lt;/div&gt;</xsl:text>
</xsl:template>

</xsl:stylesheet>

