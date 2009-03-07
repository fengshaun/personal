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

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>

#include "twoDimentionalShape.h"

class Triangle : public TwoDimentionalShape
{
	public:
		Triangle( double = 1, double = 1, int = 1, char = '-' );
		~Triangle();

		virtual void draw();

	protected:
		void setIncrement( int ); //as the row comes down, increment the number of fills in a row
		int increment();

	private:
		int inc;
};

#endif //TRIANGLE_H
