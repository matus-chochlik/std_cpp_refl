DIAGDOTFLAGS = -RN $(REVISION_NODES) -R $(REVISION) -M $(MAX_REVISION)

svg-diagrams-$(REVISION): $(foreach I, $(DIAGRAMS-$(REVISION)), ./out/$I-$(REVISION).svg)
.PHONY: svg-diagrams-$(REVISION)

pdf-diagrams-$(REVISION): $(foreach I, $(DIAGRAMS-$(REVISION)), ./out/$I-$(REVISION).pdf)
.PHONY: pdf-diagrams-$(REVISION)

./tmp/%-$(REVISION).dot: ./%-dot.xsl ../concepts.xml
	$(XSLTPROC) --stringparam revision $(REVISION) --output $@ $^

./tmp/overview-$(REVISION).dot: ../concepts.xml diagram-dot.py Makefile | tmp
	./diagram-dot.py $(DIAGDOTFLAGS) --output $@ --input $<

./tmp/hierarchy-$(REVISION).dot: ../concepts.xml diagram-dot.py Makefile | tmp
	./diagram-dot.py $(DIAGDOTFLAGS) -go 0 -gt 0 --output $@ --input $<

./tmp/operations-$(REVISION).dot: ../concepts.xml diagram-dot.py Makefile | tmp
	./diagram-dot.py $(DIAGDOTFLAGS) -go 1 -gt 0 --output $@ --input $<

./tmp/traits-$(REVISION).dot: ../concepts.xml diagram-dot.py Makefile | tmp
	./diagram-dot.py $(DIAGDOTFLAGS) -go 0 -gt 1 --output $@ --input $<

./tmp/concept-%-$(REVISION).dot: ../concepts.xml diagram-dot.py Makefile | tmp
	./diagram-dot.py $(DIAGDOTFLAGS) --metaobject $* --output $@ --input $<

./tmp/operation-%-$(REVISION).dot: ../concepts.xml diagram-dot.py Makefile | tmp
	./diagram-dot.py $(DIAGDOTFLAGS) --operation $* --output $@ --input $<

./tmp/trait-%-$(REVISION).dot: ../concepts.xml diagram-dot.py Makefile | tmp
	./diagram-dot.py $(DIAGDOTFLAGS) --trait $* --output $@ --input $<
