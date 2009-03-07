//playing with vectors and string and sorting them

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	vector< vector<string> > v ( 3, vector<string>( 2 ) );

	v[ 0 ][ 0 ] = "hello00";
	v[ 0 ][ 1 ] = "hello01";
	v[ 1 ][ 0 ] = "hello10";
	v[ 1 ][ 1 ] = "hello11";
	v[ 2 ][ 0 ] = "hello20";
	v[ 2 ][ 1 ] = "hello21";

	cout << v[ 2 ][ 0 ] << endl; 
//playing with vectors and string and sorting them
/*
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	vector<string> v;
	vector<string>::iterator vit;

	v.push_back( "1-first" );
	v.push_back( "3-third" );
	v.push_back( "2-second" );

	vit = find( v.begin(), v.end(), "2-second" );
	cout << vit-v.begin() << endl;
	cout << v[ vit-v.begin() ] << endl;

	sort( v.begin(), v.end() );
	for( int i = 0; i < v.size(); i++ ) {
		cout << v[ i ] << endl;
	}
}*/
}
