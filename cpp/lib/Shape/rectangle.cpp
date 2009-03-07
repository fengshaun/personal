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

#include "rectangle.h"

Rectangle::Rectangle( double h, double w, char f ) {
	this->setHeight( h );
	this->setWidth( w );
	this->setFill( f );
}

Rectangle::~Rectangle() { }

void Rectangle::draw() {
	for( int row = 0; row < this->height(); row++ ) {
		for( int column = 0; column < this->width(); column++ ) {
			std::cout << this->fill();
		}
		std::cout << std::endl;
	}
}
