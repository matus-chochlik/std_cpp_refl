XSLTPROC ?= xsltproc
REVISION = 1

CONCEPTS = ../doc/concepts.xml
HTMLCS = style.htmlc \
	synopsis.htmlc concepts.htmlc traits.htmlc operations.htmlc

all: P0194R1.html

P0194R1.html: compile.xsl root.html $(HTMLCS) Makefile
	$(XSLTPROC) --html --nonet -o $@ compile.xsl root.html

%.htmlc: %-htmlc.xsl $(CONCEPTS) Makefile
	$(XSLTPROC) --stringparam revision $(REVISION) -o $@ $< $(CONCEPTS)

style.htmlc: style.css
	echo "<style>" > $@
	cat $< >> $@
	echo "</style>" >> $@

.INTERMEDIATE: $(HTMLCS)
