sinclude common.mk
sinclude $(BLDDIR)/concepts-$(REVISION).mk
sinclude $(BLDDIR)/traits-$(REVISION).mk
sinclude $(BLDDIR)/operations-$(REVISION).mk

$(BLDDIR)/%-$(REVISION).mk: ./%-mk.xsl ../concepts-$(REVISION).xml Makefile | $(BLDDIR)
	$(XSLTPROC) --stringparam revision $(REVISION) --output $@ $< ../concepts-$(REVISION).xml

DIAGRAMS-$(REVISION) = overview hierarchy traits operations \
	$(foreach C, $(CONCEPTS-$(REVISION)), concept-$(C)) \
	$(foreach T, $(TRAITS-$(REVISION)), trait-$(T)) \
	$(foreach O, $(OPERATIONS-$(REVISION)), operation-$(O))


