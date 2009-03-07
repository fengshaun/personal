//A simple, automatic poker game.
//licenced under GPL 3.0 or above

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

#include "player.h"
#include "community_cards.h"
#include "definitions.h"

void shuffle();
void save( Player *, Player *, Player * );
void printResults( Player *, Player *, Player * );
void clear();
void restart();

int main ()
{
	cout << endl;
loop:	
	srand( 1206331781 );
	cout << "time is: " << 1206331781 << endl << endl;
	shuffle();
	
	Player player1( 1 );
	Player player2( 2 );
	Player player3( 3 );
	CommCards communityCards;
	
	communityCards.deal( &player1, 7, 8, 9, 11, 13 );
	communityCards.deal( &player2, 7, 8, 9, 11, 13 );
	communityCards.deal( &player3, 7, 8, 9, 11, 13 );
	
	player1.deal( 1, 2 );
	cout << "Player 1" << endl; 
	cout << "--------" << endl;
	player1.printCards();
	cout << endl;

	player2.deal( 3, 4 );
	cout << "Player 2" << endl;
	cout << "--------" << endl;
	player2.printCards();
	cout << endl;

	player3.deal( 5, 6 );
	cout << "Player 3" << endl;
	cout << "--------" << endl;
	player3.printCards();
	cout << endl;
	
	communityCards.print( &player1 );
	cout << "checking hands: " << endl;

	player1.rank();
	cout << endl;

	player2.rank();
	cout << endl;

	player3.rank();
	cout << endl;
	
	printResults( &player1, &player2, &player3 );
	cout << endl;

	char yn;
	cout << "Do you want to continue? (y/N) ";
	cin >> yn;

	switch( yn ) {
		case 'y':
		case 'Y':
			restart();

		case 'n':
		case 'N':
			cout << "Do you want to save your game? (y/N) ";
			char yn2;
			cin >> yn2;

			if( yn2 == 'y' ) {
				save( &player1, &player2, &player3 );
				exit( 1 );
			} else if( yn2 == 'n' ) {
				exit( 1 );
			}

		default:
			cout << "no option " << yn << ".  Exiting..." << endl;
	}
}



void shuffle() {
	
	for( int card = 1; card <= totalCards; card++ ) {
		int randRow = rand() % deckRows;
		int randColumn = rand() % deckColumns;
		
		while( deck[ randRow ][ randColumn ] != 0 ) {
			randRow = rand() % deckRows;
			randColumn = rand() % deckColumns;
		}
		
		deck[ randRow ][ randColumn ] = card;
	}
	
}


