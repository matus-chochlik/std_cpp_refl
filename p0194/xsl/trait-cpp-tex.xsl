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
\begin{minted}{cpp}
namespace meta {
\end{minted}
\begin{minted}[xleftmargin=1em,tabsize=4]{cpp}
<xsl:for-each select="trait[@name=$trait]">
template &lt;Object T&gt;
struct <xsl:value-of select="@name"/> : integral_constant&lt;bool, ... &gt; { };
template &lt;typename T&gt;
constexpr bool <xsl:value-of select="@name"/>_v = <xsl:value-of select="@name"/>&lt;T&gt;::value;
</xsl:for-each>
\end{minted}
\begin{minted}{cpp}
} // namespace meta
\end{minted}
</xsl:template>

</xsl:stylesheet>

