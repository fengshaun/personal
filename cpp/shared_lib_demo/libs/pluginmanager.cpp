#include "pluginmanager.h"

#include <iostream>
#include <dlfcn.h>

#include <boost/filesystem.hpp>
namespace fs = boost::filesystem;

PluginManager::PluginManager() {
	m_plugin_map.clear();
}

PluginManager::~PluginManager() {}

Shape *PluginManager::get_plugin(std::string name) {
	return m_plugin_map[name];
}

std::list<std::string> PluginManager::get_loaded_plugin_names() {
	std::list<std::string> list;
	for (std::map<std::string, Shape *>::iterator it = m_plugin_map.begin();
		 it != m_plugin_map.end(); it++) {
		list.push_back(it->first);
	}
	
	return list;
}

void PluginManager::load_libraries() {
	fs::path path("/home/armin/src/shared_lib_demo/plugins/");
	
	if (!fs::exists(path) || !fs::is_directory(path)) {
		std::cerr << path.leaf() << "does not exist or "
				  << "is not a directory." << std::endl;
		return;
	}
	
	fs::directory_iterator dir_it(path), dir_it_end;
	for (dir_it; dir_it != dir_it_end; dir_it++) {
		if (fs::is_symlink(*dir_it)) {
			//std::cerr << (*dir_it).leaf() << " is a symlink\n";
			std::string file_path = (*dir_it).leaf();
			
			if (!load_plugin(file_path)) {
				return;
			}
		}
	}
}

bool PluginManager::load_plugin(std::string file_path) {
	file_path = "/home/armin/src/shared_lib_demo/plugins/" + file_path;
	void *plugin_handle = dlopen(file_path.c_str(), RTLD_LAZY);
	
	if (!plugin_handle) {
		std::cerr << "Cannot open library: " << dlerror() << std::endl;
		return false;
	}
	
	dlerror();
	
	typedef Shape *(*creator_func_t)();
	creator_func_t creator_func = (creator_func_t) dlsym(plugin_handle, "create_t");
	const char *error = dlerror();
	
	if (error) {
		std::cerr << "Cannot load symbol 'create_t': " << error << '\n'
				  << "make sure it's present." << std::endl;
		return false;
	}
	
	Shape *shape = creator_func();
	
	if (!shape) {
		std::cerr << "Shape could not be created." << std::endl;
		return false;
	}
	
	m_plugin_map[shape->name()] = shape;
	//std::cout << m_plugin_map[shape->name()]->name() << " is loaded" << std::endl;
	
	// We should not close it!
	//dlclose(plugin_handle);
	return true;
}