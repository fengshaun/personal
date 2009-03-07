//testing the power of vectors and strings and sstream

#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int main() {
	int FN;
	int SN;
	char S;
	static int answer;

	cin >> FN;

	while( true ) {

		cin >> S;

		if( S == '=' ) {
			cout << answer << endl;
			cout << "exiting..." << endl;
			sleep( 4 );
			exit( 1 );
		}

		cin >> SN;
	
		switch( S ) {
			case '+':
				answer = FN + SN;
			break;

			case '-':
				answer = FN - SN;
			break;

			case '*':
				answer = FN * SN;
			break;

			case'=':
				cout << answer << endl;
			break;
		
			default:
				cout << answer << endl;
				sleep( 5 );		
				exit( 1 );
			break;
		}

	}
}
