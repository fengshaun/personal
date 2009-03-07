#include "Game.h"

Game::Game() {
	board = new Board();
	player1 = new Player( 1 );
	player2 = new Player( 2 );
}

Game::~Game() {
	delete board;
	delete player1;
	delete player2;
}

void Game::run() {
	board->draw();

	while( !this->isDone() ) {
		std::cout << player1->num() << ") Enter a location number (0-9): ";
		int req1 = player1->getRequest();
		board->setNew( req1, player1->num() );
		board->draw();
		if( this->isDone() ) {
			break;
		}

		std::cout << player1->num() << ") Enter a location number (0-9): ";
		int req2 = player2->getRequest();
		board->setNew( req2, player2->num() );
		board->draw();
	}

	std::cout << "Game is finished\a" << std::endl;
}

bool Game::isDone() {
	if( board->gameIsFinished() || board->isFull() ) {
		return true;
	} else {
		return false;
	}
}
