#include "sender.hpp"

Sender::Sender() {}

void Sender::send_signal() {
	signal_packet_sent.emit();
}
