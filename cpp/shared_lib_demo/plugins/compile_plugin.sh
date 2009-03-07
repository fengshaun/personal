#!/bin/bash

NAME=$1

g++ -fPIC -g -c -Wall $NAME.cpp
g++ -shared -Wl,-soname,lib$NAME.so.1 -o lib$NAME.so $NAME.o
sudo /sbin/ldconfig `pwd`