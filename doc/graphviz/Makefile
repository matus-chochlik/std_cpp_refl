sinclude common.mk

XSLTPROC ?= xsltproc
SED ?= sed
DOT ?= dot
NEATO ?= neato
INKSCAPE ?= inkscape

REVISION_NODES ?= False
MAX_REVISION ?= 4
MIN_REVISION ?= $(MAX_REVISION)
REVISIONS = $(shell seq $(MIN_REVISION) $(MAX_REVISION))

ifneq ($(MAKECMDGOALS), clean)
$(foreach R,$(REVISIONS), $(eval sinclude $(BLDDIR)/entities-$(R).mk))
endif

all: $(OUTDIR)/index.html $(OUTDIR)/overview.html svg-diagrams
.PHONY: all

ifneq ($(MAKECMDGOALS), clean)
$(foreach R,$(REVISIONS), $(eval sinclude $(BLDDIR)/revision-$(R).mk))
endif

pdf-diagrams: $(foreach R,$(REVISIONS), pdf-diagrams-$(R))
.PHONY: pdf-diagrams

svg-diagrams: $(foreach R,$(REVISIONS), svg-diagrams-$(R))
.PHONY: svg-diagrams

$(OUTDIR)/%.pdf: $(OUTDIR)/%.svg
	$(INKSCAPE) --export-pdf=$@ $<

$(OUTDIR)/%.svg: $(BLDDIR)/%.svg | $(OUTDIR)
	$(XSLTPROC) --nonet --output $@ ./dot-svg-fixup.xsl $^

$(OUTDIR)/%.html: %.html | $(OUTDIR)
	cp $< $@

$(BLDDIR)/concept-%.svg: $(BLDDIR)/concept-%.dot | $(OUTDIR)
	$(NEATO) -Tsvg -o $@ $<

$(BLDDIR)/trait-%.svg: $(BLDDIR)/trait-%.dot | $(OUTDIR)
	$(NEATO) -Tsvg -o $@ $<

$(BLDDIR)/operation-%.svg: $(BLDDIR)/operation-%.dot | $(OUTDIR)
	$(NEATO) -Tsvg -o $@ $<

$(BLDDIR)/%.svg: $(BLDDIR)/%.dot | $(OUTDIR)
	$(DOT) -Tsvg -o $@ $<

$(BLDDIR)/entities-%.mk: entities.mk Makefile | $(BLDDIR)
	$(SED) "s/\$$(REVISION)/$*/g;" < $< > $@

$(BLDDIR)/revision-%.mk: revision.mk Makefile | $(BLDDIR)
	$(SED) "s/\$$(REVISION)/$*/g;s/\$$(MAX_REVISION)/$(MAX_REVISION)/g;" < $< > $@

$(OUTDIR) $(BLDDIR):
	mkdir -p $@

clean:
	rm -rf $(OUTDIR) $(BLDDIR)

clean-pdf:
	rm -f $(OUTDIR)/*.pdf

.PHONY: clean clean-pdf
