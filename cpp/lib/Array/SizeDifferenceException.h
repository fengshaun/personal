#ifndef SIZEDIFFERENCEEXCEPTION_H
#define SIZEDIFFERENCEEXCEPTION_H

#include <stdexcept>

class SizeDifferenceException : public std::runtime_error
{
	public:
		SizeDifferenceException() : std::runtime_error( "Array objects have different sizes" ) {}
};

#endif
