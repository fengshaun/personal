/***************************************************************************
 *  General Ledger, Copyright (C) 2008 Armin Moradi <feng.shaun@gmail.com>
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
 ***************************************************************************/




#include <cstdlib>
#include <string>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

void convertToBin( vector< int > &, vector< int > & );

int main () {

	char line[ 100 ] = { 0 };
	vector< char > vline;
	vector< int > vnum;
	vector< int > v2num;

	cout << "Please enter a string of characters:" << endl;

	cin.getline( line, 100 );

	//now we can process the array: put it in the vector for "ease of use" ( vector::size() )
	for( int i = 0; i < 100; i++ ) {
		if( line[ i ] != '\0' ) {	
			vline.push_back( line[ i ] );
		} else {
			break;
		}
	}

	cout << endl;

	//cout the ASCII code for it!
	cout << "ASCII characters" << endl;
	for( int i = 0; i < vline.size(); i++ ) { //using vline.size() is the same thing as 'i < 100' but it's safer this way!
		vnum.push_back( int( vline[ i ] ) );
		cout << vnum[ i ] << " ";
	}
	
	cout << endl << endl; 

	cout << "Binary form" << endl;
	convertToBin( vnum, v2num );

	for( int i = 0; i < v2num.size(); i++ ) {
		cout << v2num[ i ];
	}
	cout << endl << endl;
}

//now it's the time to convert it to binary!
void convertToBin( vector< int > & vec, vector< int > & vec2 ) {  //passing two vectors with referece: one with the ASCII chars, and an empty one!
	int num = 0;

	for( int i = 0; i < vec.size(); i++ ) {
		num = 128;
		while( num >= 1 ) {
			if( vec[ i ] >= num ) {
				vec2.push_back( 1 );
				vec[ i ] -= num;
			} else {
				vec2.push_back( 0 );
			}
			num /= 2;
		}
	}
}
