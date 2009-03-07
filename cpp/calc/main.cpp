#include <iostream>
#include <cmath>
using namespace std;

#include "Num.h"

int main()
{
	int num1 = 0;
	int num2 = 0;
	char sign;
	cout << "Enter First number, sign, and second number" << endl;
	cin >> num1 >> sign >> num2;

	Num numbers;
	numbers.setNum1( num1 );
	numbers.setNum2( num2 );

	switch( sign ) {
		case '+':
			cout << numbers.add() << endl;
			break;

		case '-':
			cout << numbers.subtract() << endl;
			break;

		case '*':
			cout << numbers.multiply() << endl;
			break;

		case '/':
			cout << numbers.divide() << endl;
			break;
	}
}
