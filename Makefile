# the intermediate build and final output directory
blddir = $(HOME)/Build/std_cpp_refl/_bld
outdir = $(HOME)/Build/std_cpp_refl/_out

components = P0385R0 P0385R1 P0385R2 P0194R0 N4451 N4452 N4111 N3996

all: $(components)

$(components):
	cd $@ && $(MAKE) && cd ..

clean:
	rm -rf $(blddir)
	rm -rf $(outdir)

.PHONY: clean $(components)
