#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

class Player
{
	public:
		Player( int );
		~Player();

		int num();
		int getRequest();

	protected:
		void setNum( int );

	private:
		int Num;
};

#endif
