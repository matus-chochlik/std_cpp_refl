<?xml version="1.0" encoding="utf8"?>
<xsl:stylesheet
	xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0"
	xmlns:str="http://exslt.org/strings"
	xmlns:exsl="http://exslt.org/common"
	extension-element-prefixes="str exsl"
>
<xsl:param name="trait"/>
<xsl:output method="text"/>

<xsl:template match="/concepts">
\begin{minted}[tabsize=4]{cpp}
namespace meta {
<xsl:for-each select="trait[@name=$trait]">
template &lt;typename T&gt;
requires Metaobject&lt;T&gt;
struct <xsl:value-of select="@name"/>
{
	typedef bool value_type;
	static constexpr const bool value;
	typedef integral_constant&lt;bool, value&gt; type;

	operator value_type (void) const noexcept;
	value_type operator(void) const noexcept;
};

template &lt;typename T&gt;
using <xsl:value-of select="@name"/>_t = typename <xsl:value-of select="@name"/>&lt;T&gt;::type;

template &lt;typename T&gt;
constexpr bool <xsl:value-of select="@name"/>_v = <xsl:value-of select="@name"/>&lt;T&gt;::value;
</xsl:for-each>
} // namespace meta
\end{minted}
</xsl:template>

</xsl:stylesheet>

