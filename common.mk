# the intermediate build and final output directory
wrkdir = $(PWD)
blddir = $(HOME)/Build/std_cpp_refl/_bld/$(notdir $(PWD))
outdir = $(HOME)/Build/std_cpp_refl/_out/$(notdir $(PWD))

# options passed to (pdf)latex
latexopts = -shell-escape

output_pdf = $(addprefix $(outdir)/, $(addsuffix .pdf, $(input_tex)))

all: $(output_pdf)

$(blddir)/%.tex.d: %.tex | $(blddir)
	echo "$(blddir)/$*.pdf: \\" > $@
	$(wrkdir)/tex_scan_deps.sh $(blddir) $< >> $@
	echo "$(blddir)/$<" >> $@

$(blddir)/%.tex: %.tex | $(blddir)/sections
	cp $< $@

$(blddir)/%.sty: %.sty | $(blddir)
	cp $< $@

$(blddir)/%.bib: %.bib | $(blddir)
	cp $< $@

$(blddir)/%.bbl: $(blddir)/%.bib $(blddir)/%.tex
	cd $(blddir) && \
		pdflatex $(latexopts) $* && \
		bibtex $* && \
	cd $(wrkdir)



$(blddir)/%.pdf: $(blddir)/%.tex $(blddir)/%.tex.d $(blddir)/minted.sty | $(blddir)
	cp -rf images $(blddir)/ || true
	cd $(blddir) && \
		pdflatex $(latexopts) $(notdir $<) && \
		pdflatex $(latexopts) $(notdir $<) && \
	cd $(wrkdir)

$(outdir)/%.pdf: $(blddir)/%.pdf | $(outdir)
	cp $< $@
		
$(outdir) $(blddir) $(blddir)/sections:
	mkdir -p $@

sinclude $(addprefix $(blddir)/, $(addsuffix .tex.d, $(input_tex)))

.PHONY: clean
clean:
	rm -rf $(blddir)
	rm -rf $(outdir)

.PHONY: cleandeps
cleandeps:
	rm -f $(blddir)/*.d
