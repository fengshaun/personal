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
#include <vector>

#include "converter.h"

int main() {

	Converter convert;

	std::vector< int > intV( 8 );
	std::vector< char > charV;

	int intA[ 8 ] = { 0, 1, 0, 0, 0, 0, 0, 1 };

	for( int i = 0; i < 8; i++ ) {
		intV[ i ] = intA[ i ];
		std::cout << intV[ i ];
	}

	std::cout << std::endl;

	convert.binaryToText( intV, charV );

	for( int i = 0; i < charV.size(); i++ ) {
		std::cout << charV[ i ] << std::endl;
	}

	std::cout << std::endl;

	Converter::printAllASCII();
}
