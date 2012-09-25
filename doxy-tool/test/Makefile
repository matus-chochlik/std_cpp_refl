blddir = $(PWD)/../../_bld/doxy-tool/test
outdir = $(PWD)/../../_out/doxy-tool/test

CXX ?= g++
CXXFLAGS += -std=c++0x -I../include
LDFLAGS += -std=c++0x

all: $(addprefix $(outdir)/, $(basename $(wildcard *.cpp)))

$(blddir) $(outdir):
	mkdir -p $@

$(blddir)/%.d: %.cpp | $(blddir)
	$(CXX) $(CXXFLAGS) -E -MM -o $@ $<

$(blddir)/%.o: %.cpp | $(blddir)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(outdir)/%: $(blddir)/%.o | $(outdir)
	$(CXX) $(LDFLAGS) -o $@ $<

sinclude $(addsuffix .d, $(addprefix $(blddir)/, $(basename $(wildcard *.cpp))))
