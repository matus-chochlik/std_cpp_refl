/**
 *  @file plugin.hpp
 *  @brief The main source file of the plugin shader object
 *
 *  @author Matus Chochlik
 *
 *  Copyright 2011-2012 Matus Chochlik. Distributed under the Boost
 *  Software License, Version 1.0. (See accompanying file
 *  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#include <stdlib.h>
#include <gmp.h>
#include <cstdlib>
 
extern "C"
{
#include "gcc-plugin.h"
#include "plugin-version.h"
 
#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tree.h"
#include "intl.h"
 
#include <tm.h>

#include "cp/cp-tree.h"
 
#include "diagnostic.h"

#include "c-family/c-common.h"
#include "c-family/c-pragma.h"
}

#include <cassert>

class static_reflection_plugin
{
private:
	static static_reflection_plugin& self(void* raw_ptr)
	{
		assert(raw_ptr);
		return *((static_reflection_plugin*)raw_ptr);
	}
public:
	void finish(void)
	{
		// TODO: remove this
		::warning(0, G_("Finish"));	
	}

	static void on_finish(void* gcc_data, void* raw_ptr)
	{
		self(raw_ptr).finish();
	}

	void start_unit(void)
	{
		// TODO: remove this
		::warning(0, G_("Starting translation of unit"));	
	}

	static void on_start_unit(void* gcc_data, void* raw_ptr)
	{
		self(raw_ptr).start_unit();
	}

	void finish_unit(void)
	{
		// TODO: remove this
		::warning(0, G_("Finishing translation of unit"));	
	}

	static void on_finish_unit(void* gcc_data, void* raw_ptr)
	{
		self(raw_ptr).finish_unit();
	}

	void pre_genericize(void)
	{
		// TODO: remove this
		::warning(0, G_("Pre-genericize"));	
	}

	static void on_pre_genericize(void* gcc_data, void* raw_ptr)
	{
		self(raw_ptr).pre_genericize();
	}

} the_plugin;

// The plugin is distributed under the very permissive
// Boost Software License which is according to
// http://www.gnu.org/licenses/license-list.html
// compatible with GPL.
int plugin_is_GPL_compatible;

// the main entry point of the plugin
extern "C" int plugin_init (
	::plugin_name_args* plugin_args,
	::plugin_gcc_version* plugin_version
)
{
	assert(plugin_args);
	assert(plugin_version);

	const char* plugin_name = plugin_args->base_name;

	// check the version first
	if (!::plugin_default_version_check (plugin_version, &gcc_version))
	{
		::error(G_("Incompatible version of GCC for %qs!"), plugin_name);
		return 1;
	}

	// provide information about this plugin
	struct ::plugin_info info = {
		"0.1",
		"Plugin enabling static reflection for C++"
	};
	::register_callback(plugin_name, PLUGIN_INFO, NULL, &info);

	//
	// register the callbacks
	//
	::register_callback(
		plugin_name,
		PLUGIN_FINISH,
		&static_reflection_plugin::on_finish,
		&the_plugin
	);
	::register_callback(
		plugin_name,
		PLUGIN_START_UNIT,
		&static_reflection_plugin::on_start_unit,
		&the_plugin
	);
	::register_callback(
		plugin_name,
		PLUGIN_FINISH_UNIT,
		&static_reflection_plugin::on_finish_unit,
		&the_plugin
	);
	::register_callback(
		plugin_name,
		PLUGIN_PRE_GENERICIZE,
		&static_reflection_plugin::on_pre_genericize,
		&the_plugin
	);

	return 0;
}

