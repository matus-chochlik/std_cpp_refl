XSLTPROC = xsltproc
GRAPHVIZ = dot

DIAGRAMS = overview traits
SVG_IMAGES = $(foreach I, $(DIAGRAMS), ./$I.svg)

all: $(SVG_IMAGES)

./%.svg: ./%.dot
	$(GRAPHVIZ) -Tsvg -o $@ $<


./%.dot: ./%-dot.xsl ../concepts.xml
	$(XSLTPROC) --output $@ $< ../concepts.xml
	less $@

clean:
	rm -f $(SVG_IMAGES)
