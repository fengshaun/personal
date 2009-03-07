/***************************************************************************
 * General Ledger, Copyright (C) 2008 Armin Moradi <feng.shaun@gmail.com>  *
 * http://fengshaun.wordpress.com                                          *
 *                                                                         *
 * This program is free software; you can redistribute it and/or modify    *
 * it under the terms of the GNU General Public License as published by    *
 * the Free Software Foundation; either version 3 of the License, or       *
 * (at your option) any later version.                                     *
 *                                                                         *
 * This program is distributed in the hope that it will be useful,         *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of          *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the            *
 * GNU General Public License for more details.                            *
 *                                                                         *
 * You should have received a copy of the GNU General Public License       *
 * along with this program; if not, write to the Free Software             *
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 US  *
 ***************************************************************************/

#include "triangle.h"

Triangle::Triangle( double h, double w, int inc, char f ) {
	setHeight( h );
	setWidth( w );
	setFill( f );
	setIncrement( inc );
}

Triangle::~Triangle() { }

void Triangle::draw() {
	for( int i = 0; i < height(); i++ ) { //ic is increment
		for( int j = 0; j < width(); j += increment() ) {
			std::cout << fill();
		}
		std::cout << std::endl;
	}
}

void Triangle::setIncrement( int i ) {
	i > 0 ? inc = i : inc = 1;
}

int Triangle::increment() {
	return this->inc;
}
