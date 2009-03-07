//Class Player definition

#ifndef PLAYER_H
#define PLAYER_H

#include "definitions.h"

class Player
{
	public:
		Player( int );
		~Player();
		
		void deal( int, int );
		void printCards();
 		void rank();

	private:
		char *cards[ 7 ][ 2 ];
		char *hold;
		
		bool highCards;
		bool pair; 
		bool twoPair;  
		bool threeOfAKind; 
		bool straight;
		bool flush;  
		bool fullHouse;  
		bool fourOfAKind; 
		bool straightFlush;
		bool royalFlush;

		unsigned int pairCounter;
		unsigned int playerNumber;

		friend class CommCards;
		friend void save( Player *, Player *, Player * );
		friend void printResults( Player *, Player *, Player * );
		friend void makeTrue( Player *, Player *, Player * );
		
};

Player::Player( int pNum ) {
	char *cards[ 7 ][ 2 ];
	char *hold;

	highCards = false;
	pair = false;
	twoPair = false;
	threeOfAKind = false;
	straight = false;
	flush = false;
	fullHouse = false;
	fourOfAKind = false;
	straightFlush = false;
	royalFlush = false;

	pairCounter = 0;

	playerNumber = pNum;

}

Player::~Player() {}

void Player::deal( int x, int y ) {
	//first card
	for( int row = 0; row < deckRows; row++ ) {
		for( int column = 0; column < deckColumns; column++ ) {
			if( deck[ row ][ column ] == x ) {
				cards[ 0 ][ 0 ] = face[ column ];
				cards[ 0 ][ 1 ] = suite[ row ];
			}
		}
	}
	
	//second card
	for( int row = 0; row < deckRows; row++ ) {
		for( int column = 0; column < deckColumns; column++ ) {
			if( deck[ row ][ column ] == y ) {
				cards[ 1 ][ 0 ] = face[ column ];
				cards[ 1 ][ 1 ] = suite[ row ];
			}
		}
	}

}

void Player::printCards() {
	cout << cards[ 0 ][ 0 ] << " of " << cards[ 0 ][ 1 ] << endl;
	cout << cards[ 1 ][ 0 ] << " of " << cards[ 1 ][ 1 ] << endl;
}

