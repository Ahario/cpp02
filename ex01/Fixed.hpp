#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string.h>
#include <cmath>

class Fixed{
	public:
		Fixed();
		Fixed(Fixed& a);
		Fixed &operator=(Fixed& a);
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);

		Fixed(const int i);
		Fixed(const float f);
		float toFloat(void) const;
		int toInt(void) const;
		std::ostream& operator<<(const float f);
	private:
		int FixedPointNumber;
		const static int NumberofFractionalBits;
};

#endif