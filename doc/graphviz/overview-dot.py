#!/usr/bin/python
# coding: UTF-8

import sys
 
class options:
	def __init__(self):
		self.output = sys.stdout

		self.type_head_color = "#707070"
		self.cell_color = "#D0D0D0"

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
		"head_color": opts.type_head_color,
		"cell_color": opts.cell_color
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
		"head_color": opts.type_head_color,
		"cell_color": opts.cell_color
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
	values = {
		"name" : "Pointer",
		"head_color": opts.type_head_color,
		"cell_color": opts.cell_color
	}

	opts.output.write("""
	%(name)s [label=<
	<TABLE BORDER="2" CELLBORDER="0" CELLSPACING="0" HREF="%(name)s.svg">"""
	% values)

	opts.output.write("""
	<TR>
		<TD BGCOLOR="%(head_color)s" COLSPAN="3" ALIGN="LEFT">template &lt;typename T&gt;</TD>
	</TR>""" % values)

	opts.output.write("""
	<TR>
		<TD BGCOLOR="%(head_color)s" ALIGN="RIGHT">using</TD>
		<TD BGCOLOR="%(head_color)s" ALIGN="LEFT"><B>%(name)s</B></TD>
		<TD BGCOLOR="%(cell_color)s" ALIGN="CENTER"> = </TD>
	</TR>""" % values)

	opts.output.write("""
	</TABLE>>
	shape="none"
	];\n""")
 
def print_plain_type_node(opts, concepts, name, label):
	values = {
		"name" : name,
		"label" : label,
		"head_color": opts.type_head_color,
		"cell_color": opts.cell_color
	}

	opts.output.write("""
	%(name)s [label=<
	<TABLE BORDER="2" CELLBORDER="0" CELLSPACING="0" HREF="%(name)s.svg">"""
	% values)

	opts.output.write("""
	<TR>
		<TD BGCOLOR="%(head_color)s" ALIGN="CENTER">%(label)s</TD>
	</TR>""" % values)

	opts.output.write("""
	</TABLE>>
	shape="none"
	];\n""")

 
def print_metaobject_node(opts, concepts, metaobject):
	name = metaobject.attrib["name"]
	is_base = name == "Object"
	values = {
		"name" : name,
		"typename_T": "typename T" if is_base else "Object T",
		"head_color": "ORANGE",
		"cell_color": opts.cell_color
	}

	opts.output.write("""
	%(name)s [label=<
	<TABLE BORDER="2" CELLBORDER="0" CELLSPACING="0" HREF="%(name).svg">"""
	% values)

	opts.output.write("""
	<TR>
		<TD BGCOLOR="%(head_color)s" COLSPAN="3" ALIGN="LEFT">template &lt;%(typename_T)s&gt;</TD>
	</TR>"""
	% values);

	opts.output.write("""
	<TR>
		<TD BGCOLOR="%(head_color)s" ALIGN="RIGHT">concept bool</TD>
		<TD BGCOLOR="%(head_color)s" ALIGN="LEFT"><B>%(name)s</B></TD>
		<TD BGCOLOR="%(cell_color)s" ALIGN="CENTER">=</TD>
	</TR>"""
	% values)

	requirements = list()

	requirements += [x.attrib["concept"] for x in metaobject.findall("generalization")]
	requirements += [x.attrib["name"] for x in concepts.findall("trait[@indicates='%s']" % name)]

	if is_base: requirements += ["is_metaobject"]

	for item, is_last in iter_last(requirements):
		values_in = values
		values_in["item"] = item
		values_in["sep"] = ";" if is_last else "&amp;&amp;"
		opts.output.write("""
		<TR>
		<TD BGCOLOR="%(cell_color)s" COLSPAN="2" ALIGN="RIGHT"><B>%(item)s</B>&lt;T&gt;</TD>
		<TD BGCOLOR="%(cell_color)s" ALIGN="LEFT">%(sep)s</TD>
		</TR>""" % values)


	opts.output.write("""
	</TABLE>>
	shape="none"
	];\n""")

 
