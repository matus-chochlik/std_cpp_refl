sinclude common.mk

DIAGDOTFLAGS = -RN $(REVISION_NODES) -R $(REVISION) -M $(MAX_REVISION)

svg-diagrams-$(REVISION): $(foreach I, $(DIAGRAMS-$(REVISION)), $(OUTDIR)/$I-$(REVISION).svg)
.PHONY: svg-diagrams-$(REVISION)

pdf-diagrams-$(REVISION): $(foreach I, $(DIAGRAMS-$(REVISION)), $(OUTDIR)/$I-$(REVISION).pdf)
.PHONY: pdf-diagrams-$(REVISION)

$(BLDDIR)/%-$(REVISION).dot: ./%-dot.xsl ../concepts-$(REVISION).xml
	$(XSLTPROC) --stringparam revision $(REVISION) --output $@ $^

$(BLDDIR)/overview-$(REVISION).dot: ../concepts-$(REVISION).xml diagram-dot.py Makefile | $(BLDDIR)
	./diagram-dot.py $(DIAGDOTFLAGS) --output $@ --input $<

$(BLDDIR)/hierarchy-$(REVISION).dot: ../concepts-$(REVISION).xml diagram-dot.py Makefile | $(BLDDIR)
	./diagram-dot.py $(DIAGDOTFLAGS) -go 0 -gt 0 --output $@ --input $<

$(BLDDIR)/operations-$(REVISION).dot: ../concepts-$(REVISION).xml diagram-dot.py Makefile | $(BLDDIR)
	./diagram-dot.py $(DIAGDOTFLAGS) -go 1 -gt 0 --output $@ --input $<

$(BLDDIR)/traits-$(REVISION).dot: ../concepts-$(REVISION).xml diagram-dot.py Makefile | $(BLDDIR)
	./diagram-dot.py $(DIAGDOTFLAGS) -go 0 -gt 1 --output $@ --input $<

$(BLDDIR)/concept-%-$(REVISION).dot: ../concepts-$(REVISION).xml diagram-dot.py Makefile | $(BLDDIR)
	./diagram-dot.py $(DIAGDOTFLAGS) --metaobject $* --output $@ --input $<

$(BLDDIR)/operation-%-$(REVISION).dot: ../concepts-$(REVISION).xml diagram-dot.py Makefile | $(BLDDIR)
	./diagram-dot.py $(DIAGDOTFLAGS) --operation $* --output $@ --input $<

$(BLDDIR)/trait-%-$(REVISION).dot: ../concepts-$(REVISION).xml diagram-dot.py Makefile | $(BLDDIR)
	./diagram-dot.py $(DIAGDOTFLAGS) --trait $* --output $@ --input $<
