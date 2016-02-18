diagrams-$(REVISION): $(foreach I, $(DIAGRAMS-$(REVISION)), ./out/$I-$(REVISION).svg)
.PHONY: diagrams-$(REVISION)

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