void Player::rank() {
	int pairC1;
	int pairC2;
	int pair2C1;
	int pair2C2;
	int threeC1;
	int threeC2;
	int threeC3;
	int straightC1;
	int straightC2;
	int straightC3;
	int straightC4;
	int straightC5;
	int flushC1;
	int flushC2;
	int flushC3;
	int flushC4;
	int flushC5;
	int fourC1;
	int fourC2;
	int fourC3;
	int fourC4;

	int hearts = 0;
	int clubs = 0;
	int spades = 0;
	int diamonds = 0;


	//sorting the deck: usable for straight, straight flush, and royal flush
	for( int pass = 0; pass < 7; pass++ ) {
		for( int i = 0; i < 7; i++ ) {
			if( ( strncmp( cards[ i ][ 0 ], cards[ i+1 ][ 0 ], 1 ) ) > 0 ) {
				hold = cards[ i ][ 0 ];
				cards[ i ][ 0 ] = cards[ i+1 ][ 0 ];
				cards[ i+1 ][ 0 ] = hold;
			}
		}
	}


	//THREE OF A KIND
	for( threeC1 = 0; threeC1 < 7; threeC1++ ) {
		for( threeC2 = 0; threeC2 < 7; threeC2++ ) {
			if( threeC1 > threeC2 && cards[ threeC1 ][ 0 ] == cards[ threeC2 ][ 0 ] ) {
				hold = cards[ threeC1 ][ 0 ];
				
				for( threeC3 = 0; threeC3 < 7; threeC3++ ) {
					if( threeC3 != threeC1 && threeC3 != threeC2 ) {
						if( cards[ threeC3 ][ 0 ] == cards[ threeC1 ][ 0 ] && threeOfAKind == false ) {
							cout << "player " << playerNumber << " has a three of a kind: " << endl;
							cout << cards[ threeC1 ][ 0 ] << " of " << cards[ threeC1 ][ 1 ] << endl;
							cout << cards[ threeC2 ][ 0 ] << " of " << cards[ threeC2 ][ 1 ] << endl;
							cout << cards[ threeC3 ][ 0 ] << " of " << cards[ threeC3 ][ 1 ] << endl << endl;
							threeOfAKind = true;
						}
					}
				}
			}
		}
	}
	
	//PAIRS
	for( pairC1 = 0; pairC1 < 7; pairC1++ ) {
		for( pairC2 = 0; pairC2 < 7; pairC2++ ) {
			if( pairC1 > pairC2 && cards[ pairC1 ][ 0 ] == cards[ pairC2 ][ 0 ] && pairCounter <= 2 ) {
				if( !( cards[ pairC2 ][ 0 ] == cards[ threeC3 ][ 0 ] && threeOfAKind == true ) ) {
					cout << "Player " << playerNumber << " has a pair of: " << endl;
					cout << cards[ pairC1 ][ 0 ] << " of " << cards[ pairC1 ][ 1 ] << " AND "
					     << cards[ pairC2 ][ 0 ] << " of " << cards[ pairC2 ][ 1 ] << endl;
					pairCounter++;
					pair = true;
				}	
			}
		}
	}

	//Two Pair
	if( pairCounter >= 2 ) {
		cout << "Player has two pairs." << endl;
		twoPair = true;
	}

	//FLUSH
	for( int card1 = 0; card1 < 7; card1++ ) {
		if( cards[ card1 ][ 1 ] == suite[ 0 ] ) {
			hearts++;
		}
		if( cards[ card1 ][ 1 ] == suite[ 1 ] ) {
			diamonds++;
		}
		if( cards[ card1 ][ 1 ] == suite[ 2 ] ) {
			spades++;
		}
		if( cards[ card1 ][ 1 ] == suite[ 3 ] ) {
			clubs++;
		}
	}
	if( hearts >= 5 ) {
		cout << "Player " << playerNumber << " has a flush of Hearts" << endl;
		flush = true;
	}
	else if( clubs >= 5 ) {
		cout << "Player " << playerNumber << " has a flush of Clubs" << endl;
		flush = true;
	}
	else if( diamonds >= 5 ) {
		cout << "Player " << playerNumber << " has a flush of Diamonds" << endl;
		flush = true;
	}
	else if( spades >= 5 ) {
		cout << "Player " << playerNumber << " has a flush of Spades" << endl;
		flush = true;
	}


	//Four of a kind
	for( fourC1 = 0; fourC1 < 7; fourC1++ ) {
		for( fourC2 = 0; fourC2 < 7; fourC2++ ) {
			for( fourC3 = 0; fourC3 < 7; fourC3++ ) {
				for( fourC4 = 0; fourC4 < 7; fourC4++ ) {
					if( fourC1 > fourC2 && fourC2 > fourC3 && fourC3 > fourC4 ) {
						if( cards[ fourC1 ][ 0 ] == cards[ fourC2 ][ 0 ] && cards[ fourC2 ][ 0 ] == cards[ fourC3 ][ 0 ] && cards[ fourC3 ][ 0 ] == cards[ fourC4 ][ 0 ] && cards[ fourC4 ][ 0 ] == cards[ fourC1 ][ 0 ] ) {
							cout << "Player " << playerNumber << " has a four of kind of: " << endl;
							cout << cards[ fourC1 ][ 0 ] << " of " << cards[ fourC1 ][ 1 ] << endl
									<< cards[ fourC2 ][ 0 ] << " of " << cards[ fourC2 ][ 1 ] << endl
									<< cards[ fourC3 ][ 0 ] << " of " << cards[ fourC3 ][ 1 ] << endl
									<< cards[ fourC4 ][ 0 ] << " of " << cards[ fourC4 ][ 1 ] << endl << endl;
							fourOfAKind = true;
						}
					}
				}
			}
		}
	}

	//full house
	if( pair && threeOfAKind ) {
		cout << "Player " << playerNumber << " has a Full House." << endl;
		fullHouse = true;
	}


	//straight
	
	//getting out the number in front
	stringstream buffer1( cards[ 0 ][ 0 ] );
	stringstream buffer2( cards[ 1 ][ 0 ] );
	stringstream buffer3( cards[ 2 ][ 0 ] );
	stringstream buffer4( cards[ 3 ][ 0 ] );
	stringstream buffer5( cards[ 4 ][ 0 ] );
	stringstream buffer6( cards[ 5 ][ 0 ] );
	stringstream buffer7( cards[ 6 ][ 0 ] );

	int buffer[ 7 ];

	buffer1 >> buffer[ 0 ];
	buffer2 >> buffer[ 1 ];
	buffer3 >> buffer[ 2 ];
	buffer4 >> buffer[ 3 ];
	buffer5 >> buffer[ 4 ];
	buffer6 >> buffer[ 5 ];
	buffer7 >> buffer[ 6 ];
	
	//'if' loops
	for( int i = 0; i < 3; i++ ) {
		if( buffer[ i ] == ( buffer[ i+1 ] - 1 ) ) {
			if( buffer[ i+1 ] == ( buffer[ i+2 ] -1 ) ) {
				if( buffer[ i+2 ] == ( buffer[ i+3 ] -1 ) ) {
					if( buffer[ i+3 ] == ( buffer[ i+4 ] -1 ) ) {
						cout << "Player " << playerNumber << " has a straight." << endl;
						straight = true;
					}
				}
			}
		}
	}

	//straight flush
	//copy the straight and an added 'if'
	
	for( int i = 0; i < 3; i++ ) {
		if( buffer[ i ] == ( buffer[ i+1 ] - 1 ) ) {
			if( buffer[ i+1 ] == ( buffer[ i+2 ] -1 ) ) {
				if( buffer[ i+2 ] == ( buffer[ i+3 ] -1 ) ) {
					if( buffer[ i+3 ] == ( buffer[ i+4 ] -1 ) ) {
						if( cards[ i ][ 1 ] == cards[ i+1 ][ 1 ] && cards[ i+1 ][ 1 ] == cards[ i+2 ][ 1 ] && cards[ i+2 ][ 1 ] == cards[ i+3 ][ 1 ] && cards[ i+3 ][ 1 ] == cards[ i+4 ][ 1 ] ) {
							cout << "Player " << playerNumber << " has a straight flush." << endl;
							straightFlush = true;
						}
					}
				}
			}
		}
	}

	
	//royal flush
	for( int a = 0; a < 7; a++ ) {
		if( cards[ a ][ 0 ] == "1-Ace" ) {
			for( int b = 0; b < 7; b++ ) {
				if( cards[ b ][ 0 ] == "13-King" ) {
					for( int c = 0; c < 7; c++ ) {
						if( cards[ c ][ 0 ] == "12-Queen" ) {
							for( int d = 0; d < 7; d++ ) {
								if( cards[ d ][ 0 ] == "11-Jack" ) {
									for( int e = 0; e < 7; e++ ) {
										if( cards[ e ][ 0 ] == "10-Ten" ) {
											if( cards[ a ][ 1 ] == cards[ b ][ 1 ] && cards[ b ][ 1 ] == cards[ c ][ 1 ] && cards[ c ][ 1 ] == cards[ d ][ 1 ] && cards[ d ][ 1 ] == cards[ e ][ 1 ] ) {
												cout << "Player " << playerNumber << " has a royal flush." << endl;
												royalFlush = true;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}	

	//High Cards
	if( !( pair || twoPair || threeOfAKind || straight || flush || fullHouse || fourOfAKind || straightFlush || royalFlush) )  {
		cout << "Player " << playerNumber <<  " has High Cards." << endl;
		highCards = true;
	}
}


#endif