void save( Player *player1, Player *player2, Player *player3 ) {
	ofstream ofile;
	ofile.open( "autopoker.sav" );

	if( ofile.is_open() ) {

		ofile << "time is: " << time( 0 ) << endl << endl;
		
		ofile << "Player 1 has:" << endl;
		ofile << player1->cards[ 0 ][ 0 ] << " of " << player1->cards[ 0 ][ 1 ] << endl;
		ofile << player1->cards[ 1 ][ 0 ] << " of " << player1->cards[ 1 ][ 1 ] << endl;
		ofile << endl;

		ofile << "Player 2 has:" << endl;
		ofile << player2->cards[ 0 ][ 0 ] << " of " << player2->cards[ 0 ][ 1 ] << endl;
		ofile << player2->cards[ 1 ][ 0 ] << " of " << player2->cards[ 1 ][ 1 ] << endl;
		ofile << endl;

		ofile << "Player 3 has:" << endl;
		ofile << player3->cards[ 0 ][ 0 ] << " of " << player3->cards[ 0 ][ 1 ] << endl;
		ofile << player3->cards[ 1 ][ 0 ] << " of " << player3->cards[ 1 ][ 1 ] << endl;
		ofile << endl;
	
		ofile << "community cards are ( 3 flops, turn, and river ):" << endl;
		ofile << player1->cards[ 2 ][ 0 ] << " of " << player1->cards[ 2 ][ 1 ] << endl;
		ofile << player1->cards[ 3 ][ 0 ] << " of " << player1->cards[ 3 ][ 1 ] << endl;
		ofile << player1->cards[ 4 ][ 0 ] << " of " << player1->cards[ 4 ][ 1 ] << endl;
		ofile << player1->cards[ 5 ][ 0 ] << " of " << player1->cards[ 5 ][ 1 ] << endl;
		ofile << player1->cards[ 6 ][ 0 ] << " of " << player1->cards[ 6 ][ 1 ] << endl;
		ofile << endl;

		{
		if( player1->highCards ) {
			ofile << "Player " << player1->playerNumber << " has high cards." << endl;
		}

		if( player1->pair ) {
			ofile << "Player " << player1->playerNumber << " has a pair." << endl;
		}

		if( player1->twoPair ) {
			ofile << "Player " << player1->playerNumber << " has two pairs." << endl;
		}

		if( player1->threeOfAKind ) {
			ofile << "Player " << player1->playerNumber << " has a three of a kind." << endl;
		}

		if( player1->straight ) {
			ofile << "Player " << player1->playerNumber << " has a straight." << endl;
		}

		if( player1->flush ) {
			ofile << "Player " << player1->playerNumber << " has a flush." << endl;
		}

		if( player1->fullHouse ) {
			ofile << "Player " << player1->playerNumber << " has a flush." << endl;
		}

		if( player1->fourOfAKind ) {
			ofile << "Player " << player1->playerNumber << " has a four of a kind." << endl;
		}

		if( player1->straightFlush ) {
			ofile << "Player " << player1->playerNumber << " has straight flush." << endl;
		}

		if( player1->royalFlush ) {
			ofile << "Player " << player1->playerNumber << " has royal flush." << endl;
		}
		}
		{
		if( player2->highCards ) {
			ofile << "Player " << player2->playerNumber << " has high cards." << endl;
		}

		if( player2->pair ) {
			ofile << "Player " << player2->playerNumber << " has a pair." << endl;
		}

		if( player2->twoPair ) {
			ofile << "Player " << player2->playerNumber << " has two pairs." << endl;
		}

		if( player2->threeOfAKind ) {
			ofile << "Player " << player2->playerNumber << " has a three of a kind." << endl;
		}

		if( player2->straight ) {
			ofile << "Player " << player2->playerNumber << " has a straight." << endl;
		}

		if( player2->flush ) {
			ofile << "Player " << player2->playerNumber << " has a flush." << endl;
		}

		if( player2->fullHouse ) {
			ofile << "Player " << player2->playerNumber << " has a flush." << endl;
		}

		if( player2->fourOfAKind ) {
			ofile << "Player " << player2->playerNumber << " has a four of a kind." << endl;
		}

		if( player2->straightFlush ) {
			ofile << "Player " << player2->playerNumber << " has straight flush." << endl;
		}

		if( player2->royalFlush ) {
			ofile << "Player " << player2->playerNumber << " has royal flush." << endl;
		}
		}
		{
		if( player3->highCards ) {
			ofile << "Player " << player3->playerNumber << " has high cards." << endl;
		}

		if( player3->pair ) {
			ofile << "Player " << player3->playerNumber << " has a pair." << endl;
		}

		if( player3->twoPair ) {
			ofile << "Player " << player3->playerNumber << " has two pairs." << endl;
		}

		if( player3->threeOfAKind ) {
			ofile << "Player " << player3->playerNumber << " has a three of a kind." << endl;
		}

		if( player3->straight ) {
			ofile << "Player " << player3->playerNumber << " has a straight." << endl;
		}

		if( player3->flush ) {
			ofile << "Player " << player3->playerNumber << " has a flush." << endl;
		}

		if( player3->fullHouse ) {
			ofile << "Player " << player3->playerNumber << " has a flush." << endl;
		}

		if( player3->fourOfAKind ) {
			ofile << "Player " << player3->playerNumber << " has a four of a kind." << endl;
		}

		if( player3->straightFlush ) {
			ofile << "Player " << player3->playerNumber << " has straight flush." << endl;
		}

		if( player3->royalFlush ) {
			ofile << "Player " << player3->playerNumber << " has royal flush." << endl;
		}
		}

		sleep( 3 );

		cout << "game successfully saved." << endl;
	}
	else {
		sleep( 2 );
		cout << "ERROR: autopoker.sav could not be opened" << endl;
		cout << "Please make sure that the file is present in the same directory as the game." << endl;
	}
}

