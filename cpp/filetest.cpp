//testing file operations
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main ()
{
	ofstream ofile;
	ifstream ifile;
	ofile.open( "data.txt" );
	ifile.open( "data.txt" );

	if( !( ifile.is_open() ) ) {
		cout << "file could not be opened for input operations." << endl;
		exit( 1 );
	}
	if( !( ofile.is_open() ) ) {
		cout << "file could not be opened for output operations." << endl;
		exit( 1 );
	}
	
	ofile << "This is the first line in the file" << endl;
	ofile << "This is the second line in the file" << endl;
	cout << "segment written successfully" << endl;

	sleep( 2 );

	cout << "inputing first segment" << endl;
	sleep( 1 );

	string line;

	while( !( ifile.eof() ) ) {
		getline( ifile, line );
		cout << line << endl;
	}
	
	ifile.close();
	ofile.close();
}
