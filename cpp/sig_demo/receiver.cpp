#include "receiver.hpp"

#include <iostream>

Receiver::Receiver() {}

void Receiver::print_message() {
	std::cout << "signal has been received by Receiver" << std::endl;
}