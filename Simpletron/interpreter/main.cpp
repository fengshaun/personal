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
#include <cstring>
#include <cstdlib>
#include <fstream>
using namespace std;

#include "machine.h"

void welcome();  //just two simple functions to welcome and help the user!
void help();	 //only std::cout is used! nothing big!

int main( int argc, char *argv[] ) {

	Machine machine;
	cout << endl;

	if( argc >= 2 ) {
		if( strcmp( argv[ 1 ], "--help" ) == 0 ) {
			help();
			exit( 1 );
		} else {
			welcome();
			char *fileName = argv[ 1 ];
			fstream srcCode;
			srcCode.open( fileName, ios::in );
			if( srcCode.is_open() ) {
				cout << "***Program input started***" << endl;
				cout << "Reading from file " << fileName << endl;
				machine.getFile( srcCode );
			} else {
				cout << "ERROR: " << fileName << " could not be opened" << endl;
				exit( 1 );
			}
		}
	} else { 
		welcome();
		cout << "***Program input started***" << endl;
		cin >> machine;
	}

	cout << "***Program input completed***" << endl << endl;
	cout << "***Program execution started***" << endl;
	machine.processInstructions();
	cout << "***Program execution completed***" << endl;

	return 0;
}

void welcome() {
	cout << "***              Simpletron             ***" << endl << endl;
	cout << "*** type --help as an argument for this ***" << endl
	     << "*** program to see different possible   ***" << endl
	     << "*** instructions you can use for this   ***" << endl
	     << "*** program. type 9999 to terminate the ***" << endl
	     << "*** program input.                      ***" << endl
	     << "***                                     ***" << endl
	     << "*** Have Fun!                           ***" << endl << endl;
}

void help() {
	cout << "***              Simpletron             ***" << endl
		<< "*** These are the instructions you can  ***" << endl
		<< "*** use to write useful programs.       ***" << endl 
		<< "*** Please note that this help is       ***" << endl
		<< "*** intended to be a reference.  For    ***" << endl
		<< "*** more help, and a guide, refer to    ***" << endl
		<< "*** the README file included.           ***" << endl
		<< "***                                     ***" << endl
		<< "***  10  READ                           ***" << endl
		<< "***  11  PRINT                          ***" << endl
		<< "***  20  LOAD                           ***" << endl
		<< "***  21  STORE                          ***" << endl
		<< "***  30  BRANCH                         ***" << endl
		<< "***  31  BRANCH_ZERO                    ***" << endl
		<< "***  32  BRANCH_NEGATIVE                ***" << endl
		<< "***                                     ***" << endl
		<< "***  prefix of 1 to indicate that you're***" << endl
		<< "***  using calculator is needed         ***" << endl
		<< "***                                     ***" << endl
		<< "***  30  ADD                            ***" << endl
		<< "***  31  SUBTRACT                       ***" << endl
		<< "***  32  DIVIDE                         ***" << endl
		<< "***  33  MULTIPLY                       ***" << endl
		<< "***  34  PERMUTATION                    ***" << endl
		<< "***  35  COMBINATION                    ***" << endl
		<< "***  36  FACTORIAL                      ***" << endl << endl;
}

