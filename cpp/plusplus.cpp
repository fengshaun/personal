#include <iostream>

int main() {
	std::cout << "The difference between i++ and ++i with 'for loop'" << std::endl;
	std::cout << "using i++: " << std::endl;
	for ( int i = 0; i < 10; i++ ) {
		std::cout << i << " ";
	}
	
	std::cout << std::endl << "using ++i: " << std::endl;
	for ( int i = 0; i < 10; ++i ) {
		std::cout << i << " ";
	}
	
	std::cout << std::endl << std::endl;
	
	std::cout << "The difference between i++ and ++i with 'while loop'" << std::endl;
	std::cout << "using i++: " << std::endl;
	int i = 0;
	while( i < 10 ) {
		std::cout << i << " ";
		i++;
	}
	
	std::cout << std::endl << "using ++i: " << std::endl;
	i = 0;
	while( i < 10 ) {
		std::cout << i << " ";
		++i;
	}

	std::cout << std::endl << std::endl;
	
	std::cout << "The difference between i++ and ++i in std::cout" << std::endl;
	std::cout << "i = 5" << std::endl;
	i = 5;
	
	std::cout << "++i, i++, and then i!" << std::endl;
	std::cout << ++i << std::endl;
	std::cout << i++ << std::endl;
	std::cout << i << std::endl << std::endl;
}