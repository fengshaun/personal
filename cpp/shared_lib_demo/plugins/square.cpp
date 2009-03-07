#include "square.h"

#include <iostream>
#include <string>

Square::Square() {}

std::string Square::name() {
	return std::string("square");
}

void Square::set_fill(char fill) {
	m_fill = fill;
}

void Square::draw() {
	for (unsigned int i = 0; i < 6; i++) {
		for (unsigned int i = 0; i < 12; i++) {
			std::cout << m_fill;
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

extern "C" Shape *create_t() {
	return new Square;
}
