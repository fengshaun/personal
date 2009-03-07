#ifndef SENDER_HPP
#define SENDER_HPP

#include <sigc++/sigc++.h>

class Sender : public sigc::trackable
{
	public:
		Sender();
		
		void send_signal();
		sigc::signal<void> signal_packet_sent;
};

#endif // SENDER_HPP