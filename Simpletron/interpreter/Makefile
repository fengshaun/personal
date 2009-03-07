# Makefile for Simpletron
#
# General Ledger, Copyright (C) 2008 Armin Moradi <feng.shaun@gmail.com>
# http://fengshaun.wordpress.com
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3 of the License, or
# (at your option) any later version.
# 
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 US
# 

CC=g++
CFLAGS=-c -g -Wall
SOURCES=machine.cpp main.cpp calculator.cpp
EXECUTABLE=simpletron
OBJECTS=machine.o main.o calculator.o

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXECUTABLE)

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp 

machine.o: machine.cpp
	$(CC) $(CFLAGS) machine.cpp 

calculator.o: calculator.cpp
	$(CC) $(CFLAGS) calculator.cpp

clean:
	rm -rf *o $(EXECUTABLE)

install:
	cp $(EXECUTABLE) /usr/bin/

uninstall:
	rm -f /usr/bin/$(EXECUTABLE)