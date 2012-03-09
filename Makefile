# the output documents
docs = std_cpp_refl

# the intermediate build and final output directory
blddir = _bld
outdir = _out

# options passed to (pdf)latex
latexopts = --output-dir=$(blddir)

all: $(addprefix $(outdir)/, $(addsuffix .pdf, $(docs)))

$(blddir)/%.tex.d: %.tex | $(blddir)
	echo "$(blddir)/$*.pdf: \\" > $@
	./tex_scan_deps.sh $< >> $@
	echo "$<" >> $@

$(blddir)/%.pdf: %.tex $(blddir)/%.tex.d | $(blddir)
	pdflatex $(latexopts) $<
	pdflatex $(latexopts) $<

$(outdir)/%.pdf: $(blddir)/%.pdf | $(outdir)
	cp $< $@
		
$(blddir) $(outdir):
	mkdir -p $@


.PHONY: clean
clean:
	rm -rf $(blddir)
	rm -rf $(outdir)


sinclude $(addprefix $(blddir)/, $(addsuffix .tex.d, $(docs)))
