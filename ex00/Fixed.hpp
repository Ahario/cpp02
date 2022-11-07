#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string.h>

class Fixed{
	public:
		Fixed();
		Fixed(Fixed& a);
		Fixed &operator=(Fixed& a);
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);
	private:
		int FixedPointNumber;
		const static int NumberofFractionalBits;
};

#endif