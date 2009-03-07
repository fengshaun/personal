//playground
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <ctime>
#include <cmath>
using namespace std;

class Object
{
	public:
		Object() { x = y = 0; }
		Object( int a ) { x = y = 0; z = a; }
		~Object() {}
		
		void print();
		void setnum( int, int );
		
		int z;
		
		friend class Object2;
		
	private:
		int x;
		int y;
};

void Object::print()
{
	cout << x << " and " << y << endl;
}

void Object::setnum( int a, int b )
{
	x = a;
	y = b;
}


int main()
{
	char *hello[ 2 ];
	hello[ 1 ] = "hello1";
	cout << hello[ 1 ] << endl;
	if( hello[ 1 ] == "hello1" ) {
		cout << hello[ 1 ] << endl;
	}
}

