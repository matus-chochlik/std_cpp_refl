XSLTPROC ?= xsltproc
SED ?= sed
DOT ?= dot
NEATO ?= neato
MAX_REVISION ?= 1
REVISIONS = $(shell seq 0 $(MAX_REVISION))

ifneq ($(MAKECMDGOALS), clean)
$(foreach R,$(REVISIONS), $(eval sinclude ./tmp/entities-$(R).mk))
endif

all: ./out/index.html diagrams
.PHONY: all

ifneq ($(MAKECMDGOALS), clean)
$(foreach R,$(REVISIONS), $(eval sinclude ./tmp/revision-$(R).mk))
endif

diagrams: $(foreach R,$(REVISIONS), diagrams-$(R))
.PHONY: diagrams

./out/%.svg: ./tmp/%.svg | out
	$(XSLTPROC) --output $@ ./dot-svg-fixup.xsl $^

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

.PHONY: clean
