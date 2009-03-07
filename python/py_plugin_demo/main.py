#!/usr/bin/python

import os
import imp
import sys

plugins = {}

plugin_path = os.path.join(os.path.dirname(imp.find_module('main')[1]), 'plugins/')
plugin_files = [fname[:-3] for fname in os.listdir(plugin_path) if fname.endswith('.py')]

if not plugin_path in sys.path:
    sys.path.append(plugin_path)

imported_modules = [__import__(f) for f in plugin_files]

for mod in imported_modules:
    mod.register(plugins)

for i in plugins.keys():
    print i

a = raw_input('What shape do you want to draw? ')

while a in plugins.keys():
    plugins[a].draw()
    a = raw_input('What shape do you want to draw? ')

print 'finished...'
