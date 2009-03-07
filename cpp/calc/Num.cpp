#include "Num.h"

Num::Num() {
	num1 = 0;
	num2 = 0;
}

Num::~Num() {}

int Num::add() {   //use return int
	return ( num1 + num2 );
}

int Num::subtract() {
	return ( num1 - num2 );
}

int Num::multiply() {
	return ( num1 * num2 );
}

int Num::divide() {
	return ( num1 / num2 );
}

void Num::setNum1( int n1 ) {
	this->num1 = n1;
}

void Num::setNum2( int n2 ) {
	this->num2 = n2;
}
