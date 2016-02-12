#!/usr/bin/python
# coding: UTF-8

import sys
 
class options:
	def __init__(self):
		self.output = sys.stdout

def iter_last(iterable):
    items = iter(iterable)
    prev = next(items)

    for item in items:
        yield prev, False
        prev = item
    yield prev, True

 
def print_concept_node(opts, concepts, name, definition):

	values = {
		"name" : name,
		"definition": definition,
		"head_color": "#707070",
		"cell_color": "#D0D0D0"
	}

	opts.output.write("""
	%(name)s [label=<
	<TABLE BORDER="2" CELLBORDER="0" CELLSPACING="0" HREF="%(name)s.svg">"""
	% values)

	opts.output.write("""
	<TR>
		<TD BGCOLOR="%(head_color)s" ALIGN="RIGHT">using</TD>
		<TD BGCOLOR="%(head_color)s" ALIGN="LEFT"><B>%(name)s</B></TD>
		<TD BGCOLOR="%(cell_color)s" ALIGN="CENTER">=</TD>
	</TR>"""
	% values)

	opts.output.write("""
	<TR>
		<TD BGCOLOR="%(cell_color)s" COLSPAN="2" ALIGN="RIGHT"><B>%(definition)s</B></TD>
		<TD BGCOLOR="%(cell_color)s" ALIGN="LEFT">;</TD>
	</TR>""" % values)


	opts.output.write("""
	</TABLE>>
	shape="none"
	];\n""")

 
def print_string_const_node(opts, concepts):

	values = {
		"name" : "StringConstant",
		"head_color": "#707070",
		"cell_color": "#D0D0D0"
	}

	opts.output.write("""
	%(name)s [label=<
	<TABLE BORDER="2" CELLBORDER="0" CELLSPACING="0" HREF="%(name)s.svg">"""
	% values)

	opts.output.write("""
	<TR>
		<TD BGCOLOR="%(head_color)s" COLSPAN="2" ALIGN="LEFT">struct <B>%(name)s</B></TD>
	</TR>""" % values)

	opts.output.write("""
	<TR>
		<TD BGCOLOR="%(cell_color)s" ALIGN="LEFT">{</TD>
		<TD BGCOLOR="%(cell_color)s"></TD>
	</TR>""" % values)

	opts.output.write("""
	<TR>
		<TD BGCOLOR="%(cell_color)s"></TD>
		<TD BGCOLOR="%(cell_color)s" ALIGN="RIGHT">constexpr const char value[N+1];</TD>
	</TR>""" % values)

	opts.output.write("""
	<TR>
		<TD BGCOLOR="%(cell_color)s" ALIGN="LEFT">};</TD>
		<TD BGCOLOR="%(cell_color)s"></TD>
	</TR>""" % values)

	opts.output.write("""
	</TABLE>>
	shape="none"
	];\n""")

 
def print_pointer_node(opts, concepts):
	name = "Pointer"

	opts.output.write("""
	%s [label=<
	<TABLE BORDER="2" CELLBORDER="0" CELLSPACING="0" HREF="%s.svg">"""
	% (name, name))

	opts.output.write("""
	<TR>
		<TD BGCOLOR="#707070" COLSPAN="3" ALIGN="LEFT">template &lt;typename T&gt;</TD>
	</TR>""")

	opts.output.write("""
	<TR>
		<TD BGCOLOR="#707070" ALIGN="RIGHT">using</TD>
		<TD BGCOLOR="#707070" ALIGN="LEFT"><B>Pointer</B></TD>
		<TD BGCOLOR="#D0D0D0" ALIGN="CENTER"> = </TD>
	</TR>""")

	opts.output.write("""
	</TABLE>>
	shape="none"
	];\n""")
 
def print_plain_type_node(opts, concepts, name, label):

	opts.output.write("""
	%s [label=<
	<TABLE BORDER="2" CELLBORDER="0" CELLSPACING="0" HREF="%s.svg">"""
	% (name, name))

	opts.output.write("""
	<TR>
		<TD BGCOLOR="#707070" ALIGN="CENTER">%s</TD>
	</TR>""" % label)

	opts.output.write("""
	</TABLE>>
	shape="none"
	];\n""")

 
