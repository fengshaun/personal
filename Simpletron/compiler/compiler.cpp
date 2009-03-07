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

#define DEBUG 1

#include "compiler.h"

Compiler::Compiler( char * srcFile, char * outFile)
		: m_output_size( 200 ),
		  m_symbolTable_size( 100 ),
		  m_input_cmd( "input" ),
		  m_print_cmd( "print" ),
		  m_rem_cmd( "rem" ),
		  m_end_cmd( "end" ),
		  m_assign_cmd( "assign" )
{
	m_srcFileName = srcFile;
	m_outFileName = outFile;

	m_srcFile.open( m_srcFileName, std::ios::in );

	m_token = "";
	m_instruction_counter = 0;
	m_symbol_counter = 0;

	//variables are stored from the end of the symbol table backwards
	m_varLocation_counter = m_symbolTable_size - 1;

	for ( int i = 0; i < m_output_size; i++ ) {
		output[ i ] = -1;
	}

	for ( int i = 0; i < m_symbolTable_size; i++ ) {
		symbolTable[ i ] = NULL;
	}
}

Compiler::~Compiler() { }

void Compiler::compile() {
	//we read each line and send it to processStatement
	std::string line = "";
	#ifdef DEBUG
	std::cout << "while: getting lines" << std::endl;
	#endif
	while ( std::getline( m_srcFile, line ) ) {
		#ifdef DEBUG
		std::cout << "processStatement()" << std::endl;
		#endif
		processStatement( line );
		#ifdef DEBUG
		std::cout << "clearing line: line = \"\"" << std::endl;
		std::cout << "clearing m_tokens vector" << std::endl;
		#endif
		line = "";
		m_tokens.clear();
	}
	//then write the files to the output file
	std::cout << "flush output" << std::endl;
	flushOutput();
}

