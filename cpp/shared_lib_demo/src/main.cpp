#include <iostream>
#include <string>
#include <list>

#include <pluginmanager.h>

#include "../plugins/shape.h"

int main() {
	PluginManager plugin_manager;
	plugin_manager.load_libraries();
	
	std::list<std::string> loaded_plugin_names = plugin_manager.get_loaded_plugin_names();
	
	if (loaded_plugin_names.empty()) {
		std::cout << "There are no loaded plugins." << std::endl;
		return 0;
	}
	
	std::cout << "The currently loaded plugins are: \n";
	for (std::list<std::string>::iterator it = loaded_plugin_names.begin();
		 it != loaded_plugin_names.end(); it++) {
		std::cout << *it << std::endl << std::endl;
	}
	
	std::string shape;
	char fill;
	
	std::cout << "Choose a shape to draw: "; std::cin >> shape;
	
	Shape *plugin = plugin_manager.get_plugin(shape);
	if (!plugin) {
		std::cout << "plugin is not identified" << std::endl;
		return 1;
	}
	
	std::cout << "Choose a filling for the shape: "; std::cin >> fill;
	std::cout << std::endl;
	
	plugin->set_fill(fill);
	plugin->draw();
	
	return 0;
}
