XSLTPROC ?= xsltproc
REVISION = 0

all: P0194R1.html

P0194R1.html: compile.xsl root.html synopsis.htmlc Makefile
	$(XSLTPROC) --html --nonet -o $@ compile.xsl root.html

%.htmlc: %-htmlc.xsl concepts.xml Makefile
	$(XSLTPROC) --stringparam revision $(REVISION) -o $@ $< concepts.xml
