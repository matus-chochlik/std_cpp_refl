# the intermediate build and final output directory
blddir = $(PWD)/_bld
outdir = $(PWD)/_out

components = current n4451 n4452 n4111 n3996 gcc-plugin doxy-tool

all: $(components)

$(components):
	cd $@ && $(MAKE) && cd ..

clean:
	rm -rf $(blddir)
	rm -rf $(outdir)

.PHONY: clean $(components)
