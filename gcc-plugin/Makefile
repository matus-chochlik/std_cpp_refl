#  Copyright 2011-2012 Matus Chochlik. Distributed under the Boost
#  Software License, Version 1.0. (See accompanying file
#  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#
#
# the intermediate build and final output directory
blddir = ../_bld/$(notdir $(PWD))
outdir = ../_out/$(notdir $(PWD))
srcdir = ./src

plugin = $(outdir)/static-reflection.so

test_sources = $(wildcard test/*.cpp)
tests = $(addprefix $(blddir)/, $(test_sources:.cpp=))

# the main/default target of the Makefile
all: $(plugin) $(tests)


# plugin compilation options
CXX_OPTIONS = \
	-I./include \
	-I$(shell $(CXX) -print-file-name=plugin)/include \
	-fPIC \
	$(CXXFLAGS)

# plugin link options
LD_OPTIONS = \
	-fPIC -shared \
	$(LDFLAGS)

# test compilation options
TEST_OPTIONS = \
	-x c++ \
	-fplugin=$(plugin) \
	$(CXXFLAGS) $(LDFLAGS)


# the plugin shared object
$(plugin): \
	$(blddir)/plugin.o |\
	$(outdir)
	$(CXX) $(LD_OPTIONS) $^ -o $@ 

# individual object files
$(blddir)/%.o: $(srcdir)/%.cpp | $(blddir)
	$(CXX) $(CXX_OPTIONS) -c $< -o $@ 

# tests
$(blddir)/test/%: test/%.cpp $(plugin) | $(blddir)/test
	$(CXX) $(TEST_OPTIONS) $< -o $@ 

# directories
$(blddir) $(blddir)/test $(outdir):
	mkdir -p $@
