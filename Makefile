# the intermediate build and final output directory
blddir = $(PWD)/_bld
outdir = $(PWD)/_out

components = P0318 P0194R0 N4451 N4452 N4111 N3996

all: $(components)

$(components):
	cd $@ && $(MAKE) && cd ..

clean:
	rm -rf $(blddir)
	rm -rf $(outdir)

.PHONY: clean $(components)
