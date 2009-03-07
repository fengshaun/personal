//community cards

#ifndef COMMUNITY_CARDS_H
#define COMMUNITY_CARDS_H

#include "definitions.h"
#include "player.h"

class Player;

class CommCards
{
	public:
		CommCards() { flop1Num = flop2Num = flop3Num = turnNum = riverNum = 0; }
		~CommCards() { }
		
		void deal( Player *, int, int, int, int, int );
		void print( Player * );

	private:
		int flop1Num;
		int flop2Num;
		int flop3Num;
		int turnNum;
		int riverNum;

};

void CommCards::deal( Player *player, int a, int b, int c, int d, int e ) {
	flop1Num = a;
	flop2Num = b;
	flop3Num = c;
	turnNum = d;
	riverNum = e;

	for( int row = 0; row < deckRows; row++ ) {
		for( int column = 0; column < deckColumns; column++ ) {
			
			if( deck[ row ][ column ] == flop1Num ) {
				player->cards[ 2 ][ 0 ] = face[ column ] + '\0';
				player->cards[ 2 ][ 1 ] = suite[ row ] + '\0';
			}
			
			else if( deck[ row ][ column ] == flop2Num ) {
				player->cards[ 3 ][ 0 ] = face[ column ] + '\0';
				player->cards[ 3 ][ 1 ] = suite[ row ] + '\0';
			}
			
			else if( deck[ row ][ column ] == flop3Num ) {
				player->cards[ 4 ][ 0 ] = face[ column ] + '\0';
				player->cards[ 4 ][ 1 ] = suite[ row ] + '\0';
			}
			
			else if( deck[ row ][ column ] == turnNum ) {
				player->cards[ 5 ][ 0 ] = face[ column ] + '\0';
				player->cards[ 5 ][ 1 ] = suite[ row ] + '\0';
			}
			
			else if( deck[ row ][ column ] == riverNum ) {
				player->cards[ 6 ][ 0 ] = face[ column ] + '\0';
				player->cards[ 6 ][ 1 ] = suite[ row ] + '\0';
			}
			
		}
	}
	
}

void CommCards::print( Player *player ) {
	
	cout << "Community Cards" << endl;
	cout << "---------------" << endl;
	cout << player->cards[ 2 ][ 0 ] << " of " << player->cards[ 2 ][ 1 ] << endl;
	cout << player->cards[ 3 ][ 0 ] << " of " << player->cards[ 3 ][ 1 ] << endl;
	cout << player->cards[ 4 ][ 0 ] << " of " << player->cards[ 4 ][ 1 ] << endl;
	cout << player->cards[ 5 ][ 0 ] << " of " << player->cards[ 5 ][ 1 ] << endl;
	cout << player->cards[ 6 ][ 0 ] << " of " << player->cards[ 6 ][ 1 ] << endl;
	cout << endl << endl;
	
}

#endif