void printResults( Player *player1, Player *player2, Player *player3 ) {
	cout << setw( 30 ) << "Player 1" << setw( 14 ) << "Player 2" << setw( 14 ) << "Player 3" << endl;
	cout << "==============================================================" << endl;
	
	cout << setiosflags( ios::right );
	
	cout << setw( 20 ) << "Pair |";
	cout << setw( 3 ) << " ";
	if( player1->pair ) cout << "#";
	cout << setw( 13 ) << " ";
	if( player2->pair ) cout << "#";
	cout << setw( 13 ) << " ";
	if( player3->pair ) cout << "#";
	
	cout << endl << setw( 20 ) << "Two pairs |";
	cout << setw( 3 ) << " ";
	if( player1->twoPair ) cout << "#";
	cout << setw( 13 ) << " ";
	if( player2->twoPair ) cout << "#";
	cout << setw( 13 ) << " ";
	if( player3->twoPair ) cout << "#";
	
	cout << endl << setw( 20 ) << "Three of a kind |";
	cout << setw( 3 ) << " ";
	if( player1->threeOfAKind ) cout << "#";
	cout << setw( 13 ) << " ";
	if( player2->threeOfAKind ) cout << "#";
	cout << setw( 13 ) << " ";
	if( player3->threeOfAKind ) cout << "#";
	
	cout << endl << setw( 20 ) << "Straight |";
	cout << setw( 3 ) << " ";
	if( player1->straight ) cout << "#";
	cout << setw( 13 ) << " ";
	if( player2->straight ) cout << "#";
	cout << setw( 13 ) << " ";
	if( player3->straight ) cout << "#";
	
	cout << endl << setw( 20 ) << "Flush |";
	cout << setw( 3 ) << " ";
	if( player1->flush ) cout << "#";
	cout << setw( 13 ) << " ";
	if( player2->flush ) cout << "#";
	cout << setw( 13 ) << " ";
	if( player3->flush ) cout << "#";
	
	cout << endl << setw( 20 ) << "Full house |";
	cout << setw( 3 ) << " ";
	if( player1->fullHouse ) cout << "#";
	cout << setw( 13 ) << " ";
	if( player2->fullHouse ) cout << "#";
	cout << setw( 13 ) << " ";
	if( player3->fullHouse ) cout << "#";
	
	cout << endl << setw( 20 ) << "Four of a kind |";
	cout << setw( 3 ) << " ";
	if( player1->fourOfAKind ) cout << "#";
	cout << setw( 13 ) << " ";
	if( player2->fourOfAKind ) cout << "#";
	cout << setw( 13 ) << " ";
	if( player3->fourOfAKind ) cout << "#";
	
	cout << endl << setw( 20 ) << "Straight flush |";
	cout << setw( 3 ) << " ";
	if( player1->straightFlush ) cout << "#";
	cout << setw( 13 ) << " ";
	if( player2->straightFlush ) cout << "#";
	cout << setw( 13 ) << " ";
	if( player3->straightFlush ) cout << "#";
	
	cout << endl << setw( 20 ) << "Royal flush |";
	cout << setw( 3 ) << " ";
	if( player1->royalFlush ) cout << "#";
	cout << setw( 13 ) << " ";
	if( player2->royalFlush ) cout << "#";
	cout << setw( 13 ) << " ";
	if( player3->royalFlush ) cout << "#";
	
}

void makeTrue( Player *player1, Player *player2, Player *player3 ) {
	player1->pair = true;
	player1->twoPair = true;
	player1->threeOfAKind = true;
	player1->straight = true;
	player1->flush = true;
	player1->fullHouse = true;
	player1->fourOfAKind = true;
	player1->straightFlush = true;
	player1->royalFlush = true;

	player2->pair = true;
	player2->twoPair = true;
	player2->threeOfAKind = true;
	player2->straight = true;
	player2->flush = true;
	player2->fullHouse = true;
	player2->fourOfAKind = true;
	player2->straightFlush = true;
	player2->royalFlush = true;
	
	player3->pair = true;
	player3->twoPair = true;
	player3->threeOfAKind = true;
	player3->straight = true;
	player3->flush = true;
	player3->fullHouse = true;
	player3->fourOfAKind = true;
	player3->straightFlush = true;
	player3->royalFlush = true;
}

void clear() {
	for( int i = 0; i < 4; i++ ) {
		for( int j = 0; j < 13; j++ ) {
			deck[ i ][ j ] = 0;
		}
	}
}

void restart() {
	clear();
	main();
}
