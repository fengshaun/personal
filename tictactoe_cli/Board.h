#ifndef BOARD_H
#define BOARD_H

#include <iostream>

class Board
{
	public:
		Board();
		~Board();

		void draw();
		bool setNew( int, int );
		bool isFull();
		bool gameIsFinished();

	protected:
		void setDimension( int, int );
		int getX();
		int getY();

	private:
		int array[ 3 ][ 3 ];
		int x;
		int y;
};

#endif
