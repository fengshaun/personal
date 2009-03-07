//put random numbers in slots

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;


int main ()
{
	const int totalCards = 52;
	const int deckRows = 4;
	const int deckColumns = 13;
	int deck[ deckRows ][ deckColumns ] = { 0 };
	char *suite[] = { "Hearts", "Clubs", "Diamonds", "Spades" };
	char *face[] = { "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };
	srand( time( 0 ) );
/***************************************
	char *rules[] = { "Pair", "Two Pair", 
 ***************************************/
	for( int card = 1; card <= totalCards; card++ ) {
		int randrow = rand() % deckRows;
		int randcolumn = rand() % deckColumns;

		while( deck[randrow][randcolumn] != 0 ) {
			randrow = rand() % 4;
			randcolumn = rand() % 13;
		}

		deck[randrow][randcolumn] = card;
	}

/*
	//print the deck
	for( int i = 0; i < deckRows; i++ ) {
		for( int j = 0; j < deckColumns; j++ ) {
			cout << setw( 5 ) << deck[ i ][ j ] << " ";
		}
		cout << endl;
	}

	//check for wrong numbers
	for( int x = 0; x < deckRows; x++ ) {
		for( int y = 0; y < deckColumns; y++ ) {
			if( deck[ x ][ y ] > 52 || deck[ x ][ y ] < 1 ) {
				cout << "INVALID NUMBER DETECTED IN LOCATION: " << x << ", " << y << endl;
			}
		}
	}
*/

	//print each random card that is dealt.
	for( int card = 1; card < totalCards; card++ ) {
		for( int i = 0; i < deckRows; i++ ) {
			for( int j = 0; j < deckColumns; j++ ) {
				if( deck[ i ][ j ] == card ) {
					//cout << face[ j ] << " of " << suite[ i ] << endl;
					switch( card ) {

						case 1:
							cout << "Player 1 gets: " << endl;
							cout << face[ j ] << " of " << suite[ i ] << endl;
						break;

						case 2:
							cout << face[ j ] << " of " << suite[ i ] << endl << endl;
						break;

						case 3:
							cout << "Player 2 gets: " << endl;
							cout << face[ j ] << " of " << suite[ i ] << endl;
						break;

						case 4:
							cout << face[ j ] << " of " << suite[ i ] << endl << endl;
						break;

						case 5:
							cout << "Player 3 gets: " << endl;
							cout << face[ j ] << " of " << suite[ i ] << endl;
						break;

						case 6:
							cout << face[ j ] << " of " << suite[ i ] << endl << endl;
						break;

						case 7:
							cout << "Player 4 gets: " << endl;
							cout << face[ j ] << " of " << suite[ i ] << endl;
						break;

						case 8:
							cout << face[ j ] << " of " << suite[ i ] << endl << endl;
						break;

						case 9:
							cout << "Player 5 gets: " << endl;
							cout << face[ j ] << " of " << suite[ i ] << endl;
						break;

						case 10:
							cout << face[ j ] << " of " << suite[ i ] << endl << endl;
						break;

						case 11:
							cout << "Player 6 gets: " << endl;
							cout << face[ j ] << " of " << suite[ i ] << endl;
						break;

						case 12:
							cout << face[ j ] << " of " << suite[ i ] << endl << endl;
						break;

						case 13:
							cout << "Player 7 gets: " << endl;
							cout << face[ j ] << " of " << suite[ i ] << endl;
						break;

						case 14:
							cout << face[ j ] << " of " << suite[ i ] << endl << endl;
						break;

						case 15:
							cout << "Player 8 gets: " << endl;
							cout << face[ j ] << " of " << suite[ i ] << endl;
						break;

						case 16:
							cout << face[ j ] << " of " << suite[ i ] << endl << endl;
						break;

						case 17:
							cout << "Player 9 gets: " << endl;
							cout << face[ j ] << " of " << suite[ i ] << endl;
						break;

						case 18:
							cout << face[ j ] << " of " << suite[ i ] << endl << endl;
						break;

						case 19:
							cout << "Player 10 gets: " << endl;
							cout << face[ j ] << " of " << suite[ i ] << endl;
						break;

						case 20:
							cout << face[ j ] << " of " << suite[ i ] << endl << endl;
						break;

						case 21:
							cout << "The five cards on table are:" << endl;
							cout << face[ j ] << " of " << suite[ i ] << endl;
						break;

						case 22:
							cout << face[ j ] << " of " << suite[ i ] << endl;
						break;

						case 23:
							cout << face[ j ] << " of " << suite[ i ] << endl;
						break;

						case 24:
							cout << face[ j ] << " of " << suite[ i ] << endl;
						break;

						case 25:
							cout << face[ j ] << " of " << suite[ i ] << endl << endl;
						break;

						default:
						break;
					
					}
				}
			}
		}
	}



}
