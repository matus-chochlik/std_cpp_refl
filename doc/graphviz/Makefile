XSLTPROC ?= xsltproc
DOT ?= dot
NEATO ?= neato
REVISION ?= 0
MAX_REVISION ?= 1

sinclude tmp/concepts-$(REVISION).mk
sinclude tmp/traits-$(REVISION).mk
sinclude tmp/operations-$(REVISION).mk

DIAGRAMS = overview hierarchy traits operations \
	$(foreach C, $(CONCEPTS), concept-$(C)) \
	$(foreach T, $(TRAITS), trait-$(T)) \
	$(foreach O, $(OPERATIONS), operation-$(O))

all: diagrams
.PHONY: all

diagrams: $(foreach I, $(DIAGRAMS), ./out/$I-$(REVISION).svg)
.PHONY: diagrams

./out/%.svg: ./tmp/%.svg | out
	$(XSLTPROC) --output $@ ./dot-svg-fixup.xsl $^

./tmp/concept-%.svg: ./tmp/concept-%.dot | out
	$(NEATO) -Tsvg -o $@ $<

./tmp/trait-%.svg: ./tmp/trait-%.dot | out
	$(NEATO) -Tsvg -o $@ $<

./tmp/operation-%.svg: ./tmp/operation-%.dot | out
	$(NEATO) -Tsvg -o $@ $<

./tmp/%.svg: ./tmp/%.dot | out
	$(DOT) -Tsvg -o $@ $<


./tmp/%-$(REVISION).dot: ./%-dot.xsl ../concepts.xml
	$(XSLTPROC) --stringparam revision $(REVISION) --output $@ $^

./tmp/overview-$(REVISION).dot: ../concepts.xml diagram-dot.py Makefile | tmp
	./diagram-dot.py -R $(REVISION) -M $(MAX_REVISION) --output $@ --input $<

./tmp/hierarchy-$(REVISION).dot: ../concepts.xml diagram-dot.py Makefile | tmp
	./diagram-dot.py -R $(REVISION) -M $(MAX_REVISION) -go 0 -gt 0 --output $@ --input $<

./tmp/operations-$(REVISION).dot: ../concepts.xml diagram-dot.py Makefile | tmp
	./diagram-dot.py -R $(REVISION) -M $(MAX_REVISION) -go 1 -gt 0 --output $@ --input $<

./tmp/traits-$(REVISION).dot: ../concepts.xml diagram-dot.py Makefile | tmp
	./diagram-dot.py -R $(REVISION) -M $(MAX_REVISION) -go 0 -gt 1 --output $@ --input $<

./tmp/concept-%-$(REVISION).dot: ../concepts.xml diagram-dot.py Makefile | tmp
	./diagram-dot.py -R $(REVISION) -M $(MAX_REVISION) --metaobject $* --output $@ --input $<

./tmp/operation-%-$(REVISION).dot: ../concepts.xml diagram-dot.py Makefile | tmp
	./diagram-dot.py -R $(REVISION) -M $(MAX_REVISION) --operation $* --output $@ --input $<

./tmp/trait-%-$(REVISION).dot: ../concepts.xml diagram-dot.py Makefile | tmp
	./diagram-dot.py -R $(REVISION) -M $(MAX_REVISION) --trait $* --output $@ --input $<

./tmp/%-$(REVISION).mk: ./%-mk.xsl ../concepts.xml Makefile | tmp
	$(XSLTPROC) --stringparam revision $(REVISION) --output $@ $< ../concepts.xml

out tmp:
	mkdir -p $@

clean:
	rm -rf out tmp

.PHONY: clean
