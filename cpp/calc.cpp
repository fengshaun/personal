//a calculator

#include <sstream>
#include <iostream>
#include <cmath>
using namespace std;

int main() 
{
	cout << "enter a string then we will take out the numbers :)" << endl;
	
	string Str;
	
	getline( cin, Str );
	
	istringstream Buffer( Str );
	
	int integer;
	
	Buffer >> integer;
	
	cout << integer << endl;
}
