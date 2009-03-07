/***************************************************************************
 * General Ledger, Copyright (C) 2008 Armin Moradi <feng.shaun@gmail.com>  *
 * http://fengshaun.wordpress.com                                          *
 *                                                                         *
 * This program is free software; you can redistribute it and/or modify    *
 * it under the terms of the GNU General Public License as published by    *
 * the Free Software Foundation; either version 3 of the License, or       *
 * (at your option) any later version.                                     *
 *                                                                         *
 * This program is distributed in the hope that it will be useful,         *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of          *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the            *
 * GNU General Public License for more details.                            *
 *                                                                         *
 * You should have received a copy of the GNU General Public License       *
 * along with this program; if not, write to the Free Software             *
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 US  *
 ***************************************************************************/

#include <iostream>
#include <fstream>

#include "compiler.h"

int main( int argc, char * argv[] ) {
	std::cout << "starting main" << std::endl;
	std::cout << "checking arguments" << std::endl;
	if ( argc < 3 || argc > 3 ) {
		std::cout << "Invalid number of arguments" << std::endl;
		exit( 0 );
	}

	std::cout << "assigning file names" << std::endl;
	char * inFile = argv[ 1 ];
	char * outFile = argv[ 2 ];

	std::cout << "making compiler object" << std::endl;
	Compiler compiler( inFile, outFile );

	std::cout << "compiling compiler.compile()" << std::endl;
	compiler.compile();
	std::cout << "Done!" << std::endl;
}