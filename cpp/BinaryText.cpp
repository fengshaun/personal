//Convert given binary string to normal text

#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
using namespace std;

void convertToASCII( vector< int > &, vector< int > & );

int main () {

	char originalArray[ 5000 ];
	vector< int > original;
	vector< int > ASCvec;
	vector< char > text;
	
	cout << "Please enter a string of 1s and 0s: " << endl;
	cin.getline( originalArray, 5000 );

	//put it in a vector
	for( int i = 0; i < 5000; i++ ) {
		if( originalArray[ i ] != '\0' ) {
			original.push_back( originalArray[ i ] );
			original[ i ] -= 48;
		} else {
			break;
		}
	}

	//check if the number of 1s and 0s are enough
	if( ( original.size() % 8 ) != 0 ) {
		cout << "There is insufficient number of bytes, it must be divisible by 8" << endl;
		exit( 1 );
	}

	convertToASCII( original, ASCvec );

	//pring the ASCII vector
	cout << endl << "The ASCII form of the text:" << endl;
	for( int i = 0; i < ASCvec.size(); i++ ) {
		cout << ASCvec[ i ] << " ";
	}
	cout << endl << endl;

	//convert it to real text
	for( int i = 0; i < ASCvec.size(); i++ ) {
		text.push_back( char( ASCvec[ i ] ) );
	}

	//print the text out
	cout << "The text: " << endl;
	for( int i = 0; i < text.size(); i++ ) {
		cout << text[ i ];
	}
	cout << endl << endl;
}

void convertToASCII( vector< int > & intvec, vector< int > & ascvec ) {

	for( int i = 0; i < intvec.size(); i += 8 ) {
		int factor = 128;
		int j = 0;
		int total = 0;

		while( factor >= 1 ) {
			total += intvec[ i+j ] * factor;
			j++;
			factor /= 2;
		}

		ascvec.push_back( total );

	}
}
