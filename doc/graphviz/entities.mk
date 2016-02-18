sinclude tmp/concepts-$(REVISION).mk
sinclude tmp/traits-$(REVISION).mk
sinclude tmp/operations-$(REVISION).mk

./tmp/%-$(REVISION).mk: ./%-mk.xsl ../concepts.xml Makefile | tmp
	$(XSLTPROC) --stringparam revision $(REVISION) --output $@ $< ../concepts.xml

DIAGRAMS-$(REVISION) = overview hierarchy traits operations \
	$(foreach C, $(CONCEPTS-$(REVISION)), concept-$(C)) \
	$(foreach T, $(TRAITS-$(REVISION)), trait-$(T)) \
	$(foreach O, $(OPERATIONS-$(REVISION)), operation-$(O))


