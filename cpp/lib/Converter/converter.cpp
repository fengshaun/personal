/* General Ledger, Copyright (C) 2008 Armin Moradi <feng.shaun@gmail.com>
* http://fengshaun.wordpress.com
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 3 of the License, or
* (at your option) any later version.
* 
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 US
*/
 
#include <iostream>
#include <vector>

#include "converter.h"

Converter::Converter() {}

Converter::~Converter() {}

void Converter::binaryToText( vector< int > &binary, vector< char > &text ) {
	this->binaryToASCII( binary );
	this->ASCIIToText( text );
}

void Converter::ASCIIToText( vector< char > &text ) {
	for( unsigned int i = 0; i < ASCII.size(); i++ ) {
		text.push_back( char( ASCII[ i ] ) );
	}
}

void Converter::binaryToASCII( vector< int > &binary ) {
	for( unsigned int i = 0; i < binary.size(); i += 8 ) {
		int factor = 128;
		int j = 0;
		int total = 0;

		while( factor >= 1 ) {
			total += binary[ i + j ] * factor;
			j++;
			factor /= 2;
		}
		
		ASCII.push_back( total );

	}
}

void Converter::printAllASCII() {
	for( int i = 0; i < 256; i++ ) {
		std::cout << i << "\t" << char( i ) << std::endl;
	}
}
