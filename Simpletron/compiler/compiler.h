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

#ifndef COMPILER_H
#define COMPILER_H

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>

#include "symbol.h"

class Compiler
{
	public:
		Compiler( char *, char * );
		virtual ~Compiler();

		void compile();
		void processStatement( std::string & );

		int output[ 200 ];

	protected:
		void flushOutput();
		Symbol * symbolTable[ 100 ];

	private:
		std::ifstream m_srcFile;
		std::ofstream m_outFile;

		char * m_srcFileName;
		char * m_outFileName;

		std::string m_token;
		std::vector< std::string > m_tokens;

		//Counters to keep track of things
		unsigned short int m_instruction_counter;
		unsigned short int m_symbol_counter;


		//Sizes of different components of the compiler
		const int m_output_size;
		const int m_symbolTable_size;
		
		//available commands
		const std::string m_input_cmd;
		const std::string m_print_cmd;
		const std::string m_assign_cmd;
		const std::string m_rem_cmd;
		const std::string m_end_cmd;

		//a counter to keep track of where variables should be stored
		unsigned short int m_varLocation_counter;

		//symbol found
		bool m_found;
};

#endif //COMPILER_H