/* General Ledger, Copyright (C) 2008 Armin Moradi <feng.shaun@gmail.com>
* http://fengshaun.wordpress.com
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 3 of the License, or
* (at your option) any later version.
* 
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 US
*/

#include <cstdlib>
#include "machine.h"

Machine::Machine () : counter( 0 ), accumulator( 0 ), instruction( 0 ) {
	for( int i = 0; i < 100; i++ ) {
		disk[ i ] = 0;
	}
}

Machine::~Machine () {
}

void Machine::processInstructions() {

	for( unsigned int i = 0; i < memory.size(); i++ ) {
		int section = memory[ i ] / 10000;
		int task = ( memory[ i ] / 100 ) % 100;
		int location = memory[ i ] % 100;

		if( section == GENERAL ) {

			switch( task ) {
				case READ:
					double input;
					cout << "> ";
					cin >> input;
					disk[ location ] = input;
					break;

				case PRINT:
					cout << disk[ location ] << endl;
					break;

				case LOAD:
					accumulator = disk[ location ];
					break;

				case STORE:
					disk[ location ] = accumulator;
					break;
					
				case BRANCH:
					i = location - 1; //because we want to branch off to the desired location.
					break;

				case BRANCH_ZERO:
					if( accumulator == 0 ) {
						i = location - 1;
					}
					break;

				case BRANCH_NEGATIVE:
					if( accumulator < 0 ) {
						i = location - 1;
					}
					break;

				case 0: //just ignore 0000 instructions
					break;

				default:
					cout << "ERROR: instruction " << task << " at location " << i << " is not defined in GENERAL" << endl;
					exit( 1 );
					break;
			}
		} else if( section == CALCULATOR ) {

			switch( task ) {

				case ADD:
					accumulator = calculator->add( accumulator, disk[ location ] );
					break;

				case SUBTRACT:
					accumulator = calculator->subtract( accumulator, disk[ location ] );
					break;

				case DIVIDE:
					accumulator = calculator->divide( accumulator, disk[ location ] );
					break;

				case MULTIPLY:
					accumulator = calculator->multiply( accumulator, disk[ location ] );
					break;

				case PERMUTATION:
					accumulator = calculator->permutation( accumulator, disk[ location ] );
					break;

				case COMBINATION:
					accumulator = calculator->combination( accumulator, disk[ location ] );
					break;

				case FACTORIAL:
					accumulator = calculator->factorial( disk[ location ] );
					break;

				case POWER:
					accumulator = calculator->power( accumulator, disk[ location ] );
					break;

				case SQROOT:
					accumulator = calculator->sqroot( disk[ location ] );
					break;

				case SINE:
					accumulator = calculator->sine( disk[ location ] );
					break;

				case COSINE:
					accumulator = calculator->cosine( disk[ location ] );
					break;

				case TANGENT:
					accumulator = calculator->tangent( disk[ location ] );
					break;

				case RANDOM:
					accumulator = calculator->random();
					break;

				case RANDOM_DICE:
					accumulator = calculator->randomDice();
					break;

				case 0:
					break;

				default:
					cout << "ERROR: instruction (" << task << ") at location " << i << " is not defined in CALCULATOR" << endl;
					exit( 1 );
					break;
			}
		} else {
			cout << "ERROR: section (" << section << ") not defined. " << endl;
			exit( 1 );
		}
	}
}

void Machine::setConst( double number, int location ) {
	disk[ location ] = number;
}

istream &Machine::getFile( istream &file ) {
	memory.push_back( 0 );

	while( true ) {
		file >> this->instruction;

		if( ( instruction / 100 ) == 100 ) {
			file >> accumulator;
			this->setConst( accumulator, instruction % 100 );
			memory.push_back( 0 );
		} else if( this->instruction != END ) {
			this->memory.push_back( this->instruction );
		} else {
			break;
		}
	}
	return file;
}

istream &operator>>( istream &input, Machine &machine ) {
	while( true ) {
		cout << setfill( '0' ) << setw( 3 ) << right << machine.counter << " ? ";
		input >> machine.instruction;
		
		if( ( machine.instruction / 100 ) == 100 ) {
			input >> machine.accumulator;
			machine.setConst( machine.accumulator, machine.instruction % 100 );
			machine.memory.push_back( 0 );
			machine.counter++;
		} else if( machine.instruction != END ) {
			machine.memory.push_back( machine.instruction );
			machine.counter++;
		} else {
			break;
		}
	}
	return input;
}

