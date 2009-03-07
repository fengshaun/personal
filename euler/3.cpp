#include <iostream>
#include <vector>
#include <fstream>
/*
std::vector<long int> prime_list(long int max) {
	std::cout << "prime numbers: ";
	std::vector<long int> vec;
	vec.push_back(2);
	
	bool is_prime;
	for (int i = 3; i < max; i++) {
		is_prime = true;
		for (int j = 2; j < i / 2 + 1; j++) {
			if (!(i % j)) {
				is_prime = false;
				break;
			}
		}
		if (is_prime) {
			std::cout << i << " ";
			vec.push_back(i);
		}
	}
	
	std::cout << std::endl;
	return vec;
}
*/
bool is_prime(long int num) {
	// it's assumed not to be even number
	// why i * i?  was: i < num...
	for (long int i = 3; i * i < num / 2 + 1; i += 2) {
		if (!(num % i)) {
			return false;
		}
	}
	return true;
}
		

int main() {
	/*
	const long int num = 600851475143;
	for (long int factor = num / 2; factor > 1; factor -= 2) {
		if (!(num % factor)) {
			std::cout << std::endl << factor << std::endl;
			if (is_prime(factor)) {
				std::cout << std::endl << std::endl << std::endl << factor << std::endl;
				break;
			}
		}
	}
	*/
	long int factor = 0;
	const long int num = 600851475143;
	// why i * i? was: i < num...
	// because a number can have at most one
	// prime factor more than sqrt(number)
	for (long int i = 3; i * i < num / 2 + 1; i += 2) {
		if (!(num % i)) {
			if (is_prime(factor)) {
				std::cout << std::endl << factor << std::endl;
				factor = i;
			}
		}
	}
	
	std::cout << std::endl << std::endl << factor << std::endl;
}

//NOTE: answer is: 6857