void Compiler::processStatement( std::string & line ) {
	//we start by tokenizing the line
	#ifdef DEBUG
	std::cout << "tokenizing processStatement argument" << std::endl;
	#endif
	m_found = false;
	
	std::istringstream str( line );
	while ( std::getline( str, m_token, ' ' ) ) {
		m_tokens.push_back( m_token );
	}

	#ifdef DEBUG
	std::cout << "printing contents of m_tokens: ";
	for ( unsigned int i = 0; i < m_tokens.size(); i++ ) {
		std::cout << "\'" << m_tokens[ i ] << "\'" << " ";
	}
	std::cout << std::endl;
	#endif
	
	//now that the m_tokens is filled with tokens of the statement line,
	//we process it.
	//
	//the first token is always a line number
	//so we make a symbol in the symbol table with
	//the type as line number and location as the counter
	//and the name as the number of the line number
	std::istringstream lineNStr( m_tokens[ 0 ] );
	int ln;
	lineNStr >> ln;
	if ( !lineNStr >> ln ) {
		std::cout << "ERROR: syntax error" << std::endl;
	}
	//we use new here to make and object without name,
	//because this is done automatically!
	#ifdef DEBUG
	std::cout << "the value of m_tokens[ 0 ]: " << m_tokens[ 0 ] << std::endl;
	std::cout << "the value of lineNStr is: " << lineNStr << std::endl;
	std::cout << "making line number symbol: " << ln << std::endl;
	#endif
	
	symbolTable[ m_symbol_counter++ ] = new Symbol( ln, 'L', m_instruction_counter );

	//we should use if-else clauses to determine the command,
	//the switch logic doesn't work because we need to
	//compare two char *
	//and do the appropriate thing with it
	//and remember that the second token is always the command
	//
	//if the comparison results in a zero, they are the same
	if ( m_tokens[ 1 ] == m_input_cmd ) {
		#ifdef DEBUG
		std::cout << "it's an input command" << std::endl;
		#endif
		//the third token is always a one letter variable;
		//that's part of the syntax!
		//
		//first we have to search the symbol table to find the symbol
		//if not found, then we make that symbol and put it in
		//the symbol table
		#ifdef DEBUG
		std::cout << "the value of m_tokens[ 2 ] is: " << m_tokens[ 2 ] << std::endl;
		std::cout << "making string stream varStr for m_tokens[ 2 ]" << std::endl;
		#endif
		
		std::istringstream varStr( m_tokens[ 2 ] );
		char vC;
		#ifdef DEBUG
		std::cout << "making vC ( char v ), and varStr >> vC" << std::endl;
		#endif
		varStr >> vC;
		if ( !varStr >> vC ) {
			std::cerr << "ERROR: syntax error" << std::endl;
		}
		int v = int( vC );

		#ifdef DEBUG
		std::cout << "the value of 'v': " << v << std::endl;
		std::cout << "starting to search for the variable" << std::endl;
		#endif
		//search for the symbol in the symbol table.  If found, do the right thing.
		for ( int i = 0; i < m_symbolTable_size; i++ ) {
			#ifdef DEBUG
			std::cout << "checking if statement for symbolTable[ " << i << " ]->symbol()" << std::endl;
			#endif
			if ( symbolTable[ i ] == NULL ) break;
			if ( v == int( symbolTable[ i ]->symbol() ) ) {
				#ifdef DEBUG
				std::cout << "symbol " << char( v ) << " was found" << std::endl;
				std::cout << "v == " << symbolTable[ i ]->symbol() << std::endl;
				#endif
				output[ m_instruction_counter++ ] = ( 10 * 100 ) + symbolTable[ i ]->location();
				m_found = true;
				break;
			}
		}
		//if not found, put it in there.
		if ( m_found == false ) {
			#ifdef DEBUG
			std::cout << "symbol " << char( v ) << " not found" << std::endl;
			std::cout << "making new symbol: " << char( v ) << " : " << v << std::endl;
			#endif
			symbolTable[ m_symbol_counter ] = new Symbol( v, 'V', m_varLocation_counter-- );
			output[ m_instruction_counter++ ] = ( 10 * 100 ) + symbolTable[ m_symbol_counter++ ]->location();
			m_found = true;
		}
		/***** done with the input statement *****/
		/***** print statement *****/
	} else if ( m_tokens[ 1 ] == m_print_cmd ) {
		std::cout << "it's a print command" << std::endl;
		//now we do the same things as above, but with different output ( 11 for PRINT )
		#ifdef DEBUG
		std::cout << "making string stream varStr from m_tokens[ 2 ] : " << m_tokens[ 2 ] << std::endl;
		#endif
		std::istringstream varStr( m_tokens[ 2 ] );
		char vC;
		varStr >> vC;

		#ifdef DEBUF
		std::cout << "int v = int( vC ) " << std::endl;
		#endif
		int v = int( vC );

		if ( !varStr >> v ) {
			std::cerr << "ERROR: syntax error" << std::endl;
		}

		#ifdef DEBUG
		std::cout << "searching for symbol: " << v << std::endl;
		#endif
		for ( int i = 0; i < m_symbolTable_size; i++ ) {
			if ( symbolTable[ i ] == NULL ) break;
			if ( v == int( symbolTable[ i ]->symbol() ) ) {
				#ifdef DEBUG
				std::cout << "symbol found, pushing 11 * 100 + " << symbolTable[ i ]->location() << " " << std::endl;
				#endif
				output[ m_instruction_counter++ ] = ( 11 * 100 ) + symbolTable[ i ]->location();
				m_found = true;
			}
		}

		if ( m_found == false ) {
			std::cerr << "ERROR: undefined reference: " << char( v ) << " not found." << std::endl;
		}
		/***** done with the print statement *****/
		/***** rem statement for remarks *****/
	} else if ( m_tokens[ 1 ] == m_rem_cmd ) {
		#ifdef DEBUG
		std::cout << "it's a remark" << std::endl;
		#endif
		//do nothing here
		//we ignore the rest because this line is a comment
	} else if ( m_tokens[ 1 ] == m_assign_cmd ) {
		#ifdef DEBUG
		std::cout << "it's an assignment" << std::endl;
		#endif
		//m_tokens[ 2 ] is a variable not defined before.
		//it's kind of the same as input_cmd
		std::istringstream varStr( m_tokens[ 2 ] );
		char vC;
		#ifdef DEBUG
		std::cout << "making vC ( char v ), and varStr >> vC" << std::endl;
		#endif
		varStr >> vC;
		if ( !varStr >> vC ) {
			std::cerr << "ERROR: syntax error" << std::endl;
		}
		int v = int( vC );

		#ifdef DEBUG
		std::cout << "the value of 'v': " << v << std::endl;
		std::cout << "starting to search for the variable" << std::endl;
		#endif
		//search for the symbol in the symbol table.  If found, do the right thing.
		for ( int i = 0; i < m_symbolTable_size; i++ ) {
			#ifdef DEBUG
			std::cout << "checking if statement for symbolTable[ " << i << " ]->symbol()" << std::endl;
			#endif
			if ( symbolTable[ i ] == NULL ) break;
			if ( v == int( symbolTable[ i ]->symbol() ) ) {
				#ifdef DEBUG
				std::cout << "symbol " << char( v ) << " was found" << std::endl;
				std::cout << "v == " << symbolTable[ i ]->symbol() << std::endl;
				#endif
				output[ m_instruction_counter++ ] = ( 1 * 10000 ) + symbolTable[ i ]->location();
				m_found = true;
				break;
			}
		}
		//if not found, put it in there.
		if ( m_found == false ) {
			#ifdef DEBUG
			std::cout << "symbol " << char( v ) << " not found" << std::endl;
			std::cout << "making new symbol: " << char( v ) << " : " << v << std::endl;
			#endif
			symbolTable[ m_symbol_counter ] = new Symbol( v, 'V', m_varLocation_counter-- );
			output[ m_instruction_counter++ ] = ( 1 * 10000 ) + symbolTable[ m_symbol_counter++ ]->location();
			m_found = true;
		}

		std::istringstream nStream( m_tokens[ 3 ] );
		int n;
		nStream >> n;
		if ( !nStream >> n ) {
			std::cerr << "ERROR: syntax error" << std::endl;
		}

		output[ m_instruction_counter++ ] = n;
	} else if ( m_tokens[ 1 ] == m_end_cmd ) {
		std::cout << "it's end" << std::endl;
		output[ m_instruction_counter ] = 9999;
	} else {
		std::cout << "ERROR: syntax error" << std::endl;
		//TODO: checking for other stuff!
	}

	/**********************************************
	 *  HERE WE ADD MORE NEW COMMANDS AND SYNTAX  *
	 *  USING THE SAME ELSE_IF CLAUSES            *
	 **********************************************/
	
}

void Compiler::flushOutput() {
	m_outFile.open( m_outFileName, std::ios::out );
	for ( int i = 0; i < m_output_size; i++ ) {
		if ( output[ i ] == -1 ) break;

		m_outFile << output[ i ] << std::endl;
	}
}