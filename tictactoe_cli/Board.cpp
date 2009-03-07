#include "Board.h"

Board::Board() {
	setDimension( 3, 3 );
	for( int i = 0; i < 3; i++ ) {
		for( int j = 0; j < 3; j++ ) {
			array[ i ][ j ] = 0;
		}
	}
}

Board::~Board() { }

void Board::draw() {
	//printing the array would suffice for now
	for( int i = 0; i < 3; i++ ) {
		for( int j = 0; j < 3; j++ ) {
			std::cout << array[ i ][ j ] << '\t';
		}
		std::cout << std::endl << '\v';
	}
	std::cout << std::endl << '\v';
}

void Board::setDimension( int a, int b ) {
	this->x = a;
	this->y = b;
}

int Board::getX() {
	return this->x;
}

int Board::getY() {
	return this->y;
}

bool Board::setNew( int location, int num ) {
	//only if the location is not already occupied
	//poor way of using switch
	switch( location ) {
		case 1:
			if( array[ 0 ][ 0 ] == 0 ) {
				array[ 0 ][ 0 ] = num;
			} else {
				std::cout << "ERROR: location already occupied" << std::endl;
				std::cout << "Enter another location: ";
				std::cin >> location;
				this->setNew( location, num );
			}
			break;

		case 2:
			if( array[ 0 ][ 1 ] == 0 ) {
				array[ 0 ][ 1 ] = num;
			} else {
				std::cout << "ERROR: location already occupied" << std::endl;
				std::cout << "Enter another location: ";
				std::cin >> location;
				this->setNew( location, num );
			}
			break;

		case 3:
			if( array[ 0 ][ 2 ] == 0 ) {
				array[ 0 ][ 2 ] = num;
			} else {
				std::cout << "ERROR: location already occupied" << std::endl;
				std::cout << "Enter another location: ";
				std::cin >> location;
				this->setNew( location, num );
			}
			break;

		case 4:
			if( array[ 1 ][ 0 ] == 0 ) {
				array[ 1 ][ 0 ] = num;
			} else {
				std::cout << "ERROR: location already occupied" << std::endl;
				std::cout << "Enter another location: ";
				std::cin >> location;
				this->setNew( location, num );
			}
			break;

		case 5:
			if( array[ 1 ][ 1 ] == 0 ) {
				array[ 1 ][ 1 ] = num;
			} else {
				std::cout << "ERROR: location already occupied" << std::endl;
				std::cout << "Enter another location: ";
				std::cin >> location;
				this->setNew( location, num );
			}
			break;

		case 6:
			if( array[ 1 ][ 2 ] == 0 ) {
				array[ 1 ][ 2 ] = num;
			} else {
				std::cout << "ERROR: location already occupied" << std::endl;
				std::cout << "Enter another location: ";
				std::cin >> location;
				this->setNew( location, num );
			}
			break;

		case 7:
			if( array[ 2 ][ 0 ] == 0 ) {
				array[ 2 ][ 0 ] = num;
			} else {
				std::cout << "ERROR: location already occupied" << std::endl;
				std::cout << "Enter another location: ";
				std::cin >> location;
				this->setNew( location, num );
			}
			break;

		case 8:
			if( array[ 2 ][ 1 ] == 0 ) {
				array[ 2 ][ 1 ] = num;
			} else {
				std::cout << "ERROR: location already occupied" << std::endl;
				std::cout << "Enter another location: ";
				std::cin >> location;
				this->setNew( location, num );
			}
			break;

		case 9:
			if( array[ 2 ][ 2 ] == 0 ) {
				array[ 2 ][ 2 ] = num;
			} else {
				std::cout << "ERROR: location already occupied" << std::endl;
				std::cout << "Enter another location: ";
				std::cin >> location;
				this->setNew( location, num );
			}
			break;

		case 10:
			break;

		default:
			std::cout << "ERROR: Wrong location: not found" << std::endl;
			break;

	}
}

bool Board::isFull() {
	for( int i = 0; i < 3; i++ ) {
		for( int j = 0; j < 3; j++ ) {
			if( array[ i ][ j ] == 0 ) {
				return false;
			}
		}
	}

	return true;
}

bool Board::gameIsFinished() {
	//8 possibilities

	if( array[ 0 ][ 0 ] == array[ 0 ][ 1 ] && array[ 0 ][ 1 ] == array[ 0 ][ 2 ] && array[ 0 ][ 0 ] != 0 ) { //first row
		return true; 
	} else if( array[ 1 ][ 0 ] == array[ 1 ][ 1 ] && array[ 1 ][ 1 ] == array[ 1 ][ 2 ] && array[ 1 ][ 0 ] != 0 ) { //second row
		return true;
	} else if( array[ 2 ][ 0 ] == array[ 2 ][ 1 ] && array[ 2 ][ 1 ] == array[ 2 ][ 2 ] && array[ 2 ][ 0 ] != 0 ) { //third row
		return true;
	} else if( array[ 0 ][ 0 ] == array[ 1 ][ 0 ] && array[ 1 ][ 0 ] == array[ 2 ][ 0 ] && array[ 0 ][ 0 ] != 0 ) { //first column
		return true;
	} else if( array[ 0 ][ 1 ] == array[ 1 ][ 1 ] && array[ 1 ][ 1 ] == array[ 2 ][ 1 ] && array[ 0 ][ 1 ] != 0 ) { //second column
		return true;
	} else if( array[ 0 ][ 2 ] == array[ 1 ][ 2 ] && array[ 1 ][ 2 ] == array[ 2 ][ 2 ] && array[ 0 ][ 2 ] != 0 ) { //third column
		return true;
	} else if( array[ 0 ][ 0 ] == array[ 1 ][ 1 ] && array[ 1 ][ 1 ] == array[ 2 ][ 2 ] && array[ 0 ][ 0 ] != 0 ) { //first diagonal
		return true;
	} else if( array[ 0 ][ 2 ] == array[ 1 ][ 1 ] && array[ 1 ][ 1 ] == array[ 2 ][ 0 ] && array[ 0 ][ 2 ] != 0 ) { //second diagonal
		return true;
	} else {
		return false;
	}
}
