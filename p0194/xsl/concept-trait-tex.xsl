<?xml version="1.0" encoding="utf8"?>
<xsl:stylesheet
	xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0"
	xmlns:str="http://exslt.org/strings"
	xmlns:exsl="http://exslt.org/common"
	extension-element-prefixes="str exsl"
>
<xsl:param name="metaobject"/>
<xsl:output method="text"/>

<xsl:template match="/concepts">
<xsl:for-each select="trait[@indicates=$metaobject]">
\subsubsection{\texttt{<xsl:value-of select="str:replace(@name,'_','\_')"/>}}

The \texttt{<xsl:value-of select="@scope"/>::<xsl:value-of select="str:replace(@name,'_','\_')"/>}
trait indicates if the \meta{Declaration} passed as argument is a \meta{<xsl:value-of select="$metaobject"/>}.

\input{sections/t_<xsl:value-of select="@name"/>_cpp.tex}
</xsl:for-each>
</xsl:template>

</xsl:stylesheet>

