#!/bin/bash

#g++ -fPIC -g -c pluginmanager.cpp
#g++ -shared -Wl,-soname,libpluginmanager.so.1 -o libpluginmanager.so pluginmanager.o -ldl
g++ -fPIC -shared -Wl,-soname,libpluginmanager.so.1 -o libpluginmanager.so pluginmanager.cpp -ldl
sudo /sbin/ldconfig `pwd`