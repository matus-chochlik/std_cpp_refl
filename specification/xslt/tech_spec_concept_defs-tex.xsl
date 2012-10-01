<xsl:stylesheet
  xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0"
  xmlns:str="http://exslt.org/strings"
  xmlns:exsl="http://exslt.org/common"
  extension-element-prefixes="str exsl"
>
<xsl:strip-space elements="desc"/>

<xsl:output method="text"/>

<xsl:template name="nl">
<xsl:text>&#xA;</xsl:text>
</xsl:template>

<xsl:template match="*">
</xsl:template>

<xsl:template name="decorate-text">
  <xsl:param name="self"/>
  <xsl:param name="base"/>
  <xsl:param name="text"/>
  <xsl:choose>

    <!-- replace references to $(self) -->
    <xsl:when test="contains($text, '$(self)')">
      <xsl:call-template name="decorate-text">
        <xsl:with-param name="self" select="$self"/>
        <xsl:with-param name="base" select="$base"/>
        <xsl:with-param name="text" select="substring-before($text, '$(self)')"/>
      </xsl:call-template>
      <xsl:text>{\metaobject{</xsl:text>
      <xsl:value-of select="$self"/>
      <xsl:text>}}</xsl:text>
      <xsl:call-template name="decorate-text">
        <xsl:with-param name="self" select="$self"/>
        <xsl:with-param name="base" select="$base"/>
        <xsl:with-param name="text" select="substring-after($text, '$(self)')"/>
      </xsl:call-template>
    </xsl:when>

    <!-- replace references to $(base) -->
    <xsl:when test="contains($text, '$(base)')">
      <xsl:call-template name="decorate-text">
        <xsl:with-param name="self" select="$self"/>
        <xsl:with-param name="base" select="$base"/>
        <xsl:with-param name="text" select="substring-before($text, '$(base)')"/>
      </xsl:call-template>
      <xsl:text>{\metaobject{</xsl:text>
      <xsl:value-of select="$base"/>
      <xsl:text>}}</xsl:text>
      <xsl:call-template name="decorate-text">
        <xsl:with-param name="self" select="$self"/>
        <xsl:with-param name="base" select="$base"/>
        <xsl:with-param name="text" select="substring-after($text, '$(base)')"/>
      </xsl:call-template>
    </xsl:when>

    <!-- replace references to attribues/functions in $(()) -->
    <xsl:when test="contains($text, '$((')">
      <xsl:call-template name="decorate-text">
        <xsl:with-param name="self" select="$self"/>
        <xsl:with-param name="base" select="$base"/>
        <xsl:with-param name="text" select="substring-before($text, '$((')"/>
      </xsl:call-template>
      <xsl:text>\verb@</xsl:text>
      <xsl:value-of select="substring-before(substring-after($text, '$(('), '))')"/>
      <xsl:text>@</xsl:text>
      <xsl:call-template name="decorate-text">
        <xsl:with-param name="self" select="$self"/>
        <xsl:with-param name="base" select="$base"/>
        <xsl:with-param name="text" select="substring-after($text, '))')"/>
      </xsl:call-template>
    </xsl:when>

    <!-- replace references to other concepts in $() -->
    <xsl:when test="contains($text, '$(')">
      <xsl:call-template name="decorate-text">
        <xsl:with-param name="self" select="$self"/>
        <xsl:with-param name="base" select="$base"/>
        <xsl:with-param name="text" select="substring-before($text, '$(')"/>
      </xsl:call-template>
      <xsl:text>{\metaobject{</xsl:text>
      <xsl:value-of select="substring-before(substring-after($text, '$('), ')')"/>
      <xsl:text>}}</xsl:text>
      <xsl:call-template name="decorate-text">
        <xsl:with-param name="self" select="$self"/>
        <xsl:with-param name="base" select="$base"/>
        <xsl:with-param name="text" select="substring-after($text, ')')"/>
      </xsl:call-template>
    </xsl:when>

    <!-- replace text in @@...@@ -->
    <xsl:when test="contains($text, '@@')">
      <xsl:call-template name="decorate-text">
        <xsl:with-param name="self" select="$self"/>
        <xsl:with-param name="base" select="$base"/>
        <xsl:with-param name="text" select="substring-before($text, '@@')"/>
      </xsl:call-template>
      <xsl:text>\begin{minted}{cpp}</xsl:text>
      <xsl:value-of select="substring-before(substring-after($text, '@@'), '@@')"/>
      <xsl:text>\end{minted}</xsl:text>
      <xsl:call-template name="decorate-text">
        <xsl:with-param name="self" select="$self"/>
        <xsl:with-param name="base" select="$base"/>
        <xsl:with-param name="text" select="substring-after(substring-after($text, '@@'), '@@')"/>
      </xsl:call-template>
    </xsl:when>

    <!-- replace text in @...@ -->
    <xsl:when test="contains($text, '@')">
      <xsl:call-template name="decorate-text">
        <xsl:with-param name="self" select="$self"/>
        <xsl:with-param name="base" select="$base"/>
        <xsl:with-param name="text" select="substring-before($text, '@')"/>
      </xsl:call-template>
      <xsl:text>\verb@</xsl:text>
      <xsl:value-of select="substring-before(substring-after($text, '@'), '@')"/>
      <xsl:text>@</xsl:text>
      <xsl:call-template name="decorate-text">
        <xsl:with-param name="self" select="$self"/>
        <xsl:with-param name="base" select="$base"/>
        <xsl:with-param name="text" select="substring-after(substring-after($text, '@'), '@')"/>
      </xsl:call-template>
    </xsl:when>

    <xsl:otherwise>
      <xsl:value-of select="$text"/>
    </xsl:otherwise>
  </xsl:choose>
