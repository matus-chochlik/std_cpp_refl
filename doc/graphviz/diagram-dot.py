#!/usr/bin/python
# coding: UTF-8

import sys

def get_argument_parser():
	import argparse

	def BoolArgValue(arg):
		if(arg in ("True", "true", "T", "Yes", "yes", "Y", "On", "1")):
			return True
		elif(arg in ("False", "false", "F", "No", "no", "N", "Off", "0")):
			return False
		else:
			msg = "'%s' is not a valid boolean value" % str(arg)
			raise argparse.ArgumentTypeError(msg)

	argparser = argparse.ArgumentParser(
		prog="overview-dot"
	)

	argparser.add_argument(
		'infile',
		nargs='?',
		type=argparse.FileType('r'),
		default=sys.stdin
	)

	argparser.add_argument(
		"--generate-operations", "-go",
		type=BoolArgValue,
		choices=[True, False],
		action="store",
		default=True,
	)

	argparser.add_argument(
		"--generate-traits", "-gt",
		type=BoolArgValue,
		choices=[True, False],
		action="store",
		default=True,
	)

	mode_args = argparser.add_mutually_exclusive_group()

	mode_args.add_argument(
		"--metaobject", "-mo",
		type=str,
		action="store",
		default=None
	)

	mode_args.add_argument(
		"--trait", "-tr",
		type=str,
		action="store",
		default=None
	)

	mode_args.add_argument(
		"--operation", "-op",
		type=str,
		action="store",
		default=None
	)

	return argparser
 
class options:
	def __init__(self):

		useropts = get_argument_parser().parse_args(sys.argv[1:])

		self.type_head_color = "#707070"
		self.metaobject_head_color = "ORANGE"
		self.trait_head_color = "#8080E0"
		self.operation_head_color = "#E08080"
		self.cell_color = "#D0D0D0"
		self.gen_operations = useropts.generate_operations
		self.gen_traits = useropts.generate_traits

		self.traits_rank_same = True
		self.operations_rank_same = False

		self.rankdir = "BT"
		self.ranksep = 0.9

		self.metaobject = useropts.metaobject
		self.operation = useropts.operation
		self.trait = useropts.trait
		self.xmlinput = useropts.infile
		self.output = sys.stdout

def iter_last(iterable):
    items = iter(iterable)
    prev = next(items)

    for item in items:
        yield prev, False
        prev = item
    yield prev, True

def find_metaobject(concepts, name):
	mos = concepts.findall("metaobject[@name='%s']" % name)
	return mos[0] if len(mos) > 0 else None

def find_operation(concepts, name):
	ops = concepts.findall("operation[@name='%s']" % name)
	return ops[0] if len(ops) > 0 else None
 
