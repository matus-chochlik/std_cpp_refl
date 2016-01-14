XSLTPROC = xsltproc
GRAPHVIZ = dot

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
	$(XSLTPROC) --output $@ ./cc2dot-fixup.xsl $^

./tmp/%.svg: ./tmp/%.dot | out
	$(GRAPHVIZ) -Tsvg -o $@ $<

./tmp/%.dot: ./%-dot.xsl ../concepts.xml | tmp
	$(XSLTPROC) --output $@ $^

./tmp/concept-%.dot: ./concept-dot.xsl ../concepts.xml | tmp
	$(XSLTPROC) --stringparam metaobject $* --output $@ $^

./tmp/trait-%.dot: ./trait-dot.xsl ../concepts.xml | tmp
	$(XSLTPROC) --stringparam trait $* --output $@ $^

./tmp/operation-%.dot: ./operation-dot.xsl ../concepts.xml | tmp
	$(XSLTPROC) --stringparam operation $* --output $@ $^

./tmp/%.mk: ./%-mk.xsl ../concepts.xml | tmp
	$(XSLTPROC) --output $@ $^

out tmp:
	mkdir -p $@

clean:
	rm -rf out tmp
