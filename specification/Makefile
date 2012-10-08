# the output documents
input_tex = std_cpp_refl

# the intermediate build and final output directory
wrkdir = $(PWD)
blddir = ../_bld/$(notdir $(PWD))
outdir = ../_out/$(notdir $(PWD))

# options passed to (pdf)latex
latexopts = -shell-escape

revision = $(shell cat REVISION)
output_pdf = $(addprefix $(outdir)/, $(addsuffix .pdf, $(addsuffix -rev-$(revision), $(input_tex))))

all: $(output_pdf)

$(blddir)/%.tex.d: %.tex | $(blddir)
	echo "$(blddir)/$*.pdf: \\" > $@
	$(wrkdir)/tex_scan_deps.sh $(blddir) $< >> $@
	echo "$(blddir)/$<" >> $@

$(blddir)/%.tex: %.tex | $(blddir)/sections
	cp $< $@

$(blddir)/sections/%.tex: xslt/%-tex.xsl concepts.xml | $(blddir)/sections
	xsltproc $+ > $@

$(blddir)/%.sty: %.sty | $(blddir)
	cp $< $@

$(blddir)/%.pdf: $(blddir)/%.tex $(blddir)/%.tex.d $(blddir)/minted.sty | $(blddir)
	cp -r images $(blddir)/images
	cd $(blddir) && pdflatex $(latexopts) $(notdir $<) && cd $(wrkdir)

$(outdir)/%-rev-$(revision).pdf: $(blddir)/%.pdf | $(outdir)
	cp $< $@
		
$(outdir) $(blddir) $(blddir)/sections:
	mkdir -p $@

sinclude $(addprefix $(blddir)/, $(addsuffix .tex.d, $(input_tex)))

.PHONY: clean
clean:
	rm -rf $(blddir)
	rm -rf $(outdir)

