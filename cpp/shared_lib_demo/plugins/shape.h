#ifndef SHAPE_H
#define SHAPE_H

#include <string>

class Shape
{
	public:
		Shape() {}
		
		virtual std::string name() = 0;
		virtual void set_fill(char) = 0;
		virtual void draw() = 0;
};

// Please do not forget to add this to the .cpp file
/*
extern "C" Shape *create_t() {
	return new Shape;
}
*/

#endif // SHAPE_H
