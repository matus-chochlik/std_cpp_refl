# the output documents
input_tex = current

XSLTPROC = xsltproc

include ../common.mk

./sections/c_%_def.tex: ./xsl/concept-def-tex.xsl ./concepts.xml
	$(XSLTPROC) --stringparam metaobject $* --output $@ $^
	git add $@

./sections/c_%_trait.tex: ./xsl/concept-trait-tex.xsl ./concepts.xml
	$(XSLTPROC) --stringparam metaobject $* --output $@ $^
	git add $@

./sections/c_%_opers.tex: ./xsl/concept-opers-tex.xsl ./concepts.xml
	$(XSLTPROC) --stringparam metaobject $* --output $@ $^
	git add $@

./sections/t_%_cpp.tex: ./xsl/trait-cpp-tex.xsl ./concepts.xml
	$(XSLTPROC) --stringparam trait $* --output $@ $^
	git add $@

