XSLTPROC = xsltproc
BJAM = bjam

sinclude ./tmp/concepts.mk

CONCEPT_HPPS = $(foreach C, $(CONCEPTS), ./quickref/$(C).hpp)
CONCEPT_QBKS = $(foreach C, $(CONCEPTS), ./quickref/$(C).qbk)

all: ./html/index.html ./html/boostbook.css

clean:
	rm -r bin/ html/ tmp/ out/

.PHONY: all clean

./html/index.html: index.qbk $(CONCEPT_QBKS) | html
	$(BJAM)

./html/%.css: %.css | html
	cp $< $@

./quickref/%.qbk: ./xsl/concept-qbk.xsl ../concepts.xml | ./quickref/%.hpp
	$(XSLTPROC) --stringparam metaobject $* --output $@ $^
	git add $@

./quickref/%.hpp: ./xsl/concept-hpp.xsl ../concepts.xml
	$(XSLTPROC) --stringparam metaobject $* --output $@ $^
	git add $@

./tmp/%.mk: ./xsl/%-mk.xsl ../concepts.xml | tmp
	$(XSLTPROC) --output $@ $^

out tmp html bin:
	mkdir -p $@

