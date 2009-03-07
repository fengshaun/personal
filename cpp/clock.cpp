#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() 
{
	for( int n = 10; n > 0; n-- ) {
		cout << n << endl;
		sleep( 1 );
	}

	cout << "FIRE!" << endl;
}
