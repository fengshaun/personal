#include <unistd.h>
#include <cstdlib>
#include <ctime>

#include "sender.hpp"
#include "receiver.hpp"

int main() {
	Sender sender;
	Receiver receiver;
	
	std::srand(time(0));
	
	sender.signal_packet_sent.connect(sigc::mem_fun(receiver, &Receiver::print_message));
	
	int a = 1 + std::rand() % 6;
	
	for(unsigned int i = 0; i < a; i++) {
		int n = 1 + std::rand() % 6;
		sleep(n);
		sender.signal_packet_sent.emit();
	}
	
	return 0;
}