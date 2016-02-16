XSLTPROC = xsltproc
DOT = dot
NEATO = neato
REVISION = 0

sinclude tmp/concepts.mk
sinclude tmp/traits.mk
sinclude tmp/operations.mk

DIAGRAMS = overview hierarchy traits operations \
	$(foreach C, $(CONCEPTS), concept-$(C)) \
	$(foreach T, $(TRAITS), trait-$(T)) \
	$(foreach O, $(OPERATIONS), operation-$(O))

all: diagrams

diagrams: $(foreach I, $(DIAGRAMS), ./out/$I.svg)

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


./tmp/%.dot: ./%-dot.xsl ../concepts.xml | tmp
	$(XSLTPROC) --stringparam revision $(REVISION) --output $@ $^

./tmp/overview.dot: ../concepts.xml diagram-dot.py Makefile | tmp
	./diagram-dot.py -R $(REVISION) --output $@ --input $<

./tmp/hierarchy.dot: ../concepts.xml diagram-dot.py Makefile | tmp
	./diagram-dot.py -R $(REVISION) -go 0 -gt 0 --output $@ --input $<

./tmp/operations.dot: ../concepts.xml diagram-dot.py Makefile | tmp
	./diagram-dot.py -R $(REVISION) -go 1 -gt 0 --output $@ --input $<

./tmp/traits.dot: ../concepts.xml diagram-dot.py Makefile | tmp
	./diagram-dot.py -R $(REVISION) -go 0 -gt 1 --output $@ --input $<

./tmp/concept-%.dot: ../concepts.xml diagram-dot.py Makefile | tmp
	./diagram-dot.py -R $(REVISION) --metaobject $* --output $@ --input $<

./tmp/operation-%.dot: ../concepts.xml diagram-dot.py Makefile | tmp
	./diagram-dot.py -R $(REVISION) --operation $* --output $@ --input $<

./tmp/trait-%.dot: ../concepts.xml diagram-dot.py Makefile | tmp
	./diagram-dot.py -R $(REVISION) --trait $* --output $@ --input $<

./tmp/%.mk: ./%-mk.xsl ../concepts.xml Makefile | tmp
	$(XSLTPROC) --stringparam revision $(REVISION) --output $@ $< ../concepts.xml

out tmp:
	mkdir -p $@

clean:
	rm -rf out tmp