</xsl:template>

<xsl:template name="inheritance-graph">
  <xsl:param name="concept"/>

  <xsl:for-each select="graph_layout/concept">
    <xsl:text>\node [concept] (</xsl:text>
    <xsl:value-of select="@name"/>
    <xsl:text>)</xsl:text>
    <xsl:if test="rel">
      <xsl:text>[</xsl:text>
      <xsl:for-each select="rel">
        <xsl:value-of select="@pos"/>
        <xsl:text>=of </xsl:text>
        <xsl:value-of select="@name"/>
        <xsl:if test="position() != last()">
          <xsl:text>, </xsl:text>
        </xsl:if>
      </xsl:for-each>
      <xsl:text>]</xsl:text>
    </xsl:if>
    <xsl:text> {</xsl:text>
    <xsl:value-of select="@name"/>
    <xsl:text>}</xsl:text>
    <xsl:for-each select="rel">
      <xsl:call-template name="nl"/>
      <xsl:text>	edge [inheritance</xsl:text>
      <xsl:if test="@edge">
        <xsl:text>, </xsl:text><xsl:value-of select="@edge"/>
      </xsl:if>
      <xsl:if test="@optional='true'">
        <xsl:text>, dotted</xsl:text>
      </xsl:if>
      <xsl:text>] (</xsl:text>
      <xsl:value-of select="@name"/>
      <xsl:text>)</xsl:text>
    </xsl:for-each>
    <xsl:text>;</xsl:text>
    <xsl:call-template name="nl"/>
  </xsl:for-each>

</xsl:template>

