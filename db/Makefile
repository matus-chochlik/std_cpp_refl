BLDDIR = tmp
OUTDIR = out
VISJSDIR = $(OUTDIR)/vis_js

all: visjs

visjs: \
	$(VISJSDIR)/nodes_all.js \
	$(VISJSDIR)/edges_all.js \
	$(VISJSDIR)/nodes_concepts_only.js \
	$(VISJSDIR)/edges_concepts_inheritance.js \
	$(VISJSDIR)/concept_hierarchy.html \
	$(VISJSDIR)/concept_hierarchy.js \
	$(VISJSDIR)/overview.html \
	$(VISJSDIR)/overview.js \
	$(VISJSDIR)/reflexpr_network.css \
	$(VISJSDIR)/reflexpr_network.js

$(VISJSDIR)/%: vis_js/%
	cp $^ $@

$(VISJSDIR)/nodes_all.js: $(BLDDIR)/db_ok.tag | $(VISJSDIR)
	psql -A -t -c 'SELECT reflexpr.vis_js_nodes()' > $@

$(VISJSDIR)/edges_all.js: $(BLDDIR)/db_ok.tag | $(VISJSDIR)
	psql -A -t -c 'SELECT reflexpr.vis_js_edges()' > $@

$(VISJSDIR)/nodes_concepts_only.js: $(BLDDIR)/db_ok.tag | $(VISJSDIR)
	psql -A -t -c 'SELECT reflexpr.vis_js_nodes(TRUE, FALSE)' > $@

$(VISJSDIR)/edges_concepts_inheritance.js: $(BLDDIR)/db_ok.tag | $(VISJSDIR)
	psql -A -t -c 'SELECT reflexpr.vis_js_edges(TRUE)' > $@

database: $(BLDDIR)/db_ok.tag

$(BLDDIR)/db_ok.tag: psql/*.psql | $(BLDDIR)
	cd psql && psql -1 -f 'reflexpr.psql' && cd .. && touch $@ 

$(BLDDIR) $(OUTDIR) $(VISJSDIR):
	mkdir -p $@

.PHONY: clean

clean:
	rm -rf $(BLDDIR) $(OUTDIR)
