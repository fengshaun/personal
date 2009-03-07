#ifndef PLUGINMANAGER_H
#define PLUGINMANAGER_H

#include <map>
#include <string>
#include <list>

#include "../plugins/shape.h"

class PluginManager
{
	public:
		PluginManager();
		~PluginManager();
		
		void load_libraries();
		Shape *get_plugin(std::string name);
		std::list<std::string> get_loaded_plugin_names();
		
	protected:
		bool load_plugin(std::string file_path);
		
	private:
		std::map<std::string, Shape *> m_plugin_map;
};

#endif // PLUGINMANAGER_H