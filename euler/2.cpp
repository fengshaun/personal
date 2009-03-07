#include <iostream>
#include <vector>

int main() {
	const long int max = 4000000;
	std::vector<long int> vec;
	long int sum = 0;
	
	vec.push_back(1);
	vec.push_back(2);
	
	long int i = 2;
	while (1) {
		long int num = vec[i - 1] + vec[i - 2];
		
		if (num > 4000000) {
			break;
		}

		vec.push_back(num);
		i++;
	}
	
	for (i = 0; i < vec.size(); i++) {
		if (!(vec[i] % 2)) {
			sum += vec[i];
		}
	}
	
	std::cout << sum << std::endl;
}