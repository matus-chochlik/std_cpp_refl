# the intermediate build and final output directory
blddir = $(PWD)/_bld
outdir = $(PWD)/_out

components = specification gcc-plugin doxy-tool

all: $(components)

$(components):
	cd $@ && $(MAKE) && cd ..

clean:
	rm -rf $(blddir)
	rm -rf $(outdir)

.PHONY: clean $(components)
