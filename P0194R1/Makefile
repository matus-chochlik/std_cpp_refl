XSLTPROC ?= xsltproc
REVISION = 1

CONCEPTS = ../doc/concepts-$(REVISION).xml
GEN_HTMLCS = style.htmlc \
	synopsis.htmlc concepts.htmlc traits.htmlc operations.htmlc
PER_HTMLCS = introduction.htmlc \
	revisions.htmlc \
	discussion.htmlc \
	acks.htmlc \
	references.htmlc

all: P0194R1.html

P0194R1.html: compile.xsl root.html $(PER_HTMLCS) $(GEN_HTMLCS) Makefile
	$(XSLTPROC) --html --nonet -o $@ compile.xsl root.html

%.htmlc: %-htmlc.xsl $(CONCEPTS) Makefile
	$(XSLTPROC) --nonet --stringparam revision $(REVISION) -o $@ $< $(CONCEPTS)

style.htmlc: style.css
	echo "<style>" > $@
	cat $< >> $@
	echo "</style>" >> $@

.INTERMEDIATE: $(GEN_HTMLCS)
