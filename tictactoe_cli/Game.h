#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "Player.h"

class Game
{
	public:
		Game();
		~Game();

		void run();
		bool isDone();

	private:
		Board *board;
		Player *player1;
		Player *player2;
};

#endif
