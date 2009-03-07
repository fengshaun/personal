/* General Ledger, Copyright (C) 2008 Armin Moradi <feng.shaun@gmail.com>
* http://fengshaun.wordpress.com
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 3 of the License, or
* (at your option) any later version.
* 
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 US
*/

#include "calculator.h"

Calculator::Calculator() {}

Calculator::~Calculator() {}

double Calculator::add( double a, double b ) {
	return a + b;
}

double Calculator::subtract( double a, double b ) {
	return a - b;
}

double Calculator::divide( double a, double b ) {
	return a / b;
}

double Calculator::multiply( double a, double b ) {
	return a * b;
}

double Calculator::sqroot( double a ) {
	return sqrt( a );
}

double Calculator::factorial( int number ) {
	if( number == 1 || number == 0 ) {
		return number;
	} else {
		return number * factorial( number -1 );
	}
}

double Calculator::permutation( int a, int b ) {
	double top = factorial( a );
	double bottom = factorial( a - b );
	
	double answer = top / bottom;
	return answer;
}

double Calculator::combination( int a, int b ) {
	double top = factorial( a );
	double bottom = factorial( b ) * factorial( a - b );

	double answer = top / bottom;
	return answer;
}

double Calculator::power( double a, int b ) {
	if( b < 0 ) {
		return 0;
	} else if( b == 0 ) {
		return 1;
	} else if( b == 1 ) {
		return a;
	} else {
		return a * power( a, b-1 );
	}
}

double Calculator::sine( double a ) {
	return sin( a );
}

double Calculator::cosine( double a ) {
	return cos( a );
}

double Calculator::tangent( double a ) {
	return tan( a );
}

long int Calculator::random() {
	srand( time( 0 ) );
	return rand();
}

short int Calculator::randomDice() {
	srand( time( 0 ) );
	return rand() % 6 + 1;
}

