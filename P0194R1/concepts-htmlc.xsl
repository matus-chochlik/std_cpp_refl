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
<xsl:text>&lt;tr&gt;
&lt;th&gt;Concept&lt;/th&gt;
&lt;th&gt;Requirements&lt;/th&gt;
&lt;th&gt;Optional restrictions&lt;/th&gt;
&lt;th&gt;Description&lt;/th&gt;
&lt;/tr&gt;
</xsl:text>

<xsl:for-each select="/concepts/metaobject[@since_revision &lt;= $revision]">

&lt;tr&gt;&lt;td&gt;
&lt;pre&gt;&lt;code&gt;
<xsl:text>template &amp;lt;typename T&gt;</xsl:text>
concept bool <xsl:value-of select="@name"/>;
<xsl:text>&lt;/code&gt;&lt;/pre&gt;</xsl:text>
<xsl:text>&lt;/td&gt;&lt;td&gt;</xsl:text>
	<xsl:for-each select="generalization[not(@optional='true')]">
		<xsl:text>&lt;code&gt;</xsl:text>
		<xsl:value-of select="@concept"/><xsl:text>&amp;lt;T&amp;gt;</xsl:text>
		<xsl:text>&lt;/code&gt;&lt;br/&gt;</xsl:text>
	</xsl:for-each>
	<xsl:for-each select="not_a">
		<xsl:text>&lt;code&gt;not(</xsl:text>
		<xsl:value-of select="@concept"/><xsl:text>&amp;lt;T&amp;gt;</xsl:text>
		<xsl:text>)&lt;/code&gt;&lt;br/&gt;</xsl:text>
	</xsl:for-each>
	<xsl:for-each select="constraint">
		<xsl:if test="@operation and @trait">
			<xsl:variable name="trait" select="@trait"/>
			<xsl:text>&lt;code&gt;</xsl:text>
			<xsl:value-of select="/concepts/trait[@name=$trait]/@indicates"/><xsl:text>&amp;lt;</xsl:text>
			<xsl:value-of select="@operation"/><xsl:text>_m&amp;lt;T&amp;gt;&amp;gt;</xsl:text>
			<xsl:text>&lt;/code&gt;&lt;br/&gt;</xsl:text>
		</xsl:if>
	</xsl:for-each>
	<xsl:if test="@name='Object'">&lt;code&gt;is_metaobject_v&amp;lt;T&amp;gt;&lt;/code&gt;&lt;br/&gt;</xsl:if>
<xsl:text>&lt;/td&gt;&lt;td&gt;</xsl:text>
	<xsl:for-each select="generalization[@optional='true']">
		<xsl:text>&lt;code&gt;</xsl:text>
		<xsl:value-of select="@concept"/><xsl:text>&amp;lt;T&amp;gt;</xsl:text>
		<xsl:text>&lt;/code&gt;&lt;br/&gt;</xsl:text>
	</xsl:for-each>
<xsl:text>&lt;/td&gt;&lt;td&gt;</xsl:text>
<xsl:choose>
	<xsl:when test="@is_a">
		<xsl:text>&lt;p&gt;&lt;code&gt;meta::</xsl:text>
		<xsl:value-of select="@name"/>&lt;/code&gt; is <xsl:value-of select="@is_a"/>.
		<xsl:text>&lt;/p&gt;</xsl:text>
	</xsl:when>
	<xsl:when test="@brief">
		<xsl:text>&lt;p&gt;&lt;code&gt;meta::</xsl:text>
		<xsl:value-of select="@name"/>&lt;/code&gt; <xsl:value-of select="@brief"/>.
		<xsl:text>&lt;/p&gt;</xsl:text>
	</xsl:when>
	<xsl:when test="@reflects">
		<xsl:text>&lt;p&gt;&lt;code&gt;meta::</xsl:text>
		<xsl:value-of select="@name"/>&lt;/code&gt; reflects <xsl:value-of select="@reflects"/>.
		<xsl:text>&lt;/p&gt;</xsl:text>
	</xsl:when>
</xsl:choose>
<xsl:text>&lt;/td&gt;&lt;/tr&gt;
</xsl:text>

</xsl:for-each>
<xsl:text>&lt;/table&gt;</xsl:text>
<xsl:text>&lt;/div&gt;</xsl:text>
</xsl:template>

</xsl:stylesheet>