<xsl:template match="/concepts">
  <xsl:for-each select="concept">
    <xsl:variable name="concept_name" select="@name"/>
    <xsl:variable name="concept_uid1" select="position() + count(ancestor::node()) + count(descendant::node())"/>
    <xsl:variable name="concept_uid2" select="($concept_uid1 * $concept_uid1) + count(parent::node()/following-sibling::node())"/>
    <xsl:text>\subsubsection{</xsl:text>
    <xsl:value-of select="@name"/>
    <xsl:if test="@parameter">
      <xsl:text> \{</xsl:text>
      <xsl:value-of select="@parameter"/>
      <xsl:text>\}</xsl:text>
    </xsl:if>
    <xsl:text>}</xsl:text>
    <xsl:call-template name="nl"/>

    <xsl:text>\label{concept-def-</xsl:text><xsl:value-of select="@name"/><xsl:text>}</xsl:text>
    <xsl:call-template name="nl"/>
    <xsl:call-template name="nl"/>

    <xsl:call-template name="decorate-text">
      <xsl:with-param name="self" select="@name"/>
      <xsl:with-param name="base" select="is_a[position()=1]/@concept"/>
      <xsl:with-param name="text">

        <!-- reflects -->
        <xsl:if test="reflects">
          <xsl:text>{\metaobject{</xsl:text><xsl:value-of select="@name"/><xsl:text>}} is a </xsl:text>
          <xsl:for-each select="is_a">
            <xsl:if test="position() != 1 and position() != last()"><xsl:text>, </xsl:text></xsl:if>
            <xsl:if test="position() != 1 and position()  = last()"><xsl:text> and </xsl:text></xsl:if>
            <xsl:text>{\metaobject{</xsl:text><xsl:value-of select="@concept"/><xsl:text>}}</xsl:text>
          </xsl:for-each>
          <xsl:if test="may_be">
            <xsl:choose>
              <xsl:when test="is_a">
                <xsl:text> and possibly a </xsl:text>
              </xsl:when>
              <xsl:otherwise>
                <xsl:text> either </xsl:text>
              </xsl:otherwise>
            </xsl:choose>
            <xsl:for-each select="may_be">
              <xsl:if test="position() != 1 and position() != last()"><xsl:text>, </xsl:text></xsl:if>
              <xsl:if test="position() != 1 and position()  = last()"><xsl:text> or </xsl:text></xsl:if>
              <xsl:text>{\metaobject{</xsl:text><xsl:value-of select="@concept"/><xsl:text>}}</xsl:text>
            </xsl:for-each>
          </xsl:if>
          <xsl:choose>
            <xsl:when test="$concept_uid1 mod 3 = 0">
              <xsl:text> which reflects </xsl:text>
            </xsl:when>
            <xsl:when test="$concept_uid1 mod 3 = 1">
              <xsl:text> that reflects </xsl:text>
            </xsl:when>
            <xsl:otherwise><xsl:text> reflecting </xsl:text></xsl:otherwise>
          </xsl:choose>
          <xsl:value-of select="reflects/text()"/>
        </xsl:if>
        <xsl:call-template name="nl"/>

        <!-- descriptions -->
        <xsl:if test="desc">
          <xsl:value-of select="desc/text()"/>
        </xsl:if>
      </xsl:with-param>
    </xsl:call-template>
    <xsl:call-template name="nl"/>
    <xsl:call-template name="nl"/>

    <xsl:text>\begin{tikzpicture}</xsl:text>
    <xsl:call-template name="nl"/>
    <xsl:if test="graph_layout">
      <xsl:call-template name="inheritance-graph">
        <xsl:with-param name="concept" select="$concept_name"/>
      </xsl:call-template>
    </xsl:if>
    <xsl:text>\end{tikzpicture}</xsl:text>
    <xsl:call-template name="nl"/>
    <xsl:call-template name="nl"/>

    <xsl:if test="
      trait|attribute|element|function|template|instance|range or
      /concepts/concept[@name='MetaobjectCategory']/instance[@indicates=$concept_name]
    ">
      <xsl:choose>
        <xsl:when test="@kind='tag'">
          <xsl:text>Instances of the {\metaobject{</xsl:text><xsl:value-of select="@name"/><xsl:text>} concept are listed below.</xsl:text>
        </xsl:when>
        <xsl:otherwise>
          <xsl:choose>
            <xsl:when test="$concept_uid2 mod 3 = 0">
              <xsl:text>{\metaobject{</xsl:text><xsl:value-of select="@name"/><xsl:text>}} has these requirements:</xsl:text>
            </xsl:when>
            <xsl:when test="$concept_uid2 mod 3 = 1">
              <xsl:text>Concrete metaobjects modelling {\metaobject{</xsl:text><xsl:value-of select="@name"/><xsl:text>}} must satisfy the following:</xsl:text>
            </xsl:when>
            <xsl:otherwise><xsl:text>This concept requires the following:</xsl:text></xsl:otherwise>
          </xsl:choose>
        </xsl:otherwise>
      </xsl:choose>
      <xsl:call-template name="nl"/>

      <xsl:text>\begin{itemize}</xsl:text>
      <xsl:call-template name="nl"/>

      <xsl:if test="/concepts/concept[@name='MetaobjectCategory']/instance[@indicates=$concept_name]">
        <xsl:text>\item The value of the {\metaobject{MetaobjectCategory}} \verb@category@ attribute inherited from {\metaobject{Metaobject}} is \verb@</xsl:text>
        <xsl:value-of select="/concepts/concept[@name='MetaobjectCategory']/instance[@indicates=$concept_name]/@name"/>
        <xsl:text>@.</xsl:text>
        <xsl:call-template name="nl"/>
      </xsl:if>

      <xsl:for-each select="/concepts/concept[@name='Metaobject']/trait[@indicates=$concept_name]">
        <xsl:text>\item The \verb@</xsl:text>
        <xsl:value-of select="@name"/>
        <xsl:text>@ trait inherited from {\metaobject{Metaobject}} is true.</xsl:text>
      </xsl:for-each>

      <!-- format individual items -->
      <xsl:for-each select="trait|attribute|element|function|template|instance|range">
        <!-- the bullet and kind -->
        <xsl:text>\item {\em </xsl:text>
        <xsl:value-of select="name(.)"/>
        <xsl:if test="enabled_if|disabled_if">
          <xsl:text> (conditional)</xsl:text>
        </xsl:if>
        <xsl:text>:} </xsl:text>

        <!-- the synopsis -->
        <xsl:choose>
          <xsl:when test="@concept">
            <xsl:text> {\metaobject{</xsl:text>
              <xsl:value-of select="@concept"/>
            <xsl:text>}}</xsl:text>
            <xsl:if test="@argument">
              <xsl:text> \{</xsl:text>
              <xsl:text>{\metaobject{</xsl:text>
                <xsl:value-of select="@argument"/>
              <xsl:text>}}</xsl:text>
              <xsl:text>\}</xsl:text>
            </xsl:if>
          </xsl:when>
          <xsl:when test="@constant">
            <xsl:text> \verb@</xsl:text>
              <xsl:value-of select="@constant"/>
            <xsl:text>@</xsl:text>
          </xsl:when>
          <xsl:when test="@placeholder">
            <xsl:text> \verb@</xsl:text>
              <xsl:value-of select="@placeholder"/>
            <xsl:text>@</xsl:text>
          </xsl:when>
          <xsl:when test="@unspecified_type">
            <xsl:text> {\em </xsl:text>
              <xsl:value-of select="@unspecified_type"/>
            <xsl:text>}</xsl:text>
          </xsl:when>
        </xsl:choose>
        <xsl:text> \verb@</xsl:text>
        <xsl:value-of select="@name"/>
        <xsl:if test="parameter|parameters">
          <xsl:text>(</xsl:text>
            <xsl:for-each select="parameter">
              <xsl:value-of select="@name"/>
              <xsl:if test="position() != last()">
                <xsl:text>, </xsl:text>
              </xsl:if>
            </xsl:for-each>
            <xsl:if test="parameters">@$\dots$\verb@</xsl:if>
          <xsl:text>)</xsl:text>
        </xsl:if>
        <xsl:text>@ -- </xsl:text>
        <!-- the definition -->
        <xsl:call-template name="decorate-text">
          <xsl:with-param name="self" select="parent::node()/@name"/>
          <xsl:with-param name="base" select="parent::node()/is_a[position()=1]/@concept"/>
          <xsl:with-param name="text">
            <xsl:if test="desc">
              <xsl:value-of select="desc/text()"/>
            </xsl:if>
            <xsl:if test="@indicates and name(.)='instance' and parent::node()/@kind='tag'">
              <xsl:text>Indicates that the tagged metaobject satisfies the </xsl:text>
              <xsl:text> {\metaobject{</xsl:text>
              <xsl:value-of select="@indicates"/>
              <xsl:text>}} concept</xsl:text>
              <xsl:if test="kind">
                <xsl:text> and is reflecting the </xsl:text>
                <xsl:text> @</xsl:text>
                <xsl:value-of select="@name"/>
                <xsl:text>@ </xsl:text>
                <xsl:for-each select="kind">
                  <xsl:if test="position() = last() and position() &gt; 1">
                    <xsl:text> or </xsl:text>
                  </xsl:if>
                  <xsl:text>{\em </xsl:text>
                  <xsl:value-of select="text()"/>
                  <xsl:text>}</xsl:text>
                </xsl:for-each>
                <xsl:text> specifier</xsl:text>
              </xsl:if>
              <xsl:text>.</xsl:text>
            </xsl:if>
            <xsl:if test="@indicates and name(.)='trait'">
              <xsl:text>Indicates that the examined metaobject satisfies the {\metaobject{</xsl:text>
              <xsl:value-of select="@indicates"/>
              <xsl:text>}} concept.</xsl:text>
            </xsl:if>
            <xsl:call-template name="nl"/>
            <xsl:if test="enabled_if">
              <xsl:text>This </xsl:text>
              <xsl:value-of select="name(.)"/>
              <xsl:text> is availabile only if the @</xsl:text>
              <xsl:value-of select="enabled_if/@trait"/>
              <xsl:text>@ trait is true for this $(self), i.e. when it also satisfies the {\metaobject{</xsl:text>
              <xsl:variable name="enable_if_trait" select="enabled_if/@trait"/>
              <xsl:value-of select="/concepts/concept[@name='Metaobject']/trait[@name=$enable_if_trait]/@indicates"/>
              <xsl:text>}} concept.</xsl:text>
            </xsl:if>
          </xsl:with-param>
        </xsl:call-template>
        <xsl:call-template name="nl"/>
        <xsl:if test="parameter">
          <xsl:text>\begin{itemize}</xsl:text>
            <xsl:for-each select="parameter">
              <xsl:text>\item </xsl:text>
              <xsl:value-of select="@name"/>
              <xsl:text>: </xsl:text>

              <xsl:call-template name="decorate-text">
                <xsl:with-param name="self" select="parent::node()/@name"/>
                <xsl:with-param name="base" select="parent::node()/is_a[position()=1]/@concept"/>
                <xsl:with-param name="text">
                  <xsl:value-of select="desc/text()"/>
                  <xsl:if test="@min and @max">
                    <xsl:text>Valid values for this argument are from the range $\{</xsl:text>
                    <xsl:value-of select="@min"/>
                    <xsl:text> \dots </xsl:text>
                    <xsl:value-of select="@max"/>
                    <xsl:text>\}$. For other arguments the result is undefined.</xsl:text>
                  </xsl:if>
                  <xsl:call-template name="nl"/>
                </xsl:with-param>
              </xsl:call-template>

            </xsl:for-each>

          <xsl:text>\end{itemize}</xsl:text>
          <xsl:call-template name="nl"/>
        </xsl:if>
        <xsl:call-template name="nl"/>
      </xsl:for-each>

      <xsl:text>\end{itemize}</xsl:text>
      <xsl:call-template name="nl"/>
    </xsl:if>

    <xsl:call-template name="nl"/>
    <xsl:call-template name="nl"/>
  </xsl:for-each>
</xsl:template>

</xsl:stylesheet>
