#ifndef SQUARE_H
#define SQUARE_H

#include "shape.h"

class Square : public Shape
{
	public:
		Square();
		
		std::string name();
		void set_fill(char fill);
		void draw();
		
	private:
		char m_fill;
};

#endif // SQUARE_H