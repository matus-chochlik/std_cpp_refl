XSLTPROC ?= xsltproc
SED ?= sed
DOT ?= dot
NEATO ?= neato
INKSCAPE ?= inkscape

REVISION_NODES ?= True
MAX_REVISION ?= 2
REVISIONS = $(shell seq 1 $(MAX_REVISION))

ifneq ($(MAKECMDGOALS), clean)
$(foreach R,$(REVISIONS), $(eval sinclude ./tmp/entities-$(R).mk))
endif

all: ./out/index.html svg-diagrams
.PHONY: all

ifneq ($(MAKECMDGOALS), clean)
$(foreach R,$(REVISIONS), $(eval sinclude ./tmp/revision-$(R).mk))
endif

pdf-diagrams: $(foreach R,$(REVISIONS), pdf-diagrams-$(R))
.PHONY: pdf-diagrams

svg-diagrams: $(foreach R,$(REVISIONS), svg-diagrams-$(R))
.PHONY: svg-diagrams

./out/%.pdf: ./out/%.svg
	$(INKSCAPE) --export-pdf=$@ $<

./out/%.svg: ./tmp/%.svg | out
	$(XSLTPROC) --nonet --output $@ ./dot-svg-fixup.xsl $^

./out/index.html: index.html | out
	cp $< $@

./tmp/concept-%.svg: ./tmp/concept-%.dot | out
	$(NEATO) -Tsvg -o $@ $<

./tmp/trait-%.svg: ./tmp/trait-%.dot | out
	$(NEATO) -Tsvg -o $@ $<

./tmp/operation-%.svg: ./tmp/operation-%.dot | out
	$(NEATO) -Tsvg -o $@ $<

./tmp/%.svg: ./tmp/%.dot | out
	$(DOT) -Tsvg -o $@ $<

./tmp/entities-%.mk: entities.mk Makefile | tmp
	$(SED) "s/\$$(REVISION)/$*/g;" < $< > $@

./tmp/revision-%.mk: revision.mk Makefile | tmp
	$(SED) "s/\$$(REVISION)/$*/g;s/\$$(MAX_REVISION)/$(MAX_REVISION)/g;" < $< > $@

out tmp:
	mkdir -p $@

clean:
	rm -rf out tmp

clean-pdf:
	rm -f out/*.pdf

.PHONY: clean clean-pdf
