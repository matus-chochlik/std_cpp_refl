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
<xsl:for-each select="/concepts/metaobject[@since_revision &lt;= $revision]">

	<xsl:variable name="metaobject" select="@name"/>
	<xsl:variable name="n" select="count(preceding-sibling::metaobject[@since_revision &lt;= $revision])"/>
	&lt;h5&gt;?.4.<xsl:value-of select="$n+1"/> &lt;code&gt;<xsl:value-of select="@name"/>&lt;/code&gt;&lt;/h5&gt;

	<xsl:if test="@is_a">
	<xsl:text>&lt;p&gt;&lt;code&gt;meta::</xsl:text>
	<xsl:value-of select="@name"/>&lt;/code&gt; is <xsl:value-of select="@is_a"/>.
	<xsl:text>&lt;/p&gt;</xsl:text>
	</xsl:if>

	TODO

	&lt;pre&gt;&lt;code&gt;
	<xsl:text>template &amp;lt;</xsl:text>
	<xsl:choose>
		<xsl:when test="@name='Object'">typename</xsl:when>
		<xsl:otherwise>Object</xsl:otherwise>
	</xsl:choose>
	<xsl:text> T&amp;gt; concept bool </xsl:text><xsl:value-of select="@name"/>
	<xsl:text> =
	  </xsl:text>
	<xsl:for-each select="generalization[not(@optional='true') and not(@concept='Object')]">
		<xsl:if test="position() != 1"> &amp;amp;&amp;amp; </xsl:if>
		<xsl:value-of select="@concept"/><xsl:text>&amp;lt;T&amp;gt;</xsl:text>
	</xsl:for-each>
	<xsl:variable name="has_gens" select="generalization[not(@optional='true') and not(@concept='Object')]"/>
	<xsl:for-each select="/concepts/trait[@indicates=$metaobject]">
		<xsl:if test="position() != 1 or $has_gens"> &amp;amp;&amp;amp; </xsl:if>
		<xsl:value-of select="@name"/><xsl:text>_v&amp;lt;T&amp;gt;</xsl:text>
	</xsl:for-each>
	<xsl:variable name="has_trts" select="/concepts/trait[@indicates=$metaobject]"/>
	<xsl:for-each select="constraint">
		<xsl:if test="position() != 1 or $has_gens or $has_trts"> &amp;amp;&amp;amp; </xsl:if>
		<xsl:if test="@operation and @trait">
			<xsl:variable name="trait" select="@trait"/>
			<xsl:value-of select="/concepts/trait[@name=$trait]/@indicates"/><xsl:text>&amp;lt;</xsl:text>
			<xsl:value-of select="@operation"/><xsl:text>_t&amp;lt;T&amp;gt;&amp;gt;</xsl:text>
		</xsl:if>
	</xsl:for-each>
	<xsl:if test="@name='Object'">is_metaobject_v&amp;lt;T&amp;gt;</xsl:if>;
	&lt;/code&gt;&lt;/pre&gt;

</xsl:for-each>
<xsl:text>&lt;/div&gt;</xsl:text>
</xsl:template>

</xsl:stylesheet>