def print_metaobject_node(opts, concepts, metaobject):
	name = metaobject.attrib["name"]
	is_base = name == "Object"

	opts.output.write("""
	%s [label=<
	<TABLE BORDER="2" CELLBORDER="0" CELLSPACING="0" HREF="%s.svg">"""
	% (name, name))

	opts.output.write("""
	<TR>
		<TD BGCOLOR="ORANGE" COLSPAN="3" ALIGN="LEFT">template &lt;%s&gt;</TD>
	</TR>"""
	% ("typename T" if is_base else "Object T"));

	opts.output.write("""
	<TR>
		<TD BGCOLOR="ORANGE" ALIGN="RIGHT">concept bool</TD>
		<TD BGCOLOR="ORANGE" ALIGN="LEFT"><B>%s</B></TD>
		<TD BGCOLOR="#D0D0D0" ALIGN="CENTER">=</TD>
	</TR>"""
	% (name))

	requirements = list()

	requirements += [x.attrib["concept"] for x in metaobject.findall("generalization")]
	requirements += [x.attrib["name"] for x in concepts.findall("trait[@indicates='%s']" % name)]

	if is_base: requirements += ["is_metaobject"]

	for item, is_last in iter_last(requirements): opts.output.write("""
	<TR>
		<TD BGCOLOR="#D0D0D0" COLSPAN="2" ALIGN="RIGHT"><B>%s</B>&lt;T&gt;</TD>
		<TD BGCOLOR="#D0D0D0" ALIGN="LEFT">%s</TD>
	</TR>""" % (item, ";" if is_last else "&amp;&amp;"))


	opts.output.write("""
	</TABLE>>
	shape="none"
	];\n""")

 
def print_trait_node(opts, concepts, trait):
	name = trait.attrib["name"]

	opts.output.write("""
	%s [label=<
	<TABLE BORDER="2" CELLBORDER="0" CELLSPACING="0" HREF="%s.svg">"""
	% (name, name))

	opts.output.write("""
	<TR>
		<TD BGCOLOR="#8080D0" COLSPAN="2" ALIGN="LEFT">template &lt;Object T&gt;</TD>
	</TR>""")

	opts.output.write("""
	<TR>
		<TD BGCOLOR="#8080D0" ALIGN="LEFT">struct <B>%s</B></TD>
		<TD BGCOLOR="#D0D0D0" ALIGN="CENTER">:</TD>
	</TR>"""
	% (name))

	opts.output.write("""
	<TR>
		<TD BGCOLOR="#D0D0D0" ALIGN="RIGHT"><B>BooleanConstant</B></TD>
		<TD BGCOLOR="#D0D0D0" ALIGN="LEFT">{ };</TD>
	</TR>""")

	opts.output.write("""
	</TABLE>>
	shape="none"
	];""")

	opts.output.write("""
	{rank=same; %s, %s};\n"""
	% (trait.attrib["indicates"], name))

 
def print_operation_node(opts, concepts, operation):
	name = operation.attrib["name"]
	result = operation.attrib["result"]

	inherit_result = result in ["StringConstant", "IntegralConstant", "BooleanConstant"]

	operand = "Object"
	for arg in operation.findall("argument"):
		argt = arg.attrib["type"]
		if len(concepts.findall("metaobject[@name='%s']" % argt)) > 0:
			operand = argt
			break

	opts.output.write("""
	%s [label=<
	<TABLE BORDER="2" CELLBORDER="0" CELLSPACING="0" HREF="%s.svg">"""
	% (name, name))

	opts.output.write("""
	<TR>
		<TD BGCOLOR="#C080D0" COLSPAN="2" ALIGN="LEFT">template &lt;%s T&gt;</TD>
	</TR>"""
	% operand)


	if inherit_result:
		opts.output.write("""
		<TR>
			<TD BGCOLOR="#C080D0" ALIGN="LEFT">struct <B>%s</B></TD>
			<TD BGCOLOR="#C0D0D0" ALIGN="CENTER">:</TD>
		</TR>"""
		% (name))

		opts.output.write("""
		<TR>
			<TD BGCOLOR="#D0D0D0" ALIGN="RIGHT"><B>%s</B></TD>
			<TD BGCOLOR="#D0D0D0" ALIGN="LEFT">{ };</TD>
		</TR>"""
		% result)
	else:
		opts.output.write("""
		<TR>
			<TD BGCOLOR="#C080D0" COLSPAN="2" ALIGN="LEFT">struct <B>%s</B></TD>
		</TR>"""
		% (name))
		opts.output.write("""
		<TR>
			<TD BGCOLOR="#D0D0D0" ALIGN="LEFT">{</TD>
			<TD BGCOLOR="#D0D0D0"></TD>
		</TR>""")

		if result == "Pointer":
			opts.output.write("""
			<TR>
				<TD BGCOLOR="#D0D0D0"></TD>
				<TD BGCOLOR="#D0D0D0" ALIGN="RIGHT">const Pointer value;</TD>
			</TR>""")
		else:
			opts.output.write("""
			<TR>
				<TD BGCOLOR="#D0D0D0"></TD>
				<TD BGCOLOR="#D0D0D0" ALIGN="RIGHT">typedef %s type;</TD>
			</TR>""" % result)
	

		opts.output.write("""
		<TR>
			<TD BGCOLOR="#D0D0D0" ALIGN="LEFT">};</TD>
			<TD BGCOLOR="#D0D0D0"></TD>
		</TR>""")


	opts.output.write("""
	</TABLE>>
	shape="none"
	];""")

	opts.output.write("""
	{rank=same; %s, %s};\n"""
	% (operand, name))