def print_concept_node(opts, concepts, name, definition):

	values = {
		"name" : name,
		"href" : name,
		"definition": definition,
		"head_color": opts.type_head_color,
		"cell_color": opts.cell_color
	}

	opts.output.write("""
	%(name)s [label=<
	<TABLE BORDER="2" CELLBORDER="0" CELLSPACING="0" HREF="%(href)s.svg">"""
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

 
def print_plain_type_node(opts, concepts, name, label):
	values = {
		"name" : name,
		"href" : name,
		"label" : label,
		"head_color": opts.type_head_color,
		"cell_color": opts.cell_color
	}

	opts.output.write("""
	%(name)s [label=<
	<TABLE BORDER="2" CELLBORDER="0" CELLSPACING="0" HREF="%(href)s.svg">"""
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
		"href" : name,
		"typename_T": "typename T" if is_base else "Object T",
		"head_color": opts.metaobject_head_color,
		"cell_color": opts.cell_color
	}

	opts.output.write("""
	%(name)s [label=<
	<TABLE BORDER="2" CELLBORDER="0" CELLSPACING="0" HREF="%(href).svg">"""
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
		"href" : name,
		"head_color": opts.trait_head_color,
		"cell_color": opts.cell_color
	}

	opts.output.write("""
	%(name)s [label=<
	<TABLE BORDER="2" CELLBORDER="0" CELLSPACING="0" HREF="%(href)s.svg">"""
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

	if opts.traits_rank_same:
		opts.output.write("""
		{rank=same; %s, %s};\n"""
		% (trait.attrib["indicates"], name))

 
def print_operation_node(opts, concepts, operation):
	name = operation.attrib["name"]
	result = operation.attrib["result"]

	operand = None
	operands = []
	arguments = operation.findall("argument")

	if len(arguments) == 1:
		argt = arguments[0].attrib["type"]
		if len(concepts.findall("metaobject[@name='%s']" % argt)) > 0:
			if operand is None:
				operand = argt
		operands.append("%s T" % argt)

	else:
		for arg in arguments:
			argt = arg.attrib["type"]
			argn = arg.attrib.get("name", None)
			if len(concepts.findall("metaobject[@name='%s']" % argt)) > 0:
				if operand is None:
					operand = argt
			operands.append("%s %s" % (argt, argn if argn else "T%d" % (len(operands)+1)))

	values = {
		"name" : name,
		"href" : name,
		"result" : result,
		"operands" : ", ".join(operands),
		"head_color": opts.operation_head_color,
		"cell_color": opts.cell_color
	}

	inherit_result = result in ["IntegralConstant", "BooleanConstant"]

	opts.output.write("""
	%(name)s [label=<
	<TABLE BORDER="2" CELLBORDER="0" CELLSPACING="0" HREF="%(href)s.svg">"""
	% values)

	opts.output.write("""
	<TR>
		<TD BGCOLOR="%(head_color)s" COLSPAN="4" ALIGN="LEFT">template &lt;%(operands)s&gt;</TD>
	</TR>"""
	% values)


	if inherit_result:
		opts.output.write("""
		<TR>
			<TD BGCOLOR="%(head_color)s" COLSPAN="3" ALIGN="LEFT">struct <B>%(name)s</B></TD>
			<TD BGCOLOR="%(head_color)s" ALIGN="CENTER">:</TD>
		</TR>""" % values)

		opts.output.write("""
		<TR>
			<TD BGCOLOR="%(cell_color)s" COLSPAN="3" ALIGN="RIGHT"><B>%(result)s</B></TD>
			<TD BGCOLOR="%(cell_color)s" ALIGN="LEFT">{ };</TD>
		</TR>""" % values)
	else:
		opts.output.write("""
		<TR>
			<TD BGCOLOR="%(head_color)s" COLSPAN="4" ALIGN="LEFT">struct <B>%(name)s</B></TD>
		</TR>"""
		% values)
		opts.output.write("""
		<TR>
			<TD BGCOLOR="%(cell_color)s" ALIGN="LEFT">{</TD>
			<TD BGCOLOR="%(cell_color)s" COLSPAN="3"></TD>
		</TR>""" % values)

		if result == "StringConstant":
			opts.output.write("""
			<TR>
				<TD BGCOLOR="%(cell_color)s"></TD>
				<TD BGCOLOR="%(cell_color)s" COLSPAN="3" ALIGN="LEFT">static constexpr const char value[N+1];</TD>
			</TR>""" % values)
		elif result == "Pointer":

			opts.output.write("""
			<TR>
				<TD BGCOLOR="%(cell_color)s"></TD>
				<TD BGCOLOR="%(cell_color)s" ALIGN="LEFT">const</TD>
				<TD BGCOLOR="%(cell_color)s" COLSPAN="2" ALIGN="LEFT">conditional_t&lt;</TD>
			</TR>""" % values)

			opts.output.write("""
			<TR>
				<TD BGCOLOR="%(cell_color)s" COLSPAN="2"></TD>
				<TD BGCOLOR="%(cell_color)s" ALIGN="LEFT">is_class_member_v&lt;T&gt;</TD>
				<TD BGCOLOR="%(cell_color)s">&amp;&amp;</TD>
			</TR>""" % values)

			opts.output.write("""
			<TR>
				<TD BGCOLOR="%(cell_color)s" COLSPAN="2"></TD>
				<TD BGCOLOR="%(cell_color)s" ALIGN="LEFT">!is_static_v&lt;T&gt;</TD>
				<TD BGCOLOR="%(cell_color)s" ALIGN="LEFT">,</TD>
			</TR>""" % values)

			opts.output.write("""
			<TR>
				<TD BGCOLOR="%(cell_color)s" COLSPAN="2"></TD>
				<TD BGCOLOR="%(cell_color)s" ALIGN="LEFT">get_reflected_type_t&lt;get_type_t&lt;T&gt;&gt;</TD>
				<TD BGCOLOR="%(cell_color)s" ALIGN="LEFT"></TD>
			</TR>""" % values)

			opts.output.write("""
			<TR>
				<TD BGCOLOR="%(cell_color)s" COLSPAN="2"></TD>
				<TD BGCOLOR="%(cell_color)s" ALIGN="LEFT">get_reflected_type_t&lt;get_scope_t&lt;T&gt;&gt;::*</TD>
				<TD BGCOLOR="%(cell_color)s" ALIGN="LEFT">,</TD>
			</TR>""" % values)

			opts.output.write("""
			<TR>
				<TD BGCOLOR="%(cell_color)s" COLSPAN="2"></TD>
				<TD BGCOLOR="%(cell_color)s" ALIGN="LEFT">get_reflected_type_t&lt;get_type_t&lt;T&gt;&gt;*</TD>
				<TD BGCOLOR="%(cell_color)s" ALIGN="LEFT"></TD>
			</TR>""" % values)

			opts.output.write("""
			<TR>
				<TD BGCOLOR="%(cell_color)s"></TD>
				<TD BGCOLOR="%(cell_color)s" COLSPAN="3" ALIGN="LEFT">&gt; value;</TD>
			</TR>""" % values)
		else:
			opts.output.write("""
			<TR>
				<TD BGCOLOR="%(cell_color)s"></TD>
				<TD BGCOLOR="%(cell_color)s" COLSPAN="3" ALIGN="LEFT">typedef %(result)s type;</TD>
			</TR>""" % values)
	

		opts.output.write("""
		<TR>
			<TD BGCOLOR="%(cell_color)s" ALIGN="LEFT">};</TD>
			<TD BGCOLOR="%(cell_color)s" COLSPAN="3"></TD>
		</TR>""" % values)


	opts.output.write("""
	</TABLE>>
	shape="none"
	];""")

	if opts.operations_rank_same:
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

def print_metaobject(opts, concepts):
	opts.output.write("""digraph %(metaobject)s {
	overlap=false
	rankdir=%(rankdir)s
	ranksep=%(ranksep)f
	fontName="Sans"
	maxiter=1000000

	edge [penwidth=2.0 arrowsize=2.0];
	node [penwidth=2.0];
	""" % {
		"metaobject": opts.metaobject,
		"rankdir": opts.rankdir,
		"ranksep": opts.ranksep
	})

	metaobject = find_metaobject(concepts, opts.metaobject)

	print_metaobject_node(opts, concepts, metaobject)

	# Metaobject is-a edges
	opts.output.write("""
	edge [constraint="true" style="solid" fillcolor="WHITE", arrowhead="normal"];""")

	for gen in metaobject.findall("generalization"):
		generalization = find_metaobject(concepts, gen.attrib["concept"])
		print_metaobject_node(opts, concepts, generalization)
		print_concept_edge(opts, metaobject, generalization)

	for specialization in concepts.findall("metaobject"):
		if specialization.findall("generalization[@concept='%s']" % opts.metaobject):
			print_metaobject_node(opts, concepts, specialization)
			print_concept_edge(opts, specialization, metaobject)

	# Trait -> Metaobject (indicates) edges
	opts.output.write("""
	edge [constraint="false" style="dotted" arrowhead="none"];""")

	for trait in concepts.findall("trait[@indicates='%s']" % opts.metaobject):
		print_trait_node(opts, concepts, trait)
		print_concept_edge(opts, trait, metaobject)

	# Operation -> Result edges
	opts.output.write("""
	edge [constraint="true" style="dashed" arrowhead="vee"];""")

	for operation in concepts.findall("operation[@result='%s']" % opts.metaobject):
		print_operation_node(opts, concepts, operation)
		print_edge(opts, operation.attrib["name"], operation.attrib["result"])
	opts.output.write("\n")

	# Argument -> Operation edges
	opts.output.write("""
	edge [constraint="true" style="dashed" arrowhead="vee"];""")

	if opts.gen_operations:
		for operation in concepts.findall("operation"):
			for argument in operation.findall("argument[@type='%s']" % opts.metaobject):
				print_operation_node(opts, concepts, operation)
				print_edge(opts, argument.attrib["type"], operation.attrib["name"])
		opts.output.write("\n")

	# Metaobject ordering edges
	opts.output.write("""
	edge [constraint="true" style="invis"];""")

	prev_mo = None
	for gen in metaobject.findall("generalization"):
		if prev_mo:
			print_concept_edge(opts, generalization, prev_mo)
		prev_mo = generalization

	prev_mo = None
	for specialization in concepts.findall("metaobject"):
		if specialization.findall("generalization[@concept='%s']" % opts.metaobject):
			if prev_mo:
				print_concept_edge(opts, specialization, prev_mo)
			prev_mo = specialization 

	opts.output.write("""}
	""")


def print_operation(opts, concepts):
	opts.output.write("""digraph %(operation)s {
	overlap=false
	rankdir=%(rankdir)s
	ranksep=%(ranksep)f
	fontName="Sans"
	maxiter=1000000

	edge [penwidth=2.0 arrowsize=2.0];
	node [penwidth=2.0];
	""" % {
		"operation": opts.operation,
		"rankdir": opts.rankdir,
		"ranksep": opts.ranksep
	})

	operation = find_operation(concepts, opts.operation)
	print_operation_node(opts, concepts, operation)

	result = find_metaobject(concepts, operation.attrib["result"])
	if result is not None:
		print_metaobject_node(opts, concepts, result)

		# Operation -> Result edges
		opts.output.write("""
		edge [constraint="true" style="dashed" arrowhead="vee"];""")
		print_concept_edge(opts, operation, result)

	# Argument -> Operation edges
	opts.output.write("""
	edge [constraint="true" style="dashed" arrowhead="vee"];""")

	for argument in operation.findall("argument"):
		operand = find_metaobject(concepts, argument.attrib["type"])
		if operand is not None:
			print_metaobject_node(opts, concepts, operand)
			print_concept_edge(opts, operand, operation)
	opts.output.write("\n")

	opts.output.write("""}
	""")


def print_overview(opts, concepts):
	import random

	opts.output.write("""digraph Overview {
	overlap=false
	rankdir=%(rankdir)s
	ranksep=%(ranksep)f
	fontName="Sans"
	maxiter=1000000

	edge [penwidth=2.0 arrowsize=2.0];
	node [penwidth=2.0];
	""" % {
		"rankdir": opts.rankdir,
		"ranksep": opts.ranksep
	})

	# Other concepts
	if opts.gen_traits or opts.gen_operations:
		print_concept_node(opts, concepts, "BooleanConstant", "integral_constant&lt;bool, ...&gt;")
	if opts.gen_operations:
		print_concept_node(opts, concepts, "IntegralConstant", "integral_constant&lt;size_t, ...&gt;")
		print_concept_node(opts, concepts, "SourceLocation", "source_location")
		print_plain_type_node(opts, concepts, "StringConstant", "StringConstant")
		print_plain_type_node(opts, concepts, "Pointer", "pointer")
		print_plain_type_node(opts, concepts, "OriginalType", "original-type")
		print_plain_type_node(opts, concepts, "size_t", "size_t")

	# Metaobject nodes 
	for metaobject in concepts.findall("metaobject"):
		print_metaobject_node(opts, concepts, metaobject)


	# Trait nodes
	if opts.gen_traits:
		for trait in concepts.findall("trait"):
			print_trait_node(opts, concepts, trait)

	# Operation nodes
	if opts.gen_operations:
		for operation in concepts.findall("operation"):
			print_operation_node(opts, concepts, operation)

	# Trait -> Metaobject (indicates) edges
	opts.output.write("""
	edge [constraint="true" style="dotted" arrowhead="none"];""")

	if opts.gen_traits:
		for trait in concepts.findall("trait"):
			print_edge(opts, trait.attrib["name"], trait.attrib["indicates"])
		opts.output.write("\n")

	# Trait -> BooleanConstant (result) edges
	opts.output.write("""
	edge [constraint="true" style="dashed" arrowhead="vee"];""")

	if opts.gen_traits:
		for trait in concepts.findall("trait"):
			print_edge(opts, trait.attrib["name"], "BooleanConstant")
		opts.output.write("\n")

	# Operation -> Result edges
	opts.output.write("""
	edge [constraint="true" style="dashed" arrowhead="vee"];""")

	if opts.gen_operations:
		for operation in concepts.findall("operation"):
			print_edge(opts, operation.attrib["name"], operation.attrib["result"])
		opts.output.write("\n")

	# Argument -> Operation edges
	opts.output.write("""
	edge [constraint="true" style="dashed" arrowhead="vee"];""")

	if opts.gen_operations:
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

	opts.output.write("""}
	""")


def main():
	import xml.etree.ElementTree as XET

	opts = options();
	concepts = XET.parse(opts.xmlinput).getroot()

	if opts.metaobject:
		print_metaobject(opts, concepts)
	elif opts.operation:
		print_operation(opts, concepts)
	elif opts.trait:
		pass # TODO
	else: print_overview(opts, concepts)


#pass run the main function
if __name__ == "__main__": main()
