#include <sstream>
#include <vector>
#include <string>
#include <iostream>

int main() {
	std::string string("abc:def");
	char split_char = ':';
	std::istringstream splitstr(string);
	std::vector<std::string> tokensVec;

	for(std::string token; std::getline(splitstr, token, split_char); tokensVec.push_back(token));
	
	for ( unsigned int i = 0; i < tokensVec.size(); i++ ) {
		std::cout << tokensVec[ i ] << std::endl;
	}
}
