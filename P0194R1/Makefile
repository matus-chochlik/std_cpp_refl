XSLTPROC ?= xsltproc
REVISION = 1

HTMLCS = style.htmlc  synopsis.htmlc concepts.htmlc

all: P0194R1.html

P0194R1.html: compile.xsl root.html $(HTMLCS) Makefile
	$(XSLTPROC) --html --nonet -o $@ compile.xsl root.html

%.htmlc: %-htmlc.xsl concepts.xml Makefile
	$(XSLTPROC) --stringparam revision $(REVISION) -o $@ $< concepts.xml

style.htmlc: style.css
	echo "<style>" > $@
	cat $< >> $@
	echo "</style>" >> $@

.INTERMEDIATE: $(HTMLCS)
