#include <cstdlib>
#include <iostream>

int main( int argc, char *argv[] ) {
	char buffer[ 5000 ];

	std::cin.getline( buffer, 5000 );
	system( buffer );
	std::cout << "finished :)\n";

}
