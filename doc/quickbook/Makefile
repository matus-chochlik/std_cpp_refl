XSLTPROC = xsltproc
BJAM = bjam

sinclude ./tmp/concepts.mk
sinclude ./tmp/traits.mk

CONCEPT_HPPS = $(foreach C, $(CONCEPTS), ./quickref/c_$(C).hpp)
CONCEPT_QBKS = $(foreach C, $(CONCEPTS), ./quickref/c_$(C).qbk)
TRAIT_HPPS = $(foreach T, $(TRAITS), ./quickref/t_$(T).hpp)
TRAIT_QBKS = $(foreach T, $(TRAITS), ./quickref/t_$(T).qbk)

all: ./html/index.html ./html/boostbook.css

clean:
	rm -r bin/ html/ tmp/ out/

.PHONY: all clean

_concept_qbks: $(CONCEPT_QBKS)
_concept_hpps: $(CONCEPT_HPPS)
_trait_qbks: $(TRAIT_QBKS)
_trait_hpps: $(TRAIT_HPPS)

./html/index.html: \
	index.qbk \
	./quickref/concepts-incl.qbk \
	./index/concepts-incl.qbk \
	./quickref/traits-incl.qbk \
	./index/traits-incl.qbk \
	_concept_qbks _trait_qbks | html
	$(BJAM)

./html/%.css: %.css | html
	cp $< $@

./quickref/concepts-incl.qbk: | $(CONCEPT_QBKS)
./quickref/traits-incl.qbk: | $(TRAIT_QBKS)
./index/traits-incl.qbk: | $(TRAIT_QBKS)

./index/%-incl.qbk: ./xsl/%-index-qbk.xsl ../concepts.xml
	$(XSLTPROC) --stringparam metaobject $* --output $@ $^
	git add $@

./quickref/%-incl.qbk: ./xsl/%-qbk.xsl ../concepts.xml
	$(XSLTPROC) --stringparam metaobject $* --output $@ $^
	git add $@

./quickref/c_%.qbk: ./xsl/concept-qbk.xsl ../concepts.xml | ./quickref/c_%.hpp
	$(XSLTPROC) --stringparam metaobject $* --output $@ $^
	git add $@

./quickref/c_%.hpp: ./xsl/concept-hpp.xsl ../concepts.xml
	$(XSLTPROC) --stringparam metaobject $* --output $@ $^
	git add $@

./quickref/t_%.qbk: ./xsl/trait-qbk.xsl ../concepts.xml | ./quickref/t_%.hpp
	$(XSLTPROC) --stringparam trait $* --output $@ $^
	git add $@

./quickref/t_%.hpp: ./xsl/trait-hpp.xsl ../concepts.xml
	$(XSLTPROC) --stringparam trait $* --output $@ $^
	git add $@

./tmp/%.mk: ./xsl/%-mk.xsl ../concepts.xml | tmp
	$(XSLTPROC) --output $@ $^

out tmp html bin:
	mkdir -p $@

