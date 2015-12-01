.PHONY: all

all: html/index.html html/boostbook.css

.PHONY: clean

clean:
	rm -r bin/ html/

html/index.html: index.qbk
	bjam

html/%.css: %.css
	cp $< $@

