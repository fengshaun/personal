//fstream example

#include <fstream>
#include <iostream>
using namespace std;

int main()
{
	ofstream file( "infile.dat" );
	
	if( file.fail()) {
		cout << "File could not be open." << endl;
		exit(1);
	}
	
	file.write( "This is a line that is written in the file" );
	
	file.close();
	
}