def print_edge(opts, name_from, name_to):
	opts.output.write("""
	%s -> %s;"""
	% (name_from, name_to))

def print_concept_edge(opts, concept_from, concept_to):
	name_from = concept_from.attrib["name"]
	name_to = concept_to.attrib["name"]

	print_edge(opts, name_from, name_to)

def print_concept_gen_spec_edge(opts, concepts, generalization, specialization):
	gene_name = generalization.attrib["concept"]
	spec_name = specialization.attrib["name"]

	print_edge(opts, spec_name, gene_name)

def print_graph_dot(opts, concepts):
	import random

	opts.output.write("""digraph Reflection {
	overlap=false
	rankdir=BT
	ranksep=1.0
	fontName="Sans"
	maxiter=1000000

	edge [penwidth=2.0 arrowsize=2.0];
	node [penwidth=2.0];
	""")

	# Other concepts
	print_concept_node(opts, concepts, "SourceLocation", "source_location")
	print_concept_node(opts, concepts, "BooleanConstant", "integral_constant&lt;bool, ...&gt;")
	print_concept_node(opts, concepts, "IntegralConstant", "integral_constant&lt;size_t, ...&gt;")
	print_string_const_node(opts, concepts)
	print_pointer_node(opts, concepts)
	print_plain_type_node(opts, concepts, "OriginalType", "original-type")
	print_plain_type_node(opts, concepts, "size_t", "size_t")

	# Metaobject nodes 
	for metaobject in concepts.findall("metaobject"):
		print_metaobject_node(opts, concepts, metaobject)


	# Trait nodes
	for trait in concepts.findall("trait"):
		print_trait_node(opts, concepts, trait)

	# Operation nodes
	for operation in concepts.findall("operation"):
		print_operation_node(opts, concepts, operation)

	# Trait -> Metaobject (indicates) edges
	opts.output.write("""
	edge [constraint="false" style="dashed" arrowhead="none"];""")

	for trait in concepts.findall("trait"):
		print_edge(opts, trait.attrib["name"], trait.attrib["indicates"])
	opts.output.write("\n")

	# Trait -> BooleanConstant (result) edges
	opts.output.write("""
	edge [constraint="true" style="dashed" arrowhead="vee"];""")

	for trait in concepts.findall("trait"):
		print_edge(opts, trait.attrib["name"], "BooleanConstant")
	opts.output.write("\n")

	# Operation -> Result edges
	opts.output.write("""
	edge [constraint="true" style="dashed" arrowhead="vee"];""")

	for operation in concepts.findall("operation"):
		print_edge(opts, operation.attrib["name"], operation.attrib["result"])
	opts.output.write("\n")

	# Argument -> Operation edges
	opts.output.write("""
	edge [constraint="true" style="dashed" arrowhead="vee"];""")

	for operation in concepts.findall("operation"):
		for argument in operation.findall("argument"):
			print_edge(opts, argument.attrib["type"], operation.attrib["name"])
	opts.output.write("\n")

	# Metaobject is-a edges
	opts.output.write("""
	edge [constraint="true" style="solid" fillcolor="WHITE", arrowhead="normal"];""")

	for derived in concepts.findall("metaobject"):
		for base in derived.findall("generalization"):
			print_concept_gen_spec_edge(opts, concepts, base, derived)
	opts.output.write("\n")

	# Metaobject ordering edges
	opts.output.write("""
	edge [style="invis"];""")

	for metaobject in concepts.findall("metaobject"):
		for prev_mo in metaobject.findall("order_after"):
			print_concept_gen_spec_edge(opts, concepts, prev_mo, metaobject)
	opts.output.write("\n")
			
	
	prev_mo = None
	for metaobject in concepts.findall("metaobject"):
		if prev_mo is not None:
			coef = len(metaobject.findall("generalization"))/3.0
			if random.random() < coef:
				print_concept_edge(opts, metaobject, prev_mo)
		prev_mo = metaobject

	# Operation -> Result edges
	opts.output.write("""
	edge [constraint="true" style="dashed" arrowhead="vee"];""")

	opts.output.write("""}
	""")


def main():
	import xml.etree.ElementTree as XET

	opts = options();

	print_graph_dot(opts, XET.parse(sys.argv[1]).getroot())


#pass run the main function
if __name__ == "__main__": main()
