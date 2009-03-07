############################################################################
# General Ledger, Copyright (C) 2008 Armin Moradi <feng.shaun@gmail.com>   #
# http://fengshaun.wordpress.com                                           #
#                                                                          #
# This program is free software; you can redistribute it and/or modify     #
# it under the terms of the GNU General Public License as published by     #
# the Free Software Foundation; either version 3 of the License, or        #
# (at your option) any later version.                                      #
#                                                                          #
# This program is distributed in the hope that it will be useful,          #
# but WITHOUT ANY WARRANTY; without even the implied warranty of           #
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the             #
# GNU General Public License for more details.                             #
#                                                                          #
# You should have received a copy of the GNU General Public License        #
# along with this program; if not, write to the Free Software              #
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 US   #
############################################################################

CC=g++
CFLAGS=-c -g -Wall
SOURCES=compiler.cpp main.cpp symbol.cpp
EXECUTABLE=smlcompiler
OBJECTS=compiler.o main.o symbol.o 

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXECUTABLE)

compiler.o: compiler.cpp
	$(CC) $(CFLAGS) compiler.cpp

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

symbol.o: symbol.cpp
	$(CC) $(CFLAGS) symbol.cpp

clean:
	rm -rf *.o $(EXECUTABLE)