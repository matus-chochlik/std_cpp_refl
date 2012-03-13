# the output documents
input_tex = std_cpp_refl

# the intermediate build and final output directory
blddir = _bld
outdir = _out

# options passed to (pdf)latex
latexopts = --output-dir=$(blddir)

output_pdf = $(addprefix $(outdir)/, $(addsuffix .pdf, $(input_tex)))

all: $(output_pdf)

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


publish: all
	scp $(output_pdf) kifri.fri.uniza.sk:./public_html/$(notdir $(PWD))/$(notdir $(output_pdf))

.PHONY: clean
clean:
	rm -rf $(blddir)
	rm -rf $(outdir)


sinclude $(addprefix $(blddir)/, $(addsuffix .tex.d, $(input_tex)))
