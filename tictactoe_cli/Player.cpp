#include "Player.h"

Player::Player( int n ) {
	setNum( n );
}

Player::~Player() {}

int Player::num() {
	return this->Num;
}

void Player::setNum( int a ) {
	if( a < 0 ) {
		std::cout << "ERROR: Wrong player number" << std::endl;
	} else {
		this->Num = a;
	}
}

int Player::getRequest() {
	int req = 0;
	std::cin >> req;
	while( req < 1 || req > 9 ) {
		std::cout << "Wrong, try again: ";
		std::cin >> req;
	}
	return req;
}