def print_trait_node(opts, concepts, trait):
	name = trait.attrib["name"]
	values = {
		"name" : name,
		"head_color": "#8080E0",
		"cell_color": opts.cell_color
	}

	opts.output.write("""
	%(name)s [label=<
	<TABLE BORDER="2" CELLBORDER="0" CELLSPACING="0" HREF="%(name)s.svg">"""
	% values)

	opts.output.write("""
	<TR>
		<TD BGCOLOR="%(head_color)s" COLSPAN="2" ALIGN="LEFT">template &lt;Object T&gt;</TD>
	</TR>""" % values)

	opts.output.write("""
	<TR>
		<TD BGCOLOR="%(head_color)s" ALIGN="LEFT">struct <B>%(name)s</B></TD>
		<TD BGCOLOR="%(cell_color)s" ALIGN="CENTER">:</TD>
	</TR>""" % values)

	opts.output.write("""
	<TR>
		<TD BGCOLOR="%(cell_color)s" ALIGN="RIGHT"><B>BooleanConstant</B></TD>
		<TD BGCOLOR="%(cell_color)s" ALIGN="LEFT">{ };</TD>
	</TR>""" % values)

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
	operand = "Object"
	for arg in operation.findall("argument"):
		argt = arg.attrib["type"]
		if len(concepts.findall("metaobject[@name='%s']" % argt)) > 0:
			operand = argt
			break

	values = {
		"name" : name,
		"result" : result,
		"operand" : operand,
		"head_color": "#E08080",
		"cell_color": opts.cell_color
	}

	inherit_result = result in ["StringConstant", "IntegralConstant", "BooleanConstant"]

	opts.output.write("""
	%(name)s [label=<
	<TABLE BORDER="2" CELLBORDER="0" CELLSPACING="0" HREF="%(name)s.svg">"""
	% values)

	opts.output.write("""
	<TR>
		<TD BGCOLOR="%(head_color)s" COLSPAN="2" ALIGN="LEFT">template &lt;%(operand)s T&gt;</TD>
	</TR>"""
	% values)


	if inherit_result:
		opts.output.write("""
		<TR>
			<TD BGCOLOR="%(head_color)s" ALIGN="LEFT">struct <B>%(name)s</B></TD>
			<TD BGCOLOR="%(head_color)s" ALIGN="CENTER">:</TD>
		</TR>""" % values)

		opts.output.write("""
		<TR>
			<TD BGCOLOR="%(cell_color)s" ALIGN="RIGHT"><B>%(result)s</B></TD>
			<TD BGCOLOR="%(cell_color)s" ALIGN="LEFT">{ };</TD>
		</TR>""" % values)
	else:
		opts.output.write("""
		<TR>
			<TD BGCOLOR="%(head_color)s" COLSPAN="2" ALIGN="LEFT">struct <B>%(name)s</B></TD>
		</TR>"""
		% values)
		opts.output.write("""
		<TR>
			<TD BGCOLOR="%(cell_color)s" ALIGN="LEFT">{</TD>
			<TD BGCOLOR="%(cell_color)s"></TD>
		</TR>""" % values)

		if result == "Pointer":
			opts.output.write("""
			<TR>
				<TD BGCOLOR="%(cell_color)s"></TD>
				<TD BGCOLOR="%(cell_color)s" ALIGN="RIGHT">const %(result)s value;</TD>
			</TR>""" % values)
		else:
			opts.output.write("""
			<TR>
				<TD BGCOLOR="%(cell_color)s"></TD>
				<TD BGCOLOR="%(cell_color)s" ALIGN="RIGHT">typedef %(result)s type;</TD>
			</TR>""" % values)
	

		opts.output.write("""
		<TR>
			<TD BGCOLOR="%(cell_color)s" ALIGN="LEFT">};</TD>
			<TD BGCOLOR="%(cell_color)s"></TD>
		</TR>""" % values)


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
