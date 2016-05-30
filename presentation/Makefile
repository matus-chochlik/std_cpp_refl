wrkdir = $(PWD)
blddir = ../_bld/$(notdir $(PWD))
outdir = ../_out/$(notdir $(PWD))

all: $(outdir)/Oulu.pdf

.PHONY: clean
clean:
	rm -f $(outdir)/*

$(outdir)/%.pdf: $(blddir)/%.pdf | $(outdir)
	cp $^ $@

$(blddir)/%.pdf: ./%.tex | $(blddir)
	pdflatex -shell-escape -output-directory=$(blddir) $<

$(blddir) $(outdir):
	mkdir -p $@
