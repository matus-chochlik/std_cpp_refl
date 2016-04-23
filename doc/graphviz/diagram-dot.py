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
		'outfile',
		nargs='?',
		type=argparse.FileType('w'),
		default=sys.stdout
	)

	argparser.add_argument(
		'--input',
		type=argparse.FileType('r'),
		action="store"
	)

	argparser.add_argument(
		'--output',
		type=argparse.FileType('w'),
		action="store"
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

	argparser.add_argument(
		"--revision-nodes", "-RN",
		type=bool,
		action="store",
		default=True
	)

	argparser.add_argument(
		"--revision", "-R",
		type=int,
		action="store",
		default=None
	)

	argparser.add_argument(
		"--max-revision", "-M",
		type=int,
		action="store",
		default=100
	)

	return argparser
 
class options:
	def __init__(self):

		useropts = get_argument_parser().parse_args(sys.argv[1:])

		self.type_head_color = "#707070"
		self.abstract_metaobject_head_color = "WHEAT"
		self.concrete_metaobject_head_color = "ORANGE"
		self.trait_head_color = "#8080E0"
		self.operation_head_color = "#E08080"
		self.cell_color = "#D0D0D0"
		self.gen_operations = useropts.generate_operations
		self.gen_traits = useropts.generate_traits
		self.revision_nodes = useropts.revision_nodes
		self.revision = useropts.revision
		self.max_revision = useropts.max_revision if useropts.max_revision else self.revision

		self.traits_rank_same = useropts.trait is None
		self.operations_rank_same = False

		self.metaobject = useropts.metaobject
		self.operation = useropts.operation
		self.trait = useropts.trait
		self.detail = self.metaobject is not None or \
				self.operation is not None or \
				self.trait is not None

		self.rankdir = "BT"
		self.ranksep = 0.9
		self.nodesep = 0.9 if self.detail else 0.3
		self.sep = 0.2 if self.detail else 0.1


		self.xmlinput = useropts.input if useropts.input else useropts.infile
		self.output = useropts.output if useropts.output else useropts.outfile

def iter_last(iterable):
    items = iter(iterable)
    prev = next(items)

    for item in items:
        yield prev, False
        prev = item
    yield prev, True


def in_a_revision(opts, node, revision):
	try: return int(node.attrib["since_revision"]) <= revision
	except KeyError: return True

def in_revision(opts, node):
	return in_a_revision(opts, node, opts.revision)

def findall(opts, parent_node, query):
	return [x for x in parent_node.findall(query) if in_revision(opts, x)]

def find_metaobject(opts, concepts, name):
	mos = findall(opts, concepts, "metaobject[@name='%s']" % name)
	return mos[0] if len(mos) > 0 else None

def find_operation(opts, concepts, name):
	try:
		ops = findall(opts, concepts, "operation[@uname='%s']" % name)
		if len(ops) == 0:
			raise Error()
	except: ops = findall(opts, concepts, "operation[@name='%s']" % name)
	return ops[0] if len(ops) > 0 else None

def find_trait(opts, concepts, name):
	trs = findall(opts, concepts, "trait[@name='%s']" % name)
	return trs[0] if len(trs) > 0 else None

def get_node_uname(concept):
	try: return concept.attrib["uname"]
	except: return concept.attrib["name"]
 
def print_concept_node(opts, concepts, name, definition):

	values = {
		"name" : name,
		"definition": definition,
		"head_color": opts.type_head_color,
		"cell_color": opts.cell_color
	}

	opts.output.write("""
	%(name)s [label=<
	<TABLE BORDER="2" CELLBORDER="0" CELLSPACING="0">"""
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
		"label" : label,
		"head_color": opts.type_head_color,
		"cell_color": opts.cell_color
	}

	opts.output.write("""
	%(name)s [label=<
	<TABLE BORDER="2" CELLBORDER="0" CELLSPACING="0">"""
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

	href = "concept-%s" % name

	if opts.metaobject == name:
		href = "hierarchy"

	metaobject_head_color = opts.concrete_metaobject_head_color

	try:
		if bool(metaobject.attrib["abstract"]):
			metaobject_head_color = opts.abstract_metaobject_head_color
	except: pass

	values = {
		"name" : name,
		"href" : href,
		"revision": opts.revision,
		"typename_T": "typename T" if is_base else "Object T",
		"head_color": metaobject_head_color,
		"cell_color": opts.cell_color
	}

	opts.output.write("""
	%(name)s [label=<
	<TABLE BORDER="2" CELLBORDER="0" CELLSPACING="0" HREF="%(href)s-%(revision)d.svg">"""
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

	requirements += [
		"%s&lt;T&gt;" % x.attrib["concept"]
		for x in findall(opts, metaobject, "generalization")
	]
	requirements += [
		"%s&lt;T&gt;" % x.attrib["name"]
		for x in findall(opts, concepts, "trait[@indicates='%s']" % name)
	]
	requirements += [
		"%s&lt;%s&lt;T&gt;&gt;" % (x.attrib["trait"], x.attrib["operation"])
		for x in findall(opts, metaobject, "constraint")
	]

	if is_base: requirements += ["is_metaobject"]

	for item, is_last in iter_last(requirements):
		values_in = values
		values_in["item"] = item
		values_in["sep"] = ";" if is_last else "&amp;&amp;"
		opts.output.write("""
		<TR>
		<TD BGCOLOR="%(cell_color)s" COLSPAN="2" ALIGN="RIGHT"><B>%(item)s</B></TD>
		<TD BGCOLOR="%(cell_color)s" ALIGN="LEFT">%(sep)s</TD>
		</TR>""" % values)


	opts.output.write("""
	</TABLE>>
	shape="none"
	];\n""")

 
def print_trait_node(opts, concepts, trait):
	name = trait.attrib["name"]

	href = "trait-%s" % name

	if opts.trait == name:
		href = "traits"

	values = {
		"name" : name,
		"href" : href,
		"revision": opts.revision,
		"head_color": opts.trait_head_color,
		"cell_color": opts.cell_color
	}

	opts.output.write("""
	%(name)s [label=<
	<TABLE BORDER="2" CELLBORDER="0" CELLSPACING="0" HREF="%(href)s-%(revision)d.svg">"""
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
	uname = get_node_uname(operation)
	result = operation.attrib["result"]

	href = "operation-%s" % uname

	if opts.operation == uname:
		href = "operations"

	operand = None
	operands = []
	arguments = findall(opts, operation, "argument")

	if len(arguments) == 1:
		argt = arguments[0].attrib["type"]
		if find_metaobject(opts, concepts, argt) is not None:
			if operand is None:
				operand = argt
		operands.append("%s T" % argt)

	else:
		for arg in arguments:
			argt = arg.attrib["type"]
			argn = arg.attrib.get("name", None)
			if find_metaobject(opts, concepts, argt) is not None:
				if operand is None:
					operand = argt
			operands.append("%s %s" % (argt, argn if argn else "T%d" % (len(operands)+1)))

	values = {
		"name" : name,
		"uname" : uname,
		"href" : href,
		"revision": opts.revision,
		"result" : result,
		"operands" : ", ".join(operands),
		"head_color": opts.operation_head_color,
		"cell_color": opts.cell_color,
		"padding": 6
	}

	inherit_result = result in ["IntegralConstant", "BooleanConstant"]

	opts.output.write("""
	%(uname)s [label=<
	<TABLE BORDER="2" CELLBORDER="0" CELLSPACING="0" HREF="%(href)s-%(revision)d.svg">"""
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
			<TD BGCOLOR="%(cell_color)s" ALIGN="CENTER">:</TD>
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
				<TD BGCOLOR="%(cell_color)s" COLSPAN="3" CELLPADDING="%(padding)d" ALIGN="LEFT">static constexpr const char value[N+1];</TD>
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
				<TD BGCOLOR="%(cell_color)s" ALIGN="LEFT" CELLPADDING="%(padding)d">is_class_member_v&lt;T&gt;</TD>
				<TD BGCOLOR="%(cell_color)s">&amp;&amp;</TD>
			</TR>""" % values)

			opts.output.write("""
			<TR>
				<TD BGCOLOR="%(cell_color)s" COLSPAN="2"></TD>
				<TD BGCOLOR="%(cell_color)s" ALIGN="LEFT" CELLPADDING="%(padding)d">!is_static_v&lt;T&gt;</TD>
				<TD BGCOLOR="%(cell_color)s" ALIGN="LEFT">,</TD>
			</TR>""" % values)

			opts.output.write("""
			<TR>
				<TD BGCOLOR="%(cell_color)s" COLSPAN="2"></TD>
				<TD BGCOLOR="%(cell_color)s" ALIGN="LEFT" CELLPADDING="%(padding)d">get_reflected_type_t&lt;get_type_t&lt;T&gt;&gt;</TD>
				<TD BGCOLOR="%(cell_color)s" ALIGN="LEFT"></TD>
			</TR>""" % values)

			opts.output.write("""
			<TR>
				<TD BGCOLOR="%(cell_color)s" COLSPAN="2"></TD>
				<TD BGCOLOR="%(cell_color)s" ALIGN="LEFT" CELLPADDING="%(padding)d">get_reflected_type_t&lt;get_scope_t&lt;T&gt;&gt;::*</TD>
				<TD BGCOLOR="%(cell_color)s" ALIGN="LEFT">,</TD>
			</TR>""" % values)

			opts.output.write("""
			<TR>
				<TD BGCOLOR="%(cell_color)s" COLSPAN="2"></TD>
				<TD BGCOLOR="%(cell_color)s" ALIGN="LEFT" CELLPADDING="%(padding)d">get_reflected_type_t&lt;get_type_t&lt;T&gt;&gt;*</TD>
				<TD BGCOLOR="%(cell_color)s" ALIGN="LEFT"></TD>
			</TR>""" % values)

			opts.output.write("""
			<TR>
				<TD BGCOLOR="%(cell_color)s"></TD>
				<TD BGCOLOR="%(cell_color)s" COLSPAN="3" ALIGN="LEFT">&gt; value;</TD>
			</TR>""" % values)
		elif result == "FunctionPointer":

			opts.output.write("""
			<TR>
				<TD BGCOLOR="%(cell_color)s"></TD>
				<TD BGCOLOR="%(cell_color)s" ALIGN="LEFT">const</TD>
				<TD BGCOLOR="%(cell_color)s" COLSPAN="2" ALIGN="LEFT">conditional_t&lt;</TD>
			</TR>""" % values)

			opts.output.write("""
			<TR>
				<TD BGCOLOR="%(cell_color)s" COLSPAN="2"></TD>
				<TD BGCOLOR="%(cell_color)s" ALIGN="LEFT" CELLPADDING="%(padding)d">is_class_member_v&lt;T&gt;</TD>
				<TD BGCOLOR="%(cell_color)s">&amp;&amp;</TD>
			</TR>""" % values)

			opts.output.write("""
			<TR>
				<TD BGCOLOR="%(cell_color)s" COLSPAN="2"></TD>
				<TD BGCOLOR="%(cell_color)s" ALIGN="LEFT" CELLPADDING="%(padding)d">!is_static_v&lt;T&gt;</TD>
				<TD BGCOLOR="%(cell_color)s" ALIGN="LEFT">,</TD>
			</TR>""" % values)

			opts.output.write("""
			<TR>
				<TD BGCOLOR="%(cell_color)s" COLSPAN="2"></TD>
				<TD BGCOLOR="%(cell_color)s" ALIGN="LEFT" CELLPADDING="%(padding)d">get_reflected_type_t&lt;get_result_type_t&lt;T&gt;&gt;</TD>
				<TD BGCOLOR="%(cell_color)s" ALIGN="LEFT"></TD>
			</TR>""" % values)

			opts.output.write("""
			<TR>
				<TD BGCOLOR="%(cell_color)s" COLSPAN="2"></TD>
				<TD BGCOLOR="%(cell_color)s" ALIGN="LEFT" CELLPADDING="%(padding)d">(get_reflected_type_t&lt;get_scope_t&lt;T&gt;&gt;::*)(P...)</TD>
				<TD BGCOLOR="%(cell_color)s" ALIGN="LEFT">,</TD>
			</TR>""" % values)

			opts.output.write("""
			<TR>
				<TD BGCOLOR="%(cell_color)s" COLSPAN="2"></TD>
				<TD BGCOLOR="%(cell_color)s" ALIGN="LEFT" CELLPADDING="%(padding)d">get_reflected_type_t&lt;get_result_type_t&lt;T&gt;&gt;</TD>
				<TD BGCOLOR="%(cell_color)s" ALIGN="LEFT"></TD>
			</TR>""" % values)

			opts.output.write("""
			<TR>
				<TD BGCOLOR="%(cell_color)s" COLSPAN="2"></TD>
				<TD BGCOLOR="%(cell_color)s" ALIGN="RIGHT" CELLPADDING="%(padding)d">(*)(P...)</TD>
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
				<TD BGCOLOR="%(cell_color)s" COLSPAN="3" CELLPADDING="%(padding)d" ALIGN="LEFT">typedef %(result)s type;</TD>
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


def print_edge(opts, name_from, name_to, attribs = None):
	attr_str = " [%s]" % attribs if attribs is not None else ""
	opts.output.write("""
	%s -> %s%s;"""
	% (name_from, name_to, attr_str))

def print_concept_edge(opts, concept_from, concept_to):
	name_from = get_node_uname(concept_from)
	name_to = get_node_uname(concept_to)

	print_edge(opts, name_from, name_to)

def print_concept_gen_spec_edge(opts, concepts, generalization, specialization):
	gene_name = generalization.attrib["concept"]
	spec_name = specialization.attrib["name"]

	print_edge(opts, spec_name, gene_name)

def do_print_note_node(opts, name, text):

	opts.output.write("""
	edge [constraint="false" style="dotted" arrowhead="none"];""")

	opts.output.write("""
	%(name)s [shape="note" style="filled" fillcolor="%(cell_color)s" label="%(text)s"];""" %
	{"name": name, "text": text, "cell_color": opts.cell_color})

def print_note_node(opts, name, text):
	import textwrap

	wrapper = textwrap.TextWrapper()
	wrapper.width = 22
	text = "\n".join(wrapper.wrap(text))

	do_print_note_node(opts, name, text)


def print_revision_nodes(opts, node):

	name = "revisions"

	if opts.metaobject:
		href = "concept-" + opts.metaobject
	elif opts.operation:
		href = "operation-" + opts.operation
	elif opts.trait:
		href = "trait-" + opts.trait
	elif not opts.gen_operations and not opts.gen_traits:
		href = "hierarchy"
	elif opts.gen_operations and not opts.gen_traits:
		href = "operations"
	elif not opts.gen_operations and opts.gen_traits:
		href = "traits"
	else:
		href = "overview"

	values = {
		"name" : name,
		"href" : href,
		"revision": opts.revision,
		"link_color": "#AAFF00",
		"cell_color": opts.cell_color
	}

	opts.output.write("""
	%(name)s [label=<
	<TABLE BORDER="0" CELLBORDER="0" CELLSPACING="0" CELLPADDING="4">"""
	% values)

	opts.output.write("""
	<TR><TD BGCOLOR="%(cell_color)s">This is revision %(revision)d.</TD></TR>""" % values)

	other_revisions = []
	if opts.revision > 0:
		if node is None or in_a_revision(opts, node, opts.revision-1):
			other_revisions.append(opts.revision-1)
	if opts.revision < opts.max_revision:
		other_revisions.append(opts.revision+1)

	for other_rev in other_revisions:
		values["other_rev"] = other_rev
		opts.output.write("""
		<TR><TD BGCOLOR="%(link_color)s" BORDER="1" HREF="%(href)s-%(other_rev)d.svg">Go to revision %(other_rev)d.</TD></TR>""" %
		values)

	opts.output.write("""
	</TABLE>>
	shape="folder" style="filled" fillcolor="%(cell_color)s"
	];""" % values)

	if node is not None:
		print_edge(opts, name, get_node_uname(node), 'constraint="true" style="dotted" arrowhead="none"')


def print_metaobject(opts, concepts):
	import random

	opts.output.write("""digraph %(metaobject)s {
	overlap=false
	rankdir=%(rankdir)s
	ranksep=%(ranksep)f
	nodesep=%(nodesep)f
	sep=%(sep)f
	fontName="Sans"
	splines=curved
	maxiter=10000000

	edge [penwidth=2.0 arrowsize=2.0 fillcolor="WHITE"];
	node [penwidth=2.0];
	""" % {
		"metaobject": opts.metaobject,
		"rankdir": opts.rankdir,
		"ranksep": opts.ranksep,
		"nodesep": opts.nodesep,
		"sep": opts.sep
	})

	metaobject = find_metaobject(opts, concepts, opts.metaobject)

	print_metaobject_node(opts, concepts, metaobject)

	# Metaobject is-a edges
	opts.output.write("""
	edge [constraint="true" style="solid" fillcolor="WHITE", arrowhead="normal"];""")

	for gen in findall(opts, metaobject, "generalization"):
		generalization = find_metaobject(opts, concepts, gen.attrib["concept"])
		print_metaobject_node(opts, concepts, generalization)
		print_concept_edge(opts, metaobject, generalization)

	for specialization in findall(opts, concepts, "metaobject"):
		if findall(opts, specialization, "generalization[@concept='%s']" % opts.metaobject):
			print_metaobject_node(opts, concepts, specialization)
			print_concept_edge(opts, specialization, metaobject)

	# Trait -> Metaobject (indicates) edges
	opts.output.write("""
	edge [constraint="false" style="dotted" arrowhead="none"];""")

	for trait in findall(opts, concepts, "trait[@indicates='%s']" % opts.metaobject):
		print_trait_node(opts, concepts, trait)
		print_concept_edge(opts, trait, metaobject)

	# Operation -> Result edges
	opts.output.write("""
	edge [constraint="true" style="dashed" arrowhead="vee"];""")

	for operation in findall(opts, concepts, "operation[@result='%s']" % opts.metaobject):
		uname = get_node_uname(operation)
		print_operation_node(opts, concepts, operation)
		print_edge(opts, uname, operation.attrib["result"])
	opts.output.write("\n")

	# Operation -> Element edges
	opts.output.write("""
	edge [constraint="false" style="dotted" arrowhead="diamond"];""")

	for operation in findall(opts, concepts, "operation[@element='%s']" % opts.metaobject):
		uname = get_node_uname(operation)
		print_operation_node(opts, concepts, operation)
		print_edge(opts, operation.attrib["element"], uname)
	opts.output.write("\n")

	# Argument -> Operation edges
	opts.output.write("""
	edge [constraint="true" style="dashed" arrowhead="vee"];""")

	for operation in findall(opts, concepts, "operation"):
		uname = get_node_uname(operation)
		for argument in findall(opts, operation, "argument[@type='%s']" % opts.metaobject):
			print_operation_node(opts, concepts, operation)
			print_edge(opts, argument.attrib["type"], uname)
	opts.output.write("\n")

	# Metaobject ordering edges
	opts.output.write("""
	edge [constraint="true" style="invis"];""")

	prev_mo = None
	for gen in findall(opts, metaobject, "generalization"):
		if prev_mo is not None: 
			print_concept_edge(opts, generalization, prev_mo)
		prev_mo = generalization if random.random() < 0.6 else None

	prev_mo = None
	for specialization in findall(opts, concepts, "metaobject"):
		if findall(opts, specialization, "generalization[@concept='%s']" % opts.metaobject):
			if prev_mo is not None:
				print_concept_edge(opts, specialization, prev_mo)
			prev_mo = specialization if random.random() < 0.55 else None

	prev_op = None
	for operation in findall(opts, concepts, "operation"):
		is_relevant = operation.attrib["result"] == opts.metaobject 
		is_relevant |= len(findall(opts, operation, "argument[@type='%s']" % opts.metaobject))>0
		if is_relevant:
			if prev_op is not None:
				print_concept_edge(opts, operation, prev_op)
				
			prev_op = operation if random.random() < 0.6 else None
			

	# Note
	try: desc = metaobject.attrib["brief"]
	except: desc = "Reflects %s." % metaobject.attrib["reflects"]
	print_note_node(opts, "description", desc)
	print_edge(opts, opts.metaobject, "description")

	# Revisions
	if opts.revision_nodes:
		print_revision_nodes(opts, metaobject)

	opts.output.write("""}
	""")


def print_operation(opts, concepts):
	import re

	opts.output.write("""digraph %(operation)s {
	overlap=false
	rankdir=%(rankdir)s
	ranksep=%(ranksep)f
	nodesep=%(nodesep)f
	sep=%(sep)f
	fontName="Sans"
	splines=curved
	maxiter=10000000

	edge [penwidth=2.0 arrowsize=2.0 fillcolor="WHITE"];
	node [penwidth=2.0];
	""" % {
		"operation": opts.operation,
		"rankdir": opts.rankdir,
		"ranksep": opts.ranksep,
		"nodesep": opts.nodesep,
		"sep": opts.sep
	})

	operation = find_operation(opts, concepts, opts.operation)
	uname = get_node_uname(operation)
	print_operation_node(opts, concepts, operation)

	result = find_metaobject(opts, concepts, operation.attrib["result"])
	try: element = find_metaobject(opts, concepts, operation.attrib["element"])
	except: element = None

	if result is not None:
		print_metaobject_node(opts, concepts, result)

		# Operation -> Result edges
		opts.output.write("""
		edge [constraint="true" style="dashed" arrowhead="vee"];""")
		print_concept_edge(opts, operation, result)

		# Result -> Element
		if element is not None:
			print_metaobject_node(opts, concepts, element)
			opts.output.write("""
			edge [constraint="false" arrowhead="none" arrowtail="diamond" dir="both"];""")
			print_concept_edge(opts, result, element)
			opts.output.write("""
			edge [style="dotted" dir="forward"];""")
			desc = "All elements must be Meta-%s(s)" % element.attrib["name"]
			print_note_node(opts, "element_desc", desc)
			print_edge(opts, result.attrib["name"], "element_desc")
			print_edge(opts, element.attrib["name"], "element_desc")

	# Argument -> Operation edges
	opts.output.write("""
	edge [constraint="true" style="dashed" arrowhead="vee"];""")

	reflected = None
	for argument in findall(opts, operation, "argument"):
		argt = find_metaobject(opts, concepts, argument.attrib["type"])
		if argt is not None:
			operand = argt
			reflected = operand.attrib["reflects"]

			print_metaobject_node(opts, concepts, operand)
			print_edge(opts, operand.attrib["name"], uname)
	opts.output.write("\n")

	# Note
	desc = operation.attrib["brief"]
	desc = re.sub(r"\$\(([^)]+)\)", r"%(\1)s", desc)
	desc = desc % {
		"result": "Meta-%s" % result.attrib["name"] if result is not None else "-",
		"element": "Meta-%s" % element.attrib["name"] if element is not None else "-",
		"elements": "Meta-%s(s)" % element.attrib["name"] if element is not None else "-",
		"operand": "Meta-%s" % operand.attrib["name"] if operand is not None else "-",
		"reflected": reflected if reflected is not None else "-"
	}
	print_note_node(opts, "description", desc)
	print_edge(opts, uname, "description")

	# Revisions
	if opts.revision_nodes:
		print_revision_nodes(opts, operation)

	opts.output.write("""}
	""")


def print_trait(opts, concepts):
	opts.output.write("""digraph %(trait)s {
	overlap=false
	rankdir=%(rankdir)s
	ranksep=%(ranksep)f
	nodesep=%(nodesep)f
	sep=%(sep)f
	fontName="Sans"
	splines=curved
	maxiter=10000000

	edge [penwidth=2.0 arrowsize=2.0 fillcolor="WHITE"];
	node [penwidth=2.0];
	""" % {
		"trait": opts.trait,
		"rankdir": opts.rankdir,
		"ranksep": opts.ranksep,
		"nodesep": opts.nodesep,
		"sep": opts.sep
	})

	print_concept_node(opts, concepts, "BooleanConstant", "integral_constant&lt;bool, ...&gt;")

	trait = find_trait(opts, concepts, opts.trait)
	print_trait_node(opts, concepts, trait)

	indicates = trait.attrib["indicates"]
	print_metaobject_node(opts, concepts, find_metaobject(opts, concepts, indicates))

	# Trait -> Metaobject (indicates) edges
	opts.output.write("""
	edge [constraint="true" style="dotted" arrowhead="none"];""")

	print_edge(opts, indicates, opts.trait)

	# Trait -> result
	opts.output.write("""
	edge [constraint="true" style="dashed" arrowhead="vee"];""")

	print_edge(opts, opts.trait, "BooleanConstant")

	# Note
	desc = "Indicates that a metaobject is a %s." % indicates
	print_note_node(opts, "description", desc)
	print_edge(opts, opts.trait, "description")

	# Revisions
	if opts.revision_nodes:
		print_revision_nodes(opts, trait)

	opts.output.write("""}
	""")


def print_overview(opts, concepts):
	import random

	opts.output.write("""digraph Overview {
	overlap=false
	rankdir=%(rankdir)s
	ranksep=%(ranksep)f
	nodesep=%(nodesep)f
	fontName="Sans"
	splines=true
	maxiter=10000000

	edge [penwidth=2.0 arrowsize=2.0 fillcolor="WHITE"];
	node [penwidth=2.0];
	""" % {
		"rankdir": opts.rankdir,
		"ranksep": opts.ranksep,
		"nodesep": opts.nodesep,
		"sep": opts.sep
	})

	# Other concepts
	if opts.gen_traits or opts.gen_operations:
		print_concept_node(opts, concepts, "BooleanConstant", "integral_constant&lt;bool, ...&gt;")
	if opts.gen_operations:
		print_concept_node(opts, concepts, "IntegralConstant", "integral_constant&lt;size_t, ...&gt;")
		print_concept_node(opts, concepts, "SourceLocation", "source_location")
		print_plain_type_node(opts, concepts, "StringConstant", "StringConstant")
		print_plain_type_node(opts, concepts, "Pointer", "pointer")
		print_plain_type_node(opts, concepts, "FunctionPointer", "function-pointer")
		print_plain_type_node(opts, concepts, "OriginalType", "original-type")
		print_plain_type_node(opts, concepts, "size_t", "size_t")

	# Metaobject nodes 
	for metaobject in findall(opts, concepts, "metaobject"):
		if in_revision(opts, metaobject):
			print_metaobject_node(opts, concepts, metaobject)


	# Trait nodes
	if opts.gen_traits:
		for trait in findall(opts, concepts, "trait"):
			print_trait_node(opts, concepts, trait)

	# Operation nodes
	if opts.gen_operations:
		for operation in findall(opts, concepts, "operation"):
			print_operation_node(opts, concepts, operation)

	# Trait -> Metaobject (indicates) edges
	opts.output.write("""
	edge [constraint="true" style="dotted" arrowhead="none"];""")

	if opts.gen_traits:
		for trait in findall(opts, concepts, "trait"):
			print_edge(opts, trait.attrib["name"], trait.attrib["indicates"])
		opts.output.write("\n")

	# Trait -> BooleanConstant (result) edges
	opts.output.write("""
	edge [constraint="true" style="dashed" arrowhead="vee"];""")

	if opts.gen_traits:
		for trait in findall(opts, concepts, "trait"):
			print_edge(opts, trait.attrib["name"], "BooleanConstant")
		opts.output.write("\n")

	# Operation -> Result edges
	opts.output.write("""
	edge [constraint="true" style="dashed" arrowhead="vee"];""")

	if opts.gen_operations:
		for operation in findall(opts, concepts, "operation"):
			uname = get_node_uname(operation)
			print_edge(opts, uname, operation.attrib["result"])
		opts.output.write("\n")

	# Argument -> Operation edges
	opts.output.write("""
	edge [constraint="true" style="dashed" arrowhead="vee"];""")

	if opts.gen_operations:
		for operation in findall(opts, concepts, "operation"):
			uname = get_node_uname(operation)
			for argument in findall(opts, operation, "argument"):
				print_edge(opts, argument.attrib["type"], uname)
		opts.output.write("\n")

	# Metaobject is-a edges
	opts.output.write("""
	edge [constraint="true" style="solid" arrowhead="normal"];""")

	for derived in findall(opts, concepts, "metaobject"):
		for base in findall(opts, derived, "generalization"):
			print_concept_gen_spec_edge(opts, concepts, base, derived)
	opts.output.write("\n")

	# Metaobject ordering edges
	opts.output.write("""
	edge [style="invis"];""")

	for metaobject in findall(opts, concepts, "metaobject"):
		for prev_mo in findall(opts, metaobject, "order_after"):
			print_concept_gen_spec_edge(opts, concepts, prev_mo, metaobject)
	opts.output.write("\n")
			
	
	prev_mo = None
	for metaobject in findall(opts, concepts, "metaobject"):
		if prev_mo is not None:
			coef = len(findall(opts, metaobject, "generalization"))/3.0
			if random.random() < coef:
				print_concept_edge(opts, metaobject, prev_mo)
		prev_mo = metaobject

	# Revisions
	if opts.revision_nodes:
		print_revision_nodes(opts, find_metaobject(opts, concepts, "Object"))

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
		print_trait(opts, concepts)
	else: print_overview(opts, concepts)


#pass run the main function
if __name__ == "__main__": main()
