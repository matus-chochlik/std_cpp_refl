XSLTPROC = xsltproc
BJAM = bjam

sinclude ./tmp/concepts.mk

CONCEPT_HPPS = $(foreach C, $(CONCEPTS), ./quickref/$(C).hpp)

all: ./html/index.html ./html/boostbook.css

clean:
	rm -r bin/ html/ tmp/ out/

.PHONY: all clean

concept_hpps: $(CONCEPT_HPPS)

./html/index.html: index.qbk concept_hpps | html
	$(BJAM)

./html/%.css: %.css | html
	cp $< $@

./quickref/%.hpp: ./xsl/concept-hpp.xsl ../concepts.xml
	$(XSLTPROC) --stringparam metaobject $* --output $@ $^
	git add $@

./tmp/%.mk: ./xsl/%-mk.xsl ../concepts.xml | tmp
	$(XSLTPROC) --output $@ $^

out tmp html bin:
	mkdir -p $@